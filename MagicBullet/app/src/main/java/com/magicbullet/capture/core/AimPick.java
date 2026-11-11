package com.magicbullet.capture.core;

/**
 * Target selection and anchor placement, kept pure so the rules can be unit-tested.
 *
 * <p>Two rules live here:
 *
 * <ul>
 *   <li><b>anchor</b>: the aim point inside a head box is its horizontal centre at a vertical bias
 *       ({@code 1.0} = the bottom edge, i.e. the chin, {@code 0.5} = the centre);</li>
 *   <li><b>selection</b>: among candidates whose horizontal offset is within a tolerance, the
 *       lowest one (biggest y, i.e. the nearest enemy) wins; everything else falls back to the
 *       nearest candidate.</li>
 * </ul>
 */
final class AimPick {

    private AimPick() {
    }

    /**
     * Vertical position of the aim point inside a box.
     *
     * @param topPx    box top in pixels
     * @param bottomPx box bottom in pixels
     * @param bias     0 = top edge, 0.5 = centre, 1 = bottom edge
     */
    static float anchorY(float topPx, float bottomPx, float bias) {
        float b = Math.max(0f, Math.min(1f, bias));
        return topPx + (bottomPx - topPx) * b;
    }

    /** Horizontal distance from the crosshair, used for the "centred" test. */
    static float centreOffset(float xPx, float anchorXPx) {
        return Math.abs(xPx - anchorXPx);
    }

    /** True when the candidate is horizontally "centred" within the given tolerance. */
    static boolean isCentred(float xPx, float anchorXPx, float tolerancePx) {
        return centreOffset(xPx, anchorXPx) <= Math.max(1f, tolerancePx);
    }

    /** 尺寸并列的判定门限：差 ≤ 1% 视为同样大，交给下一级判据决定。 */
    private static final float SIZE_TIE = 0.01f;

    /**
     * Picks the index to aim at, or {@code -1} when nothing is usable.
     *
     * <p>2026-11-11 schema 10：判据顺序从"居中优先"翻转为"框大优先"。横向偏离不再是资格线，
     * 而是一个**可达范围**{@code reachPx}：范围内（含范围内的大框）都能参与竞争，范围外一律
     * 不参与，避免准心被屏幕边上的大框拽走。
     *
     * <p>排序（在可达范围内的 head 候选之间，逐层带并列带）：
     *
     * <ol>
     *   <li><b>head box</b> — {@code sizes[i]} 最大者（越近）；并列带 {@link #SIZE_TIE}；</li>
     *   <li><b>body box</b> — 头框并列时 {@code bodySizes[i]} 大者（更近/更完整）；</li>
     *   <li><b>most centred</b> — 两个框都并列时，横向偏离最小者（原来的"居中"降级到这里）；</li>
     *   <li><b>lowest</b> — 都并列时 y 最大。</li>
     * </ol>
     *
     * <p>{@code reachPx <= 0} 时退回旧语义：以 {@code tolPx} 的居中容差当资格线。
     * 可达范围内没有 head 候选时，退回"距离最近"（non-head 加 {@code headBonus}）。
     *
     * @param xs         candidate anchor x in pixels
     * @param ys         candidate anchor y in pixels
     * @param sizes      head box height per candidate (normalised, bigger = nearer);
     *                   {@code null} falls back to "lowest y wins"
     * @param bodySizes  body box height per candidate (normalised, 0 when the model only gave a
     *                   head); {@code null} = no second tie-breaker
     * @param heads      whether the candidate is a head box
     * @param anchorX    crosshair x in pixels
     * @param anchorY    crosshair y in pixels
     * @param tolPx      legacy "centred" tolerance, only used when {@code reachPx <= 0}
     * @param reachPx    horizontal reach in pixels ({@code sizeReach × frameW}); {@code <= 0}
     *                   restores the old centred-gate behaviour
     * @param headBonus  penalty added to the distance of non-head candidates
     */
    static int pick(float[] xs, float[] ys, float[] sizes, float[] bodySizes, boolean[] heads,
                    float anchorX, float anchorY, float tolPx, float reachPx, float headBonus) {
        if (xs == null || ys == null || xs.length == 0 || ys.length != xs.length) {
            return -1;
        }
        int best = -1;
        float bestHeadSize = -Float.MAX_VALUE;
        float bestBodySize = -Float.MAX_VALUE;
        float bestOffset = Float.MAX_VALUE;
        float bestY = -Float.MAX_VALUE;
        int nearest = -1;
        float nearestScore = Float.MAX_VALUE;
        for (int i = 0; i < xs.length; i++) {
            boolean head = heads != null && i < heads.length && heads[i];
            float offset = Math.abs(xs[i] - anchorX);
            if (head) {
                // 资格线：reach > 0 用可达范围，否则退回旧的居中容差。
                boolean eligible = reachPx > 0f
                        ? offset <= reachPx
                        : isCentred(xs[i], anchorX, tolPx);
                if (eligible) {
                    // sizes == null → 大 = 更靠下（旧的 y 判据），保证未升级调用方行为不变。
                    float headSize = sizes != null && i < sizes.length ? sizes[i] : ys[i];
                    float bodySize = bodySizes != null && i < bodySizes.length ? bodySizes[i] : 0f;
                    if (best < 0 || better(headSize, bodySize, offset, ys[i],
                            bestHeadSize, bestBodySize, bestOffset, bestY, reachPx > 0f)) {
                        best = i;
                        bestHeadSize = headSize;
                        bestBodySize = bodySize;
                        bestOffset = offset;
                        bestY = ys[i];
                    }
                }
            }
            float distance = (float) Math.hypot(xs[i] - anchorX, ys[i] - anchorY);
            float score = distance + (head ? 0f : headBonus);
            if (score < nearestScore) {
                nearestScore = score;
                nearest = i;
            }
        }
        return best >= 0 ? best : nearest;
    }

