package com.magicbullet.capture.core;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

/**
 * Aiming maths that does not need a phone or a box: px→counts with the 2026-11-11 calibration,
 * the dead-zone byte, the per-frame step clamp and the exact {@code 0x3C} frame on the wire.
 */
public class AimMathTest {

    /** 1.25 px per count, measured on this machine (125% scaling, no acceleration). */
    private static final float PX_PER_COUNT = 1.25f;

    private static int countsFor(float px, float gain) {
        return Math.round(px / PX_PER_COUNT * gain);
    }

    @Test
    public void pixelsToCounts() {
        assertEquals(160, countsFor(200f, 1f));
        assertEquals(96, countsFor(200f, 0.6f));
        // The dead zone is applied to the pixel error *before* this conversion, so a small
        // residual still yields a couple of counts if it ever gets here.
        assertEquals(2, countsFor(4f, 0.6f));
        assertEquals(-8, countsFor(-10f, 1f));  // 10 px / 1.25 = 8 counts, sign kept
    }

    @Test
    public void deadZoneByte() {
        assertEquals(3, Math.max(1, Math.round(4f / PX_PER_COUNT)));
        assertEquals(1, Math.max(1, Math.round(0f / PX_PER_COUNT)));
    }

    @Test
    public void perFrameStepIsClamped() {
        int maxCounts = 400;
        assertEquals(400, Math.max(-maxCounts, Math.min(maxCounts, countsFor(5000f, 1f))));
        assertEquals(-400, Math.max(-maxCounts, Math.min(maxCounts, countsFor(-5000f, 1f))));
        assertEquals(160, Math.max(-maxCounts, Math.min(maxCounts, countsFor(200f, 1f))));
    }

    @Test
    public void aimPayloadLayout() {
        byte[] p = ControlPort.aimPayload(300, -160, 10, 0x01, 3);
        assertEquals(7, p.length);
        assertEquals(0x2C, p[0] & 0xFF);        // 300 = 0x012C
        assertEquals(0x01, p[1] & 0xFF);
        assertEquals(0x60, p[2] & 0xFF);        // -160 = 0xFF60
        assertEquals(0xFF, p[3] & 0xFF);
        assertEquals(10, p[4] & 0xFF);          // max_ms
        assertEquals(0x01, p[5] & 0xFF);        // flags: session clamp
        assertEquals(3, p[6] & 0xFF);           // dead_min
    }

    @Test
    public void aimFrameIsAValidBinaryFrame() {
        byte[] payload = ControlPort.aimPayload(160, 0, 10, 0x01, 3);
        byte[] frame = ControlPort.frameFor(0x3C, 0x10, payload);
        assertEquals(0x5A, frame[0] & 0xFF);
        assertEquals(0x3C, frame[1] & 0xFF);
        assertEquals(0x10, frame[2] & 0xFF);
        assertEquals(payload.length, ((frame[3] & 0xFF) | ((frame[4] & 0xFF) << 8)));
        int crc = ControlPort.crc8(frame, 1, 4 + payload.length);
        assertEquals(crc, frame[frame.length - 1] & 0xFF);
        // CRC must actually cover cmd..payload, so flipping a payload byte has to break it.
        byte[] broken = frame.clone();
        broken[5] ^= 0xFF;
        assertTrue(ControlPort.crc8(broken, 1, 4 + payload.length) != crc);
    }

    @Test
    public void aimStateDecodingMatchesTheDocumentedLayout() {
        // 00 01 2c 01 08 00 00 00 02 00 00 02 → active=0, result=1, counts=0x012c, dur=8,
        // aborted=0, rounds=2, dead_hits=0, gen=2
        byte[] p = new byte[]{0x00, 0x01, 0x2c, 0x01, 0x08, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
                0x02};
        int lastCounts = (p[2] & 0xFF) | ((p[3] & 0xFF) << 8);
        int lastDur = (p[4] & 0xFF) | ((p[5] & 0xFF) << 8);
        int rounds = (p[8] & 0xFF) | ((p[9] & 0xFF) << 8);
        assertEquals(300, lastCounts);
        assertEquals(8, lastDur);
        assertEquals(2, rounds);
        assertEquals(0, p[0]);
        assertEquals(1, p[1]);
    }
}
