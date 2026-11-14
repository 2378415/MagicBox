/* sumv - 拟人化相对移动引擎（1000 Hz 采样，三次贝塞尔 + 随机魔改）。
 *
 * 语义（2026-11-10 定稿）：
 *   - 一次调用 = 一条完整轨迹，采样 1000 Hz（esp_timer 1000 µs）
 *   - speed 单位 counts/s：T_ms = clamp(1000*D/speed, 40, 5000)，越大越快
 *   - 执行期间由 app 层把真实鼠标的 X/Y 丢掉（按键与滚轮透传，见 app_main.c）
 *   - 守恒：Σ 发出的 counts 精确等于请求（亚计数 DDA）
 *   - 再次调用 = REPLACE，旧轨迹剩余永久丢弃（aborted++）
 *
 * 拟人层（mode 位控制）：手颤 8–12 Hz / 子运动 1–3 个 / 微停顿 40–120 ms /
 * 过冲回拉（把路径延伸到目标之外，最后 20% 进度线性拉回）。
 */
#include "makcu_sumv.h"

#include <math.h>
#include <string.h>

#include "esp_log.h"
#include "esp_random.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "makcu_mouse.h"

static const char *TAG = "sumv";

/* ---------------------------------------------------------------- 常量 */
#define SUMV_TICK_US      1000            /* 1 kHz 采样 */
#define SUMV_T_MIN_MS     4        /* 极短位移也允许极短时长（原来 40 ms 把短距离速度卡死） */
#define SUMV_T_MAX_MS     5000
#define SUMV_SPEED_MIN    50
/* 请求速度上限放到 int8 单报告极限：1 kHz × 127 counts = 127,000 counts/s。
 * 注意真正生效的上限 = 1000 × max_report（见 s_max_report），127000 只有在
 * max_report=127 时才摸得到；瞄准场景默认 max_report=60 → 实际 60,000。 */
#define SUMV_SPEED_MAX    65535    /* speed 是 u16（协议同宽），更大的数只能靠 bit7 极速 */
#define SUMV_SPEED_DEF    400
#define SUMV_MAX_REPORT_DEF   12   /* 每报告的基准值（≈15 px/跳） */
/* 自动模式：每报告上限随 speed 上抬，`mr = 12 + (speed - 11000) / 1000`（夹到 8..120）。
 * 为什么要有它：1 kHz 采样下"每条报告 ≤ mr counts"等价于速度天花板 1000×mr，
 * 固定 mr=12 时请求 20000/60000 都会被夹回 12000（空转）。按这个斜率抬，
 * `mr ≈ speed/1000 + 1`，t_floor 永远 ≤ 1000·D/speed，speed 就是字面速度。 */
#define SUMV_MR_KNEE          11000
#define SUMV_MR_STEP          1000
#define SUMV_MAX_REPORT_MIN   8
#define SUMV_MAX_REPORT_MAX   120   /* 实用上限：留余量，避免每样本都撞 int8 钳位（127） */
#define SUMV_POLY_N       64              /* 折线采样点数（贝塞尔近似） */
#define SUMV_Q            16              /* 定点小数位 */
/* 粘滞收尾：最后 5% 进度把"位置-时间"压低一点（进入尾段时速度约 −15%），
 * u=1 处 bump=0，所以终点仍然精确落在请求值上。bit5 可关。 */
#define SUMV_TAIL_U0      ((int32_t)(0.95 * 65536.0))      /* Q16 */
#define SUMV_TAIL_A       560                              /* 拟人模式强度（Q16，≈0.85% 进度） */
#define SUMV_TAIL_A_HALF  280                              /* 瞄准模式强度（减半） */

/* mode 位 */
#define M_FIXED_DUR   (1u << 0)
#define M_TREMOR      (1u << 1)
#define M_SUBMOVE     (1u << 2)
#define M_OVERSHOOT   (1u << 3)   /* retired 2026-11-11: 过冲回拉已移除，传了无效 */
#define M_PAUSE       (1u << 4)   /* retired 2026-11-10: 微停顿已移除 */
#define M_TAIL_OFF    (1u << 5)   /* 关闭"粘滞收尾" */
#define M_MAX_SPEED   (1u << 7)   /* 极速：时长直接取 floor（= 1000×max_report counts/s） */
#define M_HUMAN       (1u << 6)   /* 拟人模式：min-jerk + 手颤 + 子运动 + 大弧度 + 粘滞 */
#define M_CRUISE      (1u << 3)   /* 恒速剖面（原"过冲"退役位复用）：AIM 用，最小延迟、无加减速段 */

/* ---- AIM（瞄准专用入口）---- */
#define SUMV_AIM_DEAD_DEF   2     /* 死区默认 2 counts（≈2.5 px）：残差小于它就当到位 */
#define SUMV_AIM_LIMIT      4000  /* 会话累计位移钳位（counts），flags bit0 打开 */
#define SUMV_AIM_FLAG_LIMIT (1u << 0)   /* 打开累计钳位 */
#define SUMV_AIM_FLAG_FAST  (1u << 1)   /* 等价 bit7 极速 */

/* AIM 结果码（AIM_STATE 第一字节） */
#define SUMV_R_UNKNOWN  0
#define SUMV_R_STARTED  1
#define SUMV_R_REPLACED 2
#define SUMV_R_REJECTED 3
#define SUMV_R_DEADZONE 4
#define SUMV_R_FAULT    5
#define SUMV_R_LIMIT    6

