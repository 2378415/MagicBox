package com.magicbullet.capture.ui.preview;

import android.graphics.Bitmap;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.os.Looper;
import android.os.SystemClock;
import android.view.LayoutInflater;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import com.magicbullet.capture.R;
import com.magicbullet.capture.core.AimConfig;
import com.magicbullet.capture.core.AimController;
import com.magicbullet.capture.core.AimRect;
import com.magicbullet.capture.core.Detection;
import com.magicbullet.capture.core.FrameSnapshot;
import com.magicbullet.capture.core.DummyDetector;
import com.magicbullet.capture.core.PipelineStats;
import com.magicbullet.capture.core.UvcSession;
import com.magicbullet.capture.core.UvcSessionHost;
import com.magicbullet.capture.core.YoloConfig;
import com.magicbullet.capture.core.ModelProfile;
import com.magicbullet.capture.core.ModelStore;
import com.magicbullet.capture.core.RoiConfig;
import com.magicbullet.capture.core.YoloDetector;
import com.magicbullet.capture.widget.AimRectView;
import com.magicbullet.capture.widget.DetectionOverlayView;
import com.magicbullet.capture.widget.RoiPickerView;
import com.google.android.material.button.MaterialButton;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.Locale;

/**
 * Live preview + detection overlay.
 *
 * <p>Owns no camera state: the {@link UvcSession} is attached/detached here so the USB
 * session survives tab switches. Frames arrive on the capture thread; detection results
 * are handed to the overlay on the main thread at ~30 Hz.
 */
