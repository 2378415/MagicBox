package com.magicbullet.capture.core;

import android.util.Log;

import java.io.File;
import java.security.MessageDigest;
import java.util.Locale;

/**
 * On-disk cache of the compiled QNN context.
 *
 * <p>The first session for a model makes the DSP compile the graph and dumps the result here;
 * later runs load that file as the model, which takes ~100 ms instead of ~4 s. The key covers
 * the model bytes plus a fingerprint of everything else that makes a blob unusable elsewhere
 * (QNN runtime version, SoC, EP options), so those never need a manual cache reset.
 */
public final class QnnContextCache {

    private static final String TAG = "QnnContextCache";

    private final File mDir;

    public QnnContextCache(File cacheRoot) {
        mDir = new File(cacheRoot, "qnn_context");
    }

    /**
     * @param fingerprint identifies the QNN runtime, the SoC and the EP options; see
     *                    {@link QnnRuntime#fingerprint()}
     * @return the context file for this model, or null when the cache cannot be created
     */
    public File fileFor(byte[] model, String fingerprint) throws Exception {
        if (!mDir.isDirectory() && !mDir.mkdirs()) {
            Log.w(TAG, "cannot create " + mDir + ", QNN context caching disabled");
            return null;
        }
        byte[] hash = MessageDigest.getInstance("SHA-256").digest(model);
        StringBuilder name = new StringBuilder(fingerprint).append('-');
        for (int i = 0; i < 8; i++) {
            name.append(String.format(Locale.US, "%02x", hash[i]));
        }
        File target = new File(mDir, name + ".onnx");
        deleteStale(target);
        return target;
    }

    /** Blobs from an older fingerprint can never be loaded again: drop them. */
    private void deleteStale(File keep) {
        File[] files = mDir.listFiles();
        if (files == null) {
            return;
        }
        for (File file : files) {
            if (!file.equals(keep) && file.getName().endsWith(".onnx") && !file.delete()) {
                Log.w(TAG, "cannot delete stale context " + file.getName());
            }
        }
    }
}
