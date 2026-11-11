package com.magicbullet.capture.core;

import android.content.Context;
import android.content.SharedPreferences;

import java.util.LinkedHashSet;
import java.util.Set;

/**
 * Aiming parameters, persisted in SharedPreferences.
 *
 * <p>Deliberately separate from {@link YoloConfig}: the detector's thresholds answer "what is in
 * the frame", these answer "what to do about it". They share one process-wide instance for the
 * same reason YoloConfig does - the aim tab edits the very object the preview reads every frame.
 */
public final class AimConfig {

    public interface Listener {
        void onAimConfigChanged(AimConfig config);
    }

    private static final String P = "aim_config";

    /** counts/s for the keys page's manual flick; aiming itself uses {@link #maxMs()}. */
    public static final int DEFAULT_SPEED = 1200;
    /** Per-shot time budget for {@code 0x3C AIM} (ms). 10 ms keeps a 60 fps loop lag-free. */
    public static final int DEFAULT_MAX_MS = 10;
    /** Ceiling on one correction, so a false positive cannot fling the pointer. */
    public static final int DEFAULT_MAX_STEP_COUNTS = 200;
    /** Firmware mode bits are irrelevant for AIM; kept for the keys page only. */
    public static final int DEFAULT_MODE = 0x00;
    /** Default hotkey: the right mouse button, consumed while armed (toggle style). */
    public static final int DEFAULT_HOTKEY_MASK = 0x02;
    public static final int MASK_LEFT = 0x01;
    public static final int MASK_RIGHT = 0x02;
    public static final int MASK_MIDDLE = 0x04;
    /** Mask bits offered by the box: 8 = side 4 (rear), 16 = side 5 (front). */
    public static final int MASK_SIDE_REAR = 0x08;
    public static final int MASK_SIDE_FRONT = 0x10;
    /** Measured 2026-11-11: constant 1.25 px/count (1.0 logical × 125%, no acceleration). */
    public static final float DEFAULT_PX_PER_COUNT = 1.25f;
    /** The AIM shot is ~10 ms, so the pipeline lag is much shorter than with SUMV ramps. */
    public static final int DEFAULT_LEAD_MS = 30;

    private final SharedPreferences mPrefs;
    private final Set<Listener> mListeners = new LinkedHashSet<>();
    private final android.os.Handler mMain =
            new android.os.Handler(android.os.Looper.getMainLooper());
    private static AimConfig sInstance;

