package com.magicbullet.capture.core.post;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/**
 * Greedy non-maximum suppression over {@code float[]{x1, y1, x2, y2, score, class}}.
 *
 * <p>Boxes are in source pixels; overlaps are only suppressed inside one class, exactly like
 * the per-class NMS of the reference implementations.
 */
public final class Nms {

    private Nms() {
    }

    /**
     * Sorts the candidates by score (descending), suppresses overlapping boxes of the same
     * class and stops after {@code maxDetections}.
     */
    public static List<float[]> suppress(List<float[]> candidates, float iouThreshold,
                                         int maxDetections) {
        candidates.sort(Comparator.comparingDouble((float[] box) -> box[4]).reversed());
        List<float[]> kept = new ArrayList<>(Math.min(maxDetections, candidates.size()));
        boolean[] suppressed = new boolean[candidates.size()];
        for (int i = 0; i < candidates.size() && kept.size() < maxDetections; i++) {
            if (suppressed[i]) {
                continue;
            }
            float[] best = candidates.get(i);
            suppressed[i] = true;
            for (int j = i + 1; j < candidates.size(); j++) {
                if (!suppressed[j] && (int) candidates.get(j)[5] == (int) best[5]
                        && iou(best, candidates.get(j)) > iouThreshold) {
                    suppressed[j] = true;
                }
            }
            kept.add(best);
        }
        return kept;
    }

    /** Intersection over union of two {@code x1,y1,x2,y2} boxes. */
    public static float iou(float[] a, float[] b) {
        float x1 = Math.max(a[0], b[0]);
        float y1 = Math.max(a[1], b[1]);
        float x2 = Math.min(a[2], b[2]);
        float y2 = Math.min(a[3], b[3]);
        float inter = Math.max(0, x2 - x1) * Math.max(0, y2 - y1);
        float areaA = Math.max(0, a[2] - a[0]) * Math.max(0, a[3] - a[1]);
        float areaB = Math.max(0, b[2] - b[0]) * Math.max(0, b[3] - b[1]);
        return inter / (areaA + areaB - inter + 1e-6f);
    }
}
