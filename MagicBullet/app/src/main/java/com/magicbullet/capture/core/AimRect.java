package com.magicbullet.capture.core;

import java.util.Locale;
import java.util.Objects;

/**
 * The rectangle on the captured frame that aiming is allowed to look at.
 *
 * <p>Coordinates are normalised to the frame, so a capture-mode change (1080p ↔ 2K) does not
 * invalidate a hand-dragged box. The crosshair is the rectangle's centre: putting the box where
 * the game's crosshair is doubles as the crosshair calibration, which is why there is no separate
 * anchor parameter.
 */
public final class AimRect {

    /** 1080×640 on a 1920×1080 frame, centred. */
    public static final AimRect DEFAULT =
            new AimRect(0.21875f, 0.20370f, 0.56250f, 0.59259f);

    public final float x;
    public final float y;
    public final float w;
    public final float h;

    public AimRect(float x, float y, float w, float h) {
        this.w = clamp(w, 0.02f, 1f);
        this.h = clamp(h, 0.02f, 1f);
        this.x = clamp(x, 0f, 1f - this.w);
        this.y = clamp(y, 0f, 1f - this.h);
    }

    /** Pixel bounds inside the frame: {@code {x, y, w, h}}. */
    public int[] boundsPx(int frameW, int frameH) {
        int px = Math.round(x * frameW);
        int py = Math.round(y * frameH);
        int pw = Math.max(16, Math.round(w * frameW));
        int ph = Math.max(16, Math.round(h * frameH));
        return new int[]{px, py, Math.min(pw, frameW - px), Math.min(ph, frameH - py)};
    }

    public float anchorX(int frameW) {
        return (x + w / 2f) * frameW;
    }

    public float anchorY(int frameH) {
        return (y + h / 2f) * frameH;
    }

    /** Normalised point-in-rect test. */
    public boolean contains(float nx, float ny) {
        return nx >= x && nx <= x + w && ny >= y && ny <= y + h;
    }

    /** Moves the box so its centre lands on the given normalised point. */
    public AimRect centredAt(float cx, float cy) {
        return new AimRect(cx - w / 2f, cy - h / 2f, w, h);
    }

    public AimRect withSize(float width, float height) {
        return new AimRect(x + (w - width) / 2f, y + (h - height) / 2f, width, height);
    }

    /** Keeps the requested edge length, never smaller than {@code minPx} on this frame. */
    public AimRect clampedToFrame(int frameW, int frameH, int minPx) {
        float minW = Math.min(1f, (float) minPx / Math.max(1, frameW));
        float minH = Math.min(1f, (float) minPx / Math.max(1, frameH));
        return new AimRect(x, y, Math.max(w, minW), Math.max(h, minH));
    }

    public String describe(int frameW, int frameH) {
        int[] b = boundsPx(frameW, frameH);
        return String.format(Locale.US, "%d × %d @ %.2f, %.2f", b[2], b[3],
                x + w / 2f, y + h / 2f);
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) {
            return true;
        }
        if (!(other instanceof AimRect)) {
            return false;
        }
        AimRect that = (AimRect) other;
        return Float.compare(x, that.x) == 0 && Float.compare(y, that.y) == 0
                && Float.compare(w, that.w) == 0 && Float.compare(h, that.h) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y, w, h);
    }

    private static float clamp(float value, float min, float max) {
        return Math.max(min, Math.min(max, value));
    }
}
