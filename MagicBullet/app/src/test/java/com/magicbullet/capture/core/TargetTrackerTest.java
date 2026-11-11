package com.magicbullet.capture.core;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Set;

/**
 * The aiming maths that can be checked without a phone: head/body clustering and the velocity
 * estimate that drives feed-forward.
 */
public class TargetTrackerTest {

    private static final int W = 1920;
    private static final int H = 1080;
    private static final Set<String> ALL = Collections.emptySet();
    private static final long FRAME_NS = 16_666_667L;

    private static Detection body(float cx, float cy, float w, float h) {
        return new Detection(cx - w / 2f, cy - h / 2f, cx + w / 2f, cy + h / 2f, "body", 0.9f);
    }

    private static Detection head(float cx, float cy, float w, float h) {
        return new Detection(cx - w / 2f, cy - h / 2f, cx + w / 2f, cy + h / 2f, "head", 0.8f);
    }

    @Test
    public void headAnchorDefaultsToTheChin() {
        // 头部框 0.34..0.42，默认 bias 1.0 → 瞄点落在下沿 0.42
        TargetTracker tracker = new TargetTracker();
        List<Detection> frame = new ArrayList<>();
        frame.add(body(0.5f, 0.5f, 0.1f, 0.3f));
        frame.add(head(0.5f, 0.38f, 0.04f, 0.08f));
        List<TargetTracker.Candidate> out = tracker.update(frame, W, H, 1_000_000_000L, ALL);
        assertEquals(1, out.size());
        TargetTracker.Candidate candidate = out.get(0);
        assertTrue("head shot expected", candidate.headShot);
        assertEquals(0.5f * W, candidate.x, 1f);
        assertEquals(0.42f * H, candidate.y, 2f);
    }

    @Test
    public void headAnchorBiasHalfIsTheBoxCentre() {
        TargetTracker tracker = new TargetTracker();
        tracker.setHeadAnchorBias(0.5f);
        List<Detection> frame = new ArrayList<>();
        frame.add(body(0.5f, 0.5f, 0.1f, 0.3f));
        frame.add(head(0.5f, 0.38f, 0.04f, 0.08f));
        List<TargetTracker.Candidate> out = tracker.update(frame, W, H, 2_000_000_000L, ALL);
        assertEquals(0.38f * H, out.get(0).y, 2f);
    }

    @Test
    public void bodyOnlyFallsBackToBoxCentre() {
        TargetTracker tracker = new TargetTracker();
        List<TargetTracker.Candidate> out = tracker.update(
                Collections.singletonList(body(0.4f, 0.6f, 0.1f, 0.2f)), W, H, 1_000_000_000L, ALL);
        assertEquals(1, out.size());
        assertEquals(0.4f * W, out.get(0).x, 1f);
        assertEquals(0.6f * H, out.get(0).y, 1f);
        assertFalse(out.get(0).headShot);
        // 选近优先用的等效体高：body 候选直接取自己的框高
        assertEquals(0.2f, out.get(0).sizeProxy, 0.001f);
        // 选敌主键（头框）不存在，次键（身体框）就是它自己
        assertEquals(0f, out.get(0).headSize, 0.001f);
        assertEquals(0.2f, out.get(0).bodySize, 0.001f);
    }

    @Test
    public void headOnlyCandidateScalesItsSizeProxyToBodyHeight() {
        // 只有 head 框（0.04 宽 × 0.05 高）→ 等效体高 = 0.05 × 5 = 0.25
        TargetTracker tracker = new TargetTracker();
        List<TargetTracker.Candidate> out = tracker.update(
                Collections.singletonList(head(0.5f, 0.42f, 0.04f, 0.05f)),
                W, H, 1_000_000_000L, ALL);
        assertEquals(1, out.size());
        assertEquals(0.25f, out.get(0).sizeProxy, 0.005f);
        assertEquals(0.05f, out.get(0).headSize, 0.001f);
        assertEquals("head-only has no body box", 0f, out.get(0).bodySize, 0.001f);
    }

    @Test
    public void headAttachedToBodyUsesTheBodyHeightAsSizeProxy() {
        TargetTracker tracker = new TargetTracker();
        List<Detection> frame = new ArrayList<>();
        frame.add(body(0.5f, 0.5f, 0.1f, 0.30f));
        frame.add(head(0.5f, 0.38f, 0.04f, 0.08f));
        List<TargetTracker.Candidate> out = tracker.update(frame, W, H, 1_000_000_000L, ALL);
        assertEquals(1, out.size());
        assertEquals(0.30f, out.get(0).sizeProxy, 0.001f);
        assertEquals("head box height is kept separately for the tie-break",
                0.08f, out.get(0).headSize, 0.001f);
        assertEquals(0.30f, out.get(0).bodySize, 0.001f);
    }

