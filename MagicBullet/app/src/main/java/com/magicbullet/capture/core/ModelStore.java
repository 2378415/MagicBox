package com.magicbullet.capture.core;

import android.content.Context;
import android.content.SharedPreferences;
import android.net.Uri;
import android.util.Log;

import org.json.JSONArray;
import org.json.JSONObject;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Imported models on disk plus the one currently selected.
 *
 * <p>The built-in COCO model lives in assets and is used whenever no import is
 * selected or an import fails to load.
 */
public final class ModelStore {

    private static final String TAG = "ModelStore";
    private static final String PREFS = "model_store";
    private static final String KEY_LIST = "profiles";
    private static final String KEY_CURRENT = "current_id";
    private static final String KEY_REVISION = "apply_revision";

    public static final String BUILTIN_ASSET = "yolov8n_int8_qdq.onnx";

    public static final String[] COCO_LABELS = {
            "person", "bicycle", "car", "motorcycle", "airplane", "bus", "train", "truck",
            "boat", "traffic light", "fire hydrant", "stop sign", "parking meter", "bench",
            "bird", "cat", "dog", "horse", "sheep", "cow", "elephant", "bear", "zebra",
            "giraffe", "backpack", "umbrella", "handbag", "tie", "suitcase", "frisbee",
            "skis", "snowboard", "sports ball", "kite", "baseball bat", "baseball glove",
            "skateboard", "surfboard", "tennis racket", "bottle", "wine glass", "cup",
            "fork", "knife", "spoon", "bowl", "banana", "apple", "sandwich", "orange",
            "broccoli", "carrot", "hot dog", "pizza", "donut", "cake", "chair", "couch",
            "potted plant", "bed", "dining table", "toilet", "tv", "laptop", "mouse",
            "remote", "keyboard", "cell phone", "microwave", "oven", "toaster", "sink",
            "refrigerator", "book", "clock", "vase", "scissors", "teddy bear",
            "hair drier", "toothbrush"
    };

    private final Context mContext;
    private final SharedPreferences mPrefs;

    public ModelStore(Context context) {
        mContext = context.getApplicationContext();
        mPrefs = mContext.getSharedPreferences(PREFS, Context.MODE_PRIVATE);
    }

    public File modelsDir() {
        File dir = new File(mContext.getFilesDir(), "models");
        if (!dir.exists() && !dir.mkdirs()) {
            Log.w(TAG, "cannot create " + dir);
        }
        return dir;
    }

    public List<ModelProfile> list() {
        List<ModelProfile> out = new ArrayList<>();
        String raw = mPrefs.getString(KEY_LIST, "[]");
        try {
            JSONArray arr = new JSONArray(raw);
            for (int i = 0; i < arr.length(); i++) {
                out.add(ModelProfile.fromJson(arr.getJSONObject(i)));
            }
        } catch (Throwable t) {
            Log.w(TAG, "corrupted profile list, resetting", t);
        }
        return out;
    }

    private void saveList(List<ModelProfile> profiles) {
        JSONArray arr = new JSONArray();
        for (ModelProfile p : profiles) {
            try {
                arr.put(p.toJson());
            } catch (Throwable t) {
                Log.w(TAG, "cannot serialize " + p.name, t);
            }
        }
        mPrefs.edit().putString(KEY_LIST, arr.toString()).apply();
    }

    public ModelProfile current() {
        String id = mPrefs.getString(KEY_CURRENT, null);
        if (id == null) {
            return null;
        }
        for (ModelProfile p : list()) {
            if (id.equals(p.id)) {
                return p;
            }
        }
        return null;
    }

    /** Bumped by the "应用" button so the preview knows to rebuild the detector. */
    public void bumpRevision() {
        mPrefs.edit().putLong(KEY_REVISION, revision() + 1).apply();
    }

    public long revision() {
        return mPrefs.getLong(KEY_REVISION, 0L);
    }

    public void setCurrent(String id) {
        mPrefs.edit().putString(KEY_CURRENT, id).apply();
    }

    public void add(ModelProfile profile) {
        List<ModelProfile> all = list();
        all.removeIf(p -> p.id.equals(profile.id));
        all.add(profile);
        saveList(all);
    }

    public void updateLabels(String id, List<String> labels) {
        List<ModelProfile> all = list();
        for (int i = 0; i < all.size(); i++) {
            ModelProfile p = all.get(i);
            if (p.id.equals(id)) {
                all.set(i, new ModelProfile(p.id, p.name, p.filePath, p.inputSize,
                        p.layout,
                        p.layout == ModelProfile.LAYOUT_E2E ? labels.size() : p.numClasses,
                        p.anchors, new ArrayList<>(labels)));
                break;
            }
        }
        saveList(all);
    }

    public void remove(String id) {
        ModelProfile target = null;
        for (ModelProfile p : list()) {
            if (p.id.equals(id)) {
                target = p;
            }
        }
        List<ModelProfile> all = list();
        all.removeIf(p -> p.id.equals(id));
        saveList(all);
        if (id.equals(mPrefs.getString(KEY_CURRENT, null))) {
            mPrefs.edit().remove(KEY_CURRENT).apply();
        }
        if (target != null) {
            File f = new File(target.filePath);
            if (f.exists() && !f.delete()) {
                Log.w(TAG, "cannot delete " + f);
            }
        }
    }

    /** Copies a SAF uri into app storage; returns the destination file. */
    public File importFrom(Uri uri, String id) throws Exception {
        File dest = new File(modelsDir(), id + ".onnx");
        try (InputStream in = mContext.getContentResolver().openInputStream(uri);
             OutputStream out = new FileOutputStream(dest)) {
            if (in == null) {
                throw new IllegalStateException("无法打开所选文件");
            }
            byte[] buf = new byte[256 * 1024];
            int n;
            while ((n = in.read(buf)) > 0) {
                out.write(buf, 0, n);
            }
        }
        return dest;
    }

    /** Labels one per line -> list, trimming blanks. */
    public static List<String> parseLabels(String text) {
        List<String> out = new ArrayList<>();
        if (text == null) {
            return out;
        }
        for (String line : text.split("\n")) {
            String s = line.trim();
            if (!s.isEmpty()) {
                out.add(s);
            }
        }
        return out;
    }

    public static String joinLabels(List<String> labels) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < labels.size(); i++) {
            if (i > 0) {
                sb.append('\n');
            }
            sb.append(labels.get(i));
        }
        return sb.toString();
    }

    public static List<String> builtinLabels() {
        return new ArrayList<>(Arrays.asList(COCO_LABELS));
    }
}
