package com.magicbullet.capture.core;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Set;

/**
 * Turns per-frame detections into stable, velocity-aware aim candidates.
 *
 * <p>Three jobs, in order:
 * <ol>
 *   <li>cluster a {@code head} box onto the {@code body} box it belongs to, so one enemy is one
 *       candidate and the aim point is the head centre (falling back to the body centre);</li>
 *   <li>match candidates between frames (nearest neighbour within a few tens of pixels) and keep a
 *       short position history per track;</li>
 *   <li>fit a velocity to that history and low-pass it - the feed-forward term the controller
 *       needs to cancel pipeline latency.</li>
 * </ol>
 *
 * <p>Everything is allocation-light: the per-frame lists are reused, so a 60 fps loop does not
 * hand work to the collector.
 */
public final class TargetTracker {

    /** One live target. */
    public static final class Candidate {
        public final int id;
        public final String label;
        public final float score;
        /** Aim point in frame pixels. */
        public final float x;
        public final float y;
        /** Velocity in pixels per second, already smoothed and clamped. */
        public final float vx;
        public final float vy;
        /** How many frames this track has been seen (velocity is not trustworthy below 3). */
        public final int frames;
        /** Body box centre in normalised frame coordinates, for the overlay. */
        public final float boxCx;
        public final float boxCy;
        public final float boxW;
        public final float boxH;
        public final boolean headShot;
        /** 头框高度（归一化），没有头框时为 0。选敌主键：先比头框，再比身体框。 */
        public final float headSize;
        /** 身体框高度（归一化），模型只给头时为 0。选敌次键：头框并列时身体框大的优先。 */
        public final float bodySize;
        /**
         * 等效人体高度（归一化），只用于"谁更近"的比较（粘滞门槛）：有身体框就取 body 框高，
         * 只有头时按 {@link #HEAD_TO_BODY} 折算成体高。和 {@link #boxW}/{@link #boxH} 分开
         * 是因为后两个是 overlay 画框用的真实框尺寸，不能被换算污染。
         */
        public final float sizeProxy;

        Candidate(int id, String label, float score, float x, float y, float vx, float vy,
                  int frames, float boxCx, float boxCy, float boxW, float boxH, boolean headShot,
                  float headSize, float bodySize) {
            this.id = id;
            this.label = label;
            this.score = score;
            this.x = x;
            this.y = y;
            this.vx = vx;
            this.vy = vy;
            this.frames = frames;
            this.boxCx = boxCx;
            this.boxCy = boxCy;
            this.boxW = boxW;
            this.boxH = boxH;
            this.headShot = headShot;
            this.headSize = headSize;
            this.bodySize = bodySize;
            this.sizeProxy = bodySize > 0f ? bodySize : headSize * HEAD_TO_BODY;
        }

        public float speedPx() {
            return (float) Math.hypot(vx, vy);
        }
    }

    /** One enemy as seen in this frame, before tracking. */
    private static final class Observation {
        final String label;
        final float score;
        final float ax;
        final float ay;
        final float boxCx;
        final float boxCy;
        final float boxW;
        final float boxH;
        final boolean headShot;
        final float headSize;
        final float bodySize;

        Observation(String label, float score, float ax, float ay,
                    float boxCx, float boxCy, float boxW, float boxH, boolean headShot,
                    float headSize, float bodySize) {
            this.label = label;
            this.score = score;
            this.ax = ax;
            this.ay = ay;
            this.boxCx = boxCx;
            this.boxCy = boxCy;
            this.boxW = boxW;
            this.boxH = boxH;
            this.headShot = headShot;
            this.headSize = headSize;
            this.bodySize = bodySize;
        }
    }

