package com.magicbullet.capture.core;

import java.util.Objects;

/**
 * The square region of the captured frame that is fed to the detector.
 *
 * <p>A square crop matched to the square model input removes the letterbox bars and raises the
 * effective resolution for small targets: a 640 crop into a 640 model is 1:1, while 1080 into
 * 640 is a 1.78x magnification over the whole frame.
 *
 * <p>The centre is stored normalised so it survives a capture resolution change; the edge length
 * is in source pixels and is clamped to the frame on use.
 */
public final class RoiConfig {

    /** Whole frame: today's behaviour. */
    public static final RoiConfig FULL = new RoiConfig(false, 640, 0.5f, 0.5f);

    public final boolean enabled;
    public final int sizePx;
    public final float centerX;
    public final float centerY;

    public RoiConfig(boolean enabled, int sizePx, float centerX, float centerY) {
        this.enabled = enabled;
        this.sizePx = Math.max(32, sizePx);
        this.centerX = clamp01(centerX);
        this.centerY = clamp01(centerY);
    }

    public RoiConfig withCenter(float x, float y) {
        return new RoiConfig(enabled, sizePx, x, y);
    }

    public RoiConfig withSize(boolean on, int size) {
        return new RoiConfig(on, size, centerX, centerY);
    }

    /** True when the frame is large enough to host this edge length. */
    public boolean fits(int frameW, int frameH) {
        return sizePx <= Math.min(frameW, frameH);
    }

    /**
     * Pixel bounds inside the frame: {@code {x, y, w, h}}, always square and fully inside.
     * Falls back to the biggest square that fits when the requested one does not.
     */
    public int[] bounds(int frameW, int frameH) {
        if (!enabled || frameW <= 0 || frameH <= 0) {
            return new int[]{0, 0, frameW, frameH};
        }
        int size = Math.min(sizePx, Math.min(frameW, frameH));
        int half = size / 2;
        int cx = Math.round(centerX * frameW);
        int cy = Math.round(centerY * frameH);
        int x = clamp(cx - half, 0, frameW - size);
        int y = clamp(cy - half, 0, frameH - size);
        return new int[]{x, y, size, size};
    }

    /** Magnification over feeding the whole frame into the same model input. */
    public float magnification(int frameW) {
        if (!enabled || frameW <= 0) {
            return 1f;
        }
        return (float) frameW / Math.min(sizePx, frameW);
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) {
            return true;
        }
        if (!(other instanceof RoiConfig)) {
            return false;
        }
        RoiConfig that = (RoiConfig) other;
        return enabled == that.enabled && sizePx == that.sizePx
                && Float.compare(centerX, that.centerX) == 0
                && Float.compare(centerY, that.centerY) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(enabled, sizePx, centerX, centerY);
    }

    @Override
    public String toString() {
        return enabled ? sizePx + "² @" + centerX + "," + centerY : "full";
    }

    private static float clamp01(float value) {
        return Math.max(0f, Math.min(1f, value));
    }

    private static int clamp(int value, int min, int max) {
        return Math.max(min, Math.min(max, value));
    }
}
