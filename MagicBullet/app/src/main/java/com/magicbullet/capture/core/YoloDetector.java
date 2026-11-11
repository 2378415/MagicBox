package com.magicbullet.capture.core;

import android.content.Context;
import android.os.Build;
import android.util.Log;

import org.json.JSONArray;
import org.json.JSONObject;

import com.magicbullet.capture.core.post.Geometry;
import com.magicbullet.capture.core.post.Postprocess;

import java.io.File;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import java.security.MessageDigest;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import ai.onnxruntime.NodeInfo;
import ai.onnxruntime.OnnxTensor;
import ai.onnxruntime.OrtEnvironment;
import ai.onnxruntime.OrtSession;
import ai.onnxruntime.TensorInfo;

/**
 * YOLO detector on ONNX Runtime with runtime-derived shapes.
 *
 * <p>Input size, class count and anchor count come from the model itself, so any
 * detection model with a YOLOv8-style head works without recompiling. InsightFace
 * SCRFD face heads (per-stride score/box/landmark tensors) are decoded too.
 *
 * <p>Execution providers are benchmarked at start-up and the fastest one is kept,
 * because ORT silently falls back to CPU inside a QNN session whose device could not
 * be created.
 */
public final class YoloDetector {

    private static final String TAG = "YoloDetector";
    private static final float CONF_THRESHOLD = 0.30f;
    private static final float NMS_IOU = 0.45f;
    private static final int MAX_DETECTIONS = 30;
    /** A QNN session faster than this is running on the NPU, not on a CPU fallback. */
    private static final double QNN_HTP_MS = 50;
    /** Bump when the bundled QNN runtime changes: old context blobs cannot be loaded. */

    /** One SCRFD stride level: three tensors sharing the same row count. */
    static final class StrideHead {
        final int stride;
        final int grid;
        final int anchors;
        final int rows;
        final String scoreName;
        final String bboxName;
        final String kpsName;

        StrideHead(int stride, int grid, int anchors, int rows,
                   String scoreName, String bboxName, String kpsName) {
            this.stride = stride;
            this.grid = grid;
            this.anchors = anchors;
            this.rows = rows;
            this.scoreName = scoreName;
            this.bboxName = bboxName;
            this.kpsName = kpsName;
        }
    }

    /** Shapes read straight out of the model. */
    public static final class ShapeInfo {
        public final int inputSize;
        public final int numClasses;
        public final int anchors;
        public final int layout;
        /** Per-stride output tensors, only for {@link ModelProfile#LAYOUT_SCRFD}. */
        final List<StrideHead> heads;

        ShapeInfo(int inputSize, int numClasses, int anchors, int layout) {
            this(inputSize, numClasses, anchors, layout, null);
        }

        ShapeInfo(int inputSize, int numClasses, int anchors, int layout,
                  List<StrideHead> heads) {
            this.inputSize = inputSize;
            this.numClasses = numClasses;
            this.anchors = anchors;
            this.layout = layout;
            this.heads = heads;
        }

        public String describe() {
            if (layout == ModelProfile.LAYOUT_SCRFD) {
                return "input " + inputSize + "x" + inputSize
                        + " · SCRFD " + (heads == null ? 0 : heads.size()) + " levels"
                        + " · " + anchors + " anchors";
            }
            return "input " + inputSize + "x" + inputSize
                    + " · " + numClasses + " 类 · " + anchors + " anchors"
                    + (layout == ModelProfile.LAYOUT_E2E ? " · e2e" : "");
        }
    }

    public static final class Result {
        public final List<Detection> detections;
        /** The ONNX Runtime run itself. */
        public final double runMs;
        /** Decode + NMS. */
        public final double decodeMs;
        public final String backend;

        Result(List<Detection> detections, double runMs, double decodeMs, String backend) {
            this.detections = detections;
            this.runMs = runMs;
            this.decodeMs = decodeMs;
            this.backend = backend;
        }
    }