/* ---- 瞄准模式（默认，bit6=0）：FPS 拉枪线手感 ----
 *   D ≤ 10      单发（一条报告给完）
 *   D ≤ 60      恒速 + 纯直线（贝塞尔退化为直线）
 *   D > 60      梯形速度剖面（快起、巡航、短促刹车）+ 1% 浅弧
 *   粘滞收尾只在 D ≥ 600 时保留，且强度减半                        */
#define SUMV_SINGLE_MAX      10
#define SUMV_STRAIGHT_MAX    60
#define SUMV_CURVE_AIM       60.0f     /* 法向偏移 = span/60（≈1.25% 弧高） */
#define SUMV_CURVE_HUMAN     12.0f     /* 原拟人弧度 */
#define SUMV_TAIL_MIN_D      600

typedef struct {
    /* 几何：折线（Q16 counts）+ 累计弧长（Q16） */
    int32_t  bx[SUMV_POLY_N + 1];
    int32_t  by[SUMV_POLY_N + 1];
    int32_t  cum[SUMV_POLY_N + 1];
    int32_t  total;                   /* 弧长总量，Q16 */
    int32_t  dx, dy;                  /* 请求（counts）——路径终点精确落在这里 */
    /* 速度剖面：65 点累计进度 LUT（Q16，0..65536） */
    int32_t  prof[SUMV_POLY_N + 1];
    uint8_t  prof_kind;               /* 0=恒速 1=梯形 2=min-jerk(拟人) */
    uint8_t  mr_eff;                  /* 本次实际用的每报告上限 */
    int32_t  tail_amp;                /* 粘滞收尾强度（Q16，0 = 关） */
    /* 定时 */
    uint32_t n;                       /* 有效样本数（不含停顿） */
    uint32_t i;                       /* 已走样本 */
    uint32_t pause_at;                /* 停顿起点（样本序） */
    uint32_t pause_len;               /* 停顿时长（样本） */
    uint32_t total_samples;           /* n + pause_len */
    /* DDA */
    int32_t  px, py;                  /* 已发出的位置（counts） */
    /* 个性 */
    int32_t  tremor_amp;              /* 垂直抖动幅度（Q16 counts） */
    uint32_t tremor_ph0;              /* 相位初值（0..1023） */
    uint32_t tremor_step;             /* 每样本相位步进（8–12 Hz） */
    /* 垂直方向单位向量（Q16）。必须带符号：左/下方向的分量为负，若存成 uint32，
     * 升到 int64 乘 off 时会变成 +4.29e9 量级，注入端再被 clamp 成 ±127/ms —— 表现为
     * 光标一路冲到屏幕边界（2026-11-10 定位：左、下坏，右、上正常）。 */
    int32_t  tremor_vs, tremor_vc;
    uint32_t sub_n;
    uint32_t sub_c[3], sub_w[3];      /* 子运动中心/半宽（Q16 进度） */
    int32_t  sub_a[3];                /* 幅度（Q16 进度） */
    uint16_t speed;
    uint8_t  mode;
    bool     active;
} sumv_t;

static sumv_t s_v;
static sumv_t s_backup;              /* REPLACE 前的快照：新请求退化时回滚，旧轨迹继续跑 */
static volatile uint32_t s_gen;      /* 轨迹代数：REPLACE 时 +1，任务用它丢弃过期样本 */
static uint32_t s_started_us;        /* 当前轨迹开始时刻（看门狗 / AIM_STATE 用时） */
static uint8_t  s_last_result = SUMV_R_UNKNOWN;
static uint16_t s_last_counts;       /* 上一发请求的 counts（切比雪夫长度） */
static uint16_t s_last_dur_ms;       /* 上一发实际耗时 */
static uint32_t s_dead_hits;         /* 因死区跳过的次数 */
static int32_t  s_aim_total_dx, s_aim_total_dy;   /* AIM 会话累计 */
static uint16_t s_default_speed = SUMV_SPEED_DEF;
static uint8_t  s_max_report = 0;      /* 0 = 自动（跟 speed 走）；非 0 = 固定 */
static TaskHandle_t s_task;
static esp_timer_handle_t s_timer;

/* 统计 */
static volatile uint32_t s_samples;
static volatile uint32_t s_aborted;
static volatile uint32_t s_rounds;
static volatile uint32_t s_mute_dropped;
static volatile uint32_t s_btn_forwarded;
static volatile uint32_t s_last_speed_eff;

bool makcu_sumv_active(void)
{
    return s_v.active;
}

/* ------------------------------------------------------------- 数学工具 */
/* 最小 jerk：t^3 (10 - 15t + 6t^2)，输入输出都是 Q16 的 [0,1] */
static int32_t minjerk_q16(uint32_t i, uint32_t n)
{
    if (n == 0) {
        return 0;
    }
    if (i >= n) {
        return 1 << SUMV_Q;
    }
    const int64_t t  = ((int64_t)i << SUMV_Q) / n;         /* Q16, 0..1 */
    const int64_t t2 = (t * t) >> SUMV_Q;                  /* Q16 */
    const int64_t t3 = (t2 * t) >> SUMV_Q;                 /* Q16 */
    /* u = 10t^3 - 15t^4 + 6t^5 = t^3 * (10 - 15t + 6t^2)，全部 Q16
     * 注意：内层三项都必须保持 Q16 量纲（曾把 6t² 写成 6，t→1 时内层变负，
     * 曲线在尾部来回甩，注入输出成 ±127 的震荡）。 */
    const int64_t inner = (10LL << SUMV_Q) - 15LL * t + 6LL * t2;
    int64_t v = (t3 * inner) >> SUMV_Q;
    if (v < 0) { v = 0; }
    if (v > (1 << SUMV_Q)) { v = (1 << SUMV_Q); }
    return (int32_t)v;
}

