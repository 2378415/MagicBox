package com.magicbullet.capture.core;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

/**
 * Aim hotkey debounce. The failures that matter:
 * one click must never toggle twice (chatter), a deliberate second click must not be swallowed,
 * and a single lost release edge must never lock the hotkey out.
 */
public class HotkeyGateTest {

    @Test
    public void singleClickIsAccepted() {
        HotkeyGate gate = new HotkeyGate();
        assertTrue(gate.acceptDown(1_000L));
        gate.noteUp(1_070L);
        assertEquals(0, gate.suppressed());
    }

    @Test
    public void chatterWithATinyReleaseGapIsSwallowed() {
        HotkeyGate gate = new HotkeyGate();
        assertTrue(gate.acceptDown(1_000L));
        gate.noteUp(1_004L);                     // released after 4 ms: impossible for a finger
        assertFalse(gate.acceptDown(1_006L));    // bounce
        gate.noteUp(1_008L);
        assertEquals(1, gate.suppressed());
        assertTrue(gate.acceptDown(1_400L));     // later press counts again
    }

    @Test
    public void fastButDeliberateSecondClickCounts() {
        HotkeyGate gate = new HotkeyGate();
        assertTrue(gate.acceptDown(1_000L));
        gate.noteUp(1_250L);                     // held a quarter second, then let go
        assertTrue(gate.acceptDown(1_340L));     // 90 ms later: a real second click
        assertEquals(0, gate.suppressed());
    }

    @Test
    public void lostReleaseDoesNotLockTheHotkey() {
        HotkeyGate gate = new HotkeyGate();
        assertTrue(gate.acceptDown(1_000L));
        // The release edge never arrived. A press a moment later must still toggle - otherwise
        // the user cannot cancel aiming any more.
        assertTrue(gate.acceptDown(1_200L));
        assertTrue(gate.acceptDown(1_400L));
    }

    @Test
    public void duplicateReportInsideTheSpacingIsIgnored() {
        HotkeyGate gate = new HotkeyGate();
        assertTrue(gate.acceptDown(1_000L));
        assertFalse(gate.acceptDown(1_090L));    // 90 ms later: same press reported twice
        assertEquals(1, gate.suppressed());
        assertTrue(gate.acceptDown(1_300L));
    }

    @Test
    public void resyncAfterLostReleaseKeepsWorking() {
        HotkeyGate gate = new HotkeyGate();
        assertTrue(gate.acceptDown(1_000L));
        gate.resyncReleased(1_500L);
        assertFalse(gate.held());
        assertTrue(gate.acceptDown(1_700L));
    }

    @Test
    public void resetClearsStateAndCounter() {
        HotkeyGate gate = new HotkeyGate();
        assertTrue(gate.acceptDown(1_000L));
        assertFalse(gate.acceptDown(1_010L));
        gate.reset();
        assertEquals(0, gate.suppressed());
        assertFalse(gate.held());
        assertTrue(gate.acceptDown(1_010L));
    }

    @Test
    public void twentyTogglesInARowAllWork() {
        HotkeyGate gate = new HotkeyGate();
        long t = 1_000L;
        int accepted = 0;
        for (int i = 0; i < 20; i++) {
            if (gate.acceptDown(t)) {
                accepted++;
            }
            gate.noteUp(t + 60L);
            t += 300L; // a click every 300 ms, like a player flipping aim on and off
        }
        assertEquals(20, accepted);
        assertEquals(0, gate.suppressed());
    }
}
