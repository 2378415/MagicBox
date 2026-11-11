package com.magicbullet.capture.core;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

/** Clamping and magnification of the square crop fed to the detector. */
public class RoiConfigTest {

    @Test
    public void disabledOrEmptyFrameIsTheWholeFrame() {
        assertArrayEquals(new int[]{0, 0, 1920, 1080}, RoiConfig.FULL.bounds(1920, 1080));
        assertEquals(1f, RoiConfig.FULL.magnification(1920), 1e-6);
    }

    @Test
    public void centredRoiKeepsTheRequestedSize() {
        RoiConfig roi = new RoiConfig(true, 720, 0.5f, 0.5f);
        assertArrayEquals(new int[]{600, 180, 720, 720}, roi.bounds(1920, 1080));
        assertEquals(1920f / 720f, roi.magnification(1920), 1e-6f);
    }

    @Test
    public void roiIsClampedInsideTheFrame() {
        RoiConfig corner = new RoiConfig(true, 640, 0f, 0f);
        assertArrayEquals(new int[]{0, 0, 640, 640}, corner.bounds(1920, 1080));

        RoiConfig bottomRight = new RoiConfig(true, 640, 1f, 1f);
        assertArrayEquals(new int[]{1280, 440, 640, 640}, bottomRight.bounds(1920, 1080));
    }

    @Test
    public void oversizedRoiShrinksToTheShortSide() {
        RoiConfig roi = new RoiConfig(true, 1080, 0.5f, 0.5f);
        // 1080 does not fit a 720-high frame: it becomes 720 and stays centred.
        assertArrayEquals(new int[]{280, 0, 720, 720}, roi.bounds(1280, 720));
        assertFalse(roi.fits(1280, 720));
        assertTrue(roi.fits(1920, 1080));
    }

    @Test
    public void equalityCoversEveryField() {
        RoiConfig a = new RoiConfig(true, 720, 0.5f, 0.5f);
        assertEquals(a, new RoiConfig(true, 720, 0.5f, 0.5f));
        assertFalse(a.equals(new RoiConfig(false, 720, 0.5f, 0.5f)));
        assertFalse(a.equals(new RoiConfig(true, 640, 0.5f, 0.5f)));
        assertFalse(a.equals(a.withCenter(0.6f, 0.5f)));
    }

    @Test
    public void centreIsClampedToTheUnitSquare() {
        RoiConfig roi = new RoiConfig(true, 640, -3f, 7f);
        assertEquals(0f, roi.centerX, 1e-6);
        assertEquals(1f, roi.centerY, 1e-6);
    }
}
