package com.magicbullet.capture.core;

import java.util.ArrayList;
import java.util.List;

/**
 * Stand-in detector so the pipeline (frame -> detect -> overlay) can be exercised before
 * a real model is wired in. Produces one box that drifts across the frame.
 *
 * <p>Replace the body with the TFLite interpreter call; the signature is what matters:
 * frame index + config in, normalised boxes out.
 */
public final class DummyDetector {

    private static final String[] LABELS = {"person", "vehicle", "animal", "other"};

    private float mPhase;

    public List<Detection> detect(int frameIndex, YoloConfig config) {
        List<Detection> result = new ArrayList<>(2);
        if (config != null && !config.drawBoxes()) {
            return result;
        }

        mPhase += 0.012f;
        if (mPhase > 1f) {
            mPhase -= 1f;
        }

        // A box sliding left to right, plus a second one bobbing vertically.
        float cx = 0.15f + 0.7f * mPhase;
        result.add(box(cx, 0.45f, 0.18f, 0.34f, LABELS[0], 0.9f));
        result.add(box(0.7f, 0.3f + 0.12f * (float) Math.sin(mPhase * 6.28), 0.16f, 0.22f,
                LABELS[1], 0.72f));

        if (config != null && !config.classes().isEmpty()) {
            List<Detection> filtered = new ArrayList<>(result.size());
            for (Detection detection : result) {
                if (config.classes().contains(detection.label)) {
                    filtered.add(detection);
                }
            }
            return filtered;
        }
        return result;
    }

    private static Detection box(float cx, float cy, float w, float h, String label, float score) {
        return new Detection(cx - w / 2f, cy - h / 2f, cx + w / 2f, cy + h / 2f, label, score);
    }
}
