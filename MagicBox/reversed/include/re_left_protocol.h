/* prototypes for left/protocol - generated from decompiled bodies, not original headers */
#ifndef RE_LEFT_PROTOCOL_H
#define RE_LEFT_PROTOCOL_H

#include "re_types.h"

extern undefined4 DAT_42000064;
extern undefined4 DAT_42000114;
extern undefined4 DAT_42000a38;
extern undefined4 DAT_42000c68;
extern undefined4 DAT_42000d90;
extern undefined4 DAT_42000db0;
extern undefined4 DAT_42000dc0;
extern undefined4 DAT_42000e8c;
extern undefined4 PTR_FUN_42000dcc;
extern undefined4 PTR_PTR_42000dbc;
extern undefined4 PTR_PTR_42000dc8;
extern undefined4 PTR_s_MAKCU_42000ebc;
extern undefined4 PTR_s_buttons___42000d8c;
extern undefined4 PTR_s_catch_ml_42000dd0;
extern undefined4 PTR_s_catch_mm_42000dd8;
extern undefined4 PTR_s_catch_mr_42000dd4;
extern undefined4 PTR_s_catch_ms1_42000ddc;
extern undefined4 PTR_s_catch_ms2_42000de0;
extern undefined4 PTR_s_catch_unknown_42000de4;
extern undefined4 PTR_s_left___42000db8;

void cmd_nop(void);
void cmd_reply_status(undefined *param_1,int param_2,char param_3);
void cmd_version(void);
void cmd_serial(void);
void cmd_buttons(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4, char *param_5,int param_6);
void cmd_lock_query(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4);
void cmd_lock_axis(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4);
void cmd_set_string(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, char *param_5,uint param_6);
void cmd_catch_query(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4);
void cmd_move(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, char *param_5,uint param_6);
void cmd_silent(undefined4 param_1,undefined4 param_2,int param_3);
void cmd_wheel(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, int param_5,uint param_6);
uint parse_int_or_char(char *param_1,uint param_2);
void cmd_channel_toggle(void);
void cmd_map_entry(void);
uint parse_list6(int param_1,uint param_2,int param_3);
void cmd_keys_down(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,int param_6);
void cmd_keys_up(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,int param_6);
void parse_range(int param_1,uint param_2,int *param_3,int *param_4);
void cmd_keys_combo(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,int param_6);
void cmd_key_tap(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,int param_6);
void cmd_map_16(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, int param_5,uint param_6);
void cmd_key_up(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, char *param_5,uint param_6);
void cmd_key_down(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, char *param_5,uint param_6);
void cmd_key_state(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4, char *param_5,uint param_6);
undefined * cmd_lookup(int param_1,uint param_2,uint *param_3);
void cmd_dispatch(int param_1,int param_2);
void catch_unknown(void);
void version_get(undefined4 param_1,undefined4 *param_2);
void buttons_set(int param_1,undefined1 param_2);
undefined1 buttons_get(int param_1);
byte hid_key_state_read(int param_1,uint param_2);
uint lock_status_get(int param_1,uint param_2,int param_3);
bool lock_axis_get(int param_1,int param_2);
int char_to_usage(byte param_1);
void map_entry_write16(int param_1,uint param_2,char param_3);

#endif /* RE_LEFT_PROTOCOL_H */
