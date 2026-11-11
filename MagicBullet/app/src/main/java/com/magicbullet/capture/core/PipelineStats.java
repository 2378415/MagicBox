package com.magicbullet.capture.core;

import android.os.SystemClock;

import java.util.Set;
import java.util.concurrent.CopyOnWriteArraySet;

/**
 * Live numbers for the Yolo tab: capture rate, detector time and frame-to-draw latency.
 *
 * <p>Process-wide and listener based, because the producer (preview fragment, on the
 * capture thread) and the consumer (Yolo tab) are different fragments.
 */
public final class PipelineStats {

    public interface Listener {
        void onStats(double fps, double inferMs, double latencyMs);
    }

    private static final long NOTIFY_INTERVAL_MS = 250L;
    private static final PipelineStats INSTANCE = new PipelineStats();

    private final Set<Listener> mListeners = new CopyOnWriteArraySet<>();

    private volatile String mBackend = "";
    private volatile double mFps;
    private volatile double mInferMs;
    private volatile double mLatencyMs;
    private volatile double mCopyMs;
    private volatile double mPreMs;
    private volatile double mRunMs;
    private volatile double mPostMs;
    private long mLastNotifyMs;

    private PipelineStats() {
    }

    public static PipelineStats get() {
        return INSTANCE;
    }

    public void addListener(Listener listener) {
        mListeners.add(listener);
        listener.onStats(mFps, mInferMs, mLatencyMs);
    }

    public void removeListener(Listener listener) {
        mListeners.remove(listener);
    }

    public String backend() {
        return mBackend;
    }

    public void setBackend(String backend) {
        mBackend = backend;
    }

    public double captureFps() {
        return mFps;
    }

    public double inferMs() {
        return mInferMs;
    }

    public double latencyMs() {
        return mLatencyMs;
    }

    public void setCaptureFps(double fps) {
        mFps = fps;
    }

    public void setInferMs(double inferMs) {
        mInferMs = inferMs;
    }

    public void setLatencyMs(double latencyMs) {
        mLatencyMs = latencyMs;
    }

    /** Frame copy from the UVC buffer into the detector-owned array. */
    public double copyMs() {
        return mCopyMs;
    }

    /** Letterbox + normalise into the model input tensor. */
    public double preMs() {
        return mPreMs;
    }

    /** The ONNX Runtime run itself (the DSP/NPU part). */
    public double runMs() {
        return mRunMs;
    }

    /** Decode + NMS after the run. */
    public double postMs() {
        return mPostMs;
    }

    public void setStages(double copyMs, double preMs, double runMs, double postMs) {
        mCopyMs = copyMs;
        mPreMs = preMs;
        mRunMs = runMs;
        mPostMs = postMs;
    }

    public void publish() {
        long now = SystemClock.elapsedRealtime();
        if (now - mLastNotifyMs < NOTIFY_INTERVAL_MS) {
            return;
        }
        mLastNotifyMs = now;
        double fps = mFps;
        double infer = mInferMs;
        double latency = mLatencyMs;
        for (Listener listener : mListeners) {
            listener.onStats(fps, infer, latency);
        }
    }
}

