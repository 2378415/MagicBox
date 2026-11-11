package com.magicbullet.capture.core;

/**
 * Decides which hotkey press edges are real.
 *
 * <p>Two failure modes have to be told apart:
 *
 * <ul>
 *   <li><b>contact chatter</b>: press, release, press again within a few milliseconds. The release
 *       is far too short to be a human letting go, so the second press must not toggle.</li>
 *   <li><b>a real second click</b>: the button was released for tens of milliseconds first.</li>
 * </ul>
 *
 * <p>Critically there is <b>no held latch</b>: an earlier version ignored any press while it
 * believed the button was still down, so a single lost release edge made the hotkey dead until the
 * app restarted ("aiming can no longer be cancelled"). The release-gap rule only applies when a
 * release was actually observed <em>after</em> the last accepted press; if the release is missing,
 * plain press spacing ({@link #DEBOUNCE_MS}) is the only gate, so the next real click still works.
 */
final class HotkeyGate {

    /** Minimum time the button must be released before a new press counts as intentional. */
    static final long MIN_RELEASE_MS = 80L;
    /** Minimum spacing between two accepted presses, whatever the release history says. */
    static final long DEBOUNCE_MS = 150L;

    private long mLastDownMs = Long.MIN_VALUE / 2;
    private long mLastUpMs = Long.MIN_VALUE / 2;
    private boolean mHeld;
    private int mSuppressed;

    /** @return true when this press should toggle. */
    boolean acceptDown(long nowMs) {
        if (nowMs - mLastDownMs < DEBOUNCE_MS) {
            mSuppressed++;
            return false; // too close to the previous press: duplicate report or chatter
        }
        boolean releasedSinceLastPress = mLastUpMs > mLastDownMs;
        if (releasedSinceLastPress && nowMs - mLastUpMs < MIN_RELEASE_MS) {
            mSuppressed++;
            return false; // released a few milliseconds ago: contact bounce, not a click
        }
        mLastDownMs = nowMs;
        mHeld = true;
        return true;
    }

    /** Records the release; makes the next press eligible again. */
    void noteUp(long nowMs) {
        mHeld = false;
        mLastUpMs = nowMs;
    }

    /**
     * Resync from the box's own view ({@code EVT_STAT.cur == 0} means nothing is physically held).
     * Kept for symmetry with {@link #noteUp}; the gate no longer depends on it to stay unlocked.
     */
    void resyncReleased(long nowMs) {
        if (mHeld) {
            noteUp(nowMs);
        }
    }

    boolean held() {
        return mHeld;
    }

    int suppressed() {
        return mSuppressed;
    }

    void reset() {
        mLastDownMs = Long.MIN_VALUE / 2;
        mLastUpMs = Long.MIN_VALUE / 2;
        mHeld = false;
        mSuppressed = 0;
    }
}
