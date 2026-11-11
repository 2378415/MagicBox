package com.magicbullet.capture.core;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;

import org.junit.Test;

import java.nio.ByteBuffer;

/**
 * UVC RGBX → Android ARGB conversion, the only part of the still-frame capture that can go wrong
 * silently: a byte-order mistake shows up as a picture with red and blue swapped, not as a crash.
 */
public class FrameSnapshotTest {

    private static ByteBuffer rgbx(int... pixelBytes) {
        ByteBuffer buffer = ByteBuffer.allocateDirect(pixelBytes.length);
        for (int value : pixelBytes) {
            buffer.put((byte) value);
        }
        buffer.rewind();
        return buffer;
    }

    @Test
    public void redGreenBlueStayInTheirChannels() {
        // one pixel: R=0x10, G=0x20, B=0x30, X=0x00
        int[] out = new int[1];
        FrameSnapshot.rgbxToArgb(rgbx(0x10, 0x20, 0x30, 0x00), 1, out);
        assertEquals(0xFF102030, out[0]);
    }

    @Test
    public void alphaIsAlwaysOpaque() {
        int[] out = new int[1];
        FrameSnapshot.rgbxToArgb(rgbx(0, 0, 0, 0x7F), 1, out);
        assertEquals(0xFF000000, out[0]);
    }

    @Test
    public void multiplePixelsKeepTheirOrder() {
        int[] out = new int[3];
        FrameSnapshot.rgbxToArgb(rgbx(
                0xFF, 0x00, 0x00, 0x00,
                0x00, 0xFF, 0x00, 0x00,
                0x00, 0x00, 0xFF, 0x00), 3, out);
        assertEquals(0xFFFF0000, out[0]);
        assertEquals(0xFF00FF00, out[1]);
        assertEquals(0xFF0000FF, out[2]);
    }

    @Test
    public void nullOrEmptyInputIsRejected() {
        assertNull(FrameSnapshot.fromRgbx(null, 4, 4));
        assertNull(FrameSnapshot.fromRgbx(rgbx(1, 2, 3, 4), 0, 4));
    }

    @Test
    public void shortBufferIsRejectedInsteadOfReadingGarbage() {
        // 4 bytes cannot hold a 2×2 frame
        assertNull(FrameSnapshot.fromRgbx(rgbx(1, 2, 3, 4), 2, 2));
    }

    @Test
    public void requestClearsThePreviousFrame() {
        FrameSnapshot.request();
        assertEquals(true, FrameSnapshot.isRequested());
        assertNull(FrameSnapshot.bitmap());
        assertNotNull(FrameSnapshot.class);
    }
}
