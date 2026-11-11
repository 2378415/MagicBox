package com.magicbullet.capture.ui.yolo;

import android.net.Uri;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import com.google.android.material.button.MaterialButton;
import com.google.android.material.materialswitch.MaterialSwitch;
import com.magicbullet.capture.R;
import com.magicbullet.capture.core.ModelProfile;
import com.magicbullet.capture.core.ModelStore;
import com.magicbullet.capture.core.PipelineStats;
import com.magicbullet.capture.core.YoloConfig;
import com.magicbullet.capture.core.YoloDetector;
import com.magicbullet.capture.core.YoloSettings;

import java.io.File;
import java.util.List;
import java.util.Locale;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * YOLO tab: pick a local .onnx, describe its classes one per line, tune thresholds.
 *
 * <p>The class list is the source of truth for label names; the model supplies the
 * input size and class count, and a mismatch is reported instead of silently decoding
 * with wrong names.
 */
public class YoloFragment extends Fragment {

    private YoloConfig mConfig;
    private ModelStore mStore;

    private TextView mModelName;
    private TextView mModelStatus;
    private MaterialButton mPick;
    private MaterialButton mDelete;
    private EditText mLabels;
    private TextView mLabelsCount;
    private SeekBar mConfSeek;
    private SeekBar mIouSeek;
    private SeekBar mMaxDetSeek;
    private TextView mConfValue;
    private TextView mIouValue;
    private TextView mMaxDetValue;
    private TextView mBackendLabel;
    private MaterialSwitch mDrawSwitch;

    private final ExecutorService mIo = Executors.newSingleThreadExecutor();
    private float mDraftConf;
    private float mDraftIou;
    private int mDraftMax;
    /** Snapshot of what is actually driving inference; compared against the draft on apply. */
    private YoloSettings mApplied;
    private ActivityResultLauncher<String[]> mPicker;
    private boolean mBinding;

    private final PipelineStats.Listener mStatsListener = this::renderStats;

    public static YoloFragment newInstance() {
        return new YoloFragment();
    }

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mPicker = registerForActivityResult(new ActivityResultContracts.OpenDocument(), this::onModelPicked);
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container,
                             @Nullable Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_yolo, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        mConfig = YoloConfig.load(requireContext());
        mStore = new ModelStore(requireContext());

        mModelName = view.findViewById(R.id.model_name);
        mModelStatus = view.findViewById(R.id.model_status);
        mPick = view.findViewById(R.id.pick_model);
        mDelete = view.findViewById(R.id.delete_model);
        mLabels = view.findViewById(R.id.labels_edit);
        mLabelsCount = view.findViewById(R.id.labels_count);
        mConfSeek = view.findViewById(R.id.conf_seek);
        mIouSeek = view.findViewById(R.id.iou_seek);
        mMaxDetSeek = view.findViewById(R.id.maxdet_seek);
        mConfValue = view.findViewById(R.id.conf_value);
        mIouValue = view.findViewById(R.id.iou_value);
        mMaxDetValue = view.findViewById(R.id.maxdet_value);
        mBackendLabel = view.findViewById(R.id.backend_label);
        mDrawSwitch = view.findViewById(R.id.draw_switch);
        TextView fps = view.findViewById(R.id.stat_fps);
        TextView infer = view.findViewById(R.id.stat_infer);
        TextView latency = view.findViewById(R.id.stat_latency);

        mPick.setOnClickListener(v -> mPicker.launch(new String[]{"*/*"}));
        mDelete.setOnClickListener(v -> deleteCurrent());
        view.findViewById(R.id.apply).setOnClickListener(v -> applyNow());

