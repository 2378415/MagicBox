package com.magicbullet.capture.core;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

/**
 * The self-calibrating gain and the per-shot limiter: these two are what stop the "aimed, then
 * jerked past the target" behaviour when the game's sensitivity does not match the desktop
 * px/count calibration.
 */
public class AimMathTest2 {

    /** 100 px error to the right, we asked for 60 % of it (gain 0.6). */
    private static float step(float dx, float dy) {
        return AimMath.measureResponse(dx, dy, 100f, 0f, 0.6f);
    }

    @Test
    public void perfectModelMeasuresOne() {
        // Moved exactly 60 px → residual 40 px.
        assertEquals(1.0f, step(40f, 0f), 0.01f);
    }

    @Test
    public void overshootMeasuresAboveOne() {
        // Moved 120 px for a 60 px request → the target ends up 20 px past the crosshair.
        float k = step(-20f, 0f);
        assertEquals(2.0f, k, 0.02f);
        assertTrue("overshoot must shrink the gain below the configured one",
                AimMath.gainForResponse(k) < 0.6f);
    }

    @Test
    public void undershootMeasuresBelowOne() {
        // Moved only 20 px → residual 80 px → k = 0.33.
        float k = step(80f, 0f);
        assertEquals(0.333f, k, 0.02f);
        assertEquals("under-shooting may be corrected by a larger gain",
                1.0f, AimMath.gainForResponse(k), 0.001f);
    }

    @Test
    public void gainTargetsEightyFivePercent() {
        assertEquals(0.85f, AimMath.gainForResponse(1.0f), 0.001f);
        assertEquals(0.85f / 1.5f, AimMath.gainForResponse(1.5f), 0.001f);
    }

    @Test
    public void responseIsIgnoredWhenVectorsAreTiny() {
        assertTrue(Float.isNaN(AimMath.measureResponse(0.1f, 0f, 0.2f, 0f, 0.6f)));
        assertTrue(Float.isNaN(AimMath.gainForResponse(Float.NaN)));
        assertTrue("a wildly out-of-range response must not be trusted",
                Float.isNaN(AimMath.gainForResponse(9f)));
    }

    @Test
    public void smoothingKeepsTheFirstSample() {
        assertEquals(0.7f, AimMath.smooth(-1f, 0.7f, 0.3f), 0.001f);
        assertEquals(0.7f + (0.4f - 0.7f) * 0.3f, AimMath.smooth(0.7f, 0.4f, 0.3f), 0.001f);
        assertEquals(0.7f, AimMath.smooth(0.7f, Float.NaN, 0.3f), 0.001f);
    }

    @Test
    public void perShotLimitCapsAtEightyPercentOfTheError() {
        // 100 px error at 1.25 px/count = 125 counts; 80 % of it is 100 counts.
        assertEquals(100, AimMath.limitToError(120, 100f, 1.25f));
        // Small requests pass through untouched.
        assertEquals(30, AimMath.limitToError(30, 100f, 1.25f));
        assertEquals(-100, AimMath.limitToError(-120, 100f, 1.25f));
        // Zero stays zero.
        assertEquals(0, AimMath.limitToError(0, 100f, 1.25f));
    }
}
