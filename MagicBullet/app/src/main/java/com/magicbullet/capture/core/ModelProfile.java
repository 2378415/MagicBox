package com.magicbullet.capture.core;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

/** One imported detection model: file, shape info and the label list. */
public final class ModelProfile {

    /** YOLOv8/v11 head: output [1, 4+nc, anchors]. */
    public static final int LAYOUT_V8 = 0;
    /** End-to-end head with NMS baked in: output [1, N, 6]. */
    public static final int LAYOUT_E2E = 1;
    /** Anything we cannot decode (multi-output heads, segmentation, ...). */
    public static final int LAYOUT_UNKNOWN = 2;
    /** InsightFace SCRFD face head: per-stride score [N,1], box [N,4], kps [N,10]. */
    public static final int LAYOUT_SCRFD = 3;

    public final String id;
    public final String name;
    public final String filePath;
    public final int inputSize;
    public final int layout;
    public final int numClasses;
    public final int anchors;
    public final List<String> labels;

    public ModelProfile(String id, String name, String filePath, int inputSize,
                        int layout, int numClasses, int anchors, List<String> labels) {
        this.id = id;
        this.name = name;
        this.filePath = filePath;
        this.inputSize = inputSize;
        this.layout = layout;
        this.numClasses = numClasses;
        this.anchors = anchors;
        this.labels = labels;
    }

    public String labelOf(int index) {
        if (index >= 0 && index < labels.size()) {
            return labels.get(index);
        }
        return "class_" + index;
    }

    public JSONObject toJson() throws JSONException {
        JSONObject o = new JSONObject();
        o.put("id", id);
        o.put("name", name);
        o.put("filePath", filePath);
        o.put("inputSize", inputSize);
        o.put("layout", layout);
        o.put("numClasses", numClasses);
        o.put("anchors", anchors);
        JSONArray arr = new JSONArray();
        for (String label : labels) {
            arr.put(label);
        }
        o.put("labels", arr);
        return o;
    }

    public static ModelProfile fromJson(JSONObject o) throws JSONException {
        List<String> labels = new ArrayList<>();
        JSONArray arr = o.optJSONArray("labels");
        if (arr != null) {
            for (int i = 0; i < arr.length(); i++) {
                labels.add(arr.optString(i));
            }
        }
        return new ModelProfile(
                o.optString("id"),
                o.optString("name"),
                o.optString("filePath"),
                o.optInt("inputSize", 640),
                o.optInt("layout", LAYOUT_V8),
                o.optInt("numClasses", labels.size()),
                o.optInt("anchors", 8400),
                labels);
    }
}
