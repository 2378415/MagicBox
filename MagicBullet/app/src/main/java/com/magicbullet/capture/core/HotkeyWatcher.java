package com.magicbullet.capture.core;

import android.os.Handler;
import android.os.Looper;
import android.os.SystemClock;

import java.util.Locale;

/**
 * Turns a mouse side button into an app hotkey.
 *
 * <p>The box consumes subscribed buttons (0x39): the PC never sees the click, and the edge comes
 * back here as an asynchronous 0xE1 frame. The subscription dies after 10 s without traffic, so a
 * 1 Hz {@code EVT_STAT} keeps it alive and doubles as a health probe.
 *
 * <p>"学习按键" subscribes both side buttons for a few seconds and reports which one was pressed,
 * because which physical button maps to mask 0x08 vs 0x10 differs between mice.
 */
public final class HotkeyWatcher {

    public interface Listener {
        /** Hotkey pressed (true) or released (false). */
        void onHotkey(boolean down);

        /** Subscription state for the UI. */
        void onHotkeyState(boolean subscribed, String note);

        /** Result of "学习按键": the mask bit that was seen. */
        void onHotkeyLearned(int mask);
    }

    private static final long HEARTBEAT_MS = 1000L;
    private static final long LEARN_TIMEOUT_MS = 8000L;
    /** Both side buttons plus the right button: the three keys that make sense as an aim toggle. */
    public static final int LEARN_MASK = 0x1A;

    private ControlPort mPort;
    private final Handler mHandler = new Handler(Looper.getMainLooper());
    private Listener mListener;
    private int mMask = AimConfig.DEFAULT_HOTKEY_MASK;
    /** false = pass-through: the PC still receives the button, we only get the edge. */
    private boolean mConsume;
    private boolean mSubscribed;
    private boolean mLearning;
    private long mLearnStartMs;
    private long mLastStatMs;
    private int mLastLastFwd = -1;
    /** True while the subscribed button is believed held, kept in sync with EVT_STAT.cur. */
    private boolean mReportedDown;
    /** 上一次"是否有任何订阅键按住"，用于多选热键的上升/下降沿。 */
    private boolean mWatchedDown;

    private final Runnable mHeartbeat = new Runnable() {
        @Override
        public void run() {
            if (!mSubscribed) {
                return;
            }
            if (!mPort.isOpen()) {
                mSubscribed = false;
                note("控制口已断开，热键订阅失效");
                return;
            }
            mLastStatMs = SystemClock.elapsedRealtime();
            mPort.evtStat();
            mHandler.postDelayed(this, HEARTBEAT_MS);
        }
    };

    private final Runnable mLearnTimeout = () -> {
        if (mLearning) {
            mLearning = false;
            mPort.evtSubscribe(mMask, true, mConsume);
            note("学习超时：没收到按键，保持原热键 0x" + Integer.toHexString(mMask));
        }
    };

    private final ControlPort.EvtListener mEvtListener = new ControlPort.EvtListener() {
        @Override
        public void onEvt(int mask, int edge) {
            // This callback arrives on the serial reader thread. Everything downstream (config
            // save → fragment views) must run on the main thread, so hop once here.
            mHandler.post(() -> handleEvt(mask, edge));
        }

        @Override
        public void onEvtStat(int lastFwd, int flags, int subscribedMask, int cur) {
            mHandler.post(() -> {
                if ((flags & 0x04) != 0 && mMask != 0) {
                    // 盒子 10 s 没收到心跳就自动退订（flags bit2）。若我们这边还当自己是订阅状态，
                    // 就会再也收不到边沿 —— 表现正是"按了没反应、瞄准取消不了"。这里自动补订阅。
                    mPort.logNote("盒子已自动退订（10 s 无心跳），重新订阅");
                    mPort.evtSubscribe(mMask, true, mConsume);
                }
                if (mReportedDown && !HotkeyEdge.anyHeld(cur, mMask)) {
                    // EVT_STAT.cur 是盒子看到的真实按键位图：这里等于 0 说明手早就松了，
                    // 说明松开边沿丢了 —— 补一次释放，否则去抖锁存会把热键永久关死。
                    mReportedDown = false;
                    Listener listener = mListener;
                    if (listener != null) {
                        listener.onHotkey(false);
                    }
                    mPort.logNote("热键释放补发（EVT_STAT.cur=0）");
                }
                if (lastFwd != mLastLastFwd) {
                    mLastLastFwd = lastFwd;
                    note(String.format(Locale.US,
                            "热键已订阅 mask=0x%02X · PC 侧按键字节 last_fwd=0x%02X · flags=0x%02X",
                            subscribedMask, lastFwd, flags));
                }
            });
        }
    };

