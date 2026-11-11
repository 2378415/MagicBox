package com.magicbullet.capture.core;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * The inference configuration of the YOLO tab as one immutable value: thresholds, the selected
 * model and its class list.
 *
 * <p>The tab edits a draft of this and only commits it on "应用", so this type also answers the
 * "nothing changed, skip the apply" question via {@link #equals(Object)}.
 */
public final class YoloSettings {

    public final float conf;
    public final float iou;
    public final int maxDetections;
    /** Model profile id, or null for the bundled model. */
    public final String modelId;
    public final List<String> labels;

    public YoloSettings(float conf, float iou, int maxDetections, String modelId,
                        List<String> labels) {
        this.conf = conf;
        this.iou = iou;
        this.maxDetections = maxDetections;
        this.modelId = modelId;
        this.labels = labels == null
                ? Collections.emptyList() : Collections.unmodifiableList(new ArrayList<>(labels));
    }

    /** Confidence and IoU are probabilities, and at least one box has to be allowed. */
    public boolean isValid() {
        return conf > 0f && conf <= 1f && iou > 0f && iou <= 1f && maxDetections >= 1;
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) {
            return true;
        }
        if (!(other instanceof YoloSettings)) {
            return false;
        }
        YoloSettings that = (YoloSettings) other;
        return Float.compare(conf, that.conf) == 0
                && Float.compare(iou, that.iou) == 0
                && maxDetections == that.maxDetections
                && (modelId == null ? that.modelId == null : modelId.equals(that.modelId))
                && labels.equals(that.labels);
    }

    @Override
    public int hashCode() {
        int result = Float.floatToIntBits(conf);
        result = 31 * result + Float.floatToIntBits(iou);
        result = 31 * result + maxDetections;
        result = 31 * result + (modelId == null ? 0 : modelId.hashCode());
        result = 31 * result + labels.hashCode();
        return result;
    }

    @Override
    public String toString() {
        return "conf=" + conf + " iou=" + iou + " max=" + maxDetections
                + " model=" + modelId + " labels=" + labels.size();
    }
}
