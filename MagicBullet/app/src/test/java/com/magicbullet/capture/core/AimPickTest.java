package com.magicbullet.capture.core;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

/**
 * Head anchor placement and target selection.
 *
 * <p>Rules under test: the aim point sits at a vertical bias inside the head box (1.0 = the chin /
 * bottom edge), and among candidates the one that is horizontally centred within the tolerance wins,
 * taking the lowest (nearest enemy) when several are centred.
 */
public class AimPickTest {

    private static final float W = 1920f;

    // ---------------------------------------------------------------- anchor

    @Test
    public void bottomBiasPutsTheAnchorOnTheChin() {
        // head box from y=100 to y=200
        assertEquals(200f, AimPick.anchorY(100f, 200f, 1.0f), 0.001f);
    }

    @Test
    public void centreBiasIsTheBoxCentre() {
        assertEquals(150f, AimPick.anchorY(100f, 200f, 0.5f), 0.001f);
    }

    @Test
    public void biasIsClampedToTheBox() {
        assertEquals(100f, AimPick.anchorY(100f, 200f, -3f), 0.001f);
        assertEquals(200f, AimPick.anchorY(100f, 200f, 7f), 0.001f);
    }

    // ---------------------------------------------------------------- tolerance

    @Test
    public void centredWithinThreePercentOfTheFrame() {
        float tol = 0.03f * W; // 57.6 px
        assertTrue(AimPick.isCentred(960 + 50, 960, tol));
        assertTrue(AimPick.isCentred(960 - 57, 960, tol));
        assertFalse(AimPick.isCentred(960 + 70, 960, tol));
    }

    // ---------------------------------------------------------------- selection

    @Test
    public void centredHeadBeatsCloserButOffsetHead() {
        // index 0: 30 px lower-right of the crosshair but 200 px off to the side? no - keep simple:
        // 0 = offset head very close to the crosshair vertically, 1 = centred head a bit lower.
        float[] xs = {960 + 200, 960 + 10};
        float[] ys = {480, 560};
        boolean[] heads = {true, true};
        int picked = AimPick.pick(xs, ys, heads, 960, 480, 0.03f * W, 12f);
        assertEquals("centred wins even though it is further away", 1, picked);
    }

    @Test
    public void amongCentredHeadsTheLowestWins() {
        float[] xs = {950, 965, 955};
        float[] ys = {400, 520, 470};
        boolean[] heads = {true, true, true};
        int picked = AimPick.pick(xs, ys, heads, 960, 400, 0.03f * W, 12f);
        assertEquals("lowest centred head = nearest enemy", 1, picked);
    }

    @Test
    public void noCentredHeadFallsBackToNearest() {
        float[] xs = {960 + 300, 960 - 320};
        float[] ys = {480, 470};
        boolean[] heads = {true, true};
        int picked = AimPick.pick(xs, ys, heads, 960, 480, 0.03f * W, 12f);
        assertEquals(0, picked); // nearest by distance
    }

    @Test
    public void centredBodyDoesNotBeatCentredHead() {
        // 0 = centred body, lower on screen; 1 = centred head, higher up.
        // The "centred" rule only accepts heads, so the head must win.
        float[] xs = {960, 960};
        float[] ys = {700, 500};
        boolean[] heads = {false, true};
        int picked = AimPick.pick(xs, ys, heads, 960, 480, 0.03f * W, 12f);
        assertEquals("only heads qualify for the centred rule", 1, picked);
    }

    @Test
    public void zeroToleranceDisablesTheCentredRule() {
        float[] xs = {960 + 300, 960 + 310};
        float[] ys = {480, 600};
        boolean[] heads = {true, true};
        // tolerance 0 → nothing counts as centred → nearest wins
        int picked = AimPick.pick(xs, ys, heads, 960, 480, 0f, 12f);
        assertEquals(0, picked);
    }

    // ---------------------------------------------------------------- 1% (schema 8)

    @Test
    public void onePercentToleranceNarrowsTheCentredWindow() {
        // schema 8 default: ±1% of the frame width = ±19.2 px on 1080p (was ±57.6 px at 3%)
        float tol = 0.01f * W;
        assertTrue(AimPick.isCentred(960 + 10, 960, tol));
        assertTrue(AimPick.isCentred(960 - 19, 960, tol));
        assertFalse("20 px off is already outside ±1%", AimPick.isCentred(960 + 20, 960, tol));
        // the old 3% window would still have accepted all of these
        assertTrue(AimPick.isCentred(960 + 20, 960, 0.03f * W));
    }

