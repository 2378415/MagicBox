#include <jni.h>
#include <cstdint>
#include <arm_neon.h>

namespace {

constexpr float kPad = 114.0f / 255.0f;

inline void fill(float* dst, int count) {
    const float32x4_t v = vdupq_n_f32(kPad);
    int i = 0;
    for (; i + 4 <= count; i += 4) {
        vst1q_f32(dst + i, v);
    }
    for (; i < count; i++) {
        dst[i] = kPad;
    }
}

}  // namespace

extern "C" JNIEXPORT void JNICALL
Java_com_magicbullet_capture_core_YoloPreprocess_nativeLetterbox(
        JNIEnv* env, jclass, jobject src, jint size, jint nw, jint nh,
        jintArray srcXArr, jintArray srcRowArr, jobject dstBuf, jboolean fillPad) {
    auto* srcBytes = static_cast<const uint8_t*>(env->GetDirectBufferAddress(src));
    if (srcBytes == nullptr) {
        return;
    }
    auto* out = static_cast<float*>(env->GetDirectBufferAddress(dstBuf));
    jint* cols = env->GetIntArrayElements(srcXArr, nullptr);
    jint* rows = env->GetIntArrayElements(srcRowArr, nullptr);
    float* dst = out;
    if (cols == nullptr || rows == nullptr || dst == nullptr) {
        if (cols) env->ReleaseIntArrayElements(srcXArr, cols, JNI_ABORT);
        if (rows) env->ReleaseIntArrayElements(srcRowArr, rows, JNI_ABORT);
        return;
    }

    const int plane = size * size;
    const int padX = (size - nw) / 2;
    const int padY = (size - nh) / 2;
    const float inv = 1.0f / 255.0f;
    const float32x4_t vinv = vdupq_n_f32(inv);

    // The bars never change between frames of the same size, so they are painted once.
    if (fillPad) {
    for (int p = 0; p < 3; p++) {
        float* base = dst + p * plane;
        fill(base, padY * size);
        fill(base + (padY + nh) * size, plane - (padY + nh) * size);
        for (int y = padY; y < padY + nh; y++) {
            float* row = base + y * size;
            fill(row, padX);
            fill(row + padX + nw, size - padX - nw);
        }
    }
    }

    for (int y = 0; y < nh; y++) {
        const uint8_t* rowBase = srcBytes + rows[y];
        float* outR = dst + (padY + y) * size + padX;
        float* outG = outR + plane;
        float* outB = outG + plane;
        int x = 0;
        for (; x + 8 <= nw; x += 8) {
            uint8_t rb[8], gb[8], bb[8];
            for (int k = 0; k < 8; k++) {
                const uint8_t* px = rowBase + cols[x + k];
                rb[k] = px[0];
                gb[k] = px[1];
                bb[k] = px[2];
            }
            const uint16x8_t r16 = vmovl_u8(vld1_u8(rb));
            const uint16x8_t g16 = vmovl_u8(vld1_u8(gb));
            const uint16x8_t b16 = vmovl_u8(vld1_u8(bb));
            vst1q_f32(outR + x, vmulq_f32(vcvtq_f32_u32(vmovl_u16(vget_low_u16(r16))), vinv));
            vst1q_f32(outR + x + 4, vmulq_f32(vcvtq_f32_u32(vmovl_u16(vget_high_u16(r16))), vinv));
            vst1q_f32(outG + x, vmulq_f32(vcvtq_f32_u32(vmovl_u16(vget_low_u16(g16))), vinv));
            vst1q_f32(outG + x + 4, vmulq_f32(vcvtq_f32_u32(vmovl_u16(vget_high_u16(g16))), vinv));
            vst1q_f32(outB + x, vmulq_f32(vcvtq_f32_u32(vmovl_u16(vget_low_u16(b16))), vinv));
            vst1q_f32(outB + x + 4, vmulq_f32(vcvtq_f32_u32(vmovl_u16(vget_high_u16(b16))), vinv));
        }
        for (; x < nw; x++) {
            const uint8_t* px = rowBase + cols[x];
            outR[x] = px[0] * inv;
            outG[x] = px[1] * inv;
            outB[x] = px[2] * inv;
        }
    }

    
    env->ReleaseIntArrayElements(srcXArr, cols, JNI_ABORT);
    env->ReleaseIntArrayElements(srcRowArr, rows, JNI_ABORT);
}
