/* prototypes for left/hid - generated from decompiled bodies, not original headers */
#ifndef RE_LEFT_HID_H
#define RE_LEFT_HID_H

#include "re_types.h"

extern undefined4 DAT_42000094;
extern undefined4 DAT_42000664;
extern undefined4 DAT_42000988;
extern undefined4 DAT_42001204;
extern undefined4 DAT_42001230;
extern undefined4 DAT_42001240;
extern undefined4 DAT_4200124c;
extern undefined4 DAT_42001258;
extern undefined4 DAT_4200125c;
extern undefined4 DAT_42001260;
extern undefined4 DAT_42001328;
extern undefined4 DAT_42001330;
extern undefined4 DAT_4200133c;
extern undefined4 DAT_42001340;
extern undefined4 DAT_42001344;
extern undefined4 DAT_4200135c;
extern undefined4 DAT_42001360;
extern undefined4 DAT_42001364;
extern undefined4 DAT_420013c4;
extern undefined4 DAT_420013c8;
extern undefined4 DAT_420013cc;
extern undefined4 DAT_420013d4;
extern undefined4 PTR_DAT_42001250;
extern undefined4 PTR_DAT_42001254;
extern undefined4 PTR_DAT_42001264;
extern undefined4 PTR_DAT_42001280;
extern undefined4 PTR_DAT_42001354;
extern undefined4 PTR_FUN_4200005c;
extern undefined4 PTR_FUN_42000118;
extern undefined4 PTR_FUN_420004b0;
extern undefined4 PTR_FUN_42000e7c;
extern undefined4 PTR_FUN_4200126c;
extern undefined4 PTR_FUN_4200127c;
extern undefined4 PTR_FUN_42001284;
extern undefined4 PTR_FUN_4200134c;
extern undefined4 PTR_FUN_420013d0;
extern undefined4 PTR_FUN_420013d8;
extern undefined4 PTR_FUN_420014e0;
extern undefined4 PTR_LAB_42001274;
extern undefined4 PTR_s_CommitFrame_42001350;
extern undefined4 PTR_s_hid_data_42001348;
extern undefined4 PTR_s_hid_data_processing_42001270;
extern undefined4 PTR_s_hid_parse_task_42001278;
extern undefined4 PTR_s_uart_event_task_42001268;
extern undefined4 PTR_s_uart_events_4200120c;

void uart_event_task(void);
void hid_data(void);
void usb_hid_itf_reset(uint param_1,undefined4 param_2);
undefined4 sem_create_counting(undefined4 param_1);

#endif /* RE_LEFT_HID_H */
