package com.magicbullet.capture.core;

import java.nio.ByteBuffer;
import java.nio.FloatBuffer;

/**
 * Letterbox + normalise, in native code.
 *
 * <p>The Java loop it replaces ran once per captured frame over ~2.2 M channel writes and
 * showed up as the largest CPU cost in the pipeline (5.3 ms for a 1080p frame into a 640
 * box). The native version reads the UVC buffer in place and writes straight into the
 * direct buffer that backs the input tensor, so neither the 8.3 MB RGBX copy nor a
 * 4.9 MB float array copy is left.
 */
final class YoloPreprocess {

    private static final boolean NATIVE;
    static String loadError = "";

    static {
        boolean loaded;
        try {
            System.loadLibrary("mbpre");
            loaded = true;
        } catch (Throwable t) {
            loaded = false;
            loadError = String.valueOf(t);
        }
        NATIVE = loaded;
    }

    private YoloPreprocess() {
    }

    static boolean isNative() {
        return NATIVE;
    }

    /**
     * Writes the letterboxed CHW float planes of {@code src} into {@code dst}.
     *
     * @param src    RGBX pixels, 4 bytes per pixel, read in place
     * @param nw     scaled width (centred inside the box after padding)
     * @param nh     scaled height
     * @param srcX   byte offset of column {@code x} in a source row, length >= nw
     * @param srcRow byte offset of source row {@code y}, length >= nh
     * @param dst    direct buffer of at least 3 * size * size floats
     */
    static void letterbox(ByteBuffer src, int size, int nw, int nh,
                          int[] srcX, int[] srcRow, ByteBuffer dst, boolean fillPad) {
        if (NATIVE) {
            nativeLetterbox(src, size, nw, nh, srcX, srcRow, dst, fillPad);
        } else {
            javaLetterbox(src, size, nw, nh, srcX, srcRow, dst.asFloatBuffer(), fillPad);
        }
    }

    static void javaFallback(ByteBuffer src, int size, int nw, int nh,
                             int[] srcX, int[] srcRow, ByteBuffer dst, boolean fillPad) {
        javaLetterbox(src, size, nw, nh, srcX, srcRow, dst.asFloatBuffer(), fillPad);
    }

    private static native void nativeLetterbox(ByteBuffer src, int size, int nw, int nh,
                                               int[] srcX, int[] srcRow, ByteBuffer dst,
                                               boolean fillPad);

    /** Kept as a fallback for builds without the native library. */
    private static void javaLetterbox(ByteBuffer src, int size, int nw, int nh,
                                      int[] srcX, int[] srcRow, FloatBuffer dst,
                                      boolean fillPad) {
        final int plane = size * size;
        final int padX = (size - nw) / 2;
        final int padY = (size - nh) / 2;
        final float pad = 114f / 255f;
        if (fillPad) {
        for (int p = 0; p < 3; p++) {
            int base = p * plane;
            for (int i = base; i < base + padY * size; i++) {
                dst.put(i, pad);
            }
            for (int i = base + (padY + nh) * size; i < base + plane; i++) {
                dst.put(i, pad);
            }
            for (int y = padY; y < padY + nh; y++) {
                int row = base + y * size;
                for (int i = row; i < row + padX; i++) {
                    dst.put(i, pad);
                }
                for (int i = row + padX + nw; i < row + size; i++) {
                    dst.put(i, pad);
                }
            }
        }
        }
        final float inv = 1f / 255f;
        for (int y = 0; y < nh; y++) {
            int dstRow = (padY + y) * size + padX;
            int rowBase = srcRow[y];
            for (int x = 0; x < nw; x++) {
                int s = rowBase + srcX[x];
                int d = dstRow + x;
                dst.put(d, (src.get(s) & 0xFF) * inv);
                dst.put(plane + d, (src.get(s + 1) & 0xFF) * inv);
                dst.put(2 * plane + d, (src.get(s + 2) & 0xFF) * inv);
            }
        }
    }
}