static int32_t isqrt32(uint32_t v)
{
    uint32_t r = 0, bit = 1u << 30;
    while (bit > v) {
        bit >>= 2;
    }
    while (bit) {
        if (v >= r + bit) {
            v -= r + bit;
            r = (r >> 1) + bit;
        } else {
            r >>= 1;
        }
        bit >>= 2;
    }
    return (int32_t)r;
}

/* 给定速度的有效"每报告上限"：0 = 自动时按拐点线性上抬 */
static uint32_t mr_for_speed(uint32_t speed)
{
    uint32_t mr = s_max_report;
    if (mr == 0) {
        mr = SUMV_MAX_REPORT_DEF;
        if (speed > SUMV_MR_KNEE) {
            mr += (speed - SUMV_MR_KNEE) / SUMV_MR_STEP;
        }
    }
    if (mr < SUMV_MAX_REPORT_MIN) { mr = SUMV_MAX_REPORT_MIN; }
    if (mr > SUMV_MAX_REPORT_MAX) { mr = SUMV_MAX_REPORT_MAX; }
    return mr;
}

/* ---------------------------------------------------------- 速度剖面 */
/* 恒定速度：进度与时间成正比 */
static void profile_linear(void)
{
    for (int i = 0; i <= SUMV_POLY_N; i++) {
        s_v.prof[i] = (int32_t)(((int64_t)i << SUMV_Q) / SUMV_POLY_N);
    }
}

/* 梯形：两端 raised-cosine 斜坡 + 中段恒速（速度连续，没有折角）。
 * r1/r2 是进出斜坡占全程的比例。 */
static void profile_trapezoid(double r1, double r2)
{
    double v[SUMV_POLY_N + 1];
    const double dt = 1.0 / SUMV_POLY_N;
    double total = 0.0;
    double acc = 0.0;

    for (int i = 0; i <= SUMV_POLY_N; i++) {
        const double t = (double)i * dt;
        double vel = 1.0;
        if (r1 > 1e-6 && t < r1) {
            vel = 0.5 - 0.5 * cos(M_PI * t / r1);
        } else if (r2 > 1e-6 && t > 1.0 - r2) {
            vel = 0.5 - 0.5 * cos(M_PI * (1.0 - t) / r2);
        }
        v[i] = vel;
    }
    for (int i = 1; i <= SUMV_POLY_N; i++) {
        total += 0.5 * (v[i] + v[i - 1]) * dt;
    }
    if (total <= 0.0) {
        total = 1.0;
    }
    s_v.prof[0] = 0;
    for (int i = 1; i <= SUMV_POLY_N; i++) {
        acc += 0.5 * (v[i] + v[i - 1]) * dt;
        double u = acc / total;
        if (u > 1.0) { u = 1.0; }
        s_v.prof[i] = (int32_t)(u * 65536.0);
    }
    s_v.prof[SUMV_POLY_N] = 1 << SUMV_Q;
}

/* min-jerk（拟人模式）：先算 65 点位置，供与上面同样的查表使用 */
static void profile_minjerk(void)
{
    for (int i = 0; i <= SUMV_POLY_N; i++) {
        s_v.prof[i] = minjerk_q16((uint32_t)(i * (int)SUMV_POLY_N / SUMV_POLY_N), SUMV_POLY_N);
    }
    s_v.prof[SUMV_POLY_N] = 1 << SUMV_Q;
}

/* 按样本序号取进度：把 i/n 映射到 65 点 LUT 上线性插值 */
static int32_t prof_at(uint32_t i, uint32_t n)
{
    if (n <= 1) {
        return (1 << SUMV_Q);
    }
    uint32_t idx = (uint32_t)(((uint64_t)i << 16) / n);          /* 0..65536 */
    if (idx >= (1u << SUMV_Q)) {
        return s_v.prof[SUMV_POLY_N];
    }
    uint32_t fpos = idx * SUMV_POLY_N;                            /* 低 16 位是小数 */
    uint32_t seg = fpos >> 16;
    uint32_t frac = fpos & 0xFFFFu;
    if (seg >= SUMV_POLY_N) {
        return s_v.prof[SUMV_POLY_N];
    }
    const int32_t a = s_v.prof[seg];
    const int32_t b = s_v.prof[seg + 1];
    return a + (int32_t)(((int64_t)(b - a) * (int32_t)frac) >> 16);
}

