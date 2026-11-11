package com.magicbullet.capture.core.post;

import com.magicbullet.capture.core.Detection;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Turns raw detection tensors into {@link Detection}s.
 *
 * <p>Deliberately free of ONNX Runtime types: the caller reads the tensors and hands over
 * plain arrays, which keeps every model layout unit-testable without a device or a session.
 *
 * <p>The three supported heads:
 * <ul>
 *   <li>YOLOv8/v11: one tensor {@code [1, 4+nc, N]} — centre/size boxes plus per-class scores</li>
 *   <li>end-to-end: one tensor {@code [1, N, 6]} — corners plus score and class, NMS baked in</li>
 *   <li>SCRFD: per-stride score {@code [N,1]} and distance {@code [N,4]} tensors</li>
 * </ul>
 */
public final class Postprocess {

    private Postprocess() {
    }

    /** One SCRFD stride level: the two tensors plus the geometry they were decoded with. */
    public static final class ScrfdHead {
        public final float[][] scores;
        public final float[][] boxes;
        public final int stride;
        public final int grid;
        public final int anchors;
        public final int rows;

        public ScrfdHead(float[][] scores, float[][] boxes, int stride, int grid, int anchors,
                         int rows) {
            this.scores = scores;
            this.boxes = boxes;
            this.stride = stride;
            this.grid = grid;
            this.anchors = anchors;
            this.rows = rows;
        }
    }

    /** {@code [1, N, 6]}: x1, y1, x2, y2, score, class — corners already in input pixels. */
    public static List<Detection> endToEnd(float[][] rows, int maxRows, Geometry geometry,
                                           float confThreshold, float iouThreshold,
                                           int maxDetections, String[] labels) {
        List<float[]> candidates = new ArrayList<>();
        for (int i = 0; i < rows.length && i < maxRows; i++) {
            float[] row = rows[i];
            if (row.length < 6 || row[4] < confThreshold) {
                continue;
            }
            candidates.add(new float[]{
                    geometry.sourceX(row[0]), geometry.sourceY(row[1]),
                    geometry.sourceX(row[2]), geometry.sourceY(row[3]),
                    row[4], row[5]});
        }
        return toDetections(candidates, geometry, iouThreshold, maxDetections, labels);
    }

    /** {@code [1, 4+nc, N]}: centre/size boxes, one score per class. */
    public static List<Detection> yoloV8(float[][] channels, int numClasses, int anchors,
                                         Geometry geometry, float confThreshold,
                                         float iouThreshold, int maxDetections,
                                         String[] labels) {
        List<float[]> candidates = new ArrayList<>();
        for (int i = 0; i < anchors; i++) {
            int best = -1;
            float bestScore = confThreshold;
            for (int c = 0; c < numClasses; c++) {
                float score = channels[4 + c][i];
                if (score > bestScore) {
                    bestScore = score;
                    best = c;
                }
            }
            if (best < 0) {
                continue;
            }
            float cx = channels[0][i];
            float cy = channels[1][i];
            float w = channels[2][i];
            float h = channels[3][i];
            candidates.add(new float[]{
                    geometry.sourceX(cx - w / 2f), geometry.sourceY(cy - h / 2f),
                    geometry.sourceX(cx + w / 2f), geometry.sourceY(cy + h / 2f),
                    bestScore, best});
        }
        return toDetections(candidates, geometry, iouThreshold, maxDetections, labels);
    }

    /**
     * SCRFD: distances are in stride units around the grid cell origin, rows are
     * location-major with the anchors of a cell innermost.
     */
    public static List<Detection> scrfd(List<ScrfdHead> heads, Geometry geometry,
                                        float confThreshold, float iouThreshold,
                                        int maxDetections, String[] labels) {
        List<float[]> candidates = new ArrayList<>();
        for (ScrfdHead head : heads) {
            for (int i = 0; i < head.rows && i < head.scores.length; i++) {
                float score = head.scores[i][0];
                if (score < confThreshold) {
                    continue;
                }
                int location = i / head.anchors;
                float cx = (location % head.grid) * head.stride;
                float cy = (location / head.grid) * head.stride;
                float[] d = head.boxes[i];
                candidates.add(new float[]{
                        geometry.sourceX(cx - d[0] * head.stride),
                        geometry.sourceY(cy - d[1] * head.stride),
                        geometry.sourceX(cx + d[2] * head.stride),
                        geometry.sourceY(cy + d[3] * head.stride),
                        score, 0f});
            }
        }
        return toDetections(candidates, geometry, iouThreshold, maxDetections, labels);
    }

    private static List<Detection> toDetections(List<float[]> candidates, Geometry geometry,
                                                float iouThreshold, int maxDetections,
                                                String[] labels) {
        if (candidates.isEmpty()) {
            return Collections.emptyList();
        }
        List<float[]> kept = Nms.suppress(candidates, iouThreshold, maxDetections);
        List<Detection> out = new ArrayList<>(kept.size());
        for (float[] box : kept) {
            int cls = (int) box[5];
            String label = cls >= 0 && cls < labels.length ? labels[cls] : "class_" + cls;
            out.add(new Detection(
                    clamp(box[0] / geometry.width), clamp(box[1] / geometry.height),
                    clamp(box[2] / geometry.width), clamp(box[3] / geometry.height),
                    label, box[4]));
        }
        return out;
    }

    private static float clamp(float value) {
        return Math.max(0f, Math.min(1f, value));
    }
}
