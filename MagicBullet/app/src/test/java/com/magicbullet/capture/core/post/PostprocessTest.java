package com.magicbullet.capture.core.post;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import com.magicbullet.capture.core.Detection;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/** Decoder tests: pure arrays in, detections out — no device, no ONNX Runtime session. */
public class PostprocessTest {

    private static final String[] LABELS = {"person", "ball", "face"};

    /** 1280x720 into a 640 box: scale 0.5, 140 px bars top and bottom. */
    private static Geometry wide() {
        return new Geometry(640, 1280, 720);
    }

    @Test
    public void endToEndMapsCornersBackToSource() {
        float[][] rows = {{100f, 200f, 300f, 400f, 0.9f, 1f}};
        List<Detection> out = Postprocess.endToEnd(rows, 300, wide(), 0.3f, 0.45f, 30, LABELS);

        assertEquals(1, out.size());
        Detection box = out.get(0);
        assertEquals(200f / 1280f, box.left, 1e-5);
        assertEquals(120f / 720f, box.top, 1e-5);
        assertEquals(600f / 1280f, box.right, 1e-5);
        assertEquals(520f / 720f, box.bottom, 1e-5);
        assertEquals("ball", box.label);
        assertEquals(0.9f, box.score, 1e-6);
    }

    @Test
    public void endToEndDropsCandidatesBelowThreshold() {
        float[][] rows = {{100f, 200f, 300f, 400f, 0.29f, 0f}};
        assertTrue(Postprocess.endToEnd(rows, 300, wide(), 0.3f, 0.45f, 30, LABELS).isEmpty());
    }

    @Test
    public void yoloV8PicksBestClassAndConvertsCentreBox() {
        // [1, 4+2, 1]: cx, cy, w, h, score(person), score(ball)
        float[][] channels = {
                {320f}, {320f}, {100f}, {100f}, {0.1f}, {0.8f}};
        List<Detection> out = Postprocess.yoloV8(channels, 2, 1, wide(), 0.3f, 0.45f, 30, LABELS);

        assertEquals(1, out.size());
        Detection box = out.get(0);
        assertEquals("ball", box.label);
        assertEquals(540f / 1280f, box.left, 1e-5);
        assertEquals(260f / 720f, box.top, 1e-5);
        assertEquals(740f / 1280f, box.right, 1e-5);
        assertEquals(460f / 720f, box.bottom, 1e-5);
    }

    @Test
    public void yoloV8UsesClassFallbackWhenLabelsAreMissing() {
        float[][] channels = {{320f}, {320f}, {100f}, {100f}, {0.9f}};
        List<Detection> out = Postprocess.yoloV8(channels, 1, 1, wide(), 0.3f, 0.45f, 30,
                new String[0]);
        assertEquals("class_0", out.get(0).label);
    }

    @Test
    public void scrfdDecodesDistancesAroundTheCellOrigin() {
        // stride 8, 80x80 grid, 2 anchors; row 162 is location 81 (cx=8, cy=8).
        int rows = 164;
        float[][] scores = new float[rows][1];
        float[][] boxes = new float[rows][4];
        scores[162][0] = 0.9f;
        boxes[162] = new float[]{1f, 1f, 2f, 2f};
        List<Postprocess.ScrfdHead> heads = new ArrayList<>();
        heads.add(new Postprocess.ScrfdHead(scores, boxes, 8, 80, 2, rows));

        Geometry square = new Geometry(640, 640, 640);
        List<Detection> out = Postprocess.scrfd(heads, square, 0.5f, 0.45f, 30, LABELS);

        assertEquals(1, out.size());
        Detection box = out.get(0);
        assertEquals(0f, box.left, 1e-5);          // 8 - 1*8
        assertEquals(0f, box.top, 1e-5);
        assertEquals(24f / 640f, box.right, 1e-5); // 8 + 2*8
        assertEquals(24f / 640f, box.bottom, 1e-5);
        assertEquals("person", out.get(0).label);
    }

    @Test
    public void nmsSuppressesOverlapInsideOneClassOnly() {
        List<float[]> sameClass = new ArrayList<>();
        sameClass.add(new float[]{0, 0, 100, 100, 0.9f, 0});
        sameClass.add(new float[]{0, 0, 100, 100, 0.8f, 0});
        assertEquals(1, Nms.suppress(sameClass, 0.45f, 30).size());

        List<float[]> otherClass = new ArrayList<>();
        otherClass.add(new float[]{0, 0, 100, 100, 0.9f, 0});
        otherClass.add(new float[]{0, 0, 100, 100, 0.8f, 1});
        assertEquals(2, Nms.suppress(otherClass, 0.45f, 30).size());
    }

    @Test
    public void nmsKeepsHighestScoresUpToTheCap() {
        List<float[]> candidates = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            candidates.add(new float[]{i * 200, 0, i * 200 + 50, 50, 0.5f + i / 100f, 0});
        }
        List<float[]> kept = Nms.suppress(candidates, 0.45f, 3);
        assertEquals(3, kept.size());
        assertEquals(0.59f, kept.get(0)[4], 1e-6);
    }

    @Test
    public void detectionsAreClampedToTheFrame() {
        float[][] rows = {{-100f, -100f, 2000f, 2000f, 0.9f, 0f}};
        Detection box = Postprocess.endToEnd(rows, 300, wide(), 0.3f, 0.45f, 30, LABELS).get(0);
        assertEquals(0f, box.left, 1e-6);
        assertEquals(0f, box.top, 1e-6);
        assertEquals(1f, box.right, 1e-6);
        assertEquals(1f, box.bottom, 1e-6);
    }

    @Test
    public void squareCropMapsBackToFullFrameCoordinates() {
        // 1080x1080 crop of a 1920x1080 frame, centred: x offset 420, no letterbox bars.
        Geometry crop = new Geometry(640, 1920, 1080, 420, 0, 1080, 1080);
        assertEquals(420f, crop.sourceX(0f), 1e-4);
        assertEquals(0f, crop.sourceY(0f), 1e-4);
        assertEquals(1500f, crop.sourceX(640f), 1e-4);
        assertEquals(1080f, crop.sourceY(640f), 1e-4);

        // A box filling the whole model input must therefore cover exactly the crop.
        float[][] rows = {{0f, 0f, 640f, 640f, 0.9f, 0f}};
        Detection box = Postprocess.endToEnd(rows, 300, crop, 0.3f, 0.45f, 30, LABELS).get(0);
        assertEquals(420f / 1920f, box.left, 1e-5);
        assertEquals(0f, box.top, 1e-5);
        assertEquals(1500f / 1920f, box.right, 1e-5);
        assertEquals(1f, box.bottom, 1e-5);
    }
}