        bindThresholds();
        bindLabelsWatcher();
        wireListeners(view);
        renderModel(null);
        mApplied = settingsFromUi();
        renderStats(PipelineStats.get().captureFps(), PipelineStats.get().inferMs(),
                PipelineStats.get().latencyMs());
    }

    @Override
    public void onStart() {
        super.onStart();
        PipelineStats.get().addListener(mStatsListener);
        renderModel(mStore.current());
        // The UI now mirrors what the persisted config says, so this is what is "applied".
        mApplied = settingsFromUi();
    }

    @Override
    public void onStop() {
        PipelineStats.get().removeListener(mStatsListener);
        super.onStop();
    }

    // ------------------------------------------------------------------ model

    private void onModelPicked(Uri uri) {
        if (uri == null) {
            return;
        }
        mModelStatus.setText(R.string.yolo_importing);
        mPick.setEnabled(false);
        mIo.execute(() -> {
            String id = String.valueOf(System.currentTimeMillis());
            String error = null;
            ModelProfile profile = null;
            try {
                File file = mStore.importFrom(uri, id);
                if (file.length() > 200L * 1024 * 1024) {
                    throw new IllegalStateException("模型超过 200 MB");
                }
                byte[] bytes = readAll(file);
                YoloDetector.ShapeInfo shape = YoloDetector.inspect(bytes);
                List<String> labels = mStore.current() != null
                        ? mStore.current().labels : ModelStore.builtinLabels();
                profile = new ModelProfile(id, file.getName(), file.getAbsolutePath(),
                        shape.inputSize, shape.layout, shape.numClasses, shape.anchors,
                        labels);
                mStore.add(profile);
                mStore.setCurrent(id);
            } catch (Throwable t) {
                error = String.valueOf(t.getMessage() != null ? t.getMessage() : t);
            }
            final String err = error;
            final ModelProfile ok = profile;
            requireActivity().runOnUiThread(() -> {
                mPick.setEnabled(true);
                if (err != null) {
                    mModelStatus.setText(getString(R.string.yolo_import_failed) + err);
                } else {
                    renderModel(ok);
                }
            });
        });
    }

    private void deleteCurrent() {
        ModelProfile current = mStore.current();
        if (current == null) {
            return;
        }
        mStore.remove(current.id);
        mStore.bumpRevision();
        renderModel(null);
    }

    /**
     * Commits the draft. Nothing on this page touches the detector until this runs: sliders,
     * the class list and the model picker only update local state.
     */
    private void applyNow() {
        List<String> labels = ModelStore.parseLabels(mLabels.getText().toString());
        ModelProfile current = mStore.current();
        YoloSettings draft = settingsFromUi();
        if (current != null && (current.layout == ModelProfile.LAYOUT_UNKNOWN
                || (current.numClasses == 0 && current.anchors == 0))) {
            mModelStatus.setText("暂不支持该模型输出，无法应用");
            toast(getString(R.string.yolo_toast_failed, getString(R.string.yolo_fail_layout)));
            return;
        }
        if (!draft.isValid()) {
            toast(getString(R.string.yolo_toast_failed, getString(R.string.yolo_fail_values)));
            return;
        }
        if (draft.equals(mApplied)) {
            toast(R.string.yolo_toast_unchanged);
            return;
        }
        mConfig.conf(mDraftConf);
        mConfig.iou(mDraftIou);
        mConfig.maxDet(mDraftMax);
        if (current != null) {
            mStore.updateLabels(current.id, labels);
            mConfig.save();
        } else {
            mConfig.builtinLabels(mLabels.getText().toString());
            mConfig.save();
        }
        mStore.bumpRevision();
        mApplied = draft;
        mModelStatus.setText(R.string.yolo_applied);
        toast(getString(R.string.yolo_toast_applied, mDraftConf, mDraftIou, mDraftMax));
    }

    /** What the page currently shows; this is what "应用" would commit. */
    private YoloSettings settingsFromUi() {
        ModelProfile current = mStore.current();
        return new YoloSettings(mDraftConf, mDraftIou, mDraftMax,
                current == null ? null : current.id,
                ModelStore.parseLabels(mLabels.getText().toString()));
    }

    private void toast(int resId) {
        if (getContext() != null) {
            Toast.makeText(getContext(), resId, Toast.LENGTH_SHORT).show();
        }
    }

    private void toast(CharSequence text) {
        if (getContext() != null) {
            Toast.makeText(getContext(), text, Toast.LENGTH_SHORT).show();
        }
    }

    private void renderModel(ModelProfile profile) {
        mBinding = true;
        if (profile == null) {
            mModelName.setText(R.string.yolo_model_builtin);
            mModelStatus.setText(R.string.yolo_model_no_import);
            mDelete.setEnabled(false);
            String saved = mConfig.builtinLabels();
            mLabels.setText(saved == null || saved.isEmpty()
                    ? ModelStore.joinLabels(ModelStore.builtinLabels()) : saved);
            mBinding = false;
            updateLabelsCount(80);
            return;
        }
        mModelName.setText(profile.name);
        if (profile.layout == ModelProfile.LAYOUT_UNKNOWN
                || (profile.numClasses == 0 && profile.anchors == 0)) {
            mModelStatus.setText("暂不支持该模型输出：需要单输出 [1,4+nc,N] / [1,N,6] 或 SCRFD 人脸头");
            mDelete.setEnabled(true);
            mLabels.setText(ModelStore.joinLabels(profile.labels));
            mBinding = false;
            return;
        }
        if (profile.layout == ModelProfile.LAYOUT_SCRFD) {
            mModelStatus.setText(profile.inputSize + "x" + profile.inputSize
                    + " · SCRFD 检测头（stride 8/16/32）· " + profile.anchors + " anchors"
                    + " · 类目 " + profile.labels.size() + " 行");
        } else if (profile.layout == ModelProfile.LAYOUT_E2E) {
            mModelStatus.setText(profile.inputSize + "x" + profile.inputSize
                    + " · e2e（内置 NMS）· 最多 " + profile.anchors + " 个框"
                    + " · 类别数由下方类目决定");
        } else {
            mModelStatus.setText(profile.inputSize + "x" + profile.inputSize
                    + " · " + profile.numClasses + " 类 · " + profile.anchors + " anchors");
        }
        mDelete.setEnabled(true);
        mLabels.setText(ModelStore.joinLabels(profile.labels));
        mBinding = false;
        updateLabelsCount(profile.labels.size());
    }

    private void bindLabelsWatcher() {
        mLabels.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {
            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
            }

            @Override
            public void afterTextChanged(Editable s) {
                // Draft only: the class list is committed by "应用".
                updateLabelsCount(ModelStore.parseLabels(s.toString()).size());
            }
        });
    }

    private void updateLabelsCount(int lines) {
        if (lines <= 0) {
            mLabelsCount.setText("");
            return;
        }
        mLabelsCount.setText(getString(R.string.yolo_labels_ok, lines, lines - 1));
    }

    // ------------------------------------------------------------------ thresholds

    private void bindThresholds() {
        mDraftConf = mConfig.conf();
        mDraftIou = mConfig.iou();
        mDraftMax = mConfig.maxDet();
        mBinding = true;
        mConfSeek.setProgress(Math.round(mDraftConf * 100f));
        mIouSeek.setProgress(Math.round(mDraftIou * 100f));
        mMaxDetSeek.setProgress(Math.max(0, Math.min(100, mDraftMax - 1)));
        mDrawSwitch.setChecked(mConfig.drawBoxes());
        updateThresholdLabels();
        mBinding = false;
    }

    private void updateThresholdLabels() {
        mConfValue.setText(String.format(Locale.US, "%.2f", mDraftConf));
        mIouValue.setText(String.format(Locale.US, "%.2f", mDraftIou));
        mMaxDetValue.setText(String.valueOf(mDraftMax));
    }

    private void wireListeners(View view) {
        mConfSeek.setOnSeekBarChangeListener(new SimpleSeekListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                mDraftConf = progress / 100f;
                mConfValue.setText(String.format(Locale.US, "%.2f", mDraftConf));
            }
        });
        mIouSeek.setOnSeekBarChangeListener(new SimpleSeekListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                mDraftIou = progress / 100f;
                mIouValue.setText(String.format(Locale.US, "%.2f", mDraftIou));
            }
        });
        mMaxDetSeek.setOnSeekBarChangeListener(new SimpleSeekListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                mDraftMax = 1 + progress;
                mMaxDetValue.setText(String.valueOf(mDraftMax));
            }
        });
        mDrawSwitch.setOnCheckedChangeListener((buttonView, isChecked) -> {
            if (mBinding) {
                return;
            }
            // Display only, not part of the inference configuration: applied right away.
            mConfig.drawBoxes(isChecked);
            mConfig.save();
        });
        view.findViewById(R.id.reset).setOnClickListener(v -> resetThresholds());
    }

    /** Puts the sliders back on the shipped defaults and commits them like "应用" would. */
    private void resetThresholds() {
        mDraftConf = YoloConfig.DEFAULT_CONF;
        mDraftIou = YoloConfig.DEFAULT_IOU;
        mDraftMax = YoloConfig.DEFAULT_MAX_DET;
        mBinding = true;
        mConfSeek.setProgress(Math.round(mDraftConf * 100f));
        mIouSeek.setProgress(Math.round(mDraftIou * 100f));
        mMaxDetSeek.setProgress(mDraftMax - 1);
        mBinding = false;
        updateThresholdLabels();
        applyNow();
    }

    // ------------------------------------------------------------------ stats

    private void renderStats(double fps, double inferMs, double latencyMs) {
        View root = getView();
        if (root == null) {
            return;
        }
        root.post(() -> {
            if (!isAdded()) {
                return;
            }
            String backend = PipelineStats.get().backend();
            mBackendLabel.setText(backend.isEmpty() ? "" : getString(R.string.yolo_backend_fmt, backend));
            TextView statFps = root.findViewById(R.id.stat_fps);
            TextView statInfer = root.findViewById(R.id.stat_infer);
            TextView statLatency = root.findViewById(R.id.stat_latency);
            statFps.setText(getString(R.string.yolo_stat_fps) + "  "
                    + (fps > 0 ? String.format(Locale.US, "%.1f", fps) : getString(R.string.yolo_stat_na)));
            PipelineStats stats = PipelineStats.get();
            String stages = stats.runMs() > 0
                    ? String.format(Locale.US, "  (c %.1f · p %.1f · r %.1f · d %.1f)",
                            stats.copyMs(), stats.preMs(), stats.runMs(), stats.postMs())
                    : "";
            statInfer.setText(getString(R.string.yolo_stat_infer) + "  "
                    + (inferMs > 0 ? String.format(Locale.US, "%.1f ms", inferMs) : getString(R.string.yolo_stat_na))
                    + stages);
            statLatency.setText(getString(R.string.yolo_stat_latency) + "  "
                    + (latencyMs > 0 ? String.format(Locale.US, "%.1f ms", latencyMs) : getString(R.string.yolo_stat_na)));
        });
    }

    private static byte[] readAll(File file) throws Exception {
        try (java.io.FileInputStream in = new java.io.FileInputStream(file)) {
            java.io.ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            byte[] buf = new byte[256 * 1024];
            int n;
            while ((n = in.read(buf)) > 0) {
                out.write(buf, 0, n);
            }
            return out.toByteArray();
        }
    }

    /** SeekBar.OnSeekBarChangeListener with empty start/stop callbacks. */
    private abstract static class SimpleSeekListener
            implements SeekBar.OnSeekBarChangeListener {
        @Override
        public void onStartTrackingTouch(SeekBar seekBar) {
        }

        @Override
        public void onStopTrackingTouch(SeekBar seekBar) {
        }
    }
}
