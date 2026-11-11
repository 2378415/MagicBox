package com.magicbullet.capture.core;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

/**
 * Self-tuned dead zone and step limit: both are derived from the detector's own noise, so they must
 * stay inside sane bounds and fall back to the hand-tuned value when there is nothing to learn from.
 */
public class AimMathTuneTest {

    @Test
    public void percentileOfASmallWindow() {
        float[] s = {10f, 1f, 5f, 3f, 8f, 2f, 9f, 4f, 7f, 6f}; // 1..10 shuffled
        assertEquals(9f, AimMath.percentile(s, 10, 0.9f), 0.001f);
        assertEquals(5f, AimMath.percentile(s, 10, 0.45f), 0.6f);
        assertEquals(1f, AimMath.percentile(s, 10, 0f), 0.001f);
        assertEquals(10f, AimMath.percentile(s, 10, 1f), 0.001f);
    }

    @Test
    public void tooFewSamplesIsNotAnEstimate() {
        float[] s = {1f, 2f, 3f, 4f};
        assertTrue(Float.isNaN(AimMath.percentile(s, 4, 0.9f)));
        assertTrue(Float.isNaN(AimMath.percentile(null, 0, 0.9f)));
    }

    @Test
    public void deadzoneNeverGoesBelowTheManualFloor() {
        // Measured jitter 1 px → 1.2 px, but the manual value is 4 px: keep 4.
        assertEquals(4f, AimMath.autoDeadzonePx(1f, 4f), 0.001f);
        // Measured jitter 5 px → 6 px, above the floor.
        assertEquals(6f, AimMath.autoDeadzonePx(5f, 4f), 0.001f);
        // Absurd jitter is capped so aiming does not feel dead.
        assertEquals(12f, AimMath.autoDeadzonePx(50f, 4f), 0.001f);
        // No estimate → manual value.
        assertEquals(4f, AimMath.autoDeadzonePx(Float.NaN, 4f), 0.001f);
    }

    @Test
    public void stepLimitDerivesFromBoxHeight() {
        // 100 px tall target at 1.25 px/count → 160 px ≈ 128 counts, under the 200 ceiling.
        assertEquals(128, AimMath.autoMaxCounts(100f, Float.NaN, 200f, 1.25f));
    }

    @Test
    public void stepLimitTakesTheNoisierSignal() {
        // Jump noise 100 px → 150 px of allowance beats the 20 px box (32 px).
        assertEquals(120, AimMath.autoMaxCounts(20f, 100f, 200f, 1.25f));
        // Small noise on a small box falls back to the 80-count floor.
        assertEquals(80, AimMath.autoMaxCounts(20f, 60f, 200f, 1.25f));
    }

    @Test
    public void stepLimitStaysWithinBounds() {
        // Huge target: capped at the hand-tuned ceiling, never above 400.
        assertEquals(200, AimMath.autoMaxCounts(4000f, Float.NaN, 200f, 1.25f));
        // Tiny target and no noise: floor of 80 counts so aiming is not sluggish.
        assertEquals(80, AimMath.autoMaxCounts(2f, Float.NaN, 200f, 1.25f));
        // No signals at all → manual value.
        assertEquals(200, AimMath.autoMaxCounts(Float.NaN, Float.NaN, 200f, 1.25f));
    }

    @Test
    public void stepLimitRespectsAManualCeilingBelowTheEstimate() {
        assertEquals(90, AimMath.autoMaxCounts(1000f, Float.NaN, 90f, 1.25f));
    }
}
