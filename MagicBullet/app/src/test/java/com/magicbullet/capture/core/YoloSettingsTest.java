package com.magicbullet.capture.core;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

import java.util.Arrays;
import java.util.Collections;

/** Draft-vs-applied comparison used by the "配置未变化" shortcut. */
public class YoloSettingsTest {

    private static YoloSettings settings(float conf, float iou, int maxDet) {
        return new YoloSettings(conf, iou, maxDet, "model-1", Arrays.asList("person", "ball"));
    }

    @Test
    public void identicalSettingsCompareEqual() {
        assertEquals(settings(0.65f, 0.45f, 20), settings(0.65f, 0.45f, 20));
        assertEquals(settings(0.65f, 0.45f, 20).hashCode(), settings(0.65f, 0.45f, 20).hashCode());
    }

    @Test
    public void anyThresholdDifferenceBreaksEquality() {
        assertNotEquals(settings(0.65f, 0.45f, 20), settings(0.66f, 0.45f, 20));
        assertNotEquals(settings(0.65f, 0.45f, 20), settings(0.65f, 0.46f, 20));
        assertNotEquals(settings(0.65f, 0.45f, 20), settings(0.65f, 0.45f, 21));
    }

    @Test
    public void modelOrLabelsDifferenceBreaksEquality() {
        YoloSettings base = settings(0.65f, 0.45f, 20);
        assertNotEquals(base, new YoloSettings(0.65f, 0.45f, 20, "model-2",
                Arrays.asList("person", "ball")));
        assertNotEquals(base, new YoloSettings(0.65f, 0.45f, 20, "model-1",
                Collections.singletonList("person")));
        assertNotEquals(base, new YoloSettings(0.65f, 0.45f, 20, null,
                Arrays.asList("person", "ball")));
    }

    @Test
    public void labelsAreDefensivelyCopiedAndUnmodifiable() {
        java.util.List<String> source = new java.util.ArrayList<>(Arrays.asList("a"));
        YoloSettings s = new YoloSettings(0.5f, 0.5f, 10, null, source);
        source.add("b");
        assertEquals(1, s.labels.size());
        try {
            s.labels.add("c");
            throw new AssertionError("labels should be unmodifiable");
        } catch (UnsupportedOperationException expected) {
            // expected
        }
    }

    @Test
    public void validationRejectsOutOfRangeValues() {
        assertTrue(settings(0.65f, 0.45f, 20).isValid());
        assertTrue(new YoloSettings(1f, 1f, 1, null, Collections.emptyList()).isValid());
        assertFalse(settings(0f, 0.45f, 20).isValid());
        assertFalse(settings(1.01f, 0.45f, 20).isValid());
        assertFalse(settings(0.65f, 0f, 20).isValid());
        assertFalse(settings(0.65f, 0.45f, 0).isValid());
    }
}