public class PreviewFragment extends Fragment
        implements AimConfig.Listener, SurfaceHolder.Callback,
        UvcSession.Listener, UvcSession.FrameListener, UvcSession.RawFrameListener,
        YoloConfig.Listener {

    private static final String TAG = "PreviewFragment";
    private static final long OVERLAY_INTERVAL_MS = 33L;

    private SurfaceView mSurface;
    private DetectionOverlayView mOverlay;
    private TextView mStatus;
    private TextView mDetail;
    private TextView mDevice;
    private TextView mMode;
    private UvcSession mSession;
    private YoloConfig mConfig;

    private final Handler mHandler = new Handler(Looper.getMainLooper());
    private final DummyDetector mDummy = new DummyDetector();
    private YoloDetector mDetector;
    private String mBackend = "";
    private int mFrameSkip;
    private ExecutorService mInferExec;
    private volatile boolean mInferBusy;
    /** 空闲降频用：上一次真正做检测的时刻（非预览页且未瞄准时降到 ~15 fps）。 */
    private volatile long mLastIdleDetectMs;
    /** 正在预览页里手动拖框时，不要被监听回调覆盖。 */
    private volatile boolean mEditingRect;
    private byte[] mFrameBytes;
    private long mAppliedRevision = -1;
    private String mAppliedModelId;
    private String mBaseDetail = "";
    private boolean mNoSignalShown;
    private int mFrameIndex;
    private long mLastOverlayMs;
    private long mLastStageLogMs;
    private int mAppliedLabelsHash;
    private RoiPickerView mRoiPicker;
    private MaterialButton mApplyRoi;
    private MaterialButton[] mRoiButtons;
    private MaterialButton[] mCaptureButtons;
    private RoiConfig mRoiDraft = RoiConfig.FULL;
    private RoiConfig mRoiApplied = RoiConfig.FULL;
    private int mFrameW;
    private int mFrameH;
    private AimRectView mAimRectView;
    private AimController mAim;
    private AimConfig mAimConfig;

    public static PreviewFragment newInstance() {
        return new PreviewFragment();
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container,
                             @Nullable Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_preview, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        mSession = ((UvcSessionHost) requireActivity()).session();
        mConfig = YoloConfig.load(requireContext());

        mSurface = view.findViewById(R.id.preview);
        // Draw the overlay above the surface: without this the SurfaceView punches
        // through the window and boxes would be hidden behind the video.
        mSurface.setZOrderMediaOverlay(true);
        mOverlay = view.findViewById(R.id.overlay);
        mStatus = view.findViewById(R.id.status);
        mDetail = view.findViewById(R.id.detail);
        mDevice = view.findViewById(R.id.device);
        mMode = view.findViewById(R.id.mode);

        mSurface.getHolder().addCallback(this);
        view.findViewById(R.id.rescan).setOnClickListener(v -> mSession.rescan());
        bindRoiEditor(view);
        bindAimOverlay(view);

        mInferExec = Executors.newSingleThreadExecutor();
        reloadDetectorIfNeeded();
    }

    @Override
    public void onStart() {
        super.onStart();
        if (mAimConfig != null) {
            mAimConfig.addListener(this);
            // 从横屏校准页回来时通知已经发过了（那时本页处于 stopped），这里主动同步一次。
            if (mAimRectView != null && !mEditingRect) {
                mAimRectView.setAimRect(mAimConfig.rect());
            }
        }
        mSession.setListener(this);
        mSession.setFrameListener(this);
        mSession.setRawFrameListener(this);
        // The YOLO tab may have committed new values while this fragment was stopped, so the
        // cached config instance is stale: reload before re-registering.
        mConfig.removeListener(this);
        mConfig = YoloConfig.load(requireContext());
        mConfig.addListener(this);
        int[] mode = mSession.captureMode();
        updateCaptureChips(mode[0], mode[1], mode[2]);
        reloadDetectorIfNeeded();
        if (!isHidden()) {
            SurfaceHolder holder = mSurface.getHolder();
            if (holder.getSurface() != null && holder.getSurface().isValid()) {
                mSession.attachSurface(holder);
            }
        }
    }

    @Override
    public void onStop() {
        mSession.setRawFrameListener(null);
        mSession.setFrameListener(null);
        mSession.setListener(null);
        mConfig.removeListener(this);
        super.onStop();
    }

    @Override
    public void onHiddenChanged(boolean hidden) {
        super.onHiddenChanged(hidden);
        if (mSession == null) {
            return;
        }
        if (hidden) {
            mSession.detachSurface();
            mSession.setFrameListener(null);
            // 关键：raw 帧监听必须保留。瞄准闭环（AimController.onDetections）就挂在它上面，
            // 之前切到别的 Tab 会把监听摘掉 → 状态显示"瞄准中"但一条 AIM 都发不出去。
            if (mAimRectView != null) {
                mAimRectView.setEditable(false);
            }
            mEditingRect = false;
        } else {
            mSession.setFrameListener(this);
            mSession.setRawFrameListener(this);
            reloadDetectorIfNeeded();
            SurfaceHolder holder = mSurface.getHolder();
            if (holder.getSurface() != null && holder.getSurface().isValid()) {
                mSession.attachSurface(holder);
            }
        }
    }

    // ------------------------------------------------------------------ aim overlay

    private void bindAimOverlay(View view) {
        mAimConfig = AimConfig.load(requireContext());
        mAim = AimController.get(requireContext());
        mAimRectView = view.findViewById(R.id.aim_rect);
        mAimRectView.setEditable(false);
        // Without a frame yet (card still locking its HDMI receiver) assume the usual 1080p so
        // the box is visible and can be placed before the picture comes back.
        mAimRectView.setFrame(1920, 1080);
        mAimRectView.setAimRect(mAimConfig.rect());
        mAimRectView.setListener(rect -> {
            mAimConfig.rect(rect);
            mAimConfig.save();
            mAimRectView.setAimRect(rect);
        });
        mAim.setOverlaySink((aiming, left, top, right, bottom, predictedX, predictedY) -> {
            if (mOverlay == null) {
                return;
            }
            boolean hasTarget = right > left && bottom > top;
            mOverlay.post(() -> mOverlay.setAimTarget(aiming, hasTarget, left, top, right, bottom,
                    predictedX, predictedY, mAimConfig.showPredicted()));
        });
    }

    /** 配置变化（含从横屏校准页保存返回）→ 立刻刷新叠加框。 */
    @Override
    public void onAimConfigChanged(AimConfig config) {
        if (mAimRectView == null || mEditingRect) {
            return;
        }
        mAimRectView.setAimRect(config.rect());
    }

    /** Called from the aim tab: show the handles on the live picture. */
    public void beginEditAimRect() {
        if (mAimRectView == null) {
            return;
        }
        mAimRectView.setFrame(mFrameW > 0 ? mFrameW : 1920, mFrameH > 0 ? mFrameH : 1080);
        mAimRectView.setAimRect(mAimConfig.rect());
        mAimRectView.setEditable(true);
        mEditingRect = true;
        toast("拖动/拉伸橙色框，切到其它页即结束编辑");
    }

    // ------------------------------------------------------------------ SurfaceHolder

    @Override
    public void surfaceCreated(@NonNull SurfaceHolder holder) {
        if (!isHidden()) {
            mSession.attachSurface(holder);
        }
    }

    @Override
    public void surfaceChanged(@NonNull SurfaceHolder holder, int format, int width, int height) {
        // libuvc renders straight into the Surface; nothing to resize here
    }

    // ------------------------------------------------------------------ ROI editor

    private void bindRoiEditor(View view) {
        mRoiPicker = view.findViewById(R.id.roi_picker);
        mApplyRoi = view.findViewById(R.id.apply_roi);
        mCaptureButtons = new MaterialButton[]{
                view.findViewById(R.id.cap_2k60),
                view.findViewById(R.id.cap_2k30),
                view.findViewById(R.id.cap_1080_60),
                view.findViewById(R.id.cap_1080_30)};
        for (int i = 0; i < mCaptureButtons.length; i++) {
            final int index = i;
            mCaptureButtons[i].setOnClickListener(v -> {
                int[] mode = UvcSession.CAPTURE_MODES[index];
                int[] current = mSession.captureMode();
                if (current[0] == mode[0] && current[1] == mode[1] && current[2] == mode[2]) {
                    toast(R.string.cap_unchanged);
                    return;
                }
                // The UVC interval only takes effect when the stream is opened, and this card
                // will not stream again after an in-process close, so the choice is stored and
                // applied on the next cold start.
                mSession.setCaptureMode(mode[0], mode[1], mode[2]);
                toast(getString(R.string.cap_restart_required,
                        mode[0] + "×" + mode[1], mode[2]));
            });
        }
        mRoiButtons = new MaterialButton[]{
                view.findViewById(R.id.roi_full),
                view.findViewById(R.id.roi_1080),
                view.findViewById(R.id.roi_720),
                view.findViewById(R.id.roi_640)};
        mRoiDraft = mConfig.roi();
        mRoiApplied = mRoiDraft;
        mRoiPicker.setRoi(mRoiDraft);
        mRoiPicker.setListener(roi -> {
            mRoiDraft = roi;
            markRoiDirty();
        });
        for (int i = 0; i < mRoiButtons.length; i++) {
            final int index = i;
            mRoiButtons[i].setOnClickListener(v -> selectRoiSize(index));
        }
        mApplyRoi.setOnClickListener(v -> applyRoi());
        mApplyRoi.setEnabled(false);
        updateRoiChips();
    }

    private void selectRoiSize(int index) {
        int[] sizes = {0, 1080, 720, 640};
        int size = sizes[index];
        mRoiDraft = size == 0
                ? new RoiConfig(false, mRoiDraft.sizePx, mRoiDraft.centerX, mRoiDraft.centerY)
                : new RoiConfig(true, size, mRoiDraft.centerX, mRoiDraft.centerY);
        mRoiPicker.setRoi(mRoiDraft);
        updateRoiChips();
        markRoiDirty();
    }

    /** Grey out the sizes this capture cannot host and highlight the current one. */
    private void updateRoiChips() {
        if (mRoiButtons == null) {
            return;
        }
        int[] sizes = {0, 1080, 720, 640};
        for (int i = 0; i < mRoiButtons.length; i++) {
            MaterialButton button = mRoiButtons[i];
            boolean fits = sizes[i] == 0 || mFrameW <= 0
                    || sizes[i] <= Math.min(mFrameW, mFrameH);
            boolean selected = sizes[i] == 0
                    ? !mRoiDraft.enabled
                    : mRoiDraft.enabled && mRoiDraft.sizePx == sizes[i];
            button.setEnabled(fits);
            button.setAlpha(selected ? 1f : (fits ? 0.6f : 0.25f));
            button.setStrokeWidth(selected ? (int) (2 * getResources().getDisplayMetrics().density) : 0);
        }
    }

    /** Highlights the chip of the mode the camera is actually running. */
    private void updateCaptureChips(int width, int height, int fps) {
        if (mCaptureButtons == null) {
            return;
        }
        for (int i = 0; i < mCaptureButtons.length; i++) {
            int[] mode = UvcSession.CAPTURE_MODES[i];
            boolean selected = mode[0] == width && mode[1] == height && mode[2] == fps;
            mCaptureButtons[i].setAlpha(selected ? 1f : 0.6f);
            mCaptureButtons[i].setStrokeWidth(
                    selected ? (int) (2 * getResources().getDisplayMetrics().density) : 0);
        }
    }

    @Override
    public void onCaptureMode(int width, int height, int fps, boolean ok) {
        updateCaptureChips(width, height, fps);
        if (ok) {
            toast(getString(R.string.cap_switched, width + "×" + height, fps));
        } else {
            toast(getString(R.string.cap_failed, width + "×" + height));
        }
    }

    private void markRoiDirty() {
        if (mApplyRoi != null) {
            mApplyRoi.setEnabled(!mRoiDraft.equals(mRoiApplied));
        }
        updateRoiChips();
    }

    /** Commits the crop; inference starts using it on the next frame, no session rebuild. */
    private void applyRoi() {
        RoiConfig draft = mRoiDraft;
        if (draft.equals(mRoiApplied)) {
            toast(R.string.roi_unchanged);
            return;
        }
        if (draft.enabled && mFrameW > 0 && !draft.fits(mFrameW, mFrameH)) {
            toast(R.string.roi_too_small);
        }
        mConfig.roi(draft);
        mConfig.persist();
        mRoiApplied = draft;
        mRoiPicker.setRoi(draft);
        YoloDetector detector = mDetector;
        if (detector != null) {
            detector.setRoi(draft);
        }
        mApplyRoi.setEnabled(false);
        updateRoiChips();
        toast(getString(R.string.roi_applied,
                draft.enabled ? draft.sizePx + "²" : "全屏"));
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

    @Override
    public void surfaceDestroyed(@NonNull SurfaceHolder holder) {
        mSession.detachSurface();
    }

    // ------------------------------------------------------------------ frame pipeline

    @Override
    public void onFrame(long timestampNanos, int width, int height) {
        if (mNoSignalShown) {
            mNoSignalShown = false;
            mHandler.post(() -> mDetail.setText(mBaseDetail));
        }
        if (mDetector != null) {
            return; // real detector runs from onFrame(ByteBuffer...)
        }
        long detectStart = SystemClock.elapsedRealtimeNanos();
        mFrameIndex++;
        List<Detection> boxes = mDummy.detect(mFrameIndex, mConfig);
        long detectEnd = SystemClock.elapsedRealtimeNanos();

        double inferMs = (detectEnd - detectStart) / 1_000_000.0;
        double latencyMs = (detectEnd - timestampNanos) / 1_000_000.0;
        PipelineStats stats = PipelineStats.get();
        stats.setInferMs(inferMs);
        stats.setLatencyMs(latencyMs);
        stats.publish();

        long nowMs = SystemClock.elapsedRealtime();
        if (nowMs - mLastOverlayMs < OVERLAY_INTERVAL_MS) {
            return;
        }
        mLastOverlayMs = nowMs;

        final String line = String.format(Locale.US, "%.1f fps  ·  %.2f ms  ·  %.0f ms",
                stats.captureFps(), inferMs, latencyMs);
        mOverlay.post(() -> mOverlay.setDetections(boxes, line));
    }

    @Override
    public void onFrame(ByteBuffer rgbx, long timestampNanos, int width, int height) {
        if (width <= 0 || height <= 0) {
            return;
        }
        if (width != mFrameW || height != mFrameH) {
            mFrameW = width;
            mFrameH = height;
            mHandler.post(() -> {
                mRoiPicker.setFrame(width, height);
                if (mAimRectView != null) {
                    mAimRectView.setFrame(width, height);
                }
                updateRoiChips();
            });
        }
        // 准心校准页要一张冻结帧：在这里截，检测忙/无模型时也能取到。
        if (FrameSnapshot.isRequested()) {
            Bitmap snap = FrameSnapshot.fromRgbx(rgbx, width, height);
            if (snap != null) {
                FrameSnapshot.deliver(snap, width, height);
            }
        }
        if (mDetector == null || mInferBusy) {
            return; // a frame is already in flight: drop this one, keep the stream fast
        }
        // 省电：既不在预览页、也没在瞄准时，把检测降到 ~15 fps（60 fps 推理白烧电和温度）
        if (isHidden() && !mAim.isAiming()) {
            long nowMs = android.os.SystemClock.elapsedRealtime();
            if (nowMs - mLastIdleDetectMs < 66L) {
                return;
            }
            mLastIdleDetectMs = nowMs;
        }
        // Letterbox straight out of the UVC buffer on the capture thread: nothing to copy,
        // and the frame being processed is always the newest one.
        long preStart = System.nanoTime();
        try {
            mDetector.prepare(rgbx, width, height);
        } catch (Throwable t) {
            return;
        }
        final double preMs = (System.nanoTime() - preStart) / 1e6;
        mInferBusy = true;
        final int w = width;
        final int h = height;
        final long ts = timestampNanos;
        mInferExec.execute(() -> {
            try {
                YoloDetector.Result result = mDetector.run(w, h);
                // The aim loop only ever sees the newest frame: no queue, no staleness.
                mAim.onDetections(result.detections, w, h, ts);
                double inferMs = preMs + result.runMs + result.decodeMs;
                double latencyMs = (SystemClock.elapsedRealtimeNanos() - ts) / 1_000_000.0;

                PipelineStats stats = PipelineStats.get();
                stats.setInferMs(inferMs);
                stats.setLatencyMs(latencyMs);
                stats.setStages(0, preMs, result.runMs, result.decodeMs);
                stats.publish();

                long nowMs = SystemClock.elapsedRealtime();
                logStages(stats, nowMs);
                if (nowMs - mLastOverlayMs < OVERLAY_INTERVAL_MS) {
                    return;
                }
                mLastOverlayMs = nowMs;

                final String line = String.format(Locale.US,
                        "%.0ffps · p%.1f r%.1f d%.1f · %.0fms",
                        stats.captureFps(), preMs, result.runMs, result.decodeMs, latencyMs);
                final List<Detection> boxes = result.detections;
                mOverlay.post(() -> mOverlay.setDetections(boxes, line));
            } finally {
                mInferBusy = false;
            }
        });
    }

    /** One compact line per second, so the stage split is visible in logcat without atrace. */
    private void logStages(PipelineStats stats, long nowMs) {
        if (nowMs - mLastStageLogMs < 1000L) {
            return;
        }
        mLastStageLogMs = nowMs;
        String line = String.format(Locale.US,
                "stages fps=%.1f copy=%.2f pre=%.2f run=%.2f post=%.2f latency=%.1f "
                        + "conf=%.2f iou=%.2f max=%d backend=%s",
                stats.captureFps(), stats.copyMs(), stats.preMs(), stats.runMs(), stats.postMs(),
                stats.latencyMs(), mConfig.conf(), mConfig.iou(), mConfig.maxDet(), mBackend);
        Log.i(TAG, line);
        // logcat is not always readable on a vendor build, so keep a file copy as well.
        android.content.Context context = getContext();
        if (context != null) {
            java.io.File file = new java.io.File(context.getCacheDir(), "stages.log");
            if (file.length() > 256 * 1024) {
                //noinspection ResultOfMethodCallIgnored
                file.delete();
            }
            try (java.io.FileWriter writer = new java.io.FileWriter(file, true)) {
                writer.write(line + System.lineSeparator());
            } catch (Throwable ignored) {
                // diagnostics only
            }
        }
    }

    // ------------------------------------------------------------------ UvcSession.Listener

    @Override
    public void onStatus(String status, String detail) {
        mBaseDetail = detail;
        mStatus.setText(status);
        mDetail.setText(detail);
        mNoSignalShown = false;
        mHandler.removeCallbacks(mNoSignalCheck);
        if (status != null && status.startsWith("预览已启动")) {
            mHandler.postDelayed(mNoSignalCheck, 3000L);
        }
    }

    /**
     * The card can be open and streaming yet deliver nothing (dead HDMI link, HDCP,
     * stuck capture chip). Say so instead of leaving a silently black rectangle.
     */
    private final Runnable mNoSignalCheck = new Runnable() {
        @Override
        public void run() {
            if (!isAdded() || mSession == null || !mSession.isCameraOpen()) {
                return;
            }
            if (PipelineStats.get().captureFps() >= 0.5) {
                return;
            }
            CharSequence current = mDetail.getText();
            String warning = "⚠ 采集卡 0 fps：没有收到画面\n"
                    + "如果刚退出过 App，重新插拔一次 HDMI 线即可恢复\n"
                    + "（这张卡只有物理热插拔才能重新锁定 HDMI 信号）";
            if (current != null && current.toString().contains("0 fps")) {
                return;
            }
            mNoSignalShown = true;
            mDetail.setText((current == null ? "" : current + "\n") + warning);
        }
    };

    @Override
    public void onPreviewInfo(String device, String mode) {
        mDevice.setText(device);
        mMode.setText(mode);
    }

    // ------------------------------------------------------------------ YoloConfig.Listener

    @Override
    public void onConfigChanged(YoloConfig config) {
        // Each fragment loads its own YoloConfig; adopt the notifying instance so the values
        // read here (and in the stage log) are the ones just committed by "应用".
        mConfig = config;
        if (!config.drawBoxes()) {
            mOverlay.post(() -> mOverlay.setDetections(null, ""));
        }
        YoloDetector detector = mDetector;
        if (detector != null) {
            detector.setThresholds(config.conf(), config.iou(), config.maxDet());
        }
    }

    /** Identifies the class list the running detector was built with. */
    private int labelsHash(ModelProfile profile) {
        if (profile != null) {
            return profile.labels.hashCode();
        }
        List<String> custom = ModelStore.parseLabels(mConfig.builtinLabels());
        return (custom.isEmpty() ? java.util.Arrays.asList(ModelStore.COCO_LABELS) : custom)
                .hashCode();
    }

    /**
     * Rebuilds the detector when the model or the class list changed (the YOLO tab
     * bumps a revision on "应用"). Runs off the UI thread because ONNX Runtime
     * benchmarks every execution provider during construction.
     */
    private void reloadDetectorIfNeeded() {
        if (mInferExec == null || !isAdded()) {
            return;
        }
        ModelStore store = new ModelStore(requireContext());
        ModelProfile profile = store.current();
        String id = profile == null ? "builtin" : profile.id;
        long revision = store.revision();
        if (revision == mAppliedRevision && id.equals(mAppliedModelId)) {
            return;
        }
        mAppliedRevision = revision;

        int labelsHash = labelsHash(profile);
        if (mDetector != null && id.equals(mAppliedModelId)
                && labelsHash == mAppliedLabelsHash) {
            // Only the thresholds changed: recompiling the QNN graph for that would cost
            // hundreds of milliseconds, and the decoders read them per frame anyway.
            mDetector.setThresholds(mConfig.conf(), mConfig.iou(), mConfig.maxDet());
            return;
        }
        mAppliedModelId = id;
        mAppliedLabelsHash = labelsHash;

        final android.content.Context appContext = requireContext().getApplicationContext();
        final byte[] modelBytes;
        final String[] labels;
        try {
            if (profile != null) {
                modelBytes = readAll(new File(profile.filePath));
                labels = profile.labels.toArray(new String[0]);
            } else {
                modelBytes = readAsset(ModelStore.BUILTIN_ASSET);
                List<String> custom = ModelStore.parseLabels(mConfig.builtinLabels());
                labels = custom.isEmpty()
                        ? ModelStore.COCO_LABELS : custom.toArray(new String[0]);
            }
        } catch (Throwable t) {
            Log.e(TAG, "cannot read model", t);
            mHandler.post(() -> mDetail.setText("模型读取失败：" + t));
            return;
        }

        mStatus.setText("加载模型…");
        try {
            // Build on the calling thread: creating an ORT session while another
            // session is executing on the capture thread has crashed the process.
            YoloDetector detector = new YoloDetector(appContext, modelBytes, labels);
            detector.setThresholds(mConfig.conf(), mConfig.iou(), mConfig.maxDet());
            detector.setRoi(mRoiApplied);
            YoloDetector old = mDetector;
            mDetector = detector;
            mBackend = detector.backend();
            PipelineStats.get().setBackend(mBackend);
            mDetail.setText("detector: " + mBackend);
            if (old != null) {
                // close on the inference thread so it cannot race an in-flight run
                mInferExec.execute(old::close);
            }
        } catch (Throwable t) {
            Log.e(TAG, "detector init failed", t);
            mDetector = null;
            mBackend = "dummy";
            mDetail.setText("模型加载失败：" + t);
        }
    }

    private static byte[] readAll(File file) throws Exception {        try (FileInputStream in = new FileInputStream(file)) {
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            byte[] buf = new byte[256 * 1024];
            int n;
            while ((n = in.read(buf)) > 0) {
                out.write(buf, 0, n);
            }
            return out.toByteArray();
        }
    }

    private byte[] readAsset(String name) throws Exception {
        try (InputStream in = requireContext().getAssets().open(name)) {
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            byte[] buf = new byte[256 * 1024];
            int n;
            while ((n = in.read(buf)) > 0) {
                out.write(buf, 0, n);
            }
            return out.toByteArray();
        }
    }
}