    private final OrtEnvironment mEnv;
    private final OrtSession mSession;
    private final String mInputName;
    private final String mBackend;
    private final int mInputSize;
    private final int mNumClasses;
    private final int mAnchors;
    private final int mLayout;
    private final String[] mLabels;
    private final List<StrideHead> mHeads;
    private final QnnRuntime mQnn;
    private final QnnContextCache mContextCache;
    private volatile float mConfThreshold = CONF_THRESHOLD;
    private volatile float mNmsIou = NMS_IOU;
    private volatile int mMaxDetections = MAX_DETECTIONS;
    private final ByteBuffer mInputDirect;
    private final FloatBuffer mInputBuffer;
    private final int[] mSrcX;
    private final int[] mSrcRow;
    private int mSrcWidth = -1;
    private int mSrcHeight = -1;
    private int mScaledW;
    private int mPadW = -1;
    private int mPadH = -1;
    private volatile RoiConfig mRoiConfig = RoiConfig.FULL;
    /** Reused output of the native decoder: {@code MAX_BOXES} boxes of six floats. */
    private final float[] mPostOut = new float[YoloPostprocess.MAX_BOXES * YoloPostprocess.STRIDE];
    /** Reused staging copy for heap-backed output tensors (QNN EP). */
    private float[] mPostIn;
    private boolean mPostVerified;
    private final double[] mTiming = new double[5];
    private int mTimingFrames;
    /** adb``setprop debug.mb.postjava 1`` falls back to the Java decoder, for A/B timing. */
    private static final boolean FORCE_JAVA_POST = systemFlag("debug.mb.postjava");
    private final File mCacheDir;
    private int mRoiX;
    private int mRoiY;
    private int mRoiW = 1;
    private int mRoiH = 1;
    private int mRoiFrameW = -1;
    private int mRoiFrameH = -1;
    private int mSrcRoiX = -1;
    private int mSrcRoiY = -1;
    private int mScaledH;

    /** Reads shapes with a throw-away CPU session (used when importing a file). */
    public static ShapeInfo inspect(byte[] model) throws Exception {
        OrtEnvironment env = OrtEnvironment.getEnvironment();
        OrtSession.SessionOptions options = new OrtSession.SessionOptions();
        options.setOptimizationLevel(OrtSession.SessionOptions.OptLevel.ALL_OPT);
        try (OrtSession session = env.createSession(model, options)) {
            return shapesOf(session);
        }
    }

    private static ShapeInfo shapesOf(OrtSession session) throws Exception {
        TensorInfo in = (TensorInfo) session.getInputInfo()
                .values().iterator().next().getInfo();
        long[] inShape = in.getShape();
        int inputSize = inShape.length == 4 ? (int) inShape[2] : 640;

        if (session.getOutputInfo().size() != 1) {
            // per-stride heads export one tensor per level and kind, e.g. SCRFD
            ShapeInfo scrfd = scrfd(inputSize, session.getOutputInfo());
            return scrfd != null
                    ? scrfd : new ShapeInfo(inputSize, 0, 0, ModelProfile.LAYOUT_UNKNOWN);
        }
        TensorInfo out = (TensorInfo) session.getOutputInfo()
                .values().iterator().next().getInfo();
        long[] o = out.getShape();
        int numClasses = 0;
        int anchors = 0;
        int layout = ModelProfile.LAYOUT_V8;
        if (o.length != 3) {
            return new ShapeInfo(inputSize, 0, 0, ModelProfile.LAYOUT_UNKNOWN);
        }
        if (o.length == 3) {
            if (o[2] == 6 || o[2] == 7) {
                layout = ModelProfile.LAYOUT_E2E;
                anchors = (int) o[1];
                numClasses = 0;
            } else {
                numClasses = (int) o[1] - 4;
                anchors = (int) o[2];
            }
        }
        return new ShapeInfo(inputSize, numClasses, anchors, layout);
    }