    /**
     * 抢锁判定：挑战者要把已锁定目标顶掉，必须同时满足**相对**（{@code gate}，默认 1.12）与
     * **绝对**（{@code deltaMin}，默认 0.01 归一化框高 ≈ 11 px @1080p）两个门槛。
     *
     * <p>只留相对门槛时，两个都很近的目标（框高 0.09 上下）差 12% 只要 0.011 就能被抖动凑出来，
     * 于是逐帧互抢；绝对门槛把"大一点点"挡在外面。
     */
    static boolean shouldTakeOver(float challengerHeadSize, float stickHeadSize, float gate,
                                  float deltaMin) {
        if (challengerHeadSize <= 0f || stickHeadSize <= 0f) {
            return false;
        }
        // 绝对门槛留 1e-6 容差：0.06f − 0.05f 在浮点里是 0.009999998，正好卡在 0.01f 门外。
        return challengerHeadSize >= stickHeadSize * gate
                && challengerHeadSize - stickHeadSize >= deltaMin - 1e-6f;
    }

    /**
     * 并列比较，逐层用「best ± 带宽」而不是「best × (1±tie)」：乘法与相对差混用在浮点边界上会
     * 留出"既不更大也不算并列"的缝隙（0.0500 vs 0.0505 正好踩中），候选会被静默忽略。
     *
     * @param centredFirst 新语义（{@code reachPx > 0}）才启用"最正"这一层；旧语义保持
     *                     「头框 → 身体框 → 最下面」，与 schema 9 及更早的行为逐项一致
     */
    private static boolean better(float headSize, float bodySize, float offset, float y,
                                  float bestHeadSize, float bestBodySize, float bestOffset,
                                  float bestY, boolean centredFirst) {
        float headBand = Math.abs(bestHeadSize) * SIZE_TIE;
        if (headSize > bestHeadSize + headBand) {
            return true;
        }
        if (headSize < bestHeadSize - headBand) {
            return false;
        }
        float bodyBand = Math.abs(bestBodySize) * SIZE_TIE;
        if (bodySize > bestBodySize + bodyBand) {
            return true;
        }
        if (bodySize < bestBodySize - bodyBand) {
            return false;
        }
        if (centredFirst) {
            // 框一样大 → 挑最正的（横向偏离最小），这正是"居中"从资格线降级后的落点。
            float offsetBand = Math.max(1f, Math.abs(bestOffset) * SIZE_TIE);
            if (offset < bestOffset - offsetBand) {
                return true;
            }
            if (offset > bestOffset + offsetBand) {
                return false;
            }
        }
        return y > bestY;
    }

    /** schema 9 signature: head/body sizes, but the centred tolerance is still the gate. */
    static int pick(float[] xs, float[] ys, float[] sizes, float[] bodySizes, boolean[] heads,
                    float anchorX, float anchorY, float tolPx, float headBonus) {
        return pick(xs, ys, sizes, bodySizes, heads, anchorX, anchorY, tolPx, 0f, headBonus);
    }

    /** Backwards-compatible overload: head size only, no body-box tie-breaker. */
    static int pick(float[] xs, float[] ys, float[] sizes, boolean[] heads, float anchorX,
                    float anchorY, float tolPx, float headBonus) {
        return pick(xs, ys, sizes, null, heads, anchorX, anchorY, tolPx, 0f, headBonus);
    }

    /** Oldest signature: no size information, so the centred head with the largest y wins. */
    static int pick(float[] xs, float[] ys, boolean[] heads, float anchorX, float anchorY,
                    float tolPx, float headBonus) {
        return pick(xs, ys, null, null, heads, anchorX, anchorY, tolPx, 0f, headBonus);
    }
}
