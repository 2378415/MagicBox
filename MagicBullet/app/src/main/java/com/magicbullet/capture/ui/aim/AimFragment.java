package com.magicbullet.capture.ui.aim;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.SeekBar;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import com.google.android.material.button.MaterialButton;
import com.google.android.material.materialswitch.MaterialSwitch;
import com.magicbullet.capture.R;
import com.magicbullet.capture.core.AimConfig;
import com.magicbullet.capture.core.AimController;
import com.magicbullet.capture.core.AimRect;
import com.magicbullet.capture.core.ControlPort;

import java.util.Locale;

/**
 * 瞄准 tab. Everything the closed loop needs, no pixel work: the rectangle is edited on the live
 * preview page, this page carries the numbers, the hotkey and the AIM state readback.
 */
public class AimFragment extends Fragment implements AimController.StatsListener,
        AimConfig.Listener {

    /** Implemented by the activity: switches to the preview tab in rectangle-editing mode. */
    public interface RectEditorHost {
        void editAimRect();
    }

    private AimConfig mConfig;
    private AimController mAim;

    private TextView mStatus;
    private TextView mDetail;
    private TextView mStats;
    private TextView mAimState;
    private TextView mHid;
    private TextView mAuto;
    private EditText mStable;
    private EditText mTrackMin;
    private EditText mOffsetX;
    private EditText mOffsetY;
    private MaterialSwitch mAutoDead;
    private MaterialSwitch mAdsBucket;
    private MaterialSwitch mAutoMaxStep;
    private EditText mHeadBias;
    private EditText mCenterTol;
    private MaterialSwitch mCenteredHead;
    private MaterialSwitch mPickSize;
    private EditText mSizeGate;
    private EditText mSizeReach;
    private EditText mSizeDelta;
    private EditText mSwitchFrames;
    private EditText mSizeEma;
    private TextView mBudgetValue;
    private TextView mBudgetHint;
    private TextView mRectValue;
    private TextView mLog;
    private SeekBar mBudgetSeek;
    private EditText mLabels;
    private EditText mDeadzone;
    private EditText mGain;
    private EditText mMaxStep;
    private EditText mPxPerCount;
    private MaterialSwitch mHold;
    private MaterialSwitch mVolumeKey;
    private MaterialSwitch mClamp;
    private MaterialSwitch mTurbo;
    private MaterialSwitch mPassthrough;
    private com.google.android.material.button.MaterialButtonToggleGroup mKeyGroup;
    private TextView mHotkeyMaskText;
    private MaterialButton mKeyRight;
    private MaterialButton mKeyRear;
    private MaterialButton mKeyFront;
    private MaterialButton mArm;
    private boolean mBinding;
    private boolean mPrefsBound;

    public static AimFragment newInstance() {
        return new AimFragment();
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container,
                             @Nullable Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_aim, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        mConfig = AimConfig.load(requireContext());
        mAim = AimController.get(requireContext());

        mStatus = view.findViewById(R.id.aim_status);
        mDetail = view.findViewById(R.id.aim_detail);
        mStats = view.findViewById(R.id.aim_stats);
        mAimState = view.findViewById(R.id.aim_aimstate);
        mHid = view.findViewById(R.id.aim_hid);
        mAuto = view.findViewById(R.id.aim_auto);
        mStable = view.findViewById(R.id.aim_stable);
        mTrackMin = view.findViewById(R.id.aim_trackmin);
        mOffsetX = view.findViewById(R.id.aim_offsetx);
        mOffsetY = view.findViewById(R.id.aim_offsety);
        mAutoDead = view.findViewById(R.id.aim_auto_dead);
        mAdsBucket = view.findViewById(R.id.aim_ads_bucket);
        mAutoMaxStep = view.findViewById(R.id.aim_auto_maxstep);
        mHeadBias = view.findViewById(R.id.aim_head_bias);
        mCenterTol = view.findViewById(R.id.aim_center_tol);
        mCenteredHead = view.findViewById(R.id.aim_centered_head);
        mPickSize = view.findViewById(R.id.aim_pick_size);
        mSizeGate = view.findViewById(R.id.aim_size_gate);
        mSizeReach = view.findViewById(R.id.aim_size_reach);
        mSizeDelta = view.findViewById(R.id.aim_size_delta);
        mSwitchFrames = view.findViewById(R.id.aim_switch_frames);
        mSizeEma = view.findViewById(R.id.aim_size_ema);
        android.view.View advBody = view.findViewById(R.id.aim_adv_body);
        view.findViewById(R.id.aim_adv_toggle).setOnClickListener(v -> advBody.setVisibility(
                advBody.getVisibility() == android.view.View.VISIBLE
                        ? android.view.View.GONE : android.view.View.VISIBLE));
        view.findViewById(R.id.aim_export).setOnClickListener(v -> exportConfig());
        view.findViewById(R.id.aim_import).setOnClickListener(v -> importConfig());
        mLog = view.findViewById(R.id.aim_log);
        mBudgetValue = view.findViewById(R.id.aim_speed_value);
        mBudgetHint = view.findViewById(R.id.aim_speed_hint);
        mRectValue = view.findViewById(R.id.aim_rect_value);
        mBudgetSeek = view.findViewById(R.id.aim_speed_seek);
        mLabels = view.findViewById(R.id.aim_labels);
        mDeadzone = view.findViewById(R.id.aim_deadzone);
        mGain = view.findViewById(R.id.aim_gain);
        mMaxStep = view.findViewById(R.id.aim_maxstep);
        mPxPerCount = view.findViewById(R.id.aim_pxpercount);
        mHold = view.findViewById(R.id.aim_hold);
        mVolumeKey = view.findViewById(R.id.aim_volume_key);
        mClamp = view.findViewById(R.id.aim_clamp);
        mTurbo = view.findViewById(R.id.aim_turbo);
        mPassthrough = view.findViewById(R.id.aim_passthrough);
        mKeyRight = view.findViewById(R.id.aim_key_right);
        mKeyRear = view.findViewById(R.id.aim_key_rear);
        mKeyFront = view.findViewById(R.id.aim_key_front);
        mHotkeyMaskText = view.findViewById(R.id.aim_hotkey_mask);
        mArm = view.findViewById(R.id.aim_arm);

        // The budget slider is the only "speed" control: 4..40 ms per shot.
        mBudgetSeek.setMax(36);
        mBudgetSeek.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if (mBinding) {
                    return;
                }
                mConfig.maxMs(4 + progress);
                renderBudget();
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
            }
        });

        // 启动热键可多选：任意一个按下都算触发（HotkeyWatcher 用 mask&mMask 判定"任一位按住"）
        mKeyGroup = view.findViewById(R.id.aim_key_group);
        mKeyGroup.addOnButtonCheckedListener((group, checkedId, isChecked) -> {
            if (mBinding) {
                return;
            }
            int bit = checkedId == R.id.aim_key_right ? AimConfig.MASK_RIGHT
                    : checkedId == R.id.aim_key_rear ? AimConfig.MASK_SIDE_REAR
                    : AimConfig.MASK_SIDE_FRONT;
            int mask = mConfig.hotkeyMask();
            mask = isChecked ? (mask | bit) : (mask & ~bit);
            if (mask == 0) {
                // 至少保留一个：取消最后一个时把它重新勾上
                mBinding = true;
                mKeyGroup.check(checkedId);
                mBinding = false;
                mask = mConfig.hotkeyMask();
            }
            mConfig.hotkeyMask(mask);
            mConfig.persist();          // 多选立即落盘，避免被杀后丢失
            renderHotkey();
        });
        mArm.setOnClickListener(v -> {
            applyFromUi();
            mAim.setArmed(!mAim.stats().armed);
        });
        view.findViewById(R.id.aim_learn).setOnClickListener(v -> {
            applyFromUi();
            mAim.startLearnHotkey();
        });
        view.findViewById(R.id.aim_apply).setOnClickListener(v -> {
            applyFromUi();
            mAim.setArmed(mAim.stats().armed); // re-subscribes with the (possibly new) mask
            toast(getString(R.string.aim_applied));
        });
        view.findViewById(R.id.aim_calib).setOnClickListener(v -> {
            applyFromUi();
            openCalibration();
        });
        view.findViewById(R.id.aim_rect_edit).setOnClickListener(v -> {
            if (requireActivity() instanceof RectEditorHost) {
                ((RectEditorHost) requireActivity()).editAimRect();
            }
        });
        // 页尾「保存配置」：把整页所有输入一次落盘并立即生效（等价于顶部「应用」，
        // 但不用先滚到顶；保存后重新订阅热键，确保新掩码/新参数马上起作用）。
        view.findViewById(R.id.aim_save_all).setOnClickListener(v -> {
            applyFromUi();
            mAim.setArmed(mAim.stats().armed);
            toast(getString(R.string.aim_saved_all));
        });


        bindFromConfig();
        mPrefsBound = true;
    }

    @Override
    public void onStart() {
        super.onStart();
        mAim.setUiListener(this);
        mConfig.addListener(this);
        renderAll();
    }

    @Override
    public void onStop() {
        mAim.setUiListener(null);
        mConfig.removeListener(this);
        super.onStop();
    }

    // ------------------------------------------------------------------ bind/render

    private void bindFromConfig() {
        mBinding = true;
        mBudgetSeek.setProgress(mConfig.maxMs() - 4);
        mLabels.setText(mConfig.labels());
        mDeadzone.setText(String.format(Locale.US, "%.0f", mConfig.deadzonePx()));
        mGain.setText(String.format(Locale.US, "%.2f", mConfig.gain()));
        mMaxStep.setText(String.valueOf(mConfig.maxStepCounts()));
        mPxPerCount.setText(String.format(Locale.US, "%.3f", mConfig.pxPerCount()));
        mStable.setText(String.valueOf(mConfig.stableFrames()));
        mTrackMin.setText(String.valueOf(mConfig.minTrackFrames()));
        mOffsetX.setText(String.format(Locale.US, "%.1f", mConfig.aimOffsetX()));
        mOffsetY.setText(String.format(Locale.US, "%.1f", mConfig.aimOffsetY()));
        mAutoDead.setChecked(mConfig.autoDeadzone());
        mAdsBucket.setChecked(mConfig.adsBucket());
        mAutoMaxStep.setChecked(mConfig.autoMaxStep());
        mHeadBias.setText(String.format(Locale.US, "%.2f", mConfig.headAnchorBias()));
        mCenterTol.setText(String.format(Locale.US, "%.1f", mConfig.centerTolerance() * 100f));
        mCenteredHead.setChecked(mConfig.preferCenteredHead());
        mPickSize.setChecked(mConfig.pickSizeFirst());
        mSizeGate.setText(String.format(Locale.US, "%.0f", (mConfig.sizeGate() - 1f) * 100f));
        mSizeReach.setText(String.format(Locale.US, "%.0f", mConfig.sizeReach() * 100f));
        mSizeDelta.setText(String.format(Locale.US, "%.1f", mConfig.sizeDelta() * 100f));
        mSwitchFrames.setText(String.valueOf(mConfig.switchFrames()));
        mSizeEma.setText(String.format(Locale.US, "%.0f", mConfig.sizeEma() * 100f));
        mHold.setChecked(mConfig.holdMode());
        mVolumeKey.setChecked(mConfig.volumeKeyEnabled());
        mClamp.setChecked(mConfig.sessionClamp());
        mTurbo.setChecked(mConfig.turbo());
        mPassthrough.setChecked(!mConfig.hotkeyConsume());
        mBinding = false;
        renderAll();
    }

    private void renderAll() {
        renderBudget();
        renderHotkey();
        renderRect();
        renderStats(mAim.stats());
        renderLog();
    }

    /**
     * AIM runs a constant-velocity shot inside the budget, so the per-report step is
     * {@code speed_eff / 1000} and {@code speed_eff ≈ counts / max_ms}.
     */
    private void renderBudget() {
        int maxMs = mConfig.maxMs();
        float pxPerCount = Math.max(0.05f, mConfig.pxPerCount());
        // A 200 px correction is the reference case for the "how long" readout.
        float counts = 200f / pxPerCount;
        float speedEff = counts / (maxMs / 1000f);
        int perReport = Math.max(1, Math.round(speedEff / 1000f));
        mBudgetValue.setText(String.format(Locale.US, "%d ms", maxMs));
        mBudgetHint.setText(String.format(Locale.US,
                "每报告约 %d counts ≈ %.0f px · 200 px 目标约 %d ms",
                perReport, perReport * pxPerCount,
                Math.round(counts / Math.max(1, perReport)) * maxMs));
    }

    private void renderHotkey() {
        int mask = mConfig.hotkeyMask();
        boolean right = (mask & AimConfig.MASK_RIGHT) != 0;
        boolean rear = (mask & AimConfig.MASK_SIDE_REAR) != 0;
        boolean front = (mask & AimConfig.MASK_SIDE_FRONT) != 0;
        if (mKeyGroup != null) {
            mBinding = true;
            if (right) {
                mKeyGroup.check(R.id.aim_key_right);
            } else {
                mKeyGroup.uncheck(R.id.aim_key_right);
            }
            if (rear) {
                mKeyGroup.check(R.id.aim_key_rear);
            } else {
                mKeyGroup.uncheck(R.id.aim_key_rear);
            }
            if (front) {
                mKeyGroup.check(R.id.aim_key_front);
            } else {
                mKeyGroup.uncheck(R.id.aim_key_front);
            }
            mBinding = false;
        }
        mKeyRight.setAlpha(right ? 1f : 0.55f);
        mKeyRear.setAlpha(rear ? 1f : 0.55f);
        mKeyFront.setAlpha(front ? 1f : 0.55f);
        if (mHotkeyMaskText != null) {
            mHotkeyMaskText.setText(String.format(Locale.US,
                    "当前热键 0x%02X（可多选，任一个触发即生效）", mask));
        }
    }

    private void renderRect() {
        AimRect rect = mConfig.rect();
        mRectValue.setText(rect.describe(1920, 1080)
                + " · 准心 " + String.format(Locale.US, "%.2f, %.2f",
                rect.x + rect.w / 2f, rect.y + rect.h / 2f));
    }

    private int dp(boolean selected) {
        return selected ? (int) (2 * getResources().getDisplayMetrics().density) : 0;
    }

    private void renderStats(AimController.Stats stats) {
        if (!isAdded() || mStatus == null) {
            return;
        }
        String headline;
        if (!stats.armed) {
            headline = getString(R.string.aim_status_idle);
        } else if (stats.aiming) {
            headline = getString(R.string.aim_status_aiming);
        } else {
            headline = getString(R.string.aim_status_armed);
        }
        mStatus.setText(headline);
        mDetail.setText(stats.note == null ? "" : stats.note);
        mStats.setText(String.format(Locale.US, "触发 %d 次 · 误差 %.1f px · %s",
                stats.triggers, stats.lastErrorPx,
                stats.target.isEmpty() ? "无目标" : stats.target));
        if (!stats.aimSupported) {
            mAimState.setText(R.string.aim_state_unsupported);
        } else if (stats.aiming) {
            mAimState.setText(String.format(Locale.US,
                    "AIM %s · gen %d · rounds %d · 死区 %d",
                    ControlPort.AimState.resultText(stats.lastResult), stats.gen,
                    stats.rounds, stats.deadHits));
        } else {
            // 空闲行只留实时量；"上次结果"是历史，归日志，不再占这里的位置。
            mAimState.setText(String.format(Locale.US,
                    "空闲 · rounds %d · 死区 %d", stats.rounds, stats.deadHits));
        }
        // 新文档 0x3E / 0x3F：按键队列 + 回环审计，异常直接标红
        boolean healthy = stats.btnSent >= stats.btnIn && stats.btnOverflow == 0
                && stats.auditExtra == 0 && stats.btnFlood == 0 && stats.btnWaitUs <= 5000;
        if (mHid != null) {
            mHid.setText(String.format(Locale.US,
                    "按键 %d/%d · 等待 %dµs · 溢出 %d · 洪泛 %d · 合并 %d/抵消 %d · 审计 %d/%d 多发 %d",
                    stats.btnSent, stats.btnIn, stats.btnWaitUs, stats.btnOverflow,
                    stats.btnFlood, stats.btnMerged, stats.btnCancel,
                    stats.auditOut, stats.auditIn, stats.auditExtra));
            mHid.setTextColor(getResources().getColor(healthy
                    ? R.color.text_secondary : R.color.state_error, null));
        }
        if (mAuto != null) {
            String stick = stats.stickHits + stats.stickSwitches > 0
                    ? String.format(Locale.US, " · 粘滞 %d%%（换人 %d）",
                    100 * stats.stickHits / (stats.stickHits + stats.stickSwitches),
                    stats.stickSwitches)
                    : "";
            String auto = String.format(Locale.US, " · 自动 死区 %.1fpx 上限 %dc",
                    stats.autoDeadzonePx, stats.autoMaxCounts);
            if (stats.adaptiveGain > 0f) {
                mAuto.setText(String.format(Locale.US, "自校准增益 %.2f（实测响应 %.2f）%s%s",
                        stats.adaptiveGain, stats.realGain, auto, stick));
            } else {
                mAuto.setText(getString(R.string.aim_auto_idle) + auto + stick);
            }
        }
        mArm.setText(stats.armed ? R.string.aim_disarm : R.string.aim_arm);
    }

    private void renderLog() {
        if (mLog == null) {
            return;
        }
        StringBuilder sb = new StringBuilder();
        java.util.List<String> lines = ControlPort.get(requireContext()).logLines();
        int from = Math.max(0, lines.size() - 25);
        for (int i = from; i < lines.size(); i++) {
            sb.append(lines.get(i)).append('\n');
        }
        mLog.setText(sb);
    }

    // ------------------------------------------------------------------ apply

    private void applyFromUi() {
        mConfig.maxMs(4 + mBudgetSeek.getProgress());
        mConfig.labels(mLabels.getText() == null ? "" : mLabels.getText().toString());
        mConfig.deadzonePx(parseFloat(mDeadzone, 4f));
        mConfig.gain(parseFloat(mGain, 0.6f));
        mConfig.maxStepCounts(parseInt(mMaxStep, AimConfig.DEFAULT_MAX_STEP_COUNTS));
        mConfig.pxPerCount(parseFloat(mPxPerCount, AimConfig.DEFAULT_PX_PER_COUNT));
        mConfig.stableFrames(parseInt(mStable, 3));
        mConfig.minTrackFrames(parseInt(mTrackMin, 3));
        mConfig.aimOffsetX(parseFloat(mOffsetX, 0f));
        mConfig.aimOffsetY(parseFloat(mOffsetY, 0f));
        mConfig.autoDeadzone(mAutoDead.isChecked());
        mConfig.adsBucket(mAdsBucket.isChecked());
        mConfig.autoMaxStep(mAutoMaxStep.isChecked());
        mConfig.headAnchorBias(parseFloat(mHeadBias, 1.0f));
        mConfig.centerTolerance(parseFloat(mCenterTol, 1f) / 100f);
        mConfig.preferCenteredHead(mCenteredHead.isChecked());
        mConfig.pickSizeFirst(mPickSize.isChecked());
        mConfig.sizeGate(1f + parseFloat(mSizeGate, 8f) / 100f);
        mConfig.sizeReach(parseFloat(mSizeReach, 15f) / 100f);
        mConfig.sizeDelta(parseFloat(mSizeDelta, 1f) / 100f);
        mConfig.switchFrames(parseInt(mSwitchFrames, 3));
        mConfig.sizeEma(parseFloat(mSizeEma, 30f) / 100f);
        mConfig.holdMode(mHold.isChecked());
        mConfig.volumeKeyEnabled(mVolumeKey.isChecked());
        // 前馈栏目已按用户要求移除：不再使用速度前馈与预测点。
        mConfig.feedForward(false);
        mConfig.showPredicted(false);
        mConfig.sessionClamp(mClamp.isChecked());
        mConfig.turbo(mTurbo.isChecked());
        mConfig.hotkeyConsume(!mPassthrough.isChecked());
        mConfig.save();
        renderAll();
    }

    private static float parseFloat(EditText field, float fallback) {
        String text = field.getText() == null ? "" : field.getText().toString().trim();
        try {
            return text.isEmpty() ? fallback : Float.parseFloat(text);
        } catch (NumberFormatException e) {
            return fallback;
        }
    }

    private static int parseInt(EditText field, int fallback) {
        String text = field.getText() == null ? "" : field.getText().toString().trim();
        try {
            return text.isEmpty() ? fallback : Integer.parseInt(text);
        } catch (NumberFormatException e) {
            return fallback;
        }
    }

    private void toast(CharSequence text) {
        if (getContext() != null) {
            android.widget.Toast.makeText(getContext(), text, android.widget.Toast.LENGTH_SHORT)
                    .show();
        }
    }

    // ------------------------------------------------------------------ listeners

    @Override
    public void onAimStats(AimController.Stats stats) {
        if (!isAdded()) {
            return;
        }
        renderStats(stats);
        renderLog();
    }

    @Override
    public void onAimConfigChanged(AimConfig config) {
        mConfig = config;
        if (isAdded()) {
            renderAll();
        }
    }
    /** 先向预览流要一帧冻结图，再进横屏校准页（页面盖住预览后相机就停了）。 */
    private void openCalibration() {
        com.magicbullet.capture.core.FrameSnapshot.request();
        waitAndOpen(Math.max(0, 0));
    }

    private void waitAndOpen(int attempt) {
        if (com.magicbullet.capture.core.FrameSnapshot.bitmap() != null || attempt >= 15) {
            startActivity(new android.content.Intent(requireContext(),
                    com.magicbullet.capture.ui.calib.AimCalibActivity.class));
            return;
        }
        android.view.View root = getView();
        if (root != null) {
            root.postDelayed(() -> waitAndOpen(attempt + 1), 100L);
        }
    }

    // ---------------------------------------------------------------- 配置导入导出

    private java.io.File configFile() {
        java.io.File dir = requireContext().getExternalFilesDir(null);
        return new java.io.File(dir == null ? requireContext().getFilesDir() : dir, "aim_config.json");
    }

    private void exportConfig() {
        applyFromUi();
        try {
            org.json.JSONObject o = new org.json.JSONObject();
            o.put("schema", 6);
            o.put("max_ms", mConfig.maxMs());
            o.put("deadzone", mConfig.deadzonePx());
            o.put("gain", mConfig.gain());
            o.put("max_step_counts", mConfig.maxStepCounts());
            o.put("px_per_count", mConfig.pxPerCount());
            o.put("stable_frames", mConfig.stableFrames());
            o.put("track_min", mConfig.minTrackFrames());
            o.put("aim_offset_x", mConfig.aimOffsetX());
            o.put("aim_offset_y", mConfig.aimOffsetY());
            o.put("hotkey_mask", mConfig.hotkeyMask());
            o.put("hold", mConfig.holdMode());
            o.put("hotkey_consume", mConfig.hotkeyConsume());
            o.put("auto_gain", mConfig.autoGain());
            o.put("stick_target", mConfig.stickTarget());
            o.put("head_anchor_bias", mConfig.headAnchorBias());
            o.put("prefer_centered_head", mConfig.preferCenteredHead());
            o.put("center_tolerance", mConfig.centerTolerance());
            o.put("pick_size_first", mConfig.pickSizeFirst());
            o.put("size_gate", mConfig.sizeGate());
            o.put("size_reach", mConfig.sizeReach());
            o.put("size_delta", mConfig.sizeDelta());
            o.put("switch_frames", mConfig.switchFrames());
            o.put("size_ema", mConfig.sizeEma());
            o.put("auto_deadzone", mConfig.autoDeadzone());
            o.put("ads_bucket", mConfig.adsBucket());
            o.put("gain_adapt_hip", (double) mConfig.gainAdapt(false));
            o.put("gain_adapt_ads", (double) mConfig.gainAdapt(true));
            o.put("classes", new org.json.JSONArray(mConfig.classes()));
            org.json.JSONObject rect = new org.json.JSONObject();
            rect.put("x", mConfig.rect().x);
            rect.put("y", mConfig.rect().y);
            rect.put("w", mConfig.rect().w);
            rect.put("h", mConfig.rect().h);
            o.put("rect", rect);
            java.io.File file = configFile();
            try (java.io.FileWriter w = new java.io.FileWriter(file, false)) {
                w.write(o.toString(2));
            }
            toast(getString(R.string.aim_exported) + file.getAbsolutePath());
        } catch (Throwable e) {
            toast(getString(R.string.aim_export_failed) + e.getMessage());
        }
    }

    private void importConfig() {
        try {
            java.io.File file = configFile();
            if (!file.exists()) {
                toast(getString(R.string.aim_import_missing));
                return;
            }
            String text = new String(java.nio.file.Files.readAllBytes(file.toPath()),
                    java.nio.charset.StandardCharsets.UTF_8);
            org.json.JSONObject o = new org.json.JSONObject(text);
            if (o.has("max_ms")) {
                mConfig.maxMs(o.getInt("max_ms"));
            }
            if (o.has("deadzone")) {
                mConfig.deadzonePx((float) o.getDouble("deadzone"));
            }
            if (o.has("gain")) {
                mConfig.gain((float) o.getDouble("gain"));
            }
            if (o.has("max_step_counts")) {
                mConfig.maxStepCounts(o.getInt("max_step_counts"));
            }
            if (o.has("px_per_count")) {
                mConfig.pxPerCount((float) o.getDouble("px_per_count"));
            }
            if (o.has("stable_frames")) {
                mConfig.stableFrames(o.getInt("stable_frames"));
            }
            if (o.has("track_min")) {
                mConfig.minTrackFrames(o.getInt("track_min"));
            }
            if (o.has("aim_offset_x")) {
                mConfig.aimOffsetX((float) o.getDouble("aim_offset_x"));
            }
            if (o.has("aim_offset_y")) {
                mConfig.aimOffsetY((float) o.getDouble("aim_offset_y"));
            }
            if (o.has("hotkey_mask")) {
                mConfig.hotkeyMask(o.getInt("hotkey_mask"));
            }
            if (o.has("hold")) {
                mConfig.holdMode(o.getBoolean("hold"));
            }
            if (o.has("hotkey_consume")) {
                mConfig.hotkeyConsume(o.getBoolean("hotkey_consume"));
            }
            if (o.has("auto_gain")) {
                mConfig.autoGain(o.getBoolean("auto_gain"));
            }
            if (o.has("stick_target")) {
                mConfig.stickTarget(o.getBoolean("stick_target"));
            }
            if (o.has("head_anchor_bias")) {
                mConfig.headAnchorBias((float) o.getDouble("head_anchor_bias"));
            }
            if (o.has("prefer_centered_head")) {
                mConfig.preferCenteredHead(o.getBoolean("prefer_centered_head"));
            }
            if (o.has("center_tolerance")) {
                mConfig.centerTolerance((float) o.getDouble("center_tolerance"));
            }
            if (o.has("pick_size_first")) {
                mConfig.pickSizeFirst(o.getBoolean("pick_size_first"));
            }
            if (o.has("size_gate")) {
                mConfig.sizeGate((float) o.getDouble("size_gate"));
            }
            if (o.has("size_reach")) {
                mConfig.sizeReach((float) o.getDouble("size_reach"));
            }
            if (o.has("size_delta")) {
                mConfig.sizeDelta((float) o.getDouble("size_delta"));
            }
            if (o.has("switch_frames")) {
                mConfig.switchFrames(o.getInt("switch_frames"));
            }
            if (o.has("size_ema")) {
                mConfig.sizeEma((float) o.getDouble("size_ema"));
            }
            if (o.has("auto_deadzone")) {
                mConfig.autoDeadzone(o.getBoolean("auto_deadzone"));
            }
            if (o.has("ads_bucket")) {
                mConfig.adsBucket(o.getBoolean("ads_bucket"));
            }
            if (o.has("gain_adapt_hip")) {
                mConfig.gainAdapt(false, (float) o.getDouble("gain_adapt_hip"));
            }
            if (o.has("gain_adapt_ads")) {
                mConfig.gainAdapt(true, (float) o.getDouble("gain_adapt_ads"));
            }
            if (o.has("classes")) {
                org.json.JSONArray arr = o.getJSONArray("classes");
                java.util.Set<String> classes = new java.util.LinkedHashSet<>();
                for (int i = 0; i < arr.length(); i++) {
                    classes.add(arr.getString(i));
                }
                if (!classes.isEmpty()) {
                    mConfig.labels(String.join(",", classes));
                }
            }
            if (o.has("rect")) {
                org.json.JSONObject r = o.getJSONObject("rect");
                mConfig.rect(new AimRect((float) r.getDouble("x"), (float) r.getDouble("y"),
                        (float) r.getDouble("w"), (float) r.getDouble("h")));
            }
            mConfig.persist();
            bindFromConfig();
        mPrefsBound = true;
            renderBudget();
            toast(getString(R.string.aim_imported));
        } catch (Throwable e) {
            toast(getString(R.string.aim_export_failed) + e.getMessage());
        }
    }
}