    /**
     * Recognises an InsightFace SCRFD face head. Such a graph has three tensors per
     * stride (score [N,1], box [N,4], landmarks [N,10]) instead of one, all keyed by
     * their row count N. Returns null when the graph is something else.
     */
    private static ShapeInfo scrfd(int inputSize, Map<String, NodeInfo> outputs) {
        if (inputSize <= 0) {
            return null;
        }
        Map<Integer, String> scores = new HashMap<>();
        Map<Integer, String> boxes = new HashMap<>();
        Map<Integer, String> kps = new HashMap<>();
        for (Map.Entry<String, NodeInfo> entry : outputs.entrySet()) {
            long[] s = ((TensorInfo) entry.getValue().getInfo()).getShape();
            if (s.length != 2 || s[0] <= 0 || s[1] <= 0) {
                return null;
            }
            int rows = (int) s[0];
            int cols = (int) s[1];
            if (cols == 1) {
                scores.put(rows, entry.getKey());
            } else if (cols == 4) {
                boxes.put(rows, entry.getKey());
            } else if (cols == 10) {
                kps.put(rows, entry.getKey());
            } else {
                return null; // segmentation / pose / anything with extra columns
            }
        }
        if (scores.isEmpty() || !scores.keySet().equals(boxes.keySet())) {
            return null;
        }

        List<Integer> levels = new ArrayList<>(scores.keySet());
        Collections.sort(levels, Collections.reverseOrder());

        List<StrideHead> heads = new ArrayList<>();
        int previous = 0;
        int total = 0;
        for (int rows : levels) {
            int stride = 0;
            int grid = 0;
            int anchors = 0;
            // the level with the most rows is the finest stride, so walk upwards
            for (int candidate = 8; candidate <= 64; candidate *= 2) {
                if (candidate <= previous || inputSize % candidate != 0) {
                    continue;
                }
                int g = inputSize / candidate;
                if (rows % (g * g) != 0) {
                    continue;
                }
                int a = rows / (g * g);
                if (a >= 1 && a <= 4) {
                    stride = candidate;
                    grid = g;
                    anchors = a;
                    break;
                }
            }
            if (stride == 0) {
                return null;
            }
            previous = stride;
            heads.add(new StrideHead(stride, grid, anchors, rows,
                    scores.get(rows), boxes.get(rows), kps.get(rows)));
            total += rows;
        }
        if (!kps.isEmpty() && kps.size() != scores.size()) {
            return null;
        }
        return new ShapeInfo(inputSize, 1, total, ModelProfile.LAYOUT_SCRFD, heads);
    }