/* ------------------------------------------------------------- 路径构建 */
static void build_path(void)
{
    /* 控制点：沿路径 1/3、2/3 处 + 随机垂直偏移 */
    const float dx = (float)s_v.dx;
    const float dy = (float)s_v.dy;
    const float span = sqrtf(dx * dx + dy * dy);
    if (span < 1.0f) {
        s_v.total = 0;
        return;
    }
    /* 垂直单位向量 */
    const float px = -dy / span;
    const float py = dx / span;
    /* 瞄准模式：1% 浅弧、无沿路抖动；拟人模式保留 span/12 + ±10% 抖动 */
    const bool human = (s_v.mode & M_HUMAN) != 0;
    float lim = span / (human ? SUMV_CURVE_HUMAN : SUMV_CURVE_AIM);
    float jscale = human ? 0.10f : 0.0f;
    if (!human && span <= (float)SUMV_STRAIGHT_MAX) {
        lim = 0.0f;                     /* 短距离：贝塞尔退化成直线 */
        jscale = 0.0f;
    }
    const float o1 = ((float)(int32_t)(esp_random() % 2001) - 1000.0f) / 1000.0f * lim;
    const float o2 = ((float)(int32_t)(esp_random() % 2001) - 1000.0f) / 1000.0f * lim;
    /* 沿路径方向的"手不稳"抖动 */
    const float j1 = ((float)(int32_t)(esp_random() % 2001) - 1000.0f) / 1000.0f * span * jscale;
    const float j2 = ((float)(int32_t)(esp_random() % 2001) - 1000.0f) / 1000.0f * span * jscale;

    const float c1x = dx / 3.0f + px * o1 + (dx / span) * j1;
    const float c1y = dy / 3.0f + py * o1 + (dy / span) * j1;
    const float c2x = dx * 2.0f / 3.0f + px * o2 + (dx / span) * j2;
    const float c2y = dy * 2.0f / 3.0f + py * o2 + (dy / span) * j2;

    /* 终点 = 请求值：不过冲、不延长（2026-11-11 移除"过冲回拉"） */
    for (int i = 0; i <= SUMV_POLY_N; i++) {
        const float t = (float)i / (float)SUMV_POLY_N;
        const float mt = 1.0f - t;
        const float a = mt * mt * mt, b = 3.0f * mt * mt * t;
        const float c = 3.0f * mt * t * t, d = t * t * t;
        const float x = a * 0.0f + b * c1x + c * c2x + d * dx;
        const float y = a * 0.0f + b * c1y + c * c2y + d * dy;
        s_v.bx[i] = (int32_t)(x * 65536.0f);
        s_v.by[i] = (int32_t)(y * 65536.0f);
    }
    s_v.cum[0] = 0;
    for (int i = 1; i <= SUMV_POLY_N; i++) {
        const int32_t ax = s_v.bx[i] - s_v.bx[i - 1];
        const int32_t ay = s_v.by[i] - s_v.by[i - 1];
        const int32_t seg = isqrt32((uint32_t)((int64_t)ax * ax / 65536 + (int64_t)ay * ay / 65536));
        s_v.cum[i] = s_v.cum[i - 1] + seg;
    }
    s_v.total = s_v.cum[SUMV_POLY_N];
    if (s_v.total <= 0) {
        s_v.total = 1;
    }
    /* 垂直单位向量，Q16（带符号，见结构体注释） */
    s_v.tremor_vs = (int32_t)(px * 65536.0f);
    s_v.tremor_vc = (int32_t)(py * 65536.0f);
}

/* 折线查找：按弧长百分比（Q16 的 u∈[0,1]）取点 */
static void path_at(uint32_t u, int32_t *ox, int32_t *oy)
{
    int64_t want = ((int64_t)s_v.total * u) >> SUMV_Q;    /* Q16 弧长 */
    int k = 0;
    while (k < SUMV_POLY_N - 1 && s_v.cum[k + 1] < want) {
        k++;
    }
    const int32_t seg_start = s_v.cum[k];
    const int32_t seg_len = s_v.cum[k + 1] - seg_start;
    int32_t frac = 0;
    if (seg_len > 0) {
        frac = (int32_t)((((int64_t)(want - seg_start)) << SUMV_Q) / seg_len);
    }
    if (frac < 0) { frac = 0; }
    if (frac > (1 << SUMV_Q)) { frac = 1 << SUMV_Q; }
    const int32_t x = s_v.bx[k] + (int32_t)(((int64_t)(s_v.bx[k + 1] - s_v.bx[k]) * frac) >> SUMV_Q);
    const int32_t y = s_v.by[k] + (int32_t)(((int64_t)(s_v.by[k + 1] - s_v.by[k]) * frac) >> SUMV_Q);
    *ox = x;
    *oy = y;
}

/* ------------------------------------------------------------ 单个样本
 *
 * gen：调用者看到的轨迹代数。采样过程中若被 REPLACE（s_gen 变了），这里算出来的
 * 位置属于旧轨迹，**不能再发、也不能再改 s_v**，直接丢弃 → 消掉"控制任务改 s_v、
 * 采样任务正在读"的竞态后果（最多丢一个样本，不会污染新轨迹）。
 * 另：进度取 prof_at(ip + 1)，让第一个样本就有位移（省掉 1 ms 的空起步），
 * 最后一个样本正好落在 u=1（终点精确）。
 */