    @Test
    public void tighterToleranceHandsSelectionToTheTrulyCentredHead() {
        // 0 = nearer enemy (lowest on screen) but 30 px off the crosshair axis;
        // 1 = further enemy, only 5 px off the axis.
        float[] xs = {960 + 30, 960 + 5};
        float[] ys = {620, 520};
        boolean[] heads = {true, true};
        assertEquals("±3%: both count as centred, the lowest (nearest) one wins",
                0, AimPick.pick(xs, ys, heads, 960, 480, 0.03f * W, 12f));
        assertEquals("±1%: only the 5 px one counts as centred",
                1, AimPick.pick(xs, ys, heads, 960, 480, 0.01f * W, 12f));
    }

    @Test
    public void tighterToleranceStillFallsBackToNearest() {
        // Both heads are off-axis by more than ±1% → the centred rule is out, nearest wins.
        float[] xs = {960 + 24, 960 - 70};
        float[] ys = {480, 700};
        boolean[] heads = {true, true};
        int picked = AimPick.pick(xs, ys, heads, 960, 480, 0.01f * W, 12f);
        assertEquals("nearest by distance (24 px off, same y)", 0, picked);
    }

    @Test
    public void emptyInputPicksNothing() {
        assertEquals(-1, AimPick.pick(new float[0], new float[0], new boolean[0],
                960, 480, 57f, 12f));
        assertEquals(-1, AimPick.pick(null, null, null, 960, 480, 57f, 12f));
    }

    // ---------------------------------------------------------------- 选近优先（schema 9）

    @Test
    public void biggerBoxWinsEvenWhenItSitsHigherOnScreen() {
        // 两个头都在 ±1% 内：0 = 更远但更靠下，1 = 更近（框大）但更靠上
        float[] xs = {960, 960 + 8};
        float[] ys = {620, 400};
        float[] sizes = {0.18f, 0.30f};
        boolean[] heads = {true, true};
        assertEquals("bigger box = nearer enemy wins", 1,
                AimPick.pick(xs, ys, sizes, heads, 960, 480, 0.01f * W, 12f));
        assertEquals("old behaviour (sizes=null) keeps the lowest one", 0,
                AimPick.pick(xs, ys, heads, 960, 480, 0.01f * W, 12f));
    }

    @Test
    public void sizeTieFallsBackToTheLowest() {
        float[] xs = {960, 960 + 5};
        float[] ys = {420, 610};
        float[] sizes = {0.240f, 0.241f}; // 差 0.4% < 1% → 视为并列
        boolean[] heads = {true, true};
        assertEquals(1, AimPick.pick(xs, ys, sizes, heads, 960, 480, 0.01f * W, 12f));
    }

    @Test
    public void sizeDoesNotChangeTheNoCentredFallback() {
        // 两个头都超出 ±1% → 走距离最近，尺寸大小不参与
        float[] xs = {960 + 40, 960 - 90};
        float[] ys = {480, 500};
        float[] sizes = {0.15f, 0.40f};
        boolean[] heads = {true, true};
        assertEquals("fallback stays distance-based", 0,
                AimPick.pick(xs, ys, sizes, heads, 960, 480, 0.01f * W, 12f));
    }

    @Test
    public void zeroToleranceWithSizesStillTakesTheNearest() {
        float[] xs = {960 + 30, 960 + 200};
        float[] ys = {480, 700};
        float[] sizes = {0.20f, 0.50f};
        boolean[] heads = {true, true};
        assertEquals(0, AimPick.pick(xs, ys, sizes, heads, 960, 480, 0f, 12f));
    }

    @Test
    public void centredBodyStillLosesToACentredHeadEvenWithABiggerBox() {
        // 0 = 居中的 body（框更大），1 = 居中的 head（框更小）：居中规则只认 head
        float[] xs = {960, 960};
        float[] ys = {700, 500};
        float[] sizes = {0.60f, 0.20f};
        boolean[] heads = {false, true};
        assertEquals(1, AimPick.pick(xs, ys, sizes, heads, 960, 480, 0.01f * W, 12f));
    }

