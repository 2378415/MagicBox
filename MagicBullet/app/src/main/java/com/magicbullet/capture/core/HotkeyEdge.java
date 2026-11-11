package com.magicbullet.capture.core;

/**
 * Edge logic for the aim hotkey, kept pure so multi-key behaviour can be unit-tested.
 *
 * <p>The hotkey mask can hold several bits (right button, side buttons). "Pressed" means <em>any</em>
 * subscribed bit is held, so a second key going down while the first is still held must not produce
 * another press - otherwise holding right-click and tapping a side button would toggle aim twice.
 *
 * <p>{@link #update} therefore only reports the transitions of the combined state:
 * none-held → some-held (press) and some-held → none-held (release).
 */
final class HotkeyEdge {

    private HotkeyEdge() {
    }

    /** True when any subscribed bit is currently held. */
    static boolean anyHeld(int buttons, int mask) {
        return (buttons & mask) != 0;
    }

    /**
     * Updates the previous state and reports the transition.
     *
     * @return {@link #PRESS} when the combined state went down, {@link #RELEASE} when it went up,
     *         {@link #NONE} when nothing changed (including "a second key was added")
     */
    static int transition(boolean wasHeld, boolean nowHeld) {
        if (wasHeld == nowHeld) {
            return NONE;
        }
        return nowHeld ? PRESS : RELEASE;
    }

    public static final int NONE = 0;
    public static final int PRESS = 1;
    public static final int RELEASE = -1;
}