static void emit_sample(uint32_t gen)
{
    /* 进度（剔除停顿） */
    uint32_t ip = s_v.i;
    if (s_v.pause_len != 0) {
        if (ip >= s_v.pause_at) {
            ip = (ip >= s_v.pause_at + s_v.pause_len) ? (ip - s_v.pause_len) : s_v.pause_at;
        }
    }
    int32_t u = prof_at(ip + 1, s_v.n);

    /* 子运动：叠加 1–3 个二次峰（只加不超） */
    for (uint32_t k = 0; k < s_v.sub_n; k++) {
        const int32_t d = (int32_t)u - (int32_t)s_v.sub_c[k];
        const int32_t w = (int32_t)s_v.sub_w[k];
        if (w <= 0) {
            continue;
        }
        const int64_t r = ((int64_t)d * 65536) / w;
        if (r > -65536 && r < 65536) {
            const int64_t f = 65536 - (r * r) / 65536;         /* 抛物线峰 */
            u += (int32_t)((f * s_v.sub_a[k]) >> (SUMV_Q + SUMV_Q));
        }
    }
    if (u < 0) { u = 0; }
    if (u > (1 << SUMV_Q)) { u = 1 << SUMV_Q; }

    /* 粘滞收尾：最后 5% 进度把位置往后压一点点 → 尾段速度约 −15%，
     * 但 bump 在 u=1 处归零，所以终点仍然精确落在请求值（不做回拉）。 */
    if (s_v.tail_amp != 0 && !(s_v.mode & M_TAIL_OFF) && u > SUMV_TAIL_U0) {
        const int32_t w = (1 << SUMV_Q) - SUMV_TAIL_U0;
        const int32_t x = (int32_t)(((int64_t)(u - SUMV_TAIL_U0) << SUMV_Q) / w);   /* 0..Q16 */
        const int32_t bump = (int32_t)(((int64_t)4 * x * ((1 << SUMV_Q) - x)) >> SUMV_Q);
        u -= (int32_t)(((int64_t)bump * s_v.tail_amp) >> SUMV_Q);
        if (u < 0) { u = 0; }
    }

    int32_t qx, qy;
    path_at((uint32_t)u, &qx, &qy);

    /* 手颤：垂直方向 8–12 Hz */
    if (s_v.tremor_amp != 0) {
        const uint32_t ph = (s_v.tremor_ph0 + s_v.i * s_v.tremor_step) & 1023;
        /* 三角波（比 sin 便宜，观感足够） */
        const int32_t tri = (ph < 512) ? (int32_t)ph - 256 : 768 - (int32_t)ph;
        const int32_t off = (int32_t)(((int64_t)tri * s_v.tremor_amp) / 256);
        qx += (int32_t)(((int64_t)s_v.tremor_vs * off) >> SUMV_Q);
        qy += (int32_t)(((int64_t)s_v.tremor_vc * off) >> SUMV_Q);
    }

    if (gen != s_gen) {
        return;                     /* 轨迹已被替换：这一发作废 */
    }

    /* DDA：累计位置取整，余量留在 Q16 里 */
    const int32_t tx = qx >> SUMV_Q;
    const int32_t ty = qy >> SUMV_Q;
    int32_t dx = tx - s_v.px;
    int32_t dy = ty - s_v.py;
    if (dx > 127) { dx = 127; }
    if (dx < -127) { dx = -127; }
    if (dy > 127) { dy = 127; }
    if (dy < -127) { dy = -127; }
    if (dx != 0 || dy != 0) {
        makcu_mouse_emit_now((int8_t)dx, (int8_t)dy, 0);
        s_v.px += dx;
        s_v.py += dy;
    }
    s_samples++;
}

/* ------------------------------------------------------------ 定时/任务 */
static void sumv_tick(void *arg)
{
    (void)arg;
    /* 看门狗：正常轨迹最多 total_samples ms，超过 +500 ms 还在跑说明报告发不出去
     * （HID 卸载 / 端点卡住），强制收尾，避免状态永远停在 active=1。 */
    if (s_v.active) {
        const uint32_t elapsed_ms = (uint32_t)((esp_timer_get_time() - (int64_t)s_started_us) / 1000);
        if (elapsed_ms > s_v.total_samples + 500u) {
            s_v.active = false;
            s_last_result = SUMV_R_FAULT;
            s_gen++;
            s_aborted++;
            (void)esp_timer_stop(s_timer);
            ESP_LOGW("makcu_sumv", "watchdog: %u ms > %u ms, forced stop",
                     (unsigned)elapsed_ms, (unsigned)(s_v.total_samples + 500u));
            return;
        }
    }
    if (s_task != NULL) {
        xTaskNotifyGive(s_task);
    }
}

static void sumv_task(void *arg)
{
    (void)arg;
    for (;;) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        const uint32_t gen = s_gen;
        if (!s_v.active) {
            continue;
        }
        if (s_v.i >= s_v.total_samples) {
            /* 收尾：把剩余 counts 补平，但**每个 tick 最多补一发**（最多 mr_eff）。
             * 这样极速档的大缺口会摊到接下来几毫秒里，而不是 1 ms 内连发 8 条造成跳变。 */
            if (gen != s_gen) {
                continue;
            }
            int32_t rx = s_v.dx - s_v.px;
            int32_t ry = s_v.dy - s_v.py;
            if (rx != 0 || ry != 0) {
                const int32_t cap = (int32_t)s_v.mr_eff;
                const int32_t ex = rx > cap ? cap : (rx < -cap ? -cap : rx);
                const int32_t ey = ry > cap ? cap : (ry < -cap ? -cap : ry);
                const int32_t cx = ex > 127 ? 127 : (ex < -127 ? -127 : ex);
                const int32_t cy = ey > 127 ? 127 : (ey < -127 ? -127 : ey);
                makcu_mouse_emit_now((int8_t)cx, (int8_t)cy, 0);
                s_v.px += cx;
                s_v.py += cy;
            }
            rx = s_v.dx - s_v.px;
            ry = s_v.dy - s_v.py;
            if (rx == 0 && ry == 0) {
                s_v.active = false;
                s_rounds++;
                s_last_dur_ms = (uint16_t)((esp_timer_get_time() - (int64_t)s_started_us) / 1000);
                if (s_last_result != SUMV_R_REPLACED) {
                    s_last_result = SUMV_R_STARTED;      /* 正常走完 */
                }
                if (s_timer != NULL) {
                    (void)esp_timer_stop(s_timer);
                }
            }
            continue;
        }
        emit_sample(gen);
        if (gen == s_gen) {
            s_v.i++;
        }
    }
}

