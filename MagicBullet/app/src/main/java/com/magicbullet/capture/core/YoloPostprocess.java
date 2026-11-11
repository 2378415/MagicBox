package com.magicbullet.capture.core;

import java.nio.Buffer;

/**
 * Native decode + NMS for the single-tensor heads (YOLOv8/v11 and end-to-end).
 *
 * <p>The Java reference in {@link com.magicbullet.capture.core.post.Postprocess} allocates one
 * candidate per anchor and runs an O(n^2) suppression. For a 8400-anchor head that dominated the
 * frame budget, so the same maths lives here: candidates go into one reused vector, the survivors
 * are compared only against the boxes already kept, and at most {@code maxDet} boxes come back as
 * a flat {@code {x1, y1, x2, y2, score, class}} array.
 *
 * <p>Two entry points per head: a zero-copy one for a direct buffer, and a flat-array one for the
 * heap-backed buffers ONNX Runtime hands out for QNN EP outputs. Every call returns -1 when it
 * cannot run, which makes the caller fall back to the Java path.
 */
public final class YoloPostprocess {

    /** Upper bound of boxes one call can return; must match {@code kMaxKept} in postprocess.cpp. */
    public static final int MAX_BOXES = 512;
    public static final int STRIDE = 6;

    private static final boolean NATIVE_OK;
    private static final String LOAD_ERROR;

    static {
        String error = null;
        try {
            System.loadLibrary("mbpre");
        } catch (Throwable t) {
            error = String.valueOf(t);
        }
        LOAD_ERROR = error;
        NATIVE_OK = error == null;
    }

    private YoloPostprocess() {
    }

    public static boolean available() {
        return NATIVE_OK;
    }

    /** Why the native library refused to load, or null when it did. */
    public static String loadError() {
        return LOAD_ERROR;
    }

    static native int decodeV8(Buffer src, int numClasses, int anchors,
                               float conf, float iou, int maxDetections,
                               float scale, float padX, float padY,
                               int roiX, int roiY, int frameW, int frameH,
                               float[] out);

    static native int decodeE2E(Buffer src, int stride, int rows,
                                float conf, float iou, int maxDetections,
                                float scale, float padX, float padY,
                                int roiX, int roiY, int frameW, int frameH,
                                float[] out);

    static native int decodeV8Flat(float[] src, int srcOffset, int numClasses, int anchors,
                                   float conf, float iou, int maxDetections,
                                   float scale, float padX, float padY,
                                   int roiX, int roiY, int frameW, int frameH,
                                   float[] out);

    static native int decodeE2EFlat(float[] src, int srcOffset, int stride, int rows,
                                    float conf, float iou, int maxDetections,
                                    float scale, float padX, float padY,
                                    int roiX, int roiY, int frameW, int frameH,
                                    float[] out);
}
