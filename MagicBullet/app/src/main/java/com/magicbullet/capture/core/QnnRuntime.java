package com.magicbullet.capture.core;

import android.content.Context;
import android.os.Build;
import android.util.Log;

import org.json.JSONArray;
import org.json.JSONObject;

import java.io.File;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

import ai.onnxruntime.OrtSession;

/**
 * Everything device- and option-specific about the QNN HTP execution provider: the backend
 * path, the DSP library search path, the HTP architecture, the provider options and the
 * one-shot profiling that proves the graph really ran on the NPU.
 *
 * <p>Kept out of {@link YoloDetector} so the detector deals with frames, not with vendor
 * plumbing, and so a settings change invalidates the context cache automatically.
 */
public final class QnnRuntime {

    private static final String TAG = "QnnRuntime";

    /** Bump when the bundled QNN runtime changes: old context blobs cannot be loaded. */
    private static final String QNN_VERSION = "qnn242";
    private static final String HTP_PERFORMANCE_MODE = "burst";
    private static final String FINALIZATION_MODE = "3";
    private static final String CONTEXT_PRIORITY = "high";

    private final String mNativeDir;
    private final String mSoc;
    private final String mArch;

    public QnnRuntime(Context context) {
        mNativeDir = context.getApplicationInfo().nativeLibraryDir;
        mSoc = Build.VERSION.SDK_INT >= Build.VERSION_CODES.S ? Build.SOC_MODEL : Build.BOARD;
        mArch = archForSoc(mSoc);
    }

    /**
     * The cDSP loader finds the skel through ADSP_LIBRARY_PATH: point it at the app's extracted
     * libs (useLegacyPackaging keeps them as real files) and keep the usual DSP dirs behind it.
     */
    public void prepareEnvironment() {
        try {
            String existing = System.getenv("ADSP_LIBRARY_PATH");
            String adsp = mNativeDir
                    + ";/vendor/dsp/cdsp;/vendor/lib/rfsa/adsp;/system/lib/rfsa/adsp;/dsp"
                    + (existing == null || existing.isEmpty() ? "" : ";" + existing);
            android.system.Os.setenv("ADSP_LIBRARY_PATH", adsp, true);
        } catch (Throwable t) {
            Log.w(TAG, "cannot set ADSP_LIBRARY_PATH: " + t);
        }
    }

    /**
     * Identifies the runtime, silicon and provider options that a compiled context depends on.
     * Part of the cache key, so changing any of them recompiles instead of loading a blob that
     * no longer matches.
     */
    public String fingerprint() {
        return (QNN_VERSION + "-" + safe(mSoc) + "-" + (mArch == null ? "auto" : mArch)
                + "-" + HTP_PERFORMANCE_MODE + "-fin" + FINALIZATION_MODE
                + "-" + CONTEXT_PRIORITY).toLowerCase(Locale.US);
    }

    /**
     * @param contextFile the file ORT should write the compiled graph to; null when a cached
     *                    context is being loaded instead
     * @param profileFile where ORT writes its one-shot profile, or null to disable profiling
     */
    public OrtSession.SessionOptions sessionOptions(File contextFile, File profileFile)
            throws Exception {
        OrtSession.SessionOptions options = new OrtSession.SessionOptions();
        options.setIntraOpNumThreads(4);
        options.setOptimizationLevel(OrtSession.SessionOptions.OptLevel.ALL_OPT);

        Map<String, String> provider = new HashMap<>();
        provider.put("backend_path", mNativeDir + "/libQnnHtp.so");
        provider.put("htp_performance_mode", HTP_PERFORMANCE_MODE);
        provider.put("htp_graph_finalization_optimization_mode", FINALIZATION_MODE);
        provider.put("qnn_context_priority", CONTEXT_PRIORITY);
        if (mArch != null) {
            provider.put("htp_arch", mArch);
        }
        options.addQnn(provider);

        if (contextFile != null) {
            // ep.context_* are session config entries, not QNN provider options: the first
            // session dumps the compiled HTP graph here, later ones load it instead of
            // recompiling. Embed mode 1 keeps the context inside that single .onnx.
            options.addConfigEntry("ep.context_enable", "1");
            options.addConfigEntry("ep.context_file_path", contextFile.getAbsolutePath());
            options.addConfigEntry("ep.context_embed_mode", "1");
        }
        if (profileFile != null) {
            options.enableProfiling(profileFile.getAbsolutePath());
        }
        return options;
    }