/* ------------------------------------------------------------------ API */
bool makcu_sumv_start(const makcu_sumv_req_t *req)
{
    if (req == NULL || s_task == NULL) {
        return false;
    }
    const int32_t dx = req->dx;
    const int32_t dy = req->dy;
    const int32_t ax = dx < 0 ? -dx : dx;
    const int32_t ay = dy < 0 ? -dy : dy;
    const int32_t cheb = ax > ay ? ax : ay;
    if (cheb == 0) {
        return false;
    }
    /* 距离 = 欧氏 */
    int64_t d2 = (int64_t)dx * dx + (int64_t)dy * dy;
    int32_t dist = isqrt32((uint32_t)(d2 > 0x7FFFFFFF ? 0x7FFFFFFF : d2));
    if (dist <= 0) {
        dist = cheb;
    }

    /* speed == 0 表示"用默认值"（400 counts/s）；只有显式给了 1..49 才夹到下限。
     * 实测踩过：把 0 也当成"太小"夹成 50，默认调用直接变成最慢档（5000 ms）。 */
    uint32_t speed = req->speed;
    if (speed == 0) {
        speed = s_default_speed;
    }
    if (speed < SUMV_SPEED_MIN) { speed = SUMV_SPEED_MIN; }
    if (speed > SUMV_SPEED_MAX) { speed = SUMV_SPEED_MAX; }

    /* 时长下限 = "每样本不超过 mr_eff counts"（1 kHz 采样 → 速度上限 1000×mr_eff）。
     * mr_eff 默认跟 speed 自动走（拐点 11000），台架可以 mx.mv 固定。
     * 极速档（bit7）直接用最大 120，不受拐点限制。 */
    uint32_t mr_eff = (req->mode & M_MAX_SPEED) ? SUMV_MAX_REPORT_MAX : mr_for_speed(speed);
    uint32_t t_floor = (uint32_t)((dist + mr_eff - 1) / mr_eff);
    if (t_floor < SUMV_T_MIN_MS) {
        t_floor = SUMV_T_MIN_MS;
    }
    uint32_t t_ms;
    if ((req->mode & M_FIXED_DUR) && req->dur_ms != 0) {
        /* 显式给了时长就**尊重它**（只夹到 >=4 ms），不被 t_floor 抬高 ——
         * 这样客户端可以精确要求"这一发必须在 X ms 内走完"。代价是每报告可能超过
         * mr_eff，超出部分靠收尾分支每毫秒补一发摊平。 */
        t_ms = req->dur_ms < SUMV_T_MIN_MS ? SUMV_T_MIN_MS : req->dur_ms;
    } else if (req->mode & M_MAX_SPEED) {
        t_ms = t_floor;                  /* 极速：每样本正好 mr_eff counts */
        if (t_ms < SUMV_T_MIN_MS) { t_ms = SUMV_T_MIN_MS; }
    } else {
        t_ms = (uint32_t)((int64_t)1000 * dist / speed);
        if (t_ms < t_floor) { t_ms = t_floor; }
    }
    if (t_ms > SUMV_T_MAX_MS) { t_ms = SUMV_T_MAX_MS; }
    s_last_speed_eff = (uint32_t)((int64_t)1000 * dist / (int32_t)t_ms);

    const bool human = (req->mode & M_HUMAN) != 0;

    /* 先把正在跑的轨迹"冻结 + 备份"：新请求若建路径失败，直接回滚让它继续跑完，
     * 而不是像以前那样先 kill 再发现失败 → 光标停在半路。 */
    const bool was_active = s_v.active;
    if (was_active) {
        s_backup = s_v;                  /* ~1 KB，仅在 REPLACE 时发生 */
        s_v.active = false;
        if (s_timer != NULL) { (void)esp_timer_stop(s_timer); }
    }

    memset(&s_v, 0, sizeof(s_v));
    s_v.dx = dx;
    s_v.dy = dy;
    s_v.mode = req->mode;
    s_v.speed = (uint16_t)speed;
    s_v.mr_eff = (uint8_t)mr_eff;
    /* 瞄准模式下极短位移走"单发"：n=1，收尾分支一次性给出全部位移 */
    s_v.n = (!human && dist <= SUMV_SINGLE_MAX) ? 1u : t_ms;

    if (req->seed != 0) {
        /* 可复现：用固定步进的伪随机（简单 LCG）代替 esp_random */
        uint32_t st = (uint32_t)req->seed * 2654435761u;
        for (int k = 0; k < 6; k++) {
            st = st * 1664525u + 1013904223u;
            if (k == 0) { s_v.tremor_ph0 = (st >> 8) & 1023; }
            if (k == 1) { s_v.sub_n = st % 4; }
        }
    }

    build_path();
    if (s_v.total <= 1) {
        if (was_active) {
            s_v = s_backup;              /* 回滚：旧轨迹接着跑 */
            s_v.active = true;
            if (s_timer != NULL) {
                (void)esp_timer_start_periodic(s_timer, SUMV_TICK_US);
            }
        }
        return false;
    }

    /* 速度剖面：AIM 恒速（最短延迟）→ 拟人 min-jerk → 瞄准恒速/梯形 */
    if (req->mode & M_CRUISE) {
        s_v.prof_kind = 0;
        profile_linear();
    } else if (human) {
        s_v.prof_kind = 2;
        profile_minjerk();
    } else if (dist <= SUMV_STRAIGHT_MAX) {
        s_v.prof_kind = 0;
        profile_linear();
    } else {
        double r1 = 0.08, r2 = 0.12;
        if (dist <= 300) {
            r1 = 0.06; r2 = 0.10;
        } else if (dist > 800) {
            r1 = 0.10; r2 = 0.15;
        }
        s_v.prof_kind = 1;
        profile_trapezoid(r1, r2);
    }

    /* 粘滞收尾：拟人全强度；瞄准模式只在长距离减半；短距离完全不粘 */
    s_v.tail_amp = human ? SUMV_TAIL_A
                         : (dist >= SUMV_TAIL_MIN_D ? SUMV_TAIL_A_HALF : 0);

    /* 手颤：只在拟人模式，8–11 Hz，幅度 span/400（0.5–6 counts） */
    if (human && (req->mode & M_TREMOR)) {
        const int32_t amp = (int32_t)(((int64_t)dist << SUMV_Q) / 400);
        s_v.tremor_amp = amp > (6 << SUMV_Q) ? (6 << SUMV_Q) : (amp < (1 << SUMV_Q) / 2 ? (1 << SUMV_Q) / 2 : amp);
        const uint32_t hz = 8 + (s_v.tremor_ph0 & 3);
        s_v.tremor_step = (1024u * hz) / 1000u;      /* 1 kHz 下的相位步进 */
    }

    /* 子运动：只在拟人模式，1–3 个峰，分布在路径后半段 */
    if (human && (req->mode & M_SUBMOVE) && cheb > 600) {
        uint32_t cnt = 1 + (s_v.tremor_ph0 % 3);
        if (cnt > 3) { cnt = 3; }
        s_v.sub_n = cnt;
        for (uint32_t k = 0; k < cnt; k++) {
            s_v.sub_c[k] = (uint32_t)(((16384u + (esp_random() % 24576u)) << 1) & 0xFFFF);  /* 0.25–0.80 */
            s_v.sub_w[k] = 4096 + (esp_random() % 4096);
            s_v.sub_a[k] = (int32_t)(1024 + (esp_random() % 1024));                        /* 1.5–3% */
        }
    }

    /* 微停顿：2026-11-10 按用户要求移除（观感上有"卡一下"，像掉帧而不是人味）。
     * mode bit4 保留但已无效，老调用方继续传 0x1E 也不会再顿。 */
    s_v.pause_len = 0;
    s_v.pause_at = 0;
    s_v.total_samples = s_v.n;

    if (was_active) {
        s_aborted++;                     /* 新请求真的要跑了，旧轨迹才算"被打断" */
        s_last_result = SUMV_R_REPLACED;
    }
    s_gen++;                             /* 代数 +1：在飞的旧样本看到不一致就作废 */
    s_started_us = (uint32_t)esp_timer_get_time();
    s_last_counts = (uint16_t)cheb;
    s_v.active = true;
    if (s_timer != NULL) {
        (void)esp_timer_start_periodic(s_timer, SUMV_TICK_US);
    }
    /* 立刻让任务跑第一个样本（不等下一个 1 ms tick）→ 首样本延迟 ~0.2 ms */
    if (s_task != NULL) {
        xTaskNotifyGive(s_task);
    }
    return true;
}

