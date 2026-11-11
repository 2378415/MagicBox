#include <jni.h>
#include <algorithm>
#include <vector>
#include <arm_neon.h>

namespace {

/**
 * Greedy per-class NMS, score-ordered, over one frame's candidates.
 *
 * <p>Same result as the Java reference (a box survives when it does not overlap a box already
 * kept for its class), but the survivors are compared against at most `maxDet` kept boxes
 * instead of every other candidate, and nothing allocates per candidate.
 */
constexpr int kMaxKept = 512;

struct Box {
    float x1;
    float y1;
    float x2;
    float y2;
    float score;
    int cls;
};

struct Mapping {
    float scale;
    float padX;
    float padY;
    int roiX;
    int roiY;

    inline float x(float value) const { return roiX + (value - padX) / scale; }
    inline float y(float value) const { return roiY + (value - padY) / scale; }
};

inline float clamp01(float value) {
    return value < 0.f ? 0.f : (value > 1.f ? 1.f : value);
}

inline float iou(const Box& a, const Box& b) {
    const float x1 = std::max(a.x1, b.x1);
    const float y1 = std::max(a.y1, b.y1);
    const float x2 = std::min(a.x2, b.x2);
    const float y2 = std::min(a.y2, b.y2);
    const float inter = std::max(0.f, x2 - x1) * std::max(0.f, y2 - y1);
    const float areaA = std::max(0.f, a.x2 - a.x1) * std::max(0.f, a.y2 - a.y1);
    const float areaB = std::max(0.f, b.x2 - b.x1) * std::max(0.f, b.y2 - b.y1);
    return inter / (areaA + areaB - inter + 1e-6f);
}

/**
 * Sorts, suppresses and writes `n * 6` floats: x1, y1, x2, y2 (normalised to the frame),
 * score, class. Returns the number of boxes written.
 */
int finish(std::vector<Box>& candidates, float iouThreshold, int maxDetections,
           int frameW, int frameH, float* out) {
    std::sort(candidates.begin(), candidates.end(),
              [](const Box& a, const Box& b) { return a.score > b.score; });
    const int cap = std::min(maxDetections, kMaxKept);
    Box kept[kMaxKept];
    int n = 0;
    for (const Box& candidate : candidates) {
        if (n >= cap) {
            break;
        }
        bool drop = false;
        for (int k = 0; k < n; k++) {
            if (kept[k].cls == candidate.cls && iou(kept[k], candidate) > iouThreshold) {
                drop = true;
                break;
            }
        }
        if (drop) {
            continue;
        }
        kept[n++] = candidate;
    }
    const float invW = 1.f / static_cast<float>(frameW);
    const float invH = 1.f / static_cast<float>(frameH);
    for (int i = 0; i < n; i++) {
        float* o = out + i * 6;
        o[0] = clamp01(kept[i].x1 * invW);
        o[1] = clamp01(kept[i].y1 * invH);
        o[2] = clamp01(kept[i].x2 * invW);
        o[3] = clamp01(kept[i].y2 * invH);
        o[4] = kept[i].score;
        o[5] = static_cast<float>(kept[i].cls);
    }
    return n;
}

/**
 * {@code data} is {@code [4+nc, anchors]}, channel-major.
 *
 * <p>The per-class scores are scanned one channel at a time, front to back: reading a channel is
 * a sequential stream, while an anchor-major loop would jump 4 bytes every `anchors * 4` bytes
 * and miss the cache on every class test (that version measured slower than the Java path).
 */
int decodeV8Impl(const float* data, int numClasses, int anchors, float conf, float iou,
                 int maxDet, const Mapping& map, int frameW, int frameH, float* out) {
    static thread_local std::vector<float> bestScore;
    static thread_local std::vector<float> bestClass;
    bestScore.assign(static_cast<size_t>(anchors), conf);
    bestClass.assign(static_cast<size_t>(anchors), -1.f);

    // Four anchors per step: a scalar max-update loop here costs more than the rest of the
    // decode together.
    for (int c = 0; c < numClasses; c++) {
        const float* channel = data + static_cast<long>(4 + c) * anchors;
        const float32x4_t cls = vdupq_n_f32(static_cast<float>(c));
        int i = 0;
        for (; i + 4 <= anchors; i += 4) {
            const float32x4_t score = vld1q_f32(channel + i);
            const float32x4_t best = vld1q_f32(bestScore.data() + i);
            const uint32x4_t better = vcgtq_f32(score, best);
            vst1q_f32(bestScore.data() + i, vbslq_f32(better, score, best));
            vst1q_f32(bestClass.data() + i,
                      vbslq_f32(better, cls, vld1q_f32(bestClass.data() + i)));
        }
        for (; i < anchors; i++) {
            const float score = channel[i];
            if (score > bestScore[i]) {
                bestScore[i] = score;
                bestClass[i] = static_cast<float>(c);
            }
        }
    }

    const float* cx = data;
    const float* cy = data + anchors;
    const float* bw = data + 2 * anchors;
    const float* bh = data + 3 * anchors;
    std::vector<Box> candidates;
    candidates.reserve(256);
    for (int i = 0; i < anchors; i++) {
        const int cls = static_cast<int>(bestClass[i]);
        if (cls < 0) {
            continue;
        }
        const float w = bw[i];
        const float h = bh[i];
        candidates.push_back(Box{map.x(cx[i] - w * 0.5f), map.y(cy[i] - h * 0.5f),
                                 map.x(cx[i] + w * 0.5f), map.y(cy[i] + h * 0.5f),
                                 bestScore[i], cls});
    }
    return finish(candidates, iou, maxDet, frameW, frameH, out);
}

/** {@code data} is {@code [rows, stride]}: corners, score, class. */
int decodeE2EImpl(const float* data, int stride, int rows, float conf, float iou,
                  int maxDet, const Mapping& map, int frameW, int frameH, float* out) {
    std::vector<Box> candidates;
    candidates.reserve(static_cast<size_t>(rows));
    for (int i = 0; i < rows; i++) {
        const float* row = data + static_cast<long>(i) * stride;
        if (row[4] < conf) {
            continue;
        }
        candidates.push_back(Box{map.x(row[0]), map.y(row[1]),
                                 map.x(row[2]), map.y(row[3]),
                                 row[4], static_cast<int>(row[5])});
    }
    return finish(candidates, iou, maxDet, frameW, frameH, out);
}

/** Shared tail of the flat entry points: decode into a stack buffer, copy the result out. */
inline int finishFlat(JNIEnv* env, jint n, const float* local, jfloatArray outArr) {
    if (n < 0) {
        return n;
    }
    env->SetFloatArrayRegion(outArr, 0, n * 6, local);
    return n;
}

}  // namespace

