/* cmd_sumv / cmd_sumv_stop - opcode 0x1B / 0x1C（重建扩展，非原厂命令）。
 *
 * 语法：
 *   .km.sumv(dx,dy)                  speed 默认 400，拟人层全开
 *   .km.sumv(dx,dy,speed)
 *   .km.sumv(dx,dy,speed,mode)
 *   .km.sumv(dx,dy,speed,mode,dur)   dur 仅在 mode bit0 置位时生效
 *   .km.sumv()                       -> sumv()\n<0|1|2>（2 = 引擎未装）
 *   .km.sumv_stop()                  -> 立即停在当前位置
 *
 * 速度语义：speed 单位 counts/s，T = clamp(1000*D/speed, 40, 5000) ms，越大越快。
 */
#include "makcu_cmd.h"
#include "makcu_parse.h"
#include "makcu_reply.h"
#include "makcu_sumv_hooks.h"

void cmd_sumv(const char *buf, int len, void *dev,
              const makcu_cmd_t *entry, const char *arg, int arglen)
{
    (void)dev;
    (void)entry;

    int16_t v[5] = {0};
    const int n = makcu_parse_int16_list(arg, arglen, v, 5);

    if (n == 0) {                                  /* 查询 */
        uint8_t st = 2;
        if (makcu_sumv_active_hook != NULL) {
            st = makcu_sumv_active_hook() ? 1 : 0;
        }
        makcu_reply_status("sumv()", 6, st);
        return;
    }
    if (n < 2) {                                   /* 参数不全：按查询回状态 2 */
        makcu_reply_status("sumv()", 6, 2);
        return;
    }
    if (makcu_sumv_start_hook == NULL) {
        makcu_reply_status("sumv()", 6, 2);
        return;
    }

    const uint16_t speed = (n >= 3 && v[2] > 0) ? (uint16_t)v[2] : 0;
    const uint8_t  mode = (n >= 4) ? (uint8_t)(v[3] & 0xFF) : 0x00;   /* 默认瞄准模式；0x40 = 拟人模式 */
    const uint16_t dur = (n >= 5 && v[4] > 0) ? (uint16_t)v[4] : 0;

    const bool ok = makcu_sumv_start_hook(v[0], v[1], speed, dur, mode, 0);
    makcu_reply_echo(buf, len);
    (void)ok;                                       /* 拒绝时状态由查询命令体现 */
}

void cmd_sumv_stop(const char *buf, int len, void *dev,
                   const makcu_cmd_t *entry, const char *arg, int arglen)
{
    (void)dev;
    (void)entry;
    (void)arg;
    (void)arglen;
    if (makcu_sumv_stop_hook != NULL) {
        makcu_sumv_stop_hook();
    }
    makcu_reply_echo(buf, len);
}