void makcu_sumv_stop(void)
{
    if (s_v.active) {
        s_last_result = SUMV_R_REJECTED;   /* 被显式停止 */
        s_gen++;
    }
    if (s_v.active) {
        s_aborted++;
    }
    s_v.active = false;
    if (s_timer != NULL) {
        (void)esp_timer_stop(s_timer);
    }
}

void makcu_sumv_note_mute_dropped(void)
{
    s_mute_dropped++;
}

void makcu_sumv_note_button_forwarded(void)
{
    s_btn_forwarded++;
}

void makcu_sumv_set_defaults(uint16_t speed, uint8_t max_report)
{
    if (speed != 0) {
        s_default_speed = speed;
    }
    /* max_report == 0 → 回到"自动"（跟 speed 抬）；非 0 → 固定 */
    if (max_report != 0) {
        if (max_report < SUMV_MAX_REPORT_MIN) { max_report = SUMV_MAX_REPORT_MIN; }
        if (max_report > SUMV_MAX_REPORT_MAX) { max_report = SUMV_MAX_REPORT_MAX; }
    }
    s_max_report = max_report;
}

void makcu_sumv_get_defaults(uint16_t *speed, uint8_t *max_report)
{
    if (speed) { *speed = s_default_speed; }
    if (max_report) { *max_report = s_max_report; }   /* 0 = 自动 */
}

uint8_t makcu_sumv_mr_for_speed(uint16_t speed)
{
    return (uint8_t)mr_for_speed(speed);
}

/* ---------------------------------------------------------- AIM（瞄准专用）
 *
 * 客户端只想说"朝这个方向走这么多，越快越好"，不想算 counts/s：
 *   makcu_sumv_aim(dx, dy, max_ms, flags, dead_min)
 *   - 时长 = max_ms（4..255），内部折算 speed 并走**恒速剖面**（最短延迟）
 *   - dead_min：切比雪夫残差小于它 → 直接回"已到位"（默认 2 counts ≈ 2.5 px）
 *   - flags bit0 = 打开会话累计钳位（绝对值超过 SUMV_AIM_LIMIT 就拒绝）
 *            bit1 = 极速（等价 bit7）
 * 返回：result 码（与 AIM_STATE 第一字节一致），1 = 已启动/已到位
 */
static uint8_t s_aim_prev_result;

