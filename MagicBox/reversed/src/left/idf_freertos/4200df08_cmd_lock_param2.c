void cmd_lock_param2(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,char *param_5
                 ,int param_6)

{
  if (param_6 != 0) {
    FUN_42010c08(param_3,*(undefined4 *)(param_4 + 0xc),*param_5 == '1');
    uart0_reply(param_1,param_2,0);
  }
  return;
}