    @Test
    public void boxSizesAreSmoothedAcrossFrames() {
        // α = 0.30：首帧直通 0.05，第二帧跳变到 0.09 只吸收 30%
        // → 0.3 × 0.09 + 0.7 × 0.05 = 0.062
        TargetTracker tracker = new TargetTracker();
        tracker.setSizeFilter(0.30f);
        List<TargetTracker.Candidate> first = tracker.update(
                Collections.singletonList(head(0.5f, 0.42f, 0.04f, 0.05f)), W, H, 1L, ALL);
        assertEquals(0.05f, first.get(0).headSize, 0.001f);
        List<TargetTracker.Candidate> second = tracker.update(
                Collections.singletonList(head(0.5f, 0.40f, 0.08f, 0.09f)),
                W, H, 1_000_000_000L, ALL);
        assertEquals(1, second.size());
        assertEquals("jump is absorbed by the EMA, not passed through", 0.062f,
                second.get(0).headSize, 0.002f);
    }

    @Test
    public void sizeFilterOfOneDisablesSmoothing() {
        TargetTracker tracker = new TargetTracker();
        tracker.setSizeFilter(1f);
        tracker.update(Collections.singletonList(head(0.5f, 0.42f, 0.04f, 0.05f)), W, H, 1L, ALL);
        List<TargetTracker.Candidate> second = tracker.update(
                Collections.singletonList(head(0.5f, 0.40f, 0.08f, 0.09f)),
                W, H, 1_000_000_000L, ALL);
        assertEquals(0.09f, second.get(0).headSize, 0.001f);
    }

    @Test
    public void velocityMatchesASteadyTarget() {
        TargetTracker tracker = new TargetTracker();
        tracker.setVelocityFilter(1f, 2000, 0);
        // 200 px/s to the right: 1920 * 0.1042 per second ≈ 0.001736 per frame.
        float startCx = 0.3f;
        float stepPerFrame = 200f * (FRAME_NS / 1e9f) / W;
        TargetTracker.Candidate last = null;
        for (int i = 0; i < 6; i++) {
            long ts = 1_000_000_000L + i * FRAME_NS;
            List<Detection> frame = Collections.singletonList(
                    body(startCx + i * stepPerFrame, 0.5f, 0.08f, 0.2f));
            List<TargetTracker.Candidate> out = tracker.update(frame, W, H, ts, ALL);
            assertEquals(1, out.size());
            last = out.get(0);
        }
        assertEquals("forward direction", 200f, last.vx, 25f);
        assertEquals("no vertical drift", 0f, last.vy, 5f);
        assertTrue("tracked long enough for feed-forward", last.frames >= 3);
    }

    @Test
    public void velocityIsZeroForAStillTarget() {
        TargetTracker tracker = new TargetTracker();
        tracker.setVelocityFilter(1f, 2000, 30);
        TargetTracker.Candidate last = null;
        for (int i = 0; i < 5; i++) {
            long ts = 2_000_000_000L + i * FRAME_NS;
            last = tracker.update(Collections.singletonList(body(0.5f, 0.5f, 0.08f, 0.2f)),
                    W, H, ts, ALL).get(0);
        }
        assertEquals(0f, last.vx, 0.001f);
        assertEquals(0f, last.vy, 0.001f);
    }

    @Test
    public void staleTracksAreDropped() {
        TargetTracker tracker = new TargetTracker();
        tracker.update(Collections.singletonList(body(0.5f, 0.5f, 0.08f, 0.2f)),
                W, H, 1_000_000_000L, ALL);
        List<TargetTracker.Candidate> out = tracker.update(Collections.<Detection>emptyList(),
                W, H, 1_400_000_000L, ALL);
        assertTrue("a target gone for 400 ms must not be aimed at", out.isEmpty());
    }

    @Test
    public void classFilterKeepsOtherLabelsOut() {
        TargetTracker tracker = new TargetTracker();
        List<Detection> frame = Arrays.asList(
                new Detection(0.1f, 0.1f, 0.2f, 0.3f, "team", 0.9f),
                body(0.5f, 0.5f, 0.08f, 0.2f));
        Set<String> onlyBody = Collections.singleton("body");
        List<TargetTracker.Candidate> out = tracker.update(frame, W, H, 1_000_000_000L, onlyBody);
        assertEquals(1, out.size());
        assertEquals("body", out.get(0).label);
    }

    @Test
    public void aimRectCentresTheCrosshair() {
        AimRect rect = AimRect.DEFAULT;
        assertEquals(0.5f * W, rect.anchorX(W), 1f);
        assertEquals(0.5f * H, rect.anchorY(H), 1f);
        assertTrue(rect.contains(0.5f, 0.5f));
        assertFalse(rect.contains(0.02f, 0.5f));
        AimRect moved = rect.centredAt(0.6f, 0.6f);
        assertEquals(0.6f * W, moved.anchorX(W), 1f);
        assertEquals(rect.w, moved.w, 1e-6f);
    }
}