uint8_t makcu_sumv_aim(int16_t dx, int16_t dy, uint8_t max_ms, uint8_t flags, uint8_t dead_min)
{
    if (s_task == NULL) {
        s_last_result = SUMV_R_REJECTED;
        return SUMV_R_REJECTED;
    }
    const int32_t ax = dx < 0 ? -dx : dx;
    const int32_t ay = dy < 0 ? -dy : dy;
    const int32_t cheb = ax > ay ? ax : ay;
    const uint8_t dm = dead_min ? dead_min : SUMV_AIM_DEAD_DEF;

    if (cheb == 0) {
        s_last_result = SUMV_R_STARTED;      /* 已在目标：不再发 */
        return SUMV_R_STARTED;
    }
    if (cheb <= (int32_t)dm) {          /* 残差 <= 死区就当作到位（含等号） */
        s_dead_hits++;
        s_last_result = SUMV_R_DEADZONE;
        return SUMV_R_DEADZONE;
    }
    if ((flags & SUMV_AIM_FLAG_LIMIT) &&
        (abs((int)(s_aim_total_dx + dx)) > SUMV_AIM_LIMIT ||
         abs((int)(s_aim_total_dy + dy)) > SUMV_AIM_LIMIT)) {
        s_last_result = SUMV_R_LIMIT;
        return SUMV_R_LIMIT;
    }

    uint32_t ms = max_ms ? max_ms : 8u;
    if (ms < SUMV_T_MIN_MS) { ms = SUMV_T_MIN_MS; }
    int64_t d2 = (int64_t)dx * dx + (int64_t)dy * dy;
    uint32_t dist = isqrt32((uint32_t)(d2 > 0x7FFFFFFF ? 0x7FFFFFFF : d2));
    if (dist == 0) { dist = (uint32_t)cheb; }
    uint32_t speed = (uint32_t)((int64_t)1000 * dist / (int32_t)ms);
    if (speed < SUMV_SPEED_MIN) { speed = SUMV_SPEED_MIN; }
    if (speed > SUMV_SPEED_MAX) { speed = SUMV_SPEED_MAX; }

    makcu_sumv_req_t req;
    req.dx = dx;
    req.dy = dy;
    req.speed = (uint16_t)speed;
    req.dur_ms = (uint16_t)ms;
    req.mode = (uint8_t)(M_FIXED_DUR | M_CRUISE |
                         ((flags & SUMV_AIM_FLAG_FAST) ? M_MAX_SPEED : 0u));
    req.seed = 0;

    s_aim_prev_result = s_last_result;
    if (!makcu_sumv_start(&req)) {
        s_last_result = SUMV_R_REJECTED;
        return SUMV_R_REJECTED;
    }
    s_aim_total_dx += dx;
    s_aim_total_dy += dy;
    s_last_result = SUMV_R_STARTED;
    return SUMV_R_STARTED;
}

void makcu_sumv_aim_reset(void)
{
    s_aim_total_dx = 0;
    s_aim_total_dy = 0;
    s_dead_hits = 0;
}

/* 0x40 AIM_RESET：把 AIM_STATE 的累计量全部清零。
 * 之前 makcu_sumv_aim_reset() 没有调用点，会话钳位/死区/rounds 累加到 u16 饱和后再也回不去。 */
void makcu_sumv_aim_clear_stats(void)
{
    s_aim_total_dx = 0;
    s_aim_total_dy = 0;
    s_dead_hits = 0;
    s_rounds = 0;
    s_aborted = 0;
    s_last_result = 0;      /* 0 = 还没有结果，界面显示"—"而不是上次的历史 */
    s_last_counts = 0;
    s_last_dur_ms = 0;
}

/* AIM_STATE：12 B
 *   [0] active  [1] last_result  [2..3] last_counts  [4..5] last_dur_ms
 *   [6..7] aborted  [8..9] rounds  [10] dead_hits(饱和)  [11] gen 低 8 位
 */
uint8_t makcu_sumv_aim_state(uint8_t *out, uint8_t max)
{
    if (out == NULL || max < 12) {
        return 0;
    }
    out[0] = s_v.active ? 1u : 0u;
    out[1] = s_last_result;
    out[2] = (uint8_t)(s_last_counts & 0xFF);
    out[3] = (uint8_t)(s_last_counts >> 8);
    out[4] = (uint8_t)(s_last_dur_ms & 0xFF);
    out[5] = (uint8_t)(s_last_dur_ms >> 8);
    out[6] = (uint8_t)(s_aborted & 0xFF);
    out[7] = (uint8_t)((s_aborted >> 8) & 0xFF);
    out[8] = (uint8_t)(s_rounds & 0xFF);
    out[9] = (uint8_t)((s_rounds >> 8) & 0xFF);
    out[10] = (uint8_t)(s_dead_hits > 255 ? 255 : s_dead_hits);
    out[11] = (uint8_t)(s_gen & 0xFF);
    return 12;
}

void makcu_sumv_stats(makcu_sumv_stats_t *out)
{
    if (out == NULL) {
        return;
    }
    out->samples = s_samples;
    out->aborted = s_aborted;
    out->rounds = s_rounds;
    out->mute_dropped = s_mute_dropped;
    out->btn_forwarded = s_btn_forwarded;
    out->speed_eff = s_last_speed_eff;
    out->remain_ms = s_v.active ? (s_v.total_samples > s_v.i ? s_v.total_samples - s_v.i : 0) : 0;
    out->active = s_v.active;
}

void makcu_sumv_init(void)
{
    if (s_task == NULL) {
        xTaskCreate(sumv_task, "km_sumv", 4096, NULL, 13, &s_task);
    }
    if (s_timer == NULL) {
        const esp_timer_create_args_t args = {
            .callback = sumv_tick,
            .arg = NULL,
            .name = "sumv_tick",
        };
        if (esp_timer_create(&args, &s_timer) != ESP_OK) {
            ESP_LOGE(TAG, "esp_timer_create failed");
            s_timer = NULL;
        }
    }
    ESP_LOGI(TAG, "engine up (1000 Hz, default speed %d counts/s)", SUMV_SPEED_DEF);
}