    @Test
    public void sizesArrayShorterThanCandidatesIsSafe() {
        float[] xs = {960, 960 + 6};
        float[] ys = {500, 520};
        float[] sizes = {0.20f}; // 越界索引必须回落到 y 判据，而不是抛异常
        boolean[] heads = {true, true};
        assertEquals(1, AimPick.pick(xs, ys, sizes, heads, 960, 480, 0.01f * W, 12f));
    }

    // ------------------------------------------------- 头框并列 → 比身体框（schema 9 补充）

    @Test
    public void equalHeadSizesHandTheTieToTheBiggerBody() {
        // 头框一样大（差 0.4%，落在 1% 并列带内），0 = 更靠下但身体小，1 = 更靠上但身体大
        float[] xs = {960, 960 + 8};
        float[] ys = {620, 400};
        float[] headSizes = {0.050f, 0.0502f};
        float[] bodySizes = {0.18f, 0.30f};
        boolean[] heads = {true, true};
        assertEquals("bigger body wins the head-size tie", 1,
                AimPick.pick(xs, ys, headSizes, bodySizes, heads, 960, 480, 0.01f * W, 12f));
        assertEquals("without body info the lowest one wins (old behaviour)", 0,
                AimPick.pick(xs, ys, headSizes, heads, 960, 480, 0.01f * W, 12f));
    }

    @Test
    public void boundaryBetweenBiggerAndTieHasNoGap() {
        // 回归：0.050 与 0.0505 的相对差 ≈1.0002%，正好压在并列带外沿。旧写法用
        // "× (1+tie)" 判更大、用相对差判并列，二者在浮点边界上留出缝隙，
        // 结果这个候选既不算更大也不算并列，被静默忽略（选错人）。
        float[] xs = {960, 960 + 6};
        float[] ys = {400, 620};
        float[] headSizes = {0.050f, 0.0505f};
        boolean[] heads = {true, true};
        assertEquals("a head 1.0002% bigger must count as bigger", 1,
                AimPick.pick(xs, ys, headSizes, heads, 960, 480, 0.01f * W, 12f));
    }

    @Test
    public void biggerHeadStillBeatsABiggerBody() {
        // 头框明显更大（不被 1% 判为并列）→ 头框优先，身体框大小不参与
        float[] xs = {960, 960 + 6};
        float[] ys = {450, 600};
        float[] headSizes = {0.070f, 0.050f};
        float[] bodySizes = {0.20f, 0.35f};
        boolean[] heads = {true, true};
        assertEquals(0, AimPick.pick(xs, ys, headSizes, bodySizes, heads,
                960, 480, 0.01f * W, 12f));
    }

    @Test
    public void equalBodySizesFallBackToTheLowest() {
        float[] xs = {960, 960 + 5};
        float[] ys = {430, 610};
        float[] headSizes = {0.050f, 0.050f};
        float[] bodySizes = {0.240f, 0.241f};
        boolean[] heads = {true, true};
        assertEquals(1, AimPick.pick(xs, ys, headSizes, bodySizes, heads,
                960, 480, 0.01f * W, 12f));
    }

    @Test
    public void headOnlyCandidateLosesTheTieAgainstOneWithABody() {
        // 头框并列，0 有身体框、1 是 head-only（bodySize = 0）→ 有身体的优先
        float[] xs = {960, 960 + 7};
        float[] ys = {430, 620};
        float[] headSizes = {0.050f, 0.050f};
        float[] bodySizes = {0.30f, 0f};
        boolean[] heads = {true, true};
        assertEquals(0, AimPick.pick(xs, ys, headSizes, bodySizes, heads,
                960, 480, 0.01f * W, 12f));
    }

    // ------------------------------------------------- 框大优先（schema 10，横向可达范围）

