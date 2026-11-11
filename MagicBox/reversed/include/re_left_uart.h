/* prototypes for left/uart - generated from decompiled bodies, not original headers */
#ifndef RE_LEFT_UART_H
#define RE_LEFT_UART_H

#include "re_types.h"

extern undefined4 DAT_42000064;
extern undefined4 DAT_42000664;
extern undefined4 DAT_420006dc;
extern undefined4 DAT_42000988;
extern undefined4 DAT_42000dac;
extern undefined4 DAT_42000ec4;
extern undefined4 DAT_42001294;
extern undefined4 DAT_420012a8;
extern undefined4 DAT_420012ac;
extern undefined4 DAT_420012b0;
extern undefined4 DAT_420012c8;
extern undefined4 DAT_420012cc;
extern undefined4 DAT_420012d8;
extern undefined4 DAT_420012dc;
extern undefined4 DAT_420012f4;
extern undefined4 DAT_42001310;
extern undefined4 DAT_42001314;
extern undefined4 PTR_DAT_42000d88;
extern undefined4 PTR_DAT_42000ec0;
extern undefined4 PTR_DAT_420011f8;
extern undefined4 PTR_DAT_420012b8;
extern undefined4 PTR_DAT_420012d4;
extern undefined4 PTR_DAT_42001320;
extern undefined4 PTR_FUN_4200005c;
extern undefined4 PTR_FUN_42000118;
extern undefined4 PTR_FUN_42000488;
extern undefined4 PTR_FUN_420004b0;
extern undefined4 PTR_FUN_42000a1c;
extern undefined4 PTR_FUN_42000dcc;
extern undefined4 PTR_FUN_42000e7c;
extern undefined4 PTR_FUN_4200130c;
extern undefined4 PTR_LAB_420012fc;
extern undefined4 PTR_LAB_42001304;
extern undefined4 PTR_LAB_4200131c;
extern undefined4 PTR_s_0_3c034fa0_0x14_42000d84;
extern undefined4 PTR_s_Reset_Baud_Rate_Task_42001318;
extern undefined4 PTR_s_SERIAL_SETUP_420012d0;
extern undefined4 PTR_s_UART0FrameConsumer_42001308;
extern undefined4 PTR_s_UART0_Send_Task_42001300;
extern undefined4 PTR_s___main_components_UART_uart0_c_420012e8;
extern undefined4 PTR_s_setupUart0_420012e4;
extern undefined4 PTR_s_uart0_in_420012f8;
extern undefined4 PTR_s_uart_driver_install_UART_NUM_0__R_420012f0;
extern undefined4 PTR_s_uart_param_config_UART_NUM_0___u_420012e0;
extern undefined4 PTR_s_uart_set_pin_UART_NUM_0__UART_0__420012ec;

void frame_router(byte *param_1,int param_2);
void uart_rx_frame(undefined4 param_1,int param_2);
void cmd_dump_channels(undefined4 param_1,undefined4 param_2,int param_3);
void cmd_lock_param0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,char *param_5 ,int param_6);
void cmd_button_press(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,char *param_5 ,int param_6);
void cmd_catch_set(undefined4 param_1,undefined4 param_2,int param_3,int param_4,char *param_5, int param_6);
void cmd_button_click(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4);
void lock_axis_set(int param_1,undefined4 param_2,undefined1 param_3);
void lock_set(int param_1,undefined4 param_2,undefined1 param_3);
bool serial_read(int param_1,undefined *param_2,int param_3,uint param_4,int *param_5, undefined1 *param_6);
undefined4 uart0_read_string(int param_1,uint param_2,uint *param_3);
void SERIAL_SETUP(void);
void uart0_in(void);
void uart0_reply(undefined4 param_1,uint param_2,char param_3);
void catch_set(int param_1,int param_2,uint param_3);
byte button_flags_get(int param_1,int param_2);

#endif /* RE_LEFT_UART_H */