    private static final int HISTORY = 5;
    private static final long MAX_GAP_NS = 250_000_000L;
    private static final long STALE_NS = 300_000_000L;
    private static final float MATCH_RADIUS_PX = 56f;
    /** A jump larger than this in one frame is a different box, not the same target moving. */
    private static final float MAX_FRAME_JUMP_PX = 40f;
    /** A head counts as "on" a body when this much of the head is inside the body box. */
    private static final float HEAD_INSIDE_RATIO = 0.50f;
    /**
     * 头高 → 体高的折算系数：模型只输出 head 框时，用它把 {@code sizeProxy} 折算成
     * 与 body 候选可比的量纲（人立姿体高 ≈ 5 倍头高）。换模型后可在此标定。
     */
    private static final float HEAD_TO_BODY = 5.0f;
    /** 瞄点在头部框内的纵向位置：1.0 = 下沿（下巴），0.5 = 中心。 */
    private float mHeadAnchorBias = 1.0f;
    /**
     * 框尺寸（headSize/bodySize）的 EMA 平滑系数。YOLO 框高逐帧抖动 ±5~10%，而选敌现在拿
     * 框高当距离主键，不平滑就会出现"两个近敌互相抢锁"：这一帧 A 大 10%、下一帧 B 大 9%。
     */
    private float mSizeEma = 0.30f;

    private static final class Track {
        int id;
        long lastNs;
        float x;
        float y;
        float boxCx;
        float boxCy;
        float boxW;
        float boxH;
        float headSize;
        float bodySize;
        float headSizeEma;
        float bodySizeEma;
        int sizeFrames;
        String label = "";
        float score;
        boolean headShot;
        int frames;
        int n;
        final long[] tNs = new long[HISTORY];
        final float[] xs = new float[HISTORY];
        final float[] ys = new float[HISTORY];
        long prevNs;
        float prevX;
        float prevY;
        float vx;
        float vy;

        void push(long ts, float px, float py) {
            int slot = n % HISTORY;
            tNs[slot] = ts;
            xs[slot] = px;
            ys[slot] = py;
            n = Math.min(n + 1, HISTORY);
        }
    }

    private final List<Track> mTracks = new ArrayList<>();
    private final List<Observation> mObservations = new ArrayList<>();
    private final List<Candidate> mOut = new ArrayList<>();
    private int mNextId = 1;

    private float mEma = 0.5f;
    private int mMaxVelPxPerSec = 1200;
    private int mMinVelPxPerSec = 30;

    /** 头部框内瞄点的纵向位置（1.0 = 下巴/下沿）。 */
    public void setHeadAnchorBias(float bias) {
        mHeadAnchorBias = Math.max(0f, Math.min(1f, bias));
    }

    public void setVelocityFilter(float ema, int maxVelPxPerSec, int minVelPxPerSec) {
        mEma = Math.max(0.2f, Math.min(0.8f, ema));
        mMaxVelPxPerSec = Math.max(200, maxVelPxPerSec);
        mMinVelPxPerSec = Math.max(0, minVelPxPerSec);
    }

    /** 框尺寸 EMA 平滑系数（1.0 = 不平滑，越小越稳但越迟钝）。 */
    public void setSizeFilter(float ema) {
        mSizeEma = Math.max(0.05f, Math.min(1f, ema));
    }

    /** Drops every track: used when aiming is re-armed or the frame size changes. */
    public void reset() {
        mTracks.clear();
        mOut.clear();
    }

    /**
     * Feeds one detection frame and returns the live candidates.
     *
     * @param dets   detections in normalised frame coordinates
     * @param frameW frame width in pixels (velocity unit)
     * @param frameH frame height in pixels
     * @param tsNanos capture timestamp of this frame
     * @param classes lower-case label names that may be aimed at; empty = all
     */
    public List<Candidate> update(List<Detection> dets, int frameW, int frameH, long tsNanos,
                                  Set<String> classes) {
        buildObservations(dets, frameW, frameH, classes);

        for (Track track : mTracks) {
            track.lastNs = -1L; // marks "not matched in this frame"
        }
        for (Observation obs : mObservations) {
            Track best = null;
            float bestDistance = MATCH_RADIUS_PX;
            for (Track track : mTracks) {
                if (track.lastNs != -1L) {
                    continue; // already taken by a closer observation this frame
                }
                float dx = track.x - obs.ax;
                float dy = track.y - obs.ay;
                float distance = (float) Math.hypot(dx, dy);
                if (distance < bestDistance && distance <= MAX_FRAME_JUMP_PX) {
                    bestDistance = distance;
                    best = track;
                }
            }
            if (best == null) {
                best = new Track();
                best.id = mNextId++;
                mTracks.add(best);
            }
            updateTrack(best, obs, tsNanos);
        }

        mOut.clear();
        for (int i = mTracks.size() - 1; i >= 0; i--) {
            Track track = mTracks.get(i);
            if (track.lastNs < 0 || tsNanos - track.lastNs > STALE_NS) {
                mTracks.remove(i);
            }
        }
        for (Track track : mTracks) {
            mOut.add(new Candidate(track.id, track.label, track.score, track.x, track.y,
                    track.vx, track.vy, track.frames, track.boxCx, track.boxCy,
                    track.boxW, track.boxH, track.headShot, track.headSize, track.bodySize));
        }
        return mOut;
    }