    /** Dumps and logs a per-provider breakdown of the last profiling run, then deletes it. */
    public static void logProfile(OrtSession session, File profileFile) {
        try {
            String result = session.endProfiling();
            if (result == null || result.isEmpty()) {
                Log.w(TAG, "no ORT profile returned");
                return;
            }
            // The Java binding returns the profile file path; the JSON is on disk.
            File written = new File(result.trim());
            String json = written.isFile()
                    ? new String(readAll(written), java.nio.charset.StandardCharsets.UTF_8)
                    : result;
            String trimmed = json.trim();
            JSONArray events = trimmed.startsWith("[")
                    ? new JSONArray(trimmed)
                    : new JSONObject(trimmed).optJSONArray("traceEvents");
            if (events == null) {
                Log.w(TAG, "profile without events, " + json.length() + " chars");
                return;
            }
            Map<String, long[]> byProvider = new HashMap<>();
            StringBuilder nodes = new StringBuilder();
            for (int i = 0; i < events.length(); i++) {
                JSONObject event = events.optJSONObject(i);
                if (event == null || !"Node".equals(event.optString("cat"))) {
                    continue;
                }
                JSONObject args = event.optJSONObject("args");
                String provider = args == null ? "?" : args.optString("provider", "?");
                String name = event.optString("name", "");
                if ("?".equals(provider) && name.contains("ExecutionProvider")) {
                    provider = name.substring(0, name.indexOf("ExecutionProvider") + 17);
                }
                long durationUs = (long) event.optDouble("dur", 0);
                long[] acc = byProvider.computeIfAbsent(provider, key -> new long[2]);
                acc[0]++;
                acc[1] += durationUs;
                if (nodes.length() < 400) {
                    nodes.append(String.format(Locale.US, "%s=%.2fms ", name, durationUs / 1000.0));
                }
            }
            StringBuilder summary = new StringBuilder();
            for (Map.Entry<String, long[]> entry : byProvider.entrySet()) {
                summary.append(entry.getKey()).append('=')
                        .append(entry.getValue()[0]).append(" nodes/")
                        .append(String.format(Locale.US, "%.1f ms",
                                entry.getValue()[1] / 1000.0))
                        .append("  ");
            }
            Log.i(TAG, "ORT profile by provider: " + summary);
            Log.i(TAG, "ORT profile nodes: " + nodes);
            writeText(new File(profileFile.getParentFile(), "qnn_profile_summary.txt"),
                    summary + System.lineSeparator() + nodes);
            deleteProfile(profileFile);
        } catch (Throwable t) {
            Log.w(TAG, "profile failed: " + t);
        }
    }

    /** HTP architecture for parts ONNX Runtime cannot name itself (SM8750, v79). */
    private static String archForSoc(String soc) {
        return soc != null && soc.startsWith("SM8750") ? "79" : null;
    }

    /** ORT appends a timestamp to the requested profile name, so sweep the siblings too. */
    private static void deleteProfile(File profileFile) {
        File[] files = profileFile.getParentFile() == null
                ? null : profileFile.getParentFile().listFiles();
        if (files == null) {
            return;
        }
        for (File file : files) {
            if (file.getName().startsWith(profileFile.getName()) && !file.delete()) {
                Log.w(TAG, "cannot delete " + file);
            }
        }
    }

    static void writeText(File file, String text) {
        try (java.io.FileOutputStream out = new java.io.FileOutputStream(file)) {
            out.write(text.getBytes(java.nio.charset.StandardCharsets.UTF_8));
        } catch (Throwable t) {
            Log.w(TAG, "cannot write " + file + ": " + t);
        }
    }

    static byte[] readAll(File file) throws Exception {
        byte[] data = new byte[(int) file.length()];
        try (java.io.FileInputStream in = new java.io.FileInputStream(file)) {
            int offset = 0;
            while (offset < data.length) {
                int read = in.read(data, offset, data.length - offset);
                if (read < 0) {
                    break;
                }
                offset += read;
            }
            if (offset != data.length) {
                throw new IllegalStateException("short read on " + file);
            }
        }
        return data;
    }

    private static String safe(String value) {
        return value == null ? "unknown" : value.replaceAll("[^A-Za-z0-9]", "_");
    }
}
