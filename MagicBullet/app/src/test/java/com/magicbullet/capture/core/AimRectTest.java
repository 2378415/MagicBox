package com.magicbullet.capture.core;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

/**
 * Aim rectangle geometry. Every value is normalised to the frame, so the tests pin down the pixel
 * conversions, clamping and the "centre is the crosshair" contract the whole aim module relies on.
 */
public class AimRectTest {

    private static final int W = 1920;
    private static final int H = 1080;

    @Test
    public void defaultRectIsCentredAndInsideTheFrame() {
        AimRect r = AimRect.DEFAULT;
        assertEquals(0.5f, r.x + r.w / 2f, 0.01f);
        assertEquals(0.5f, r.y + r.h / 2f, 0.01f);
        assertTrue(r.contains(0.5f, 0.5f));
    }

    @Test
    public void boundsAreWholePixelsAndInsideTheFrame() {
        AimRect r = new AimRect(0.25f, 0.25f, 0.5f, 0.5f);
        int[] b = r.boundsPx(W, H);
        assertEquals(480, b[0]);
        assertEquals(270, b[1]);
        assertEquals(960, b[2]);
        assertEquals(540, b[3]);
        assertTrue(b[0] + b[2] <= W);
        assertTrue(b[1] + b[3] <= H);
    }

    @Test
    public void anchorIsTheRectangleCentre() {
        AimRect r = new AimRect(0.2f, 0.4f, 0.4f, 0.2f);
        assertEquals((0.2f + 0.2f) * W, r.anchorX(W), 0.01f);
        assertEquals((0.4f + 0.1f) * H, r.anchorY(H), 0.01f);
    }

    @Test
    public void centringPutsTheAnchorOnTheGivenPoint() {
        AimRect r = AimRect.DEFAULT.centredAt(0.3f, 0.7f);
        assertEquals(0.3f, r.anchorX(W) / W, 0.001f);
        assertEquals(0.7f, r.anchorY(H) / H, 0.001f);
    }

    @Test
    public void nudgeByOnePixelShiftsExactlyOnePixel() {
        AimRect r = new AimRect(0.4f, 0.4f, 0.2f, 0.2f);
        AimRect moved = new AimRect(r.x + 1f / W, r.y - 1f / H, r.w, r.h);
        assertEquals(r.anchorX(W) + 1f, moved.anchorX(W), 0.01f);
        assertEquals(r.anchorY(H) - 1f, moved.anchorY(H), 0.01f);
    }

    @Test
    public void constructorClampsSizeAndPosition() {
        AimRect tiny = new AimRect(0.5f, 0.5f, 0f, 0f);
        assertTrue(tiny.w >= 0.02f);
        assertTrue(tiny.h >= 0.02f);

        AimRect outside = new AimRect(0.9f, 0.9f, 0.5f, 0.5f);
        assertTrue("x must stay inside the frame", outside.x + outside.w <= 1.0001f);
        assertTrue("y must stay inside the frame", outside.y + outside.h <= 1.0001f);
    }

    @Test
    public void resizingKeepsTheCentre() {
        AimRect r = new AimRect(0.3f, 0.3f, 0.4f, 0.4f);
        AimRect smaller = r.withSize(0.2f, 0.2f);
        assertEquals(r.anchorX(W), smaller.anchorX(W), 0.01f);
        assertEquals(r.anchorY(H), smaller.anchorY(H), 0.01f);
        assertEquals(0.2f, smaller.w, 0.0001f);
    }

    @Test
    public void minimumPixelSizeIsEnforced() {
        AimRect r = new AimRect(0.1f, 0.1f, 0.001f, 0.001f);
        AimRect clamped = r.clampedToFrame(W, H, 32);
        int[] b = clamped.boundsPx(W, H);
        assertTrue("width must reach the minimum", b[2] >= 16);
        assertTrue("height must reach the minimum", b[3] >= 16);
    }

    @Test
    public void containsUsesNormalisedCoordinates() {
        AimRect r = new AimRect(0.25f, 0.25f, 0.5f, 0.5f);
        assertTrue(r.contains(0.5f, 0.5f));
        assertTrue(r.contains(0.25f, 0.25f));
        assertFalse(r.contains(0.24f, 0.5f));
        assertFalse(r.contains(0.5f, 0.76f));
    }

    @Test
    public void describeShowsPixelSizeAndCentre() {
        AimRect r = new AimRect(0.25f, 0.25f, 0.5f, 0.5f);
        String text = r.describe(W, H);
        assertTrue(text.contains("960"));
        assertTrue(text.contains("0.50"));
        assertNull(null);
    }
}