    // ------------------------------------------------------------------ clustering

    private void buildObservations(List<Detection> dets, int frameW, int frameH,
                                   Set<String> classes) {
        mObservations.clear();
        if (dets == null || dets.isEmpty()) {
            return;
        }
        boolean filter = classes != null && !classes.isEmpty();
        for (Detection d : dets) {
            if (filter && !classes.contains(d.label.toLowerCase(Locale.US))) {
                continue;
            }
            if (isHead(d.label)) {
                continue; // heads are attached to a body below, or added alone
            }
            Detection head = bestHeadFor(d, dets);
            float ax;
            float ay;
            if (head != null) {
                ax = (head.left + head.right) / 2f * frameW;
                ay = AimPick.anchorY(head.top * frameH, head.bottom * frameH, mHeadAnchorBias);
                mObservations.add(new Observation(d.label, Math.max(d.score, head.score), ax, ay,
                        (d.left + d.right) / 2f, (d.top + d.bottom) / 2f,
                        d.right - d.left, d.bottom - d.top, true,
                        head.bottom - head.top, d.bottom - d.top));
            } else {
                ax = (d.left + d.right) / 2f * frameW;
                ay = (d.top + d.bottom) / 2f * frameH;
                mObservations.add(new Observation(d.label, d.score, ax, ay,
                        (d.left + d.right) / 2f, (d.top + d.bottom) / 2f,
                        d.right - d.left, d.bottom - d.top, false,
                        0f, d.bottom - d.top));
            }
        }
        // A head with no body of its own (models that only detect heads) is still a target.
        for (Detection d : dets) {
            if (!isHead(d.label) || (filter && !classes.contains(d.label.toLowerCase(Locale.US)))) {
                continue;
            }
            boolean attached = false;
            // 必须用同一套 bias 算出来的锚点做比对，否则"瞄点在下沿"时会把已聚类的 head 当成新的。
            final float headAy = AimPick.anchorY(d.top * frameH, d.bottom * frameH, mHeadAnchorBias);
            for (Observation obs : mObservations) {
                if (obs.headShot
                        && Math.abs(obs.ax - (d.left + d.right) / 2f * frameW) < frameW * 0.02f
                        && Math.abs(obs.ay - headAy) < frameH * 0.02f) {
                    attached = true;
                    break;
                }
            }
            if (!attached) {
                mObservations.add(new Observation(d.label, d.score,
                        (d.left + d.right) / 2f * frameW,
                        AimPick.anchorY(d.top * frameH, d.bottom * frameH, mHeadAnchorBias),
                        (d.left + d.right) / 2f, (d.top + d.bottom) / 2f,
                        d.right - d.left, d.bottom - d.top, true,
                        d.bottom - d.top, 0f));
            }
        }
    }

    private Detection bestHeadFor(Detection body, List<Detection> dets) {
        Detection best = null;
        float bestOverlap = 0f;
        for (Detection candidate : dets) {
            if (!isHead(candidate.label)) {
                continue;
            }
            float overlap = overlapRatio(candidate, body);
            // The head must sit in the body, mostly in its upper part.
            boolean upper = candidate.top < body.top + (body.bottom - body.top) * 0.55f;
            if (upper && overlap > bestOverlap) {
                bestOverlap = overlap;
                best = candidate;
            }
        }
        return bestOverlap >= HEAD_INSIDE_RATIO ? best : null;
    }