    public YoloDetector(Context context, byte[] model, String[] labels) throws Exception {
        mEnv = OrtEnvironment.getEnvironment();
        mLabels = labels;
        mQnn = new QnnRuntime(context);
        mContextCache = new QnnContextCache(context.getCacheDir());
        mCacheDir = context.getCacheDir();
        mQnn.prepareEnvironment();

        // QNN compiles the graph on the DSP at session creation. The first session for a
        // model dumps that compiled context to the cache dir, keyed by the model hash, and
        // later runs load that context model instead of recompiling.
        File qnnContext = mContextCache.fileFor(model, mQnn.fingerprint());
        boolean qnnContextHit = false;
        byte[] qnnModel = model;
        if (qnnContext != null && qnnContext.isFile()) {
            try {
                qnnModel = QnnRuntime.readAll(qnnContext);
                qnnContextHit = true;
            } catch (Throwable t) {
                Log.w(TAG, "cannot read QNN context, recompiling: " + t);
                qnnContext.delete();
            }
        }

        // QNN first: the HTP backend, its stub and the DSP skels ship in jniLibs, so ONNX
        // Runtime finds libQnnHtp.so in the app's native library directory. CPU mode stays
        // as the fallback for devices or sessions where the DSP is unavailable.
        // The first QNN session also writes a one-shot ORT profile so we can see which
        // provider every node landed on (a silent CPU fallback inside QNN shows up here).
        File profileFile = new File(context.getCacheDir(), "ort_qnn_profile.json");
        List<String> names = new ArrayList<>();
        names.add("QNN");
        names.add("CPU");
        OrtSession bestSession = null;
        String bestName = "CPU";
        double bestMs = Double.MAX_VALUE;
        double cpuMs = -1;

        for (int i = 0; i < names.size(); i++) {
            OrtSession session = null;
            try {
                OrtSession.SessionOptions options;
                byte[] bytes = model;
                if (i == 0) {
                    // A cached context is a model of its own; only a cache miss asks ORT
                    // to write one, because passing an existing path makes it refuse.
                    bytes = qnnModel;
                    options = mQnn.sessionOptions(qnnContextHit ? null : qnnContext,
                            profileFile);
                } else {
                    options = baseOptions();
                }
                long initStart = System.nanoTime();
                session = mEnv.createSession(bytes, options);
                Log.i(TAG, names.get(i) + " session " + String.format(Locale.US, "%.0f",
                        (System.nanoTime() - initStart) / 1e6) + " ms"
                        + (i == 0 && qnnContextHit ? " (ctx cache)" : ""));
                double ms = bench(session);
                Log.i(TAG, names.get(i) + " -> " + String.format(Locale.US, "%.1f", ms) + " ms");
                if (i == 0) {
                    QnnRuntime.logProfile(session, profileFile);
                }
                if ("CPU".equals(names.get(i))) {
                    cpuMs = ms;
                }
                if (ms < bestMs) {
                    if (bestSession != null) {
                        bestSession.close();
                    }
                    bestMs = ms;
                    bestSession = session;
                    bestName = names.get(i);
                    session = null;
                }
                if (i == 0 && bestMs < QNN_HTP_MS) {
                    // The DSP answered in HTP territory: skip the CPU baseline, which
                    // would otherwise cost another few hundred milliseconds per load.
                    break;
                }
            } catch (Throwable t) {
                Log.w(TAG, names.get(i) + " unavailable: " + t);
            } finally {
                if (session != null) {
                    try {
                        session.close();
                    } catch (Throwable ignored) {
                        // nothing to do
                    }
                }
            }
        }

        if (bestSession == null) {
            throw new IllegalStateException("no ORT session could be created");
        }
        if (!"CPU".equals(bestName) && cpuMs > 0 && bestMs > cpuMs * 0.85) {
            bestName = "CPU(QNN unavailable)";
            bestMs = cpuMs;
        }
        // A context that cannot be loaded leaves the session on the CPU: drop it so the
        // next start recompiles instead of loading the same broken blob forever.
        if (!"QNN".equals(bestName) && qnnContext != null && qnnContext.isFile()) {
            Log.w(TAG, "dropping QNN context cache after fallback: " + qnnContext);
            qnnContext.delete();
            qnnContextHit = false;
        }

        mSession = bestSession;
        mInputName = mSession.getInputNames().iterator().next();
        ShapeInfo shape = shapesOf(mSession);
        if (shape.layout == ModelProfile.LAYOUT_UNKNOWN) {
            throw new IllegalStateException(
                    "不支持该模型输出（分割/姿态/分类/多输出），需要单输出检测头或 SCRFD 人脸头");
        }
        mInputSize = shape.inputSize;
        mLayout = shape.layout;
        mAnchors = shape.anchors;
        mHeads = shape.heads;
        mNumClasses = shape.layout == ModelProfile.LAYOUT_E2E
                ? Math.max(1, labels.length) : shape.numClasses;
        mInputDirect = ByteBuffer.allocateDirect(4 * 3 * mInputSize * mInputSize)
                .order(ByteOrder.nativeOrder());
        mInputBuffer = mInputDirect.asFloatBuffer();
        mSrcX = new int[mInputSize];
        mSrcRow = new int[mInputSize];
        mBackend = bestName + " " + String.format(Locale.US, "%.0fms", bestMs)
                + (qnnContextHit ? " (ctx)" : "");
        Log.i(TAG, "session ready backend=" + mBackend + " " + shape.describe());
        Log.i(TAG, "preprocess native=" + YoloPreprocess.isNative());
        QnnRuntime.writeText(new File(context.getCacheDir(), "pre_native.txt"),
                YoloPreprocess.isNative() + " " + YoloPreprocess.loadError);
    }

    public void close() {
        try {
            mSession.close();
        } catch (Throwable ignored) {
            // already closed
        }
    }

    /**
     * Confidence, IoU and detection cap are post-processing only: changing them takes effect on
     * the next frame without rebuilding the session (a QNN rebuild costs ~100 ms at best).
     */
    public void setThresholds(float conf, float iou, int maxDetections) {
        mConfThreshold = conf > 0f ? conf : CONF_THRESHOLD;
        mNmsIou = iou > 0f ? iou : NMS_IOU;
        mMaxDetections = Math.max(1, maxDetections);
        Log.i(TAG, String.format(Locale.US, "thresholds conf=%.2f iou=%.2f max=%d",
                mConfThreshold, mNmsIou, mMaxDetections));
    }
    public String backend() {
        return mBackend;
    }

    private OrtSession.SessionOptions baseOptions() throws Exception {
        OrtSession.SessionOptions options = new OrtSession.SessionOptions();
        options.setIntraOpNumThreads(4);
        options.setOptimizationLevel(OrtSession.SessionOptions.OptLevel.ALL_OPT);
        return options;
    }

