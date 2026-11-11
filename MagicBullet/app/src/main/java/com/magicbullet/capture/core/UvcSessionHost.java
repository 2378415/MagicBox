package com.magicbullet.capture.core;

/**
 * Implemented by the Activity that owns the {@link UvcSession}; fragments use it to
 * reach the session without any global/static state.
 */
public interface UvcSessionHost {
    UvcSession session();
}