    /** 用户场景：近处一个大框 + 两个靠中间但更远的小框 → 必须锁大框。 */
    @Test
    public void nearBigBoxWinsOverTwoCentredFarBoxes() {
        float[] xs = {960 + 60, 960 + 5, 960 - 12};   // 近敌偏 60 px，另外两个几乎居中
        float[] ys = {600, 430, 450};
        float[] headSizes = {0.090f, 0.045f, 0.045f}; // 近敌头框是另外两个的两倍
        float[] bodySizes = {0.30f, 0.15f, 0.15f};
        boolean[] heads = {true, true, true};
        float reach = 0.15f * W;                     // ±288 px
        assertEquals("the big box wins even though it is 60 px off axis", 0,
                AimPick.pick(xs, ys, headSizes, bodySizes, heads, 960, 480, 0.01f * W, reach, 12f));
        // reach = 0 → 回到旧的居中容差资格线：近敌出局，两个小框并列时取最下面
        assertEquals(2, AimPick.pick(xs, ys, headSizes, bodySizes, heads,
                960, 480, 0.01f * W, 0f, 12f));
    }

    @Test
    public void outsideReachIsExcluded() {
        // 近敌偏 320 px > reach 288 → 出局，剩下的居中目标胜
        float[] xs = {960 + 320, 960 + 5};
        float[] ys = {600, 430};
        float[] headSizes = {0.090f, 0.045f};
        float[] bodySizes = {0.30f, 0.15f};
        boolean[] heads = {true, true};
        assertEquals(1, AimPick.pick(xs, ys, headSizes, bodySizes, heads,
                960, 480, 0.01f * W, 0.15f * W, 12f));
    }

    @Test
    public void withinReachHeadTieGoesToTheBiggerBody() {
        float[] xs = {960, 960 + 80};   // 都在 reach 内
        float[] ys = {500, 600};
        float[] headSizes = {0.050f, 0.050f};
        float[] bodySizes = {0.18f, 0.30f};
        boolean[] heads = {true, true};
        assertEquals(1, AimPick.pick(xs, ys, headSizes, bodySizes, heads,
                960, 480, 0.01f * W, 0.15f * W, 12f));
    }

    @Test
    public void withinReachFullTiePicksTheMostCentred() {
        // 头框、身体框都并列 → 挑最正的（即使它更靠上，"最正"排在"最下面"之前）
        float[] xs = {960, 960 + 40};
        float[] ys = {400, 700};
        float[] headSizes = {0.050f, 0.050f};
        float[] bodySizes = {0.20f, 0.20f};
        boolean[] heads = {true, true};
        assertEquals(0, AimPick.pick(xs, ys, headSizes, bodySizes, heads,
                960, 480, 0.01f * W, 0.15f * W, 12f));
    }

    @Test
    public void noHeadWithinReachFallsBackToNearest() {
        // 范围内没有 head 候选（只有 body）→ 距离最近，尺寸不参与
        float[] xs = {960 + 40, 960 + 200};
        float[] ys = {480, 700};
        float[] headSizes = {0f, 0f};
        float[] bodySizes = {0.15f, 0.40f};
        boolean[] heads = {false, false};
        assertEquals(0, AimPick.pick(xs, ys, headSizes, bodySizes, heads,
                960, 480, 0.01f * W, 0.15f * W, 12f));
    }

    // ------------------------------------------------- 抢锁双门槛（schema 11，治"两个近敌抢鼠标"）

    @Test
    public void takeoverNeedsBothRelativeAndAbsoluteMargin() {
        float gate = 1.12f;
        float deltaMin = 0.01f;
        // 近处两个目标都很小：相对差 13% 够，但绝对差只有 0.0065 → 不让抢
        assertFalse("relative ok but absolute not enough", AimPick.shouldTakeOver(
                0.0565f, 0.050f, gate, deltaMin));
        // 绝对差够了、相对差也够 → 可以抢
        assertTrue(AimPick.shouldTakeOver(0.060f, 0.050f, gate, deltaMin));
        // 远处大框：绝对差很大，但相对差不够 → 不让抢
        assertFalse("absolute ok but relative not enough", AimPick.shouldTakeOver(
                0.200f, 0.190f, gate, deltaMin));
    }

    @Test
    public void takeoverRejectsCandidatesWithoutSize() {
        assertFalse(AimPick.shouldTakeOver(0f, 0.05f, 1.12f, 0.01f));
        assertFalse(AimPick.shouldTakeOver(0.05f, 0f, 1.12f, 0.01f));
    }
}
