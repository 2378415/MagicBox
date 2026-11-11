package com.magicbullet.capture.core;

import android.content.Context;
import android.content.SharedPreferences;

import java.util.LinkedHashSet;
import java.util.Set;

/**
 * YOLO parameters, persisted in SharedPreferences.
 *
 * <p>This is the single source of truth shared by the Yolo tab and (later) the
 * inference pipeline. Nothing here runs inference yet - {@link #listeners} exist so
 * the pipeline can subscribe instead of polling.
 */
public final class YoloConfig {

    public interface Listener {
        void onConfigChanged(YoloConfig config);
    }

    public static final String[] MODELS = {
            "yolov8n.tflite",
            "yolov8s.tflite",
            "自定义模型…",
    };

    private static final String P = "yolo_config";

    public static final float DEFAULT_CONF = 0.65f;
    public static final float DEFAULT_IOU = 0.45f;
    public static final int DEFAULT_MAX_DET = 20;

    /** Old defaults, only used to recognise a profile that never left them. */
    private static final float LEGACY_CONF = 0.25f;
    private static final float LEGACY_IOU = 0.45f;
    private static final int LEGACY_MAX_DET = 30;
    private static final String KEY_DEFAULTS_VERSION = "defaults_version";
    private static final int DEFAULTS_VERSION = 2;

    private final SharedPreferences mPrefs;
    private final Set<Listener> mListeners = new LinkedHashSet<>();
    private static YoloConfig sInstance;

    private String mModel;
    private int mInputSize;
    private String mBackend;
    private float mConf;
    private float mIou;
    private int mMaxDet;
    private boolean mDrawBoxes;
    private boolean mRoiEnabled;
    private int mRoiSize = 1080;
    private float mRoiCx = 0.5f;
    private float mRoiCy = 0.5f;
    private final Set<String> mClasses = new LinkedHashSet<>();
    private String mBuiltinLabels;

    private YoloConfig(SharedPreferences prefs) {
        mPrefs = prefs;
        load();
    }

    /**
     * One instance per process: the tabs are added and only hidden/shown, never recreated, and
     * the listener registered by the preview has to be the same object the YOLO tab saves on.
     */
    public static synchronized YoloConfig load(Context context) {
        if (sInstance == null) {
            sInstance = new YoloConfig(context.getApplicationContext()
                    .getSharedPreferences(P, Context.MODE_PRIVATE));
        }
        return sInstance;
    }

    private void load() {
        mModel = mPrefs.getString("model", MODELS[0]);
        mInputSize = mPrefs.getInt("input", 640);
        mBackend = mPrefs.getString("backend", "NNAPI");
        mConf = mPrefs.getFloat("conf", DEFAULT_CONF);
        mIou = mPrefs.getFloat("iou", DEFAULT_IOU);
        mMaxDet = mPrefs.getInt("maxDet", DEFAULT_MAX_DET);
        mDrawBoxes = mPrefs.getBoolean("draw", true);
        mRoiEnabled = mPrefs.getBoolean("roi_enabled", false);
        mRoiSize = mPrefs.getInt("roi_size", 1080);
        mRoiCx = mPrefs.getFloat("roi_cx", 0.5f);
        mRoiCy = mPrefs.getFloat("roi_cy", 0.5f);
        mBuiltinLabels = mPrefs.getString("builtinLabels", "");
        mClasses.clear();
        String classes = mPrefs.getString("classes", "");
        if (!classes.isEmpty()) {
            for (String key : classes.split(",")) {
                if (!key.isEmpty()) {
                    mClasses.add(key);
                }
            }
        }
        migrateDefaults();
    }

    /**
     * Moves a profile that still carries the old 0.25/0.45/30 defaults onto the new ones.
     * A value the user actually chose (anything else) is left untouched.
     */
    private void migrateDefaults() {
        if (mPrefs.getInt(KEY_DEFAULTS_VERSION, 1) >= DEFAULTS_VERSION) {
            return;
        }
        boolean untouched = mConf == LEGACY_CONF && mIou == LEGACY_IOU && mMaxDet == LEGACY_MAX_DET;
        if (untouched) {
            mConf = DEFAULT_CONF;
            mIou = DEFAULT_IOU;
            mMaxDet = DEFAULT_MAX_DET;
        }
        mPrefs.edit()
                .putFloat("conf", mConf)
                .putFloat("iou", mIou)
                .putInt("maxDet", mMaxDet)
                .putInt(KEY_DEFAULTS_VERSION, DEFAULTS_VERSION)
                .apply();
    }

    /** Writes the current values without notifying: used while committing a draft. */
    public void persist() {
        mPrefs.edit()
                .putString("model", mModel)
                .putInt("input", mInputSize)
                .putString("backend", mBackend)
                .putFloat("conf", mConf)
                .putFloat("iou", mIou)
                .putInt("maxDet", mMaxDet)
                .putBoolean("draw", mDrawBoxes)
                .putBoolean("roi_enabled", mRoiEnabled)
                .putInt("roi_size", mRoiSize)
                .putFloat("roi_cx", mRoiCx)
                .putFloat("roi_cy", mRoiCy)
                .putString("classes", String.join(",", mClasses))
                .putString("builtinLabels", mBuiltinLabels)
                .apply();
    }

    /** Writes and tells the pipeline: this is what "应用" does. */
    public void save() {
        persist();
        for (Listener listener : mListeners) {
            listener.onConfigChanged(this);
        }
    }

    /** Threshold defaults only; the model, class list and draw switch stay as they are. */
    public void resetThresholds() {
        mConf = DEFAULT_CONF;
        mIou = DEFAULT_IOU;
        mMaxDet = DEFAULT_MAX_DET;
        save();
    }

    public void addListener(Listener listener) {
        mListeners.add(listener);
    }

    public void removeListener(Listener listener) {
        mListeners.remove(listener);
    }

    // ------------------------------------------------------------------ accessors

    public String model() {
        return mModel;
    }

    public void model(String model) {
        mModel = model;
    }

    public int inputSize() {
        return mInputSize;
    }

    public void inputSize(int size) {
        mInputSize = size;
    }

    public String backend() {
        return mBackend;
    }

    public void backend(String backend) {
        mBackend = backend;
    }

    public float conf() {
        return mConf;
    }

    public void conf(float conf) {
        mConf = conf;
    }

    public float iou() {
        return mIou;
    }

    public void iou(float iou) {
        mIou = iou;
    }

    public int maxDet() {
        return mMaxDet;
    }

    public void maxDet(int maxDet) {
        mMaxDet = maxDet;
    }

    public RoiConfig roi() {
        return new RoiConfig(mRoiEnabled, mRoiSize, mRoiCx, mRoiCy);
    }

    public void roi(RoiConfig roi) {
        RoiConfig value = roi == null ? RoiConfig.FULL : roi;
        mRoiEnabled = value.enabled;
        mRoiSize = value.sizePx;
        mRoiCx = value.centerX;
        mRoiCy = value.centerY;
    }

    public boolean drawBoxes() {
        return mDrawBoxes;
    }

    public void drawBoxes(boolean draw) {
        mDrawBoxes = draw;
    }

    /** Labels used while no imported model is selected. */
    public String builtinLabels() {
        return mBuiltinLabels;
    }

    public void builtinLabels(String labels) {
        mBuiltinLabels = labels;
    }

    public Set<String> classes() {
        return mClasses;
    }
}
