package com.magicbullet.capture.core.post;

/**
 * Letterbox geometry for one frame: how the fed region was fitted into the model input.
 *
 * <p>Everything the decoders need to map a tensor coordinate back to the full frame lives here,
 * so the decoder tests do not have to construct a detector. When a square crop is active the
 * region is the crop, not the frame, and {@link #sourceX(float)} already returns frame pixels.
 */
public final class Geometry {

    public final int inputSize;
    /** Full frame size, used to normalise the final boxes. */
    public final int width;
    public final int height;
    public final float scale;
    public final float padX;
    public final float padY;
    public final int roiX;
    public final int roiY;
    public final int roiW;
    public final int roiH;

    /** Whole frame, no crop. */
    public Geometry(int inputSize, int width, int height) {
        this(inputSize, width, height, 0, 0, width, height);
    }

    public Geometry(int inputSize, int width, int height,
                    int roiX, int roiY, int roiW, int roiH) {
        this.inputSize = inputSize;
        this.width = width;
        this.height = height;
        this.roiX = roiX;
        this.roiY = roiY;
        this.roiW = Math.max(1, roiW);
        this.roiH = Math.max(1, roiH);
        this.scale = Math.min((float) inputSize / this.roiW, (float) inputSize / this.roiH);
        this.padX = (inputSize - this.roiW * scale) / 2f;
        this.padY = (inputSize - this.roiH * scale) / 2f;
    }

    /** Model-input X -> full-frame X. */
    public float sourceX(float x) {
        return roiX + (x - padX) / scale;
    }

    /** Model-input Y -> full-frame Y. */
    public float sourceY(float y) {
        return roiY + (y - padY) / scale;
    }

    /** True when a crop is active. */
    public boolean cropped() {
        return roiW != width || roiH != height;
    }
}
