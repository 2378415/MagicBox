/* prototypes for left/keyboard - generated from decompiled bodies, not original headers */
#ifndef RE_LEFT_KEYBOARD_H
#define RE_LEFT_KEYBOARD_H

#include "re_types.h"

extern undefined4 DAT_403746f8;
extern undefined4 DAT_403746fc;
extern undefined4 DAT_403749a8;
extern undefined4 DAT_403749ac;
extern undefined4 DAT_420002d0;
extern undefined4 DAT_42000ecc;
extern undefined4 DAT_42000ed0;
extern undefined4 PTR_FUN_42000098;
extern undefined4 PTR_FUN_42000484;
extern undefined4 PTR_FUN_42000e24;

int clk_ticks_to_us(void);
uint esp_random(void);
void hid_key_down(int param_1,undefined2 param_2);
void hid_key_up(int param_1,ushort param_2);
void hid_key_tap(undefined4 param_1,undefined2 param_2,uint param_3,uint param_4);
void hid_type_string(undefined4 param_1,undefined1 *param_2,int param_3);
void hid_keys_down(undefined4 param_1,undefined2 *param_2,int param_3);
void hid_keys_up(undefined4 param_1,undefined2 *param_2,int param_3);
void hid_keys_combo(undefined4 param_1,undefined2 *param_2,int param_3,uint param_4,uint param_5);
uint hid_report_get_bits(int param_1,int param_2,int param_3,int param_4);
void hid_report_set_bits(int param_1,uint param_2,uint param_3,uint param_4,uint param_5);

#endif /* RE_LEFT_KEYBOARD_H */