    private int mSpeed = DEFAULT_SPEED;
    private int mMode = DEFAULT_MODE;
    private int mMaxMs = DEFAULT_MAX_MS;
    private int mMaxStepCounts = DEFAULT_MAX_STEP_COUNTS;
    private boolean mSessionClamp = true;
    private boolean mTurbo;
    /** 自校准增益学习值；< 0 = 还没学过。腰射/开镜各一桶。 */
    private float mGainAdaptHip = -1f;
    private float mGainAdaptAds = -1f;
    private float mAimOffsetX;
    private float mAimOffsetY;
    private AimRect mRect = AimRect.DEFAULT;
    private int mHotkeyMask = DEFAULT_HOTKEY_MASK;
    private boolean mHoldMode;
    /** false = the hotkey still reaches the PC (pass-through); true = the box swallows it. */
    private boolean mHotkeyConsume;
    private String mLabels = "head,body";
    private float mDeadzonePx = 4f;
    private float mGain = 0.6f;
    private int mMaxStepMs = 120;
    private int mStableFrames = 3;
    /** 自校准增益：用闭环响应在线估计真实 px/count，抵消游戏灵敏度/倍镜差异。 */
    private boolean mAutoGain = true;
    /** 当前学习桶：false=腰射，true=开镜（灵敏度不同，增益也不同）。 */
    private boolean mAdsBucket;
    /** 自适应死区：按目标框抖动放大死区，抑制静止目标上的来回微抖。 */
    /** 瞄点在头部框内的纵向位置：1.0 = 下沿（下巴）。 */
    private float mHeadAnchorBias = 1.0f;
    /** 多目标时"居中优先"：横向偏差在 tolerance 内，取最下面（最近）的那个。 */
    private boolean mPreferCenteredHead = true;
    /** 居中容差（相对画面宽度的比例，0.01 = ±1%）。 */
    private float mCenterTolerance = 0.01f;
    private boolean mAutoDeadzone = true;
    /** 单帧上限也自学习：按目标框高度与跳变噪声估计。 */
    private boolean mAutoMaxStep = true;
    /** 目标粘滞：锁定后不因为"另一个更近"而换人。 */
    private boolean mStickTarget = true;
    /** 选人第二判据：true = 框更大（更近）优先，false = 屏幕最下面（y 最大）优先。 */
    private boolean mPickSizeFirst = true;
    /** 换人门槛：新目标的 headSize 必须是当前目标的 sizeGate 倍才允许抢锁（1.12 = 大 12%）。 */
    private float mSizeGate = 1.12f;
    /** 抢锁的绝对差门槛：headSize 差值至少这么多（归一化框高，0.01 ≈ 11 px @1080p）。 */
    private float mSizeDelta = 0.01f;
    /** 换人确认帧数：连续这么多帧都判"该换"才真换，压掉单帧抖动引起的来回抢。 */
    private int mSwitchFrames = 3;
    /** 框尺寸 EMA 平滑系数（1.0 = 不平滑，0.3 = 默认）。 */
    private float mSizeEma = 0.30f;
    /**
     * 选敌横向可达范围（相对画面宽度的比例，0.15 = ±15%）：范围内的候选才参与"框大优先"竞争。
     * 0 = 退回旧的"居中容差当资格线"行为。
     */
    private float mSizeReach = 0.15f;
    private boolean mFeedForward = true;
    private int mLeadMs = DEFAULT_LEAD_MS;
    private float mVelocityEma = 0.5f;
    private int mMaxVelPxPerSec = 1200;
    private int mMinVelPxPerSec = 30;
    private int mMinTrackFrames = 3;
    private float mPxPerCount = DEFAULT_PX_PER_COUNT;
    private boolean mShowPredicted = true;
    private boolean mReleaseStop = true;
    private boolean mVolumeKeyEnabled = true;

    private AimConfig(SharedPreferences prefs) {
        mPrefs = prefs;
        load();
    }

    public static synchronized AimConfig load(Context context) {
        if (sInstance == null) {
            sInstance = new AimConfig(context.getApplicationContext()
                    .getSharedPreferences(P, Context.MODE_PRIVATE));
        }
        return sInstance;
    }

