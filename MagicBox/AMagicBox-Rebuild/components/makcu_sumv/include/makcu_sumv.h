/* sumv - 拟人化相对移动引擎（1000 Hz 采样）。
 *
 * 详细语义见 src/makcu_sumv.c 文件头。对外只暴露三件事：启动、停止、状态。
 */
#ifndef MAKCU_SUMV_H
#define MAKCU_SUMV_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int16_t  dx;
    int16_t  dy;
    uint16_t speed;      /* counts/s，0 = 默认 400；越大越快 */
    uint16_t dur_ms;     /* 仅当 mode bit0 置位时生效（固定时长） */
    uint8_t  mode;       /* bit0 固定时长 · bit1 手颤 · bit2 子运动 · bit3 过冲 · bit4 微停顿 */
    uint8_t  seed;       /* 0 = 随机；非 0 = 可复现 */
} makcu_sumv_req_t;

typedef struct {
    uint32_t samples;        /* 累计发出的样本数 */
    uint32_t aborted;        /* 被 REPLACE / stop 打断的次数 */
    uint32_t rounds;         /* 正常走完的次数 */
    uint32_t mute_dropped;   /* 屏蔽期间丢弃的真实鼠标位移报告数 */
    uint32_t btn_forwarded;  /* 屏蔽期间透传的按键/滚轮报告数 */
    uint32_t speed_eff;      /* 上一条轨迹被 clamp 后的实际速度 counts/s */
    uint32_t remain_ms;      /* 当前轨迹剩余样本（ms） */
    bool     active;
} makcu_sumv_stats_t;

#define MAKCU_SUMV_MODE_DEFAULT  0x00   /* 瞄准模式（FPS 拉枪线）：梯形剖面 + 浅弧、无手颤/子运动；0x40 = 拟人模式 */

void makcu_sumv_init(void);
bool makcu_sumv_start(const makcu_sumv_req_t *req);
void makcu_sumv_stop(void);
bool makcu_sumv_active(void);
void makcu_sumv_stats(makcu_sumv_stats_t *out);

/* ---------------------------------------------------------- AIM（瞄准专用）
 * 客户端只想说"朝这个方向走这么多，越快越好"：
 *   makcu_sumv_aim(dx, dy, max_ms, flags, dead_min)
 *   - max_ms：这一发必须在多少毫秒内走完（4..255，0 = 8）
 *   - dead_min：切比雪夫残差 < 它就算到位（0 = 默认 2 counts ≈ 2.5 px）
 *   - flags bit0 = 打开会话累计钳位，bit1 = 极速
 * 返回结果码：1 已启动/已到位 · 2 被替换 · 3 拒绝 · 4 死区 · 5 故障 · 6 超限
 */
uint8_t makcu_sumv_aim(int16_t dx, int16_t dy, uint8_t max_ms, uint8_t flags, uint8_t dead_min);
void    makcu_sumv_aim_reset(void);
/* 0x40 AIM_RESET：清空 AIM_STATE 的累计量（rounds/aborted/死区/上次结果）。 */
void    makcu_sumv_aim_clear_stats(void);
/* 12 B：active,last_result,last_counts(u16),last_dur_ms(u16),aborted(u16),rounds(u16),dead_hits,gen */
uint8_t makcu_sumv_aim_state(uint8_t *out, uint8_t max);

/* 运行时默认值：speed=0 时用它；max_report 决定"每报告最多多少 counts"，
 * 也就是真正的速度上限（1 kHz × max_report）。瞄准默认 60，极限 127。 */
void makcu_sumv_set_defaults(uint16_t speed, uint8_t max_report);
/* 给定速度的有效"每报告上限"（max_report=0 自动时按 11000 拐点线性上抬） */
uint8_t makcu_sumv_mr_for_speed(uint16_t speed);
void makcu_sumv_get_defaults(uint16_t *speed, uint8_t *max_report);

/* 由 app 层的屏蔽逻辑调用，纯计数。 */
void makcu_sumv_note_mute_dropped(void);
void makcu_sumv_note_button_forwarded(void);

#endif /* MAKCU_SUMV_H */
