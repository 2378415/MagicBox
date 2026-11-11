/* 按键事件（真实鼠标 → 控制口），订阅即消费。
 *
 * 语义（2026-11-10 定稿）：
 *   - 只监听**真实鼠标**的按键；盒子自己发出的按键（.km.left(1) / BUTTON 帧）不产生事件
 *   - 滚轮、移动：永不产生事件、永不改变转发行为
 *   - 订阅 mask 内的键 = "盒子吃掉这个键"：这些位会从转发给 PC 的 HID 报告里抹掉，
 *     PC 完全看不到这次点击，只有控制口能收到事件
 *   - 只吃"订阅之后新产生的按下"：订阅瞬间已经按住的键继续透传到松开（否则 PC 会卡按下）
 *   - 失联保护：订阅后 10 s 没收到任何心跳（EVT_READ/EVT_STAT/PING）自动恢复全透传
 */
#ifndef BTN_EVT_H
#define BTN_EVT_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/* 事件记录（8 B，与二进制 EVT_READ / EVT_PUSH 的布局一致） */
typedef struct {
    uint32_t t_us;
    uint16_t seq;
    uint8_t  mask;      /* 变化后的完整按键位图（真实鼠标的） */
    uint8_t  edge;      /* 本次变化的位 */
} btn_evt_t;

typedef struct {
    bool     enabled;
    bool     push;
    bool     auto_released;
    bool     consume;     /* true = 订阅的位被吃掉（PC 看不到） */
    uint8_t  mask;        /* 订阅并消费的位 */
    uint8_t  pending;     /* 订阅瞬间按住、仍按透传处理的位 */
    uint8_t  cur;         /* 最近一次真实按键位图 */
    uint8_t  last_fwd;    /* 最近一次实际转发给 PC 的按键字节（台架判定用） */
    uint16_t head_seq;    /* 下一条事件序号 */
    uint8_t  count;       /* 环形缓冲里未读条数 */
    uint32_t overflow;    /* 因缓冲满被覆盖的条数 */
} btn_evt_stat_t;

/* 推送回调：设备主动发 0xE1，由 control_bin 注册 */
typedef void (*btn_evt_push_fn)(uint16_t seq, uint32_t t_us, uint8_t mask, uint8_t edge);

void btn_evt_init(void);
void btn_evt_set_push_fn(btn_evt_push_fn fn);

/* enable=false 时 mask 忽略；push=1 时开主动推送 */
/* consume=false（默认）：只产生事件、按键照常透传给 PC；
 * consume=true：订阅的位从转发报告里抹掉，PC 看不到这次点击。 */
void btn_evt_ctl(bool enable, uint8_t mask, bool push, bool consume);
bool btn_evt_consume(void);
bool btn_evt_enabled(void);
uint8_t btn_evt_mask(void);

/* 收到真实鼠标报告时调用：传入原始按键位（已按布局归一到低位），
 * 返回**应该转发给 PC**的按键位（被订阅的位已被抹掉），并记录事件。 */
uint8_t btn_evt_filter(uint8_t raw_buttons);

/* 取最多 max 条事件，返回实际写入 out 的**条数**（每条 8 B） */
uint8_t btn_evt_read(uint8_t *out, uint8_t max);

void btn_evt_stat(btn_evt_stat_t *st);
void btn_evt_heartbeat(void);
/* 重置事件环与统计（0x41 EVT_RESET）。 */
void btn_evt_reset_stats(void);

#endif /* BTN_EVT_H */
