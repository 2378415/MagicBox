/* 按键轨迹环形日志（诊断用）
 *
 * 目的：精确回答"按下以后 PC 明明触发了，为什么又收回去了"。
 * 记录每一次**按键字节变化**（以及被抗抖吞掉的那次），每条带微秒时间戳与来源，
 * 通过控制口 0x44 BTN_LOG 读回，不再靠猜。
 *
 * 来源（src）：
 *   0 = 真实鼠标透传（正常转发）
 *   1 = 真实鼠标，被 20 ms 释放保护窗口吞掉（抖动闭合）
 *   2 = 瞄准期屏蔽层（sumv/aim 运行时按键走这里）
 *   3 = 引擎注入 / BUTTON 命令（.km.left / 0x32）
 */
#ifndef BTN_TRACE_H
#define BTN_TRACE_H

#include <stdbool.h>
#include <stdint.h>

#define BTN_TRACE_SRC_PASS 0u
#define BTN_TRACE_SRC_SWALLOW 1u
#define BTN_TRACE_SRC_MUTE 2u
#define BTN_TRACE_SRC_INJECT 3u

typedef struct {
    uint32_t t_us;   /* 事件时刻（µs，开机以来） */
    uint8_t  raw;    /* 真实/请求的按键字节（低 5 位） */
    uint8_t  fwd;    /* 真正转发出去的按键字节（低 5 位） */
    uint8_t  src;    /* 见上面的 BTN_TRACE_SRC_* */
    uint8_t  pad;
} btn_trace_entry_t;

/** 记录一次按键变化（只有字节变化或被吞时才调用）。 */
void btn_trace_add(uint8_t raw, uint8_t fwd, uint8_t src);

/** 读出自 since 序号之后最多 max 条；返回写入条数，total 返回累计总数。 */
uint16_t btn_trace_read(uint16_t since, btn_trace_entry_t *out, uint16_t max, uint16_t *total);

#endif /* BTN_TRACE_H */