    private double bench(OrtSession session) throws Exception {
        String input = session.getInputNames().iterator().next();
        TensorInfo info = (TensorInfo) session.getInputInfo().get(input).getInfo();
        long[] shape = info.getShape().clone();
        int count = 1;
        for (long d : shape) {
            count *= (int) Math.max(1, d);
        }
        float[] zeros = new float[count];
        OnnxTensor tensor = OnnxTensor.createTensor(mEnv, FloatBuffer.wrap(zeros), shape);
        session.run(Collections.singletonMap(input, tensor));
        long t0 = System.nanoTime();
        int n = 2;
        for (int i = 0; i < n; i++) {
            session.run(Collections.singletonMap(input, tensor));
        }
        double ms = (System.nanoTime() - t0) / 1e6 / n;
        tensor.close();
        return ms;
    }

    /**
     * Capture-thread half: letterbox the UVC buffer straight into the input tensor, no
     * intermediate copy. Only called while no run is in flight, so the buffer cannot be
     * overwritten mid-inference.
     */
    public void prepare(ByteBuffer rgbx, int width, int height) {
        updateRoi(width, height);
        letterbox(rgbx, width, height);
    }

    /**
     * Crop fed to the model. Only preprocessing and the inverse mapping change, so this takes
     * effect on the next frame without touching the session.
     */
    public void setRoi(RoiConfig roi) {
        mRoiConfig = roi == null ? RoiConfig.FULL : roi;
        mRoiFrameW = -1;
    }

    private void updateRoi(int width, int height) {
        if (width == mRoiFrameW && height == mRoiFrameH) {
            return;
        }
        int[] bounds = mRoiConfig.bounds(width, height);
        mRoiX = bounds[0];
        mRoiY = bounds[1];
        mRoiW = Math.max(1, bounds[2]);
        mRoiH = Math.max(1, bounds[3]);
        mRoiFrameW = width;
        mRoiFrameH = height;
    }

    /** Inference-thread half: run the graph and decode. */
    public Result run(int width, int height) {
        List<Detection> detections;
        long t1 = System.nanoTime();
        long t2 = t1;
        try {
            long[] shape = {1, 3, mInputSize, mInputSize};
            long tInput = System.nanoTime();
            OnnxTensor input = OnnxTensor.createTensor(mEnv, mInputBuffer, shape);
            long tRun = System.nanoTime();
            OrtSession.Result result = mSession.run(Collections.singletonMap(mInputName, input));
            t2 = System.nanoTime();
            mTiming[0] += (tRun - tInput) / 1e6;
            mTiming[1] += (t2 - tRun) / 1e6;
            detections = decode(result, width, height);
            long t3 = System.nanoTime();
            input.close();
            result.close();
            if (++mTimingFrames == 60) {
                String line = String.format(Locale.US,
                        "frames=%d input=%.3f session=%.3f materialize=%.3f decode=%.3f",
                        mTimingFrames, mTiming[0] / 60, mTiming[1] / 60, mTiming[2] / 60,
                        mTiming[3] / 60);
                Log.i(TAG, "ort " + line);
                QnnRuntime.writeText(new File(mCacheDir, "ortspeed.txt"), line + "\n");
            }
            return new Result(detections, (t2 - t1) / 1e6, (t3 - t2) / 1e6, mBackend);
        } catch (Throwable t) {
            Log.e(TAG, "inference failed", t);
            return new Result(new ArrayList<>(), 0, 0, mBackend);
        }
    }

    private List<Detection> decode(OrtSession.Result result, int width, int height)
            throws Exception {
        Geometry geometry = new Geometry(mInputSize, width, height,
                mRoiX, mRoiY, mRoiW, mRoiH);
        if (mLayout == ModelProfile.LAYOUT_SCRFD) {
            List<Postprocess.ScrfdHead> heads = new ArrayList<>(mHeads.size());
            for (StrideHead head : mHeads) {
                heads.add(new Postprocess.ScrfdHead(
                        (float[][]) valueOf(result, head.scoreName),
                        (float[][]) valueOf(result, head.bboxName),
                        head.stride, head.grid, head.anchors, head.rows));
            }
            return Postprocess.scrfd(heads, geometry, mConfThreshold, mNmsIou,
                    mMaxDetections, mLabels);
        }
        int nativeCount = decodeNative(result, geometry, width, height);
        if (nativeCount >= 0) {
            if (!mPostVerified) {
                mPostVerified = true;
                verifyNativeDecode(result, geometry, width, height, nativeCount);
            }
            return toDetections(nativeCount);
        }
        float[][] rows = ((float[][][]) result.get(0).getValue())[0];
        if (mLayout == ModelProfile.LAYOUT_E2E) {
            return Postprocess.endToEnd(rows, mAnchors, geometry, mConfThreshold, mNmsIou,
                    mMaxDetections, mLabels);
        }
        return Postprocess.yoloV8(rows, mNumClasses, mAnchors, geometry, mConfThreshold,
                mNmsIou, mMaxDetections, mLabels);
    }