    /** Fraction of {@code inner} that lies inside {@code outer}. */
    private static float overlapRatio(Detection inner, Detection outer) {
        float w = Math.min(inner.right, outer.right) - Math.max(inner.left, outer.left);
        float h = Math.min(inner.bottom, outer.bottom) - Math.max(inner.top, outer.top);
        if (w <= 0f || h <= 0f) {
            return 0f;
        }
        float area = Math.max(1e-6f, (inner.right - inner.left) * (inner.bottom - inner.top));
        return (w * h) / area;
    }

    private static boolean isHead(String label) {
        return label != null && "head".equalsIgnoreCase(label.trim());
    }

    // ------------------------------------------------------------------ tracking

    private void updateTrack(Track track, Observation obs, long tsNanos) {
        if (track.lastNs > 0) {
            track.prevNs = track.lastNs;
            track.prevX = track.x;
            track.prevY = track.y;
        }
        track.lastNs = tsNanos;
        track.x = obs.ax;
        track.y = obs.ay;
        track.label = obs.label;
        track.score = obs.score;
        track.boxCx = obs.boxCx;
        track.boxCy = obs.boxCy;
        track.boxW = obs.boxW;
        track.boxH = obs.boxH;
        // 尺寸走 EMA：选敌主键必须比单帧检测框稳定，否则两个近敌会逐帧互相夺锁。
        if (track.sizeFrames == 0) {
            track.headSizeEma = obs.headSize;
            track.bodySizeEma = obs.bodySize;
        } else {
            track.headSizeEma = mSizeEma * obs.headSize + (1f - mSizeEma) * track.headSizeEma;
            track.bodySizeEma = mSizeEma * obs.bodySize + (1f - mSizeEma) * track.bodySizeEma;
        }
        track.sizeFrames++;
        track.headSize = track.headSizeEma;
        track.bodySize = track.bodySizeEma;
        track.headShot = obs.headShot;
        track.frames++;
        track.push(tsNanos, obs.ax, obs.ay);
        updateVelocity(track);
    }

    /** Least-squares slope over the history, then EMA, then clamp. */
    private void updateVelocity(Track track) {
        if (track.n < 3) {
            track.vx = 0f;
            track.vy = 0f;
            return;
        }
        int n = track.n;
        double sumT = 0;
        double sumX = 0;
        double sumY = 0;
        long base = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            base = Math.min(base, track.tNs[i]);
        }
        for (int i = 0; i < n; i++) {
            double t = (track.tNs[i] - base) / 1e9;
            sumT += t;
            sumX += track.xs[i];
            sumY += track.ys[i];
        }
        double meanT = sumT / n;
        double meanX = sumX / n;
        double meanY = sumY / n;
        double numX = 0;
        double numY = 0;
        double den = 0;
        for (int i = 0; i < n; i++) {
            double t = (track.tNs[i] - base) / 1e9 - meanT;
            numX += t * (track.xs[i] - meanX);
            numY += t * (track.ys[i] - meanY);
            den += t * t;
        }
        if (den <= 1e-9) {
            return;
        }
        float rawVx = (float) (numX / den);
        float rawVy = (float) (numY / den);
        // The first estimate has nothing to smooth against.
        if (track.frames <= 3) {
            track.vx = rawVx;
            track.vy = rawVy;
        } else {
            track.vx = mEma * rawVx + (1f - mEma) * track.vx;
            track.vy = mEma * rawVy + (1f - mEma) * track.vy;
        }
        float speed = (float) Math.hypot(track.vx, track.vy);
        if (speed > mMaxVelPxPerSec) {
            float scale = mMaxVelPxPerSec / speed;
            track.vx *= scale;
            track.vy *= scale;
            speed = mMaxVelPxPerSec;
        }
        if (speed < mMinVelPxPerSec) {
            track.vx = 0f;
            track.vy = 0f;
        }
    }
}
