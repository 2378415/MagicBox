void cmd_catch_set(undefined4 param_1,undefined4 param_2,int param_3,int param_4,char *param_5,
                 int param_6)

{
  if (param_6 != 0) {
    if ((*(int *)(*(int *)(param_4 + 0xc) * 4 + *(int *)(param_3 + 0x210) + 0x54) == 0) ||
       (1 < (byte)(*param_5 - 0x30U))) {
      uart0_reply(param_1,param_2,0);
    }
    else {
      catch_set(param_3,*(int *)(param_4 + 0xc),*param_5 == '1');
      *DAT_42000dac = 1;
      uart0_reply(param_1,param_2,0);
    }
  }
  return;
}