package com.magicbullet.capture.core;

/**
 * One detection box in normalised frame coordinates (0..1 on both axes), so the
 * overlay does not care about the capture resolution.
 */
public final class Detection {

    public final float left;
    public final float top;
    public final float right;
    public final float bottom;
    public final String label;
    public final float score;

    public Detection(float left, float top, float right, float bottom, String label, float score) {
        this.left = clamp(left);
        this.top = clamp(top);
        this.right = clamp(right);
        this.bottom = clamp(bottom);
        this.label = label;
        this.score = score;
    }

    private static float clamp(float value) {
        return Math.max(0f, Math.min(1f, value));
    }
}