    private void load() {
        mSpeed = mPrefs.getInt("speed", DEFAULT_SPEED);
        mMode = mPrefs.getInt("mode", DEFAULT_MODE);
        mMaxMs = mPrefs.getInt("max_ms", DEFAULT_MAX_MS);
        mMaxStepCounts = mPrefs.getInt("max_step_counts", DEFAULT_MAX_STEP_COUNTS);
        mSessionClamp = mPrefs.getBoolean("session_clamp", false);
        mTurbo = mPrefs.getBoolean("turbo", false);
        mGainAdaptHip = mPrefs.getFloat("gain_adapt_hip", -1f);
        mGainAdaptAds = mPrefs.getFloat("gain_adapt_ads", -1f);
        mAimOffsetX = mPrefs.getFloat("aim_offset_x", 0f);
        mAimOffsetY = mPrefs.getFloat("aim_offset_y", 0f);
        mRect = new AimRect(mPrefs.getFloat("rect_x", AimRect.DEFAULT.x),
                mPrefs.getFloat("rect_y", AimRect.DEFAULT.y),
                mPrefs.getFloat("rect_w", AimRect.DEFAULT.w),
                mPrefs.getFloat("rect_h", AimRect.DEFAULT.h));
        mHotkeyMask = mPrefs.getInt("hotkey", DEFAULT_HOTKEY_MASK);
        mHoldMode = mPrefs.getBoolean("hold", false);
        mHotkeyConsume = mPrefs.getBoolean("hotkey_consume", false);
        mLabels = mPrefs.getString("labels", "head,body");
        mDeadzonePx = mPrefs.getFloat("deadzone", 4f);
        mGain = mPrefs.getFloat("gain", 0.6f);
        mMaxStepMs = mPrefs.getInt("max_step_ms", 120);
        mStableFrames = mPrefs.getInt("stable_frames", 3);
        mAutoGain = mPrefs.getBoolean("auto_gain", true);
        mAdsBucket = mPrefs.getBoolean("ads_bucket", false);
        mHeadAnchorBias = mPrefs.getFloat("head_anchor_bias", 1.0f);
        mPreferCenteredHead = mPrefs.getBoolean("prefer_centered_head", true);
        mCenterTolerance = mPrefs.getFloat("center_tolerance", 0.01f);
        mAutoDeadzone = mPrefs.getBoolean("auto_deadzone", true);
        mAutoMaxStep = mPrefs.getBoolean("auto_maxstep", true);
        mStickTarget = mPrefs.getBoolean("stick_target", true);
        mPickSizeFirst = mPrefs.getBoolean("pick_size_first", true);
        mSizeGate = mPrefs.getFloat("size_gate", 1.12f);
        mSizeDelta = mPrefs.getFloat("size_delta", 0.01f);
        mSwitchFrames = mPrefs.getInt("switch_frames", 3);
        mSizeEma = mPrefs.getFloat("size_ema", 0.30f);
        mSizeReach = mPrefs.getFloat("size_reach", 0.15f);
        mFeedForward = mPrefs.getBoolean("ff", true);
        mLeadMs = mPrefs.getInt("lead_ms", 60);
        mVelocityEma = mPrefs.getFloat("vel_ema", 0.5f);
        mMaxVelPxPerSec = mPrefs.getInt("vel_max", 1200);
        mMinVelPxPerSec = mPrefs.getInt("vel_min", 30);
        mMinTrackFrames = mPrefs.getInt("track_min", 3);
        mPxPerCount = mPrefs.getFloat("px_per_count", DEFAULT_PX_PER_COUNT);
        mShowPredicted = mPrefs.getBoolean("show_pred", true);
        mReleaseStop = mPrefs.getBoolean("release_stop", true);
        mVolumeKeyEnabled = mPrefs.getBoolean("volume_key", true);
        migrateToAim();
    }

