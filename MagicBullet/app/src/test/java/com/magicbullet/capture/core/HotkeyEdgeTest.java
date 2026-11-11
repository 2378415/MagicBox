package com.magicbullet.capture.core;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

/**
 * Multi-select hotkey edges. The rule under test: "pressed" means <em>any</em> subscribed key is
 * held, so adding a second key while the first is down must not fire another press, and only the
 * last release counts as a release.
 */
public class HotkeyEdgeTest {

    private static final int RIGHT = 0x02;
    private static final int REAR = 0x08;
    private static final int FRONT = 0x10;
    private static final int ALL = RIGHT | REAR | FRONT;

    @Test
    public void anySubscribedBitCountsAsPressed() {
        assertTrue(HotkeyEdge.anyHeld(RIGHT, ALL));
        assertTrue(HotkeyEdge.anyHeld(REAR | FRONT, ALL));
        assertFalse(HotkeyEdge.anyHeld(0, ALL));
    }

    @Test
    public void unsubscribedButtonsAreIgnored() {
        // Left (0x01) and middle (0x04) are not part of the aim mask.
        assertFalse(HotkeyEdge.anyHeld(0x01, ALL));
        assertFalse(HotkeyEdge.anyHeld(0x04, RIGHT));
    }

    @Test
    public void firstKeyGivesOnePress() {
        assertFalse(HotkeyEdge.anyHeld(0, ALL));
        assertTrue(HotkeyEdge.anyHeld(RIGHT, ALL));
        assertEquals(HotkeyEdge.PRESS, HotkeyEdge.transition(false, true));
    }

    @Test
    public void secondKeyWhileHeldGivesNothing() {
        // right held → side key added: still "some key down", no new press
        boolean before = HotkeyEdge.anyHeld(RIGHT, ALL);
        boolean after = HotkeyEdge.anyHeld(RIGHT | REAR, ALL);
        assertTrue(before && after);
        assertEquals(HotkeyEdge.NONE, HotkeyEdge.transition(before, after));
    }

    @Test
    public void releasingOneOfTwoKeysGivesNothing() {
        boolean before = HotkeyEdge.anyHeld(RIGHT | FRONT, ALL);
        boolean after = HotkeyEdge.anyHeld(FRONT, ALL);
        assertTrue(before && after);
        assertEquals(HotkeyEdge.NONE, HotkeyEdge.transition(before, after));
    }

    @Test
    public void lastReleaseGivesRelease() {
        boolean before = HotkeyEdge.anyHeld(FRONT, ALL);
        boolean after = HotkeyEdge.anyHeld(0, ALL);
        assertTrue(before);
        assertFalse(after);
        assertEquals(HotkeyEdge.RELEASE, HotkeyEdge.transition(before, after));
    }

    @Test
    public void fullSequenceTogglesExactlyOnce() {
        int[] frames = {
                0,            // nothing
                RIGHT,        // press  → PRESS
                RIGHT | REAR, // add key → NONE
                REAR,         // drop one → NONE
                0,            // release → RELEASE
        };
        boolean state = false;
        int presses = 0;
        int releases = 0;
        for (int buttons : frames) {
            boolean now = HotkeyEdge.anyHeld(buttons, ALL);
            int event = HotkeyEdge.transition(state, now);
            if (event == HotkeyEdge.PRESS) {
                presses++;
            } else if (event == HotkeyEdge.RELEASE) {
                releases++;
            }
            state = now;
        }
        assertEquals(1, presses);
        assertEquals(1, releases);
    }

    @Test
    public void singleKeyMaskBehavesLikeBefore() {
        assertEquals(HotkeyEdge.PRESS, HotkeyEdge.transition(false, HotkeyEdge.anyHeld(RIGHT, RIGHT)));
        assertEquals(HotkeyEdge.RELEASE, HotkeyEdge.transition(true, HotkeyEdge.anyHeld(0, RIGHT)));
        assertEquals(HotkeyEdge.NONE,
                HotkeyEdge.transition(false, HotkeyEdge.anyHeld(REAR, RIGHT)));
    }
}
