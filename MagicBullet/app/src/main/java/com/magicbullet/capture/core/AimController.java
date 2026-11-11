package com.magicbullet.capture.core;

import android.content.Context;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;

import java.util.List;
import java.util.Locale;

/**
 * Closed-loop aiming on top of the firmware's {@code 0x3C AIM} entry.
 *
 * <p>Why AIM instead of {@code 0x36 SUMV}: aiming only needs "move this far, finish inside this
 * budget". AIM takes a time budget ({@code max_ms}, constant-velocity profile, no acceleration
 * ramp), has its own dead zone and a session clamp, and reports what happened in
 * {@code 0x3D AIM_STATE}. That makes a per-frame loop both lower-latency and verifiable.
 *
 * <p>The box cannot report the pointer position, so the loop is still proportional: every frame the
 * remaining error is scaled by {@code gain}, limited to {@code maxStepCounts} and handed to AIM,
 * which replaces any correction still in flight.
 */
public final class AimController implements HotkeyWatcher.Listener, ControlPort.Listener,
        ControlPort.AimStateListener {

    private static final String TAG = "AimController";
    private static final long STATE_POLL_MS = 500L;

    /** Everything the aim page and the overlay need to show. */
    public static final class Stats {
        public final boolean armed;
        public final boolean aiming;
        public final int triggers;
        public final float lastErrorPx;
        public final float velocityPxPerSec;
        public final String target;
        public final String note;
        /** AIM_STATE mirror. */
        public final int lastResult;
        public final int rounds;
        public final int deadHits;
        public final int aborted;
        public final int gen;
        public final boolean aimSupported;
        /** Button priority counters (0x3E): in / sent / worst latency in µs / dropped motion. */
        public final int btnIn;
        public final int btnSent;
        public final int btnWaitUs;
        public final int btnOverflow;
        /** 按键字节洪泛窗口数（1 s 内变化 > 50 次）。 */
        public final int btnFlood;
        public final int btnMerged;
        public final int btnCancel;
        /** B/A：自校准结果与按键回环审计（0x3F）。 */
        public final float adaptiveGain;
        public final float realGain;
        public final int auditIn;
        public final int auditOut;
        public final int auditExtra;
        /** P2-13：粘滞命中 / 换人次数。 */
        /** 自学习结果（展示用）：当前死区与单帧上限。 */
        public final float autoDeadzonePx;
        public final int autoMaxCounts;
        public final int stickHits;
        public final int stickSwitches;

        Stats(boolean armed, boolean aiming, int triggers, float lastErrorPx,
              float velocityPxPerSec, String target, String note, int lastResult, int rounds,
              int deadHits, int aborted, int gen, boolean aimSupported,
              int btnIn, int btnSent, int btnWaitUs, int btnOverflow, int btnFlood,
              int btnMerged, int btnCancel,
              float adaptiveGain, float realGain, int auditIn, int auditOut, int auditExtra,
              float autoDeadzonePx, int autoMaxCounts, int stickHits, int stickSwitches) {
            this.armed = armed;
            this.aiming = aiming;
            this.triggers = triggers;
            this.lastErrorPx = lastErrorPx;
            this.velocityPxPerSec = velocityPxPerSec;
            this.target = target;
            this.note = note;
            this.lastResult = lastResult;
            this.rounds = rounds;
            this.deadHits = deadHits;
            this.aborted = aborted;
            this.gen = gen;
            this.aimSupported = aimSupported;
            this.btnIn = btnIn;
            this.btnSent = btnSent;
            this.btnWaitUs = btnWaitUs;
            this.btnOverflow = btnOverflow;
            this.btnFlood = btnFlood;
            this.btnMerged = btnMerged;
            this.btnCancel = btnCancel;
            this.adaptiveGain = adaptiveGain;
            this.realGain = realGain;
            this.auditIn = auditIn;
            this.auditOut = auditOut;
            this.auditExtra = auditExtra;
            this.autoDeadzonePx = autoDeadzonePx;
            this.autoMaxCounts = autoMaxCounts;
            this.stickHits = stickHits;
            this.stickSwitches = stickSwitches;
        }
    }

    /** Overlay hook: normalised body box + normalised predicted point. */
    public interface OverlaySink {
        void onAimOverlay(boolean aiming, float left, float top, float right, float bottom,
                          float predictedX, float predictedY);
    }

    /** Small indirection so the UI can subscribe without the controller knowing about views. */
    public interface StatsListener {
        void onAimStats(Stats stats);
    }

    private static AimController sInstance;

    private final Context mContext;
    private final AimConfig mConfig;
    private final ControlPort mPort;
    private final HotkeyWatcher mHotkey;
    private final TargetTracker mTracker = new TargetTracker();
    private final HotkeyGate mGate = new HotkeyGate();
    private final Handler mMain = new Handler(Looper.getMainLooper());

    private volatile StatsListener mUiListener;
    private volatile OverlaySink mOverlaySink;
    private boolean mArmed;
    private boolean mAiming;
    private int mTriggers;
    private float mLastErrorPx;
    private float mLastVelocityPx;
    private String mTargetText = "";
    private String mNote = "";
    private int mLastResult;
    private int mRounds;
    private int mDeadHits;
    private int mAborted;
    private int mGen;
    /** True between a sent AIM and the next stop: keeps SUMV_STOP from being spammed per frame. */
    private boolean mTrajectoryActive;
    /** AIM commands sent since the last AIM_STATE poll, for the "is the box accepting?" check. */
    private int mSentSinceState;
    private int mPrevRounds = -1;
    private int mPrevDeadHits = -1;
    /** Rate limiters for the diagnostic lines below. */
    private long mLastAimLogMs;
    /** A：自校准增益状态。mGainAdapt < 0 = 还没标定过。 */
    private float mGainAdapt = -1f;
    private float mLastGReal;
    private float mPrevDxPx;
    private float mPrevDyPx;
    private float mPrevErrorPx;
    private int mPrevTrackId = -1;
    private boolean mPrevShotSent;
    /** 上一枪请求的是残差的多少（自适应增益需要它才能反解真实响应）。 */
    private float mPrevShotFraction;
    /** B：目标粘滞。 */
    private int mStickId = -1;
    private int mStickMiss;
    /** 正在被观察、可能接管的候选 id，与连续判定帧数（换人确认）。 */
    private int mPendingStickId = -1;
    private int mSwitchStreak;
    private long mLastNoTargetLogMs;
    private long mLastFrameMs;
    private long mLastStallLogMs;
    private int mPollTick;
    /** P2-11：静止目标框心抖动（像素/帧），用于自适应死区。 */
    private float mJitterEma = -1f;
    private float mPrevTargetX;
    private float mPrevTargetY;
    private boolean mHasPrevTarget;
    /** P2-11/自学习：静止目标的抖动样本（P90 用于死区）。 */
    private static final int NOISE_WIN = 60;
    private final float[] mJitterWin = new float[NOISE_WIN];
    private int mJitterN;
    private int mJitterHead;
    /** 自学习：跳变样本（目标被重新匹配时的位移，P90 用于单帧上限）。 */
    private final float[] mJumpWin = new float[NOISE_WIN];
    private int mJumpN;
    private int mJumpHead;
    /** 最近一次自学习结果，仅用于界面展示。 */
    private float mAutoDeadzonePx;
    private int mAutoMaxCounts;
    private long mLastSampleMs;
    /** P2-13：粘滞统计（换人次数 = 粘滞失效次数）。 */
    private int mStickHits;
    private int mStickSwitches;
    private long mLastGainSaveMs;

    private final Runnable mStatePoll = new Runnable() {
        @Override
        public void run() {
            if (!mArmed) {
                return;
            }
            if (mPort.isOpen()) {
                mPort.aimState();
                if ((mPollTick++ & 1) == 0) {   // 1 Hz 就够：这两个是累计计数
                    mPort.hidStat();
                    mPort.btnAudit();
                }
            }
            // P1-8：检测断流看门狗。瞄准中却没有新帧时，之前是静默的，只能靠人猜。
            if (mAiming) {
                long now = android.os.SystemClock.elapsedRealtime();
                if (mLastFrameMs > 0 && now - mLastFrameMs > 200L) {
                    if (now - mLastStallLogMs > 1000L) {
                        mLastStallLogMs = now;
                        final long gap = now - mLastFrameMs;
                        mNote = "检测断流 " + gap + " ms：瞄准暂时无效（画面/推理卡住？）";
                        mPort.logNote(mNote);
                        publish();
                    }
                }
            }
            mMain.postDelayed(this, STATE_POLL_MS);
        }
    };

    private AimController(Context context) {
        mContext = context.getApplicationContext();
        mConfig = AimConfig.load(mContext);
        mPort = ControlPort.get(mContext);
        mHotkey = new HotkeyWatcher(mPort);
        mHotkey.setListener(this);
        mPort.setAimStateListener(this);
    }

    public static synchronized AimController get(Context context) {
        if (sInstance == null) {
            sInstance = new AimController(context);
        }
        return sInstance;
    }

    public void setUiListener(StatsListener listener) {
        mUiListener = listener;
        if (listener != null) {
            listener.onAimStats(stats());
        }
    }

    public void setOverlaySink(OverlaySink sink) {
        mOverlaySink = sink;
    }

    public AimConfig config() {
        return mConfig;
    }

    /** Cheap check for hot paths (per-frame): no Stats allocation. */
    public boolean isAiming() {
        return mAiming;
    }

    public Stats stats() {
        ControlPort.HidStat hid = mPort.lastHidStat();
        ControlPort.BtnAudit audit = mPort.lastBtnAudit();
        return new Stats(mArmed, mAiming, mTriggers, mLastErrorPx, mLastVelocityPx,
                mTargetText, mNote, mLastResult, mRounds, mDeadHits, mAborted, mGen,
                mPort.sawAimState(),
                hid == null ? 0 : hid.btnIn, hid == null ? 0 : hid.btnSent,
                hid == null ? 0 : hid.waitMaxUs, hid == null ? 0 : hid.overflow,
                hid == null ? 0 : hid.flood, hid == null ? 0 : hid.merged,
                hid == null ? 0 : hid.cancel,
                mGainAdapt, mLastGReal,
                audit == null ? 0 : audit.inChg, audit == null ? 0 : audit.outChg,
                audit == null ? 0 : audit.extra, mAutoDeadzonePx, mAutoMaxCounts,
                mStickHits, mStickSwitches);
    }

    // ------------------------------------------------------------------ arming

    public void setArmed(boolean armed) {
        mArmed = armed;
        mTrajectoryActive = false;
        mGate.reset();
        mMain.removeCallbacks(mStatePoll);
        if (armed) {
            mTracker.reset();
            mHotkey.setConsume(mConfig.hotkeyConsume());
            mHotkey.subscribe(mConfig.hotkeyMask());
            mNote = "已布防：按住侧键启动瞄准";
            mMain.postDelayed(mStatePoll, STATE_POLL_MS);
        } else {
            setAiming(false);
            mHotkey.unsubscribe();
            mNote = "未布防";
        }
        publish();
    }

    public void startLearnHotkey() {
        mHotkey.startLearn();
    }

    /** Volume key / on-screen button path; behaves exactly like the box side button. */
    public void onExternalTrigger(boolean down) {
        onHotkey(down);
    }

    // ------------------------------------------------------------------ HotkeyWatcher.Listener

    @Override
    public void onHotkey(boolean down) {
        if (!mArmed) {
            return;
        }
        if (mConfig.holdMode()) {
            setAiming(down); // holding needs every edge; bounce does not hurt
            return;
        }
        long now = android.os.SystemClock.elapsedRealtime();
        if (!down) {
            mGate.noteUp(now);
            return;
        }
        if (!mGate.acceptDown(now)) {
            // Either contact chatter (release only lasted a few ms) or a duplicate press that
            // never saw a release. Both must not toggle, or one click flips aim twice.
            int suppressed = mGate.suppressed();
            if (suppressed % 5 == 1) { // do not flood the note for every bounce
                mNote = String.format(Locale.US,
                        "已忽略重复按下（累计 %d 次）：一次点击只切换一次", suppressed);
                publish();
            }
            return;
        }
        boolean next = !mAiming;
        setAiming(next);
        mPort.logNote(String.format(Locale.US, "热键切换 → %s（mTriggers=%d）",
                next ? "瞄准 ON" : "瞄准 OFF", mTriggers));
    }

    @Override
    public void onHotkeyState(boolean subscribed, String note) {
        mNote = note;
        if (!subscribed && mArmed) {
            mArmed = false;
            mMain.removeCallbacks(mStatePoll);
            setAiming(false);
        }
        publish();
    }

    @Override
    public void onHotkeyLearned(int mask) {
        mConfig.hotkeyMask(mask);
        mConfig.save();
        if (mArmed) {
            mHotkey.setConsume(mConfig.hotkeyConsume());
            mHotkey.subscribe(mask);
        }
        publish();
    }

    // ------------------------------------------------------------------ ControlPort callbacks

    @Override
    public void onState(String status, String detail) {
        if (!mPort.isOpen() && mAiming) {
            setAiming(false);
        }
        publish();
    }

    @Override
    public void onLog(String line) {
        // The control port keeps its own log; aiming only reacts to AIM_STATE.
    }

    @Override
    public void onAimState(ControlPort.AimState state) {
        if (mAiming && mSentSinceState >= 20 && mPrevRounds >= 0
                && state.rounds == mPrevRounds && state.deadHits == mPrevDeadHits) {
            // 我们一直在发 AIM，盒子既没走完一轮也没判死区：要么在拒绝，要么目标不在准心框里。
            mNote = String.format(Locale.US,
                    "已发 %d 条 AIM，但 rounds/死区都没涨 → 盒子拒绝或目标不在框内", mSentSinceState);
        }
        mPrevRounds = state.rounds;
        mPrevDeadHits = state.deadHits;
        mSentSinceState = 0;
        mLastResult = state.lastResult;
        mRounds = state.rounds;
        mDeadHits = state.deadHits;
        mAborted = state.aborted;
        mGen = state.gen;
        if (state.lastResult == 6) {
            mNote = "AIM 超限：会话累计超过 4000 counts，固件会一直拒绝到重启；"
                    + "把「会话钳位」关掉即可（默认已关）";
        } else if (state.lastResult == 3) {
            mNote = "AIM 被拒绝：检查单帧步长 / 控制口是否断开";
        }
        publish();
    }

    // ------------------------------------------------------------------ per-frame tick

    /**
     * Called on the inference thread for every detection result, aiming or not: the tracker needs a
     * warm history so the first hotkey press already has a velocity estimate.
     */
    public void onDetections(List<Detection> detections, int frameW, int frameH, long tsNanos) {
        if (frameW <= 0 || frameH <= 0 || !mArmed) {
            return;
        }
        mLastFrameMs = android.os.SystemClock.elapsedRealtime();
        mTracker.setVelocityFilter(mConfig.velocityEma(), mConfig.maxVelPxPerSec(),
                mConfig.minVelPxPerSec());
        mTracker.setSizeFilter(mConfig.sizeEma());
        mTracker.setHeadAnchorBias(mConfig.headAnchorBias());
        List<TargetTracker.Candidate> candidates =
                mTracker.update(detections, frameW, frameH, tsNanos, mConfig.classes());

        if (!mAiming) {
            publishOverlay(null, 0f, 0f);
            return;
        }
        AimRect rect = mConfig.rect();
        TargetTracker.Candidate target = pick(candidates, rect, frameW, frameH);
        final boolean sentLastFrame = mPrevShotSent;
        mPrevShotSent = false;
        if (target == null) {
            mStickMiss++;
            if (mStickMiss >= 3) {
                mStickId = -1;
            }
            resetSwitchStreak();
            mLastErrorPx = 0f;
            mTargetText = "";
            long nowMs = android.os.SystemClock.elapsedRealtime();
            if (nowMs - mLastNoTargetLogMs > 1000L) {
                mLastNoTargetLogMs = nowMs;
                final int count = candidates.size();
                mPort.logNote("瞄准中 · 框内无目标（候选 " + count + "）");
            }
            stopTrajectory();
            publishOverlay(null, 0f, 0f);
            publish();
            return;
        }

        float anchorX = rect.anchorX(frameW);
        float anchorY = rect.anchorY(frameH);
        if (mHasPrevTarget) {
            float delta = (float) Math.hypot(target.x - mPrevTargetX, target.y - mPrevTargetY);
            if (target.id == mPrevTrackId && target.speedPx() < 40f) {
                // 同一个慢速目标：这就是检测噪声
                mJitterEma = mJitterEma < 0f ? delta : mJitterEma * 0.9f + delta * 0.1f;
                mJitterWin[mJitterHead] = delta;
                mJitterHead = (mJitterHead + 1) % NOISE_WIN;
                mJitterN = Math.min(NOISE_WIN, mJitterN + 1);
            } else if (target.id != mPrevTrackId) {
                // 换了目标/跳变：记录跳变幅度，用来定"一发最多能走多远"
                mJumpWin[mJumpHead] = delta;
                mJumpHead = (mJumpHead + 1) % NOISE_WIN;
                mJumpN = Math.min(NOISE_WIN, mJumpN + 1);
            }
            mLastSampleMs = System.currentTimeMillis();
        }
        mPrevTargetX = target.x;
        mPrevTargetY = target.y;
        mHasPrevTarget = true;
        float dxPx = target.x + mConfig.aimOffsetX() - anchorX;
        float dyPx = target.y + mConfig.aimOffsetY() - anchorY;
        float predictedX = target.x;
        float predictedY = target.y;

        boolean ff = mConfig.feedForward()
                && target.frames >= mConfig.minTrackFrames()
                && target.speedPx() >= mConfig.minVelPxPerSec();
        if (ff) {
            float leadS = mConfig.leadMs() / 1000f;
            dxPx += target.vx * leadS;
            dyPx += target.vy * leadS;
            predictedX = target.x + target.vx * leadS;
            predictedY = target.y + target.vy * leadS;
        }

        float error = (float) Math.hypot(dxPx, dyPx);
        mLastErrorPx = error;
        mLastVelocityPx = target.speedPx();
        mTargetText = String.format(Locale.US, "%s %.2f · %.0f px/s · h%.2f b%.2f%s",
                target.label, target.score, target.speedPx(), target.headSize, target.bodySize,
                ff ? " · ff" : "");

        if (target.frames < mConfig.stableFrames()) {
            publishOverlay(target, predictedX, predictedY);
            publish();
            return; // not stable yet: look, do not move
        }
        // 自学习：样本不足 20 或 3 s 没有新样本 → 自动回落到手填值
        boolean fresh = System.currentTimeMillis() - mLastSampleMs < 3000L;
        float jitterP90 = (mConfig.autoDeadzone() && fresh)
                ? AimMath.percentile(mJitterWin, mJitterN, 0.9f) : Float.NaN;
        float jumpP90 = (mConfig.autoMaxStep() && fresh && mJumpN >= 5)
                ? AimMath.percentile(mJumpWin, mJumpN, 0.9f) : Float.NaN;
        float deadzone = mConfig.effectiveDeadzonePx(jitterP90);
        mAutoDeadzonePx = deadzone;
        if (error < deadzone) {
            // Inside the dead zone: stop what is in flight, then stay quiet. The firmware would
            // answer dead_min anyway, but not sending keeps the wire and the engine idle.
            stopTrajectory();
            publishOverlay(target, predictedX, predictedY);
            publish();
            return;
        }

        float countsPerPx = 1f / Math.max(0.05f, mConfig.pxPerCount());

        // ---- A：自校准增益 -------------------------------------------------
        // 上一帧发过一枪、还是同一个目标：用这一帧的残差算出"实际走了多少"。
        // 完全按预期走完 effGain 时，残差轴向投影 ratio = 1 - effGain；
        // 冲过头（残差翻向）ratio < 0 → gReal > 1 → 下一枪收着点。
        float effGain = mConfig.gain();
        if (sentLastFrame && target.id == mPrevTrackId && mPrevErrorPx > mConfig.deadzonePx() * 2f) {
            // A：用上一枪的实际响应校准增益（game 灵敏度/倍镜都能自适应）
            float response = AimMath.measureResponse(dxPx, dyPx, mPrevDxPx, mPrevDyPx,
                    mPrevShotFraction);
            float want = AimMath.gainForResponse(response);
            if (!Float.isNaN(response) && !Float.isNaN(want)) {
                mLastGReal = AimMath.smooth(mLastGReal, response, 0.3f);
                mGainAdapt = AimMath.smooth(mGainAdapt, want, 0.3f);
            }
            if (mConfig.autoGain() && mGainAdapt > 0f) {
                effGain = Math.min(effGain, mGainAdapt);
            }
        }
        mPrevShotFraction = effGain;

        // ---- C：单发相对限幅（不超过残差的 80%）----------------------------
        int dx = AimMath.limitToError(Math.round(dxPx * countsPerPx * effGain),
                error, countsPerPx);
        int dy = AimMath.limitToError(Math.round(dyPx * countsPerPx * effGain),
                error, countsPerPx);
        int maxCounts = mConfig.effectiveMaxStepCounts(
                target.boxH * frameH, jumpP90);
        mAutoMaxCounts = maxCounts;
        dx = Math.max(-maxCounts, Math.min(maxCounts, dx));
        dy = Math.max(-maxCounts, Math.min(maxCounts, dy));

        // 记录本帧残差，供下一帧估计真实增益
        mPrevDxPx = dxPx;
        mPrevDyPx = dyPx;
        mPrevErrorPx = error;
        mPrevTrackId = target.id;

        int flags = 0;
        if (mConfig.sessionClamp()) {
            flags |= ControlPort.AIM_FLAG_SESSION_CLAMP;
        }
        if (mConfig.turbo()) {
            flags |= ControlPort.AIM_FLAG_TURBO;
        }
        int deadMin = Math.max(1, Math.round(deadzone * countsPerPx));
        mPort.aim(dx, dy, mConfig.maxMs(), flags, deadMin);
        mTrajectoryActive = true;
        mSentSinceState++;
        mPrevShotSent = true;
        long nowMs = android.os.SystemClock.elapsedRealtime();
        if (nowMs - mLastAimLogMs > 250L) {
            mLastAimLogMs = nowMs;
            String extra = "";
            if (sentLastFrame && mPrevDxPx != 0f
                    && Math.signum(dxPx) != Math.signum(mPrevDxPx)) {
                extra = String.format(Locale.US, " · 过冲（残差翻向，增益→%.2f）", effGain);
            }
            mPort.logNote(String.format(Locale.US, "→ AIM %d,%d counts · 残差 %.0f px · %s%s",
                    dx, dy, error, mTargetText, extra));
        }
        // 学到的增益落盘（每 2 s 且变化 > 2% 才写一次），重启后不用重新学
        if (mConfig.autoGain() && mGainAdapt > 0f && nowMs - mLastGainSaveMs > 2000L) {
            float stored = mConfig.gainAdapt(mConfig.adsBucket());
            if (stored < 0f || Math.abs(stored - mGainAdapt) > 0.02f) {
                mLastGainSaveMs = nowMs;
                mConfig.gainAdapt(mConfig.adsBucket(), mGainAdapt);
                mConfig.persist();
            }
        }
        publishOverlay(target, predictedX, predictedY);
        publish();
    }

    /**
     * Nearest live target to the crosshair, inside the aim rectangle, head shots preferred.
     *
     * <p>第二判据可配置：默认按 {@code sizeProxy}（等效体高，越大越近）取"最近的敌人"，
     * 尺寸并列才退回屏幕最下面；关掉 {@code pickSizeFirst} 则回到旧的「y 最大」。
     */
    private TargetTracker.Candidate pick(List<TargetTracker.Candidate> candidates, AimRect rect,
                                         int frameW, int frameH) {
        float anchorX = rect.anchorX(frameW);
        float anchorY = rect.anchorY(frameH);
        TargetTracker.Candidate stick = null;
        // 只考虑落在瞄准框内的候选
        java.util.List<TargetTracker.Candidate> inside = new java.util.ArrayList<>(candidates.size());
        for (TargetTracker.Candidate candidate : candidates) {
            if (rect.contains(candidate.x / frameW, candidate.y / frameH)) {
                inside.add(candidate);
                if (candidate.id == mStickId) {
                    stick = candidate;
                }
            }
        }
        // 规则（schema 10）：横向可达范围内（±sizeReach·画面宽）按 头框最大（最近）→ 身体框最大
        // → 最正（横向偏离最小）→ 最下面 排序；范围内没有 head 再退回最近。
        // reachPx 传 0 时 AimPick 退回旧的"居中容差当资格线"，即完全旧行为。
        float[] xs = new float[inside.size()];
        float[] ys = new float[inside.size()];
        float[] headSizes = mConfig.pickSizeFirst() ? new float[inside.size()] : null;
        float[] bodySizes = mConfig.pickSizeFirst() ? new float[inside.size()] : null;
        boolean[] heads = new boolean[inside.size()];
        for (int i = 0; i < inside.size(); i++) {
            xs[i] = inside.get(i).x;
            ys[i] = inside.get(i).y;
            if (headSizes != null) {
                headSizes[i] = inside.get(i).headSize;
                bodySizes[i] = inside.get(i).bodySize;
            }
            heads[i] = inside.get(i).headShot;
        }
        float tolerancePx = mConfig.preferCenteredHead()
                ? mConfig.centerTolerance() * frameW : 0f;
        float reachPx = mConfig.pickSizeFirst() ? mConfig.sizeReach() * frameW : 0f;
        int index = AimPick.pick(xs, ys, headSizes, bodySizes, heads, anchorX, anchorY,
                tolerancePx, reachPx, 12f);
        TargetTracker.Candidate best = index >= 0 ? inside.get(index) : null;
        // B：粘滞。已锁定的目标只要还在框内就继续用，避免两个敌人靠近时来回换人造成方向突变。
        // 2026-11-11 治「两个近敌抢鼠标」三件套（尺寸 EMA 在 TargetTracker 里做）：
        //   ① 抢锁门槛 = 相对（sizeGate，默认 1.12）+ 绝对（sizeDelta，默认 1% 框高）双条件；
        //   ② 换人确认：连续 switchFrames 帧（默认 3）都判"该换"才真换，单帧抖动不再生效；
        //   ③ 观察期继续锁旧目标，并计入"粘住"。
        if (mConfig.stickTarget() && stick != null) {
            float stickDistance = (float) Math.hypot(stick.x - anchorX, stick.y - anchorY);
            boolean inReach = stickDistance < rect.w * frameW * 1.5f;
            if (inReach) {
                boolean same = best != null && best.id == mStickId;
                if (best == null || same) {
                    mStickMiss = 0;
                    mStickHits++;
                    resetSwitchStreak();
                    return stick;
                }
                if (mConfig.pickSizeFirst()) {
                    boolean betterEnough = AimPick.shouldTakeOver(best.headSize, stick.headSize,
                            mConfig.sizeGate(), mConfig.sizeDelta());
                    if (!betterEnough) {
                        mStickMiss = 0;
                        mStickHits++;
                        resetSwitchStreak();
                        return stick;
                    }
                    if (best.id == mPendingStickId) {
                        mSwitchStreak++;
                    } else {
                        mPendingStickId = best.id;
                        mSwitchStreak = 1;
                    }
                    if (mSwitchStreak < mConfig.switchFrames()) {
                        mStickHits++; // 观察期：仍然锁旧目标
                        return stick;
                    }
                }
                resetSwitchStreak();
            }
        }
        if (best != null) {
            if (mStickId >= 0 && best.id != mStickId) {
                mStickSwitches++;
            }
            mStickId = best.id;
            mStickMiss = 0;
            resetSwitchStreak();
        }
        return best;
    }

    /** 换人观察期清零：目标丢了、判定不再"该换"、或已经换完，都要重置连续帧。 */
    private void resetSwitchStreak() {
        mPendingStickId = -1;
        mSwitchStreak = 0;
    }

    private void publishOverlay(TargetTracker.Candidate target, float predX, float predY) {
        OverlaySink sink = mOverlaySink;
        if (sink == null) {
            return;
        }
        if (target == null) {
            sink.onAimOverlay(mAiming, 0f, 0f, 0f, 0f, 0f, 0f);
            return;
        }
        sink.onAimOverlay(mAiming,
                target.boxCx - target.boxW / 2f, target.boxCy - target.boxH / 2f,
                target.boxCx + target.boxW / 2f, target.boxCy + target.boxH / 2f,
                predX, predY);
    }

    /** AIM has no "cancel" of its own: stopping still goes through 0x37, once per trajectory. */
    private void stopTrajectory() {
        if (!mTrajectoryActive) {
            return; // nothing in flight: sending 0x37 every frame would just flood the port
        }
        mTrajectoryActive = false;
        if (mConfig.releaseStop()) {
            mPort.sumvStop();
        }
    }

    private void setAiming(boolean aiming) {
        if (mAiming == aiming) {
            return;
        }
        mAiming = aiming;
        mGainAdapt = mConfig.gainAdapt(mConfig.adsBucket());
        if (aiming) {
            mTriggers++;
            mTracker.reset();
            mPrevShotSent = false;
            mStickId = -1;
            mStickMiss = 0;
            resetSwitchStreak();
            // 还没学到样本时先显示手填值，别在界面上露 0
            mAutoDeadzonePx = mConfig.effectiveDeadzonePx(Float.NaN);
            mAutoMaxCounts = mConfig.effectiveMaxStepCounts(Float.NaN, Float.NaN);
            mNote = "瞄准中：按住期间真实鼠标位移被盒子丢弃";
        } else {
            mTrajectoryActive = true; // force the stop through even if we think nothing runs
            stopTrajectory();
            // 0x40 AIM_RESET：每轮结束清一次盒子侧累计量，
            // 否则 rounds/aborted 会一路涨到 u16 饱和、上次结果永远粘在界面上。
            if (mPort.isOpen()) {
                mPort.aimReset();
            }
            mNote = "已松手，轨迹立即停止";
        }
        publish();
        Log.i(TAG, "aiming=" + aiming);
    }

    private void publish() {
        StatsListener listener = mUiListener;
        if (listener == null) {
            return;
        }
        Stats snapshot = stats();
        mMain.post(() -> listener.onAimStats(snapshot));
    }

    public void close() {
        setAiming(false);
        mHotkey.close();
        mMain.removeCallbacks(mStatePoll);
        mPort.setAimStateListener(null);
        mTracker.reset();
    }

    public void resetStats() {
        mTriggers = 0;
        mLastErrorPx = 0f;
        publish();
    }
}