    /** Native decode straight from the output tensor; -1 means "use the Java path". */
    private int decodeNative(OrtSession.Result result, Geometry geometry, int width, int height) {
        if (!YoloPostprocess.available()) {
            if (!mPostVerified) {
                Log.w(TAG, "native post unavailable: " + YoloPostprocess.loadError());
            }
            return -1;
        }
        try {
            if (!(result.get(0) instanceof OnnxTensor)) {
                return -1;
            }
            OnnxTensor tensor = (OnnxTensor) result.get(0);
            long[] shape = tensor.getInfo().getShape();
            int stride = shape.length > 0 ? (int) shape[shape.length - 1] : 6;
            int maxDet = Math.min(mMaxDetections, YoloPostprocess.MAX_BOXES);
            long tMaterialize = System.nanoTime();
            FloatBuffer buffer = tensor.getFloatBuffer();
            long tDecode = System.nanoTime();
            if (!mPostVerified) {
                Log.i(TAG, "post decode source direct=" + buffer.isDirect()
                        + " hasArray=" + buffer.hasArray());
            }
            if (buffer.isDirect()) {
                if (mLayout == ModelProfile.LAYOUT_E2E) {
                    return YoloPostprocess.decodeE2E(buffer, stride, mAnchors,
                            mConfThreshold, mNmsIou, maxDet,
                            geometry.scale, geometry.padX, geometry.padY,
                            mRoiX, mRoiY, width, height, mPostOut);
                }
                return YoloPostprocess.decodeV8(buffer, mNumClasses, mAnchors,
                        mConfThreshold, mNmsIou, maxDet,
                        geometry.scale, geometry.padX, geometry.padY,
                        mRoiX, mRoiY, width, height, mPostOut);
            }
            // QNN EP hands out a heap buffer. When it wraps an array, pass that array straight
            // through; otherwise copy once into the reused staging buffer.
            float[] source;
            int offset;
            if (buffer.hasArray()) {
                source = buffer.array();
                offset = buffer.arrayOffset();
            } else {
                int total = 1;
                for (long dim : shape) {
                    total *= (int) dim;
                }
                if (total <= 0) {
                    return -1;
                }
                if (mPostIn == null || mPostIn.length < total) {
                    mPostIn = new float[total];
                }
                buffer.get(mPostIn, 0, total);
                source = mPostIn;
                offset = 0;
            }
            int count;
            if (mLayout == ModelProfile.LAYOUT_E2E) {
                count = YoloPostprocess.decodeE2EFlat(source, offset, stride, mAnchors,
                        mConfThreshold, mNmsIou, maxDet,
                        geometry.scale, geometry.padX, geometry.padY,
                        mRoiX, mRoiY, width, height, mPostOut);
            } else {
                count = YoloPostprocess.decodeV8Flat(source, offset, mNumClasses, mAnchors,
                        mConfThreshold, mNmsIou, maxDet,
                        geometry.scale, geometry.padX, geometry.padY,
                        mRoiX, mRoiY, width, height, mPostOut);
            }
            mTiming[2] += (tDecode - tMaterialize) / 1e6;
            mTiming[3] += (System.nanoTime() - tDecode) / 1e6;
            return count;
        } catch (Throwable t) {
            Log.w(TAG, "native decode unavailable: " + t);
            return -1;
        }
    }

    private static boolean systemFlag(String key) {
        try {
            Class<?> properties = Class.forName("android.os.SystemProperties");
            Object value = properties.getMethod("get", String.class).invoke(null, key);
            return "1".equals(value);
        } catch (Throwable t) {
            return false;
        }
    }