// ---------------------------------------------------------------- direct buffer entry points

extern "C" JNIEXPORT jint JNICALL
Java_com_magicbullet_capture_core_YoloPostprocess_decodeV8(
        JNIEnv* env, jclass, jobject src, jint numClasses, jint anchors,
        jfloat conf, jfloat iou, jint maxDet,
        jfloat scale, jfloat padX, jfloat padY,
        jint roiX, jint roiY, jint frameW, jint frameH, jfloatArray outArr) {
    auto* data = static_cast<const float*>(env->GetDirectBufferAddress(src));
    if (data == nullptr) {
        return -1;
    }
    jfloat* out = env->GetFloatArrayElements(outArr, nullptr);
    if (out == nullptr) {
        return -1;
    }
    const int n = decodeV8Impl(data, numClasses, anchors, conf, iou, maxDet,
                               Mapping{scale, padX, padY, roiX, roiY}, frameW, frameH, out);
    env->ReleaseFloatArrayElements(outArr, out, 0);
    return n;
}

extern "C" JNIEXPORT jint JNICALL
Java_com_magicbullet_capture_core_YoloPostprocess_decodeE2E(
        JNIEnv* env, jclass, jobject src, jint stride, jint rows,
        jfloat conf, jfloat iou, jint maxDet,
        jfloat scale, jfloat padX, jfloat padY,
        jint roiX, jint roiY, jint frameW, jint frameH, jfloatArray outArr) {
    auto* data = static_cast<const float*>(env->GetDirectBufferAddress(src));
    if (data == nullptr) {
        return -1;
    }
    jfloat* out = env->GetFloatArrayElements(outArr, nullptr);
    if (out == nullptr) {
        return -1;
    }
    const int n = decodeE2EImpl(data, stride, rows, conf, iou, maxDet,
                                Mapping{scale, padX, padY, roiX, roiY}, frameW, frameH, out);
    env->ReleaseFloatArrayElements(outArr, out, 0);
    return n;
}

// ---------------------------------------------------------------- heap array entry points
// ONNX Runtime hands out a heap-backed buffer for QNN EP outputs, so the tensors are read from
// their backing array; the results are copied back with SetFloatArrayRegion from a stack buffer.

extern "C" JNIEXPORT jint JNICALL
Java_com_magicbullet_capture_core_YoloPostprocess_decodeV8Flat(
        JNIEnv* env, jclass, jfloatArray srcArr, jint srcOffset, jint numClasses, jint anchors,
        jfloat conf, jfloat iou, jint maxDet,
        jfloat scale, jfloat padX, jfloat padY,
        jint roiX, jint roiY, jint frameW, jint frameH, jfloatArray outArr) {
    if (srcArr == nullptr || srcOffset < 0) {
        return -1;
    }
    // Pinned instead of copied: the tensor is up to 2.8 MB and ART may hand out a copy.
    auto* data = static_cast<jfloat*>(env->GetPrimitiveArrayCritical(srcArr, nullptr));
    if (data == nullptr) {
        return -1;
    }
    float local[kMaxKept * 6];
    const int n = decodeV8Impl(data + srcOffset, numClasses, anchors, conf, iou, maxDet,
                               Mapping{scale, padX, padY, roiX, roiY}, frameW, frameH, local);
    env->ReleasePrimitiveArrayCritical(srcArr, data, JNI_ABORT);
    return finishFlat(env, n, local, outArr);
}

extern "C" JNIEXPORT jint JNICALL
Java_com_magicbullet_capture_core_YoloPostprocess_decodeE2EFlat(
        JNIEnv* env, jclass, jfloatArray srcArr, jint srcOffset, jint stride, jint rows,
        jfloat conf, jfloat iou, jint maxDet,
        jfloat scale, jfloat padX, jfloat padY,
        jint roiX, jint roiY, jint frameW, jint frameH, jfloatArray outArr) {
    if (srcArr == nullptr || srcOffset < 0) {
        return -1;
    }
    auto* data = static_cast<jfloat*>(env->GetPrimitiveArrayCritical(srcArr, nullptr));
    if (data == nullptr) {
        return -1;
    }
    float local[kMaxKept * 6];
    const int n = decodeE2EImpl(data + srcOffset, stride, rows, conf, iou, maxDet,
                                Mapping{scale, padX, padY, roiX, roiY}, frameW, frameH, local);
    env->ReleasePrimitiveArrayCritical(srcArr, data, JNI_ABORT);
    return finishFlat(env, n, local, outArr);
}