    /**
     * 2026-11-11 firmware overhaul: px/count became 1.25 (constant), aiming moved from
     * {@code 0x36 SUMV} to {@code 0x3C AIM} (time budget instead of speed), and the old mode bits
     * lost their meaning. Old profiles carry 0.585 px/count, a counts/s speed and 0x0C mode, all of
     * which would now misbehave, so they are translated once.
     */
    private void migrateToAim() {
        int schema = mPrefs.getInt("aim_schema", 1);
        boolean touched = false;
        if (schema < 2) {
            if (Math.abs(mPxPerCount - 0.585f) < 0.02f) {
                mPxPerCount = DEFAULT_PX_PER_COUNT;
                touched = true;
            }
            if (mPrefs.getInt("max_step_counts", 0) == 0) {
                // 120 ms × old speed → counts, then clamp: 120 × 6054 / 1000 ≈ 727 → 400
                int counts = Math.round(mMaxStepMs * Math.max(1, mSpeed) / 1000f);
                mMaxStepCounts = Math.max(50, Math.min(DEFAULT_MAX_STEP_COUNTS, counts));
                touched = true;
            }
            if (!mPrefs.contains("max_ms")) {
                // Keep the previous "how fast it felt": the old shot covered ~60 counts at speed.
                mMaxMs = Math.max(4, Math.min(40, Math.round(60000f / Math.max(500, mSpeed))));
                touched = true;
            }
            if (mLeadMs == 60) {
                mLeadMs = DEFAULT_LEAD_MS;
                touched = true;
            }
            mMode = 0x00; // AIM has no mode bits; the keys page selects its own
            touched = true;
        }
        if (schema < 3) {
            // 2026-11-11 二次调整：热键改成右键、按下切换；会话钳位默认关（否则打一会儿就
            // 累计超过 4000 counts，之后每一发都回"超限"）。
            mHotkeyMask = DEFAULT_HOTKEY_MASK;
            mHoldMode = false;
            mSessionClamp = false;
            touched = true;
        }
        if (schema < 7) {
            // 2026-11-11 瞄头改版：瞄点落到下巴（bias 1.0）、居中优先、容差 ±3%
            // （±3% 已被 schema 8 收紧到 ±1%，这里保留历史值以便逐步升级）
            mHeadAnchorBias = 1.0f;
            mPreferCenteredHead = true;
            mCenterTolerance = 0.03f;
            touched = true;
        }
        if (schema < 8) {
            // 2026-11-11 收紧居中容差：±3% → ±1% 画面宽。
            // 1080p 下判定窗口 57.6 px → 19.2 px，"居中"基本只认正压在准心上的头，
            // 多目标时更依赖"最近"回退，不再把偏一点的头抢到中心来。
            mCenterTolerance = 0.01f;
            touched = true;
        }
        if (schema < 9) {
            // 2026-11-11 选近优先：多目标改用"等效体高最大（最近）"，屏幕 y 降为并列判据；
            // 换人需新目标大 8% 才抢锁，避免两个尺寸接近的敌人每帧翻转。
            mPickSizeFirst = true;
            mSizeGate = 1.08f;
            touched = true;
        }
        if (schema < 10) {
            // 2026-11-11 框大优先翻正：横向偏离从"资格线"降为"可达范围"（±15% 画面宽），
            // 范围内按头框 → 身体框 → 最正 → 最下面排序，近处大框不再因为偏一点被丢掉。
            mSizeReach = 0.15f;
            touched = true;
        }
        if (schema < 11) {
            // 2026-11-11 治「两个近敌抢鼠标」：框尺寸 EMA 平滑 + 抢锁加绝对差 + 换人确认帧，
            // 门槛从 8% 放宽到 12%（平滑之后仍要略放宽，避免真近的那个抢不过来）。
            mSizeGate = 1.12f;
            mSizeDelta = 0.01f;
            mSwitchFrames = 3;
            mSizeEma = 0.30f;
            touched = true;
        }
        if (schema < 6) {
            // 2026-11-11 自学习默认开：死区与单帧上限都交给闭环估计
            mAutoDeadzone = true;
            mAutoMaxStep = true;
            touched = true;
        }
        if (schema < 5) {
            // 2026-11-11 过冲整改：双帧稳定改三帧，单发上限 400→200 counts
            if (mStableFrames < 3) {
                mStableFrames = 3;
            }
            if (mMaxStepCounts > 200) {
                mMaxStepCounts = 200;
            }
            touched = true;
        }
        if (schema < 4 && mMaxMs <= 4) {
            // The budget slider's floor is 4 ms; a value sitting exactly there means an
            // accidental press of 应用 with the slider at the minimum - restore the default.
            mMaxMs = DEFAULT_MAX_MS;
            touched = true;
        }
        if (touched) {
            persist();
        }
        if (schema < 11) {
            mPrefs.edit().putInt("aim_schema", 11).apply();
        }
    }

