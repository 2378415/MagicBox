package com.magicbullet.capture.core;

/**
 * The aiming loop's arithmetic, kept pure so it can be tested without a phone.
 *
 * <p>Two ideas live here:
 *
 * <ul>
 *   <li><b>self-calibrating gain</b> - the desktop calibration ({@code pxPerCount}) says nothing
 *       about how far the game rotates per count, and ADS changes it again. The loop compares the
 *       residual before and after a shot and derives how well its own model predicted the result.</li>
 *   <li><b>self-tuning dead zone and step limit</b> - both are estimated from the detector's own
 *       noise instead of being hand-tuned: the dead zone from the frame-to-frame jitter of a static
 *       target, the step limit from the size of the jumps the tracker sees.</li>
 * </ul>
 */
final class AimMath {

    private AimMath() {
    }

    /**
     * How much bigger the world's response was than the model assumed.
     *
     * <p>Both vectors point from the crosshair to the target. Asking for a fraction {@code f} of the
     * error, with a true response {@code k} times the model, leaves {@code (1 - f·k)} of the error,
     * so the projection of the new residual on the old direction is {@code 1 - f·k}.
     *
     * @return {@code k} (1 = the model is right, &gt;1 = we overshoot, &lt;1 = we under-shoot),
     *         or {@link Float#NaN} when the vectors are too small to mean anything
     */
    static float measureResponse(float dxPx, float dyPx, float prevDxPx, float prevDyPx,
                                 float requestedFraction) {
        float den = prevDxPx * prevDxPx + prevDyPx * prevDyPx;
        // Below ~2 px of previous error the projection is dominated by rounding, not response.
        if (den < 4f || requestedFraction <= 0.01f) {
            return Float.NaN;
        }
        float ratio = (dxPx * prevDxPx + dyPx * prevDyPx) / den;
        return (1f - ratio) / requestedFraction;
    }

    /**
     * Fraction of the error the next shot should ask for, given the measured response: aim to take
     * out 85 % of the residual, never more than the whole error.
     */
    static float gainForResponse(float response) {
        if (Float.isNaN(response) || response <= 0.05f || response > 3f) {
            return Float.NaN;
        }
        return Math.min(1f, 0.85f / response);
    }

    /** Exponential smoothing; {@code current < 0} means "no estimate yet". */
    static float smooth(float current, float sample, float alpha) {
        if (Float.isNaN(sample)) {
            return current;
        }
        if (current < 0f) {
            return sample;
        }
        return current + (sample - current) * alpha;
    }

    /**
     * Per-shot limit: never ask for more than 80 % of the remaining error, whatever the gain says.
     * Last line of defence against a bad estimate.
     */
    static int limitToError(int counts, float errorPx, float countsPerPx) {
        float requested = Math.abs(counts);
        float cap = errorPx * countsPerPx * 0.8f;
        if (requested <= cap || requested < 1e-3f) {
            return counts;
        }
        return Math.round(counts * (cap / requested));
    }

    /**
     * Percentile of a sample window (0..n-1). Sorts a copy; windows are small (≤60) so this is
     * cheap enough to run every frame and keeps the callers allocation-free of any sorting logic.
     *
     * @return the percentile value, or {@link Float#NaN} when there are too few samples
     */
    static float percentile(float[] samples, int n, float p) {
        if (samples == null || n < 5 || n > samples.length) {
            return Float.NaN;
        }
        float[] copy = new float[n];
        System.arraycopy(samples, 0, copy, 0, n);
        java.util.Arrays.sort(copy);
        float clamped = Math.max(0f, Math.min(1f, p));
        int idx = Math.round(clamped * (n - 1));
        return copy[Math.max(0, Math.min(n - 1, idx))];
    }

    /**
     * Self-tuned dead zone: 1.2× the 90th percentile of the jitter of a static target, never below
     * the hand-tuned value and never above 12 px (a dead zone that big would make aiming feel dead).
     *
     * @param jitterP90 90th percentile of the measured frame-to-frame jitter (NaN = no estimate)
     * @param manualPx  the value from the settings page, used as a floor
     */
    static float autoDeadzonePx(float jitterP90, float manualPx) {
        float floor = Math.max(0.5f, manualPx);
        if (Float.isNaN(jitterP90)) {
            return floor;
        }
        return Math.max(floor, Math.min(12f, jitterP90 * 1.2f));
    }

    /**
     * Self-tuned per-shot limit, in counts.
     *
     * <p>Two signals, whichever is larger: a nearby target deserves a bigger step than its own box
     * height implies ({@code 1.6×boxHeight}), and the detector's own jump noise says how far a
     * false match can throw the crosshair ({@code 1.5×jumpP90}). The hand-tuned value stays a
     * ceiling, so the automatic value can only make aiming calmer, never wilder.
     */
    static int autoMaxCounts(float boxHeightPx, float jumpP90Px, float manualCounts,
                             float pxPerCount) {
        float manual = Math.max(50f, manualCounts);
        float perPx = 1f / Math.max(0.05f, pxPerCount);
        float byBox = Float.isNaN(boxHeightPx) ? 0f : boxHeightPx * 1.6f;
        float byJump = Float.isNaN(jumpP90Px) ? 0f : jumpP90Px * 1.5f;
        float signal = Math.max(byBox, byJump);
        if (signal <= 0f) {
            return Math.round(manual);
        }
        float counts = signal * perPx;
        return Math.round(Math.max(80f, Math.min(manual, Math.min(400f, counts))));
    }
}