    private List<Detection> toDetections(int count) {
        List<Detection> out = new ArrayList<>(count);
        for (int i = 0; i < count; i++) {
            int o = i * YoloPostprocess.STRIDE;
            int cls = (int) mPostOut[o + 5];
            String label = cls >= 0 && cls < mLabels.length ? mLabels[cls] : "class_" + cls;
            out.add(new Detection(mPostOut[o], mPostOut[o + 1], mPostOut[o + 2], mPostOut[o + 3],
                    label, mPostOut[o + 4]));
        }
        return out;
    }

    /**
     * One-shot comparison of the native decoder against the Java reference: counts must match and
     * no coordinate may drift more than a pixel. Written to a file because logcat is unreliable.
     */
    private void verifyNativeDecode(OrtSession.Result result, Geometry geometry,
                                    int width, int height, int nativeCount) {
        try {
            float[][] rows = ((float[][][]) result.get(0).getValue())[0];
            List<Detection> java = mLayout == ModelProfile.LAYOUT_E2E
                    ? Postprocess.endToEnd(rows, mAnchors, geometry, mConfThreshold, mNmsIou,
                    mMaxDetections, mLabels)
                    : Postprocess.yoloV8(rows, mNumClasses, mAnchors, geometry, mConfThreshold,
                    mNmsIou, mMaxDetections, mLabels);
            float worst = 0f;
            int compared = Math.min(java.size(), nativeCount);
            for (int i = 0; i < compared; i++) {
                Detection d = java.get(i);
                int o = i * YoloPostprocess.STRIDE;
                worst = Math.max(worst, Math.abs(d.left - mPostOut[o]));
                worst = Math.max(worst, Math.abs(d.top - mPostOut[o + 1]));
                worst = Math.max(worst, Math.abs(d.right - mPostOut[o + 2]));
                worst = Math.max(worst, Math.abs(d.bottom - mPostOut[o + 3]));
                worst = Math.max(worst, Math.abs(d.score - mPostOut[o + 4]));
            }
            String line = String.format(Locale.US,
                    "native=%d java=%d worstDiff=%.6f layout=%d", nativeCount, java.size(), worst,
                    mLayout);
            Log.i(TAG, "postcheck " + line);
            QnnRuntime.writeText(new File(mCacheDir, "postcheck.txt"), line + "\n");
        } catch (Throwable t) {
            Log.w(TAG, "postcheck failed: " + t);
        }
    }

    private static Object valueOf(OrtSession.Result result, String name) throws Exception {
        return result.get(name).orElseThrow(
                () -> new IllegalStateException("模型缺少输出 " + name)).getValue();
    }

    /** RGBX -> letterboxed CHW float 0..1, native, reading the UVC buffer in place. */
    private void letterbox(ByteBuffer rgbx, int width, int height) {
        // The requested region (whole frame when no crop is active) is fitted into the square
        // model input; the tables below map output pixels back to absolute source pixels.
        float scale = Math.min((float) mInputSize / mRoiW, (float) mInputSize / mRoiH);
        int nw = (int) (mRoiW * scale);
        int nh = (int) (mRoiH * scale);
        if (mSrcWidth != mRoiW || mScaledW != nw || mSrcRoiX != mRoiX) {
            for (int x = 0; x < nw; x++) {
                int sx = mRoiX + (int) (x / scale);
                if (sx >= mRoiX + mRoiW) {
                    sx = mRoiX + mRoiW - 1;
                }
                mSrcX[x] = sx * 4;
            }
            mSrcWidth = mRoiW;
            mScaledW = nw;
            mSrcRoiX = mRoiX;
        }
        if (mSrcHeight != mRoiH || mScaledH != nh || mSrcRoiY != mRoiY) {
            for (int y = 0; y < nh; y++) {
                int sy = mRoiY + (int) (y / scale);
                if (sy >= mRoiY + mRoiH) {
                    sy = mRoiY + mRoiH - 1;
                }
                mSrcRow[y] = sy * width * 4;
            }
            mSrcHeight = mRoiH;
            mScaledH = nh;
            mSrcRoiY = mRoiY;
        }
        boolean fillPad = mPadW != nw || mPadH != nh;
        if (fillPad) {
            mPadW = nw;
            mPadH = nh;
        }
        YoloPreprocess.letterbox(rgbx, mInputSize, nw, nh, mSrcX, mSrcRow, mInputDirect, fillPad);
    }
}