    public void persist() {
        mPrefs.edit()
                .putInt("speed", mSpeed)
                .putInt("mode", mMode)
                .putInt("max_ms", mMaxMs)
                .putInt("max_step_counts", mMaxStepCounts)
                .putBoolean("session_clamp", mSessionClamp)
                .putBoolean("turbo", mTurbo)
                .putFloat("gain_adapt_hip", mGainAdaptHip)
                .putFloat("gain_adapt_ads", mGainAdaptAds)
                .putFloat("aim_offset_x", mAimOffsetX)
                .putFloat("aim_offset_y", mAimOffsetY)
                .putFloat("rect_x", mRect.x)
                .putFloat("rect_y", mRect.y)
                .putFloat("rect_w", mRect.w)
                .putFloat("rect_h", mRect.h)
                .putInt("hotkey", mHotkeyMask)
                .putBoolean("hold", mHoldMode)
                .putBoolean("hotkey_consume", mHotkeyConsume)
                .putString("labels", mLabels)
                .putFloat("deadzone", mDeadzonePx)
                .putFloat("gain", mGain)
                .putInt("max_step_ms", mMaxStepMs)
                .putInt("stable_frames", mStableFrames)
                .putBoolean("auto_gain", mAutoGain)
                .putBoolean("ads_bucket", mAdsBucket)
                .putFloat("head_anchor_bias", mHeadAnchorBias)
                .putBoolean("prefer_centered_head", mPreferCenteredHead)
                .putFloat("center_tolerance", mCenterTolerance)
                .putBoolean("auto_deadzone", mAutoDeadzone)
                .putBoolean("auto_maxstep", mAutoMaxStep)
                .putBoolean("stick_target", mStickTarget)
                .putBoolean("pick_size_first", mPickSizeFirst)
                .putFloat("size_gate", mSizeGate)
                .putFloat("size_delta", mSizeDelta)
                .putInt("switch_frames", mSwitchFrames)
                .putFloat("size_ema", mSizeEma)
                .putFloat("size_reach", mSizeReach)
                .putBoolean("ff", mFeedForward)
                .putInt("lead_ms", mLeadMs)
                .putFloat("vel_ema", mVelocityEma)
                .putInt("vel_max", mMaxVelPxPerSec)
                .putInt("vel_min", mMinVelPxPerSec)
                .putInt("track_min", mMinTrackFrames)
                .putFloat("px_per_count", mPxPerCount)
                .putBoolean("show_pred", mShowPredicted)
                .putBoolean("release_stop", mReleaseStop)
                .putBoolean("volume_key", mVolumeKeyEnabled)
                .apply();
    }

    /** Persists and tells the controller: this is what "应用" does. */
    public void save() {
        persist();
        // Callbacks may come from the serial reader thread (hotkey learn, AIM_STATE); every
        // listener here touches views, so the notification is hopped onto the main thread.
        mMain.post(() -> {
            for (Listener listener : mListeners) {
                listener.onAimConfigChanged(this);
            }
        });
    }

    public void addListener(Listener listener) {
        mListeners.add(listener);
    }

    public void removeListener(Listener listener) {
        mListeners.remove(listener);
    }

    // ------------------------------------------------------------------ accessors

    public int speed() {
        return mSpeed;
    }

    public void speed(int speed) {
        mSpeed = Math.max(50, Math.min(8000, speed));
    }

    public int mode() {
        return mMode;
    }

    public void mode(int mode) {
        mMode = mode & 0xFF;
    }

    /** Per-shot time budget for {@code 0x3C AIM}, in ms. */
    public int maxMs() {
        return mMaxMs;
    }

    public void maxMs(int ms) {
        mMaxMs = Math.max(4, Math.min(40, ms));
    }

    /** Largest correction per frame, in counts (guards against a bogus detection). */
    public int maxStepCounts() {
        return mMaxStepCounts;
    }

    public void maxStepCounts(int counts) {
        mMaxStepCounts = Math.max(20, Math.min(2000, counts));
    }

    /** AIM flag bit0: refuse when the session accumulates more than 4000 counts. */
    public boolean sessionClamp() {
        return mSessionClamp;
    }

    public void sessionClamp(boolean on) {
        mSessionClamp = on;
    }

    /** AIM flag bit1: as fast as physically possible. */
    public boolean turbo() {
        return mTurbo;
    }

    public void turbo(boolean on) {
        mTurbo = on;
    }

    /** Aim-point nudge in pixels, added after head/body selection. */
    /** Learning value of the self-calibrating gain for hip-fire / ADS. */
    public float gainAdapt(boolean ads) {
        return ads ? mGainAdaptAds : mGainAdaptHip;
    }

    /** Stores a learned gain; values < 0 clear the bucket. */
    public void gainAdapt(boolean ads, float value) {
        float clamped = value > 0f ? Math.max(0.15f, Math.min(1f, value)) : -1f;
        if (ads) {
            mGainAdaptAds = clamped;
        } else {
            mGainAdaptHip = clamped;
        }
    }

    public boolean adsBucket() {
        return mAdsBucket;
    }

    public void adsBucket(boolean ads) {
        mAdsBucket = ads;
    }

    /** 0 = 头顶, 0.5 = 中心, 1 = 下沿（下巴）。 */
    public float headAnchorBias() {
        return mHeadAnchorBias;
    }

    public void headAnchorBias(float bias) {
        mHeadAnchorBias = Math.max(0f, Math.min(1f, bias));
    }

    public boolean preferCenteredHead() {
        return mPreferCenteredHead;
    }

    public void preferCenteredHead(boolean on) {
        mPreferCenteredHead = on;
    }

    public float centerTolerance() {
        return mCenterTolerance;
    }

    public void centerTolerance(float ratio) {
        mCenterTolerance = Math.max(0.005f, Math.min(0.25f, ratio));
    }

    public boolean autoDeadzone() {
        return mAutoDeadzone;
    }

    public void autoDeadzone(boolean on) {
        mAutoDeadzone = on;
    }

    /** Dead zone actually used: the configured floor, or 1.2× the measured jitter when enabled. */
    public boolean autoMaxStep() {
        return mAutoMaxStep;
    }

    public void autoMaxStep(boolean on) {
        mAutoMaxStep = on;
    }

    /** 死区实际取值：自学习 P90 与手填值取大（自学习关闭时就是手填值）。 */
    public float effectiveDeadzonePx(float jitterP90Px) {
        if (!mAutoDeadzone) {
            return mDeadzonePx;
        }
        return AimMath.autoDeadzonePx(jitterP90Px, mDeadzonePx);
    }

    /** 单帧上限实际取值：自学习关闭时就是手填值。 */
    public int effectiveMaxStepCounts(float boxHeightPx, float jumpP90Px) {
        if (!mAutoMaxStep) {
            return mMaxStepCounts;
        }
        return AimMath.autoMaxCounts(boxHeightPx, jumpP90Px, mMaxStepCounts, mPxPerCount);
    }

    public float aimOffsetX() {
        return mAimOffsetX;
    }

    public void aimOffsetX(float px) {
        mAimOffsetX = Math.max(-200f, Math.min(200f, px));
    }

    public float aimOffsetY() {
        return mAimOffsetY;
    }

    public void aimOffsetY(float px) {
        mAimOffsetY = Math.max(-200f, Math.min(200f, px));
    }

    public AimRect rect() {
        return mRect;
    }

    public void rect(AimRect rect) {
        mRect = rect == null ? AimRect.DEFAULT : rect;
    }

    public int hotkeyMask() {
        return mHotkeyMask;
    }

    public void hotkeyMask(int mask) {
        mHotkeyMask = mask & 0x1F;
    }

    public boolean holdMode() {
        return mHoldMode;
    }

    public void holdMode(boolean hold) {
        mHoldMode = hold;
    }

    /** True = the box eats the hotkey (PC never sees it); false = pass-through (default). */
    public boolean hotkeyConsume() {
        return mHotkeyConsume;
    }

    public void hotkeyConsume(boolean consume) {
        mHotkeyConsume = consume;
    }

    public Set<String> classes() {
        Set<String> out = new LinkedHashSet<>();
        for (String part : mLabels.split("[,\\n]")) {
            String s = part.trim();
            if (!s.isEmpty()) {
                out.add(s.toLowerCase(java.util.Locale.US));
            }
        }
        return out;
    }

    public String labels() {
        return mLabels;
    }

    public void labels(String labels) {
        mLabels = labels == null ? "" : labels;
    }

    public float deadzonePx() {
        return mDeadzonePx;
    }

    public void deadzonePx(float px) {
        mDeadzonePx = Math.max(0f, Math.min(40f, px));
    }

    public float gain() {
        return mGain;
    }

    public void gain(float gain) {
        mGain = Math.max(0.2f, Math.min(1f, gain));
    }

    public int maxStepMs() {
        return mMaxStepMs;
    }

    public void maxStepMs(int ms) {
        mMaxStepMs = Math.max(40, Math.min(500, ms));
    }

    public int stableFrames() {
        return mStableFrames;
    }

    public void stableFrames(int frames) {
        mStableFrames = Math.max(1, Math.min(5, frames));
    }

    public boolean autoGain() {
        return mAutoGain;
    }

