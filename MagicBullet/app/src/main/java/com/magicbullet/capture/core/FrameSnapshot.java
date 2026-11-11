package com.magicbullet.capture.core;

import android.graphics.Bitmap;

import java.nio.ByteBuffer;

/**
 * One-shot still frame, taken from the live UVC stream and handed to the calibration screen.
 *
 * <p>The calibration page needs a <em>frozen</em> picture to zoom into: a live stream would keep
 * moving under the finger and cost a decode per frame. The preview fragment keeps its raw-frame
 * listener alive even while another tab is shown, so requesting a snapshot works from anywhere.
 */
public final class FrameSnapshot {

    private static volatile boolean sRequested;
    private static volatile Bitmap sBitmap;
    private static volatile int sWidth;
    private static volatile int sHeight;

    private FrameSnapshot() {
    }

    /** Ask the next incoming frame to be turned into a bitmap. */
    public static void request() {
        sBitmap = null;
        sWidth = 0;
        sHeight = 0;
        sRequested = true;
    }

    public static boolean isRequested() {
        return sRequested;
    }

    public static Bitmap bitmap() {
        return sBitmap;
    }

    public static int width() {
        return sWidth;
    }

    public static int height() {
        return sHeight;
    }

    /** Called by the capture thread once the frame is converted. */
    public static void deliver(Bitmap bitmap, int width, int height) {
        sBitmap = bitmap;
        sWidth = width;
        sHeight = height;
        sRequested = false;
    }

    /**
     * Pure conversion used by {@link #fromRgbx}: RGBX (R,G,B,X per pixel) to Android ARGB ints.
     * Kept separate so the byte order can be unit-tested without a Bitmap.
     *
     * @param src   buffer positioned at the first pixel
     * @param pixels number of pixels to convert
     * @param out   destination of at least {@code pixels} ints
     */
    static void rgbxToArgb(ByteBuffer src, int pixels, int[] out) {
        for (int i = 0; i < pixels; i++) {
            int r = src.get() & 0xFF;
            int g = src.get() & 0xFF;
            int b = src.get() & 0xFF;
            src.get(); // padding byte
            out[i] = 0xFF000000 | (r << 16) | (g << 8) | b;
        }
    }

    /**
     * Converts a UVC RGBX frame (4 bytes per pixel, R,G,B,X) into an {@link Bitmap}.
     *
     * <p>Android's ARGB_8888 wants B,G,R,A in memory, so the bytes are reordered explicitly instead
     * of being blitted straight through (that would swap red and blue).
     */
    public static Bitmap fromRgbx(ByteBuffer rgbx, int width, int height) {
        if (rgbx == null || width <= 0 || height <= 0) {
            return null;
        }
        ByteBuffer src = rgbx.duplicate();
        src.rewind();
        int pixels = width * height;
        if (src.remaining() < pixels * 4) {
            return null;
        }
        int[] argb = new int[pixels];
        rgbxToArgb(src, pixels, argb);
        Bitmap bitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
        bitmap.setPixels(argb, 0, width, 0, 0, width, height);
        return bitmap;
    }
}