    private void handleEvt(int mask, int edge) {
        // 每次边沿都留痕：偶发"双击"时能直接看出是两个 down 还是一个 down 一个 up。
        mPort.logNote(String.format(Locale.US, "热键边沿 mask=0x%02X edge=0x%02X（%s）",
                mask, edge, mLearning ? "学习中" : "运行中"));
        if (mLearning) {
            int pressed = edge & mask & LEARN_MASK;
            if (pressed != 0) {
                finishLearn(pressed);
            }
            return;
        }
        // 多选热键：mask 里任何一位按住就算按下。只有"从没人按住 → 有人按住"才报 down，
        // "还有人按住"没有变化，全部松开才报 up —— 这样加按第二个键不会重复触发。
        boolean down = HotkeyEdge.anyHeld(mask, mMask);
        if (HotkeyEdge.transition(mWatchedDown, down) == HotkeyEdge.NONE) {
            return;
        }
        mWatchedDown = down;
        mReportedDown = down;
        Listener listener = mListener;
        if (listener != null) {
            listener.onHotkey(down);
        }
    }

    public HotkeyWatcher(ControlPort port) {
        mPort = port;
        mPort.setEvtListener(mEvtListener);
    }

    public void setListener(Listener listener) {
        mListener = listener;
    }

    public void setConsume(boolean consume) {
        mConsume = consume;
    }

    public boolean consume() {
        return mConsume;
    }

    public boolean isSubscribed() {
        return mSubscribed;
    }

    public int mask() {
        return mMask;
    }

    /** Subscribes {@code mask} (0 = unsubscribe) and starts the heartbeat. */
    public void subscribe(int mask) {
        mMask = mask & 0x1F;
        mHandler.removeCallbacks(mLearnTimeout);
        mLearning = false;
        if (mMask == 0) {
            unsubscribe();
            return;
        }
        if (!mPort.isOpen()) {
            mSubscribed = false;
            note("控制口未连接，热键无法订阅");
            return;
        }
        mPort.setEvtListener(mEvtListener);
        mPort.evtSubscribe(mMask, true, mConsume);
        mSubscribed = true;
        note(String.format(Locale.US, "热键已订阅 mask=0x%02X（%s）", mMask,
                mConsume ? "吃掉，PC 收不到" : "穿透，PC 照常收到"));
        mHandler.removeCallbacks(mHeartbeat);
        mHandler.postDelayed(mHeartbeat, HEARTBEAT_MS);
    }

    public void unsubscribe() {
        mHandler.removeCallbacks(mHeartbeat);
        mHandler.removeCallbacks(mLearnTimeout);
        mLearning = false;
        if (mSubscribed) {
            mPort.evtSubscribe(0, false, false);
        }
        mSubscribed = false;
        note("热键已退订，按键恢复透传给 PC");
    }

    /** Subscribes both side buttons for up to 8 s and reports which one fires. */
    public void startLearn() {
        if (!mPort.isOpen()) {
            note("控制口未连接，无法学习按键");
            return;
        }
        mHandler.removeCallbacks(mHeartbeat);
        mWatchedDown = false;
        mReportedDown = false;
        mLearning = true;
        mSubscribed = true;
        mLearnStartMs = SystemClock.elapsedRealtime();
        mPort.setEvtListener(mEvtListener);
        mPort.evtSubscribe(LEARN_MASK, true, mConsume);
        note("请按一下要当热键的侧键（8 秒内）…");
        mHandler.postDelayed(mLearnTimeout, LEARN_TIMEOUT_MS);
    }

    private void finishLearn(int mask) {
        mLearning = false;
        mHandler.removeCallbacks(mLearnTimeout);
        // 多选热键：学到的键并入现有位图（可多次学习把多个键加进来）
        mMask = mMask == 0 ? mask : (mMask | mask);
        mPort.evtSubscribe(mMask, true, mConsume);
        mSubscribed = true;
        note(String.format(Locale.US, "已学到侧键 mask=0x%02X，热键改为它", mask));
        mHandler.removeCallbacks(mHeartbeat);
        mHandler.postDelayed(mHeartbeat, HEARTBEAT_MS);
        Listener listener = mListener;
        if (listener != null) {
            listener.onHotkeyLearned(mask);
        }
    }

    public void close() {
        mHandler.removeCallbacksAndMessages(null);
        if (mSubscribed) {
            mPort.evtSubscribe(0, false, false);
        }
        mSubscribed = false;
        mPort.setEvtListener(null);
    }

    private void note(String text) {
        Listener listener = mListener;
        if (listener != null) {
            listener.onHotkeyState(mSubscribed, text);
        }
    }
}