    public void autoGain(boolean on) {
        mAutoGain = on;
    }

    public boolean stickTarget() {
        return mStickTarget;
    }

    public void stickTarget(boolean on) {
        mStickTarget = on;
    }

    /** 选人第二判据：true = 框更大（更近）优先，false = 屏幕最下面优先。 */
    public boolean pickSizeFirst() {
        return mPickSizeFirst;
    }

    public void pickSizeFirst(boolean on) {
        mPickSizeFirst = on;
    }

    /** 换人门槛：1.12 = 新目标要"大 12%"才允许抢走锁定目标。 */
    public float sizeGate() {
        return mSizeGate;
    }

    public void sizeGate(float ratio) {
        mSizeGate = Math.max(1.0f, Math.min(2.0f, ratio));
    }

    /** 抢锁的绝对差门槛（归一化框高，0.01 ≈ 11 px @1080p）。 */
    public float sizeDelta() {
        return mSizeDelta;
    }

    public void sizeDelta(float delta) {
        mSizeDelta = Math.max(0f, Math.min(0.10f, delta));
    }

    /** 换人确认帧数：连续这么多帧都判"该换"才真换。 */
    public int switchFrames() {
        return mSwitchFrames;
    }

    public void switchFrames(int frames) {
        mSwitchFrames = Math.max(1, Math.min(10, frames));
    }

    /** 框尺寸 EMA 平滑系数（1.0 = 不平滑）。 */
    public float sizeEma() {
        return mSizeEma;
    }

    public void sizeEma(float alpha) {
        mSizeEma = Math.max(0.05f, Math.min(1f, alpha));
    }

    /** 选敌横向可达范围（比例，0.15 = ±15% 画面宽）；0 = 退回居中容差当资格线。 */
    public float sizeReach() {
        return mSizeReach;
    }

    public void sizeReach(float ratio) {
        mSizeReach = Math.max(0f, Math.min(0.5f, ratio));
    }

    public boolean feedForward() {
        return mFeedForward;
    }

    public void feedForward(boolean on) {
        mFeedForward = on;
    }

    public int leadMs() {
        return mLeadMs;
    }

    public void leadMs(int ms) {
        mLeadMs = Math.max(0, Math.min(200, ms));
    }

    public float velocityEma() {
        return mVelocityEma;
    }

    public void velocityEma(float ema) {
        mVelocityEma = Math.max(0.2f, Math.min(0.8f, ema));
    }

    public int maxVelPxPerSec() {
        return mMaxVelPxPerSec;
    }

    public void maxVelPxPerSec(int vel) {
        mMaxVelPxPerSec = Math.max(200, Math.min(3000, vel));
    }

    public int minVelPxPerSec() {
        return mMinVelPxPerSec;
    }

    public void minVelPxPerSec(int vel) {
        mMinVelPxPerSec = Math.max(0, Math.min(100, vel));
    }

    public int minTrackFrames() {
        return mMinTrackFrames;
    }

    public void minTrackFrames(int frames) {
        mMinTrackFrames = Math.max(2, Math.min(6, frames));
    }

    public float pxPerCount() {
        return mPxPerCount;
    }

    public void pxPerCount(float value) {
        mPxPerCount = Math.max(0.3f, Math.min(2.0f, value));
    }

    public boolean showPredicted() {
        return mShowPredicted;
    }

    public void showPredicted(boolean show) {
        mShowPredicted = show;
    }

    public boolean releaseStop() {
        return mReleaseStop;
    }

    public void releaseStop(boolean stop) {
        mReleaseStop = stop;
    }

    public boolean volumeKeyEnabled() {
        return mVolumeKeyEnabled;
    }

    public void volumeKeyEnabled(boolean on) {
        mVolumeKeyEnabled = on;
    }

    /** True when every value is inside its documented range (the UI gates "应用" on this). */
    public boolean isValid() {
        return mMaxMs >= 4 && mMaxMs <= 40 && mGain >= 0.2f && mGain <= 1f
                && mMaxStepCounts >= 20 && mPxPerCount > 0f && mDeadzonePx >= 0f;
    }
}
