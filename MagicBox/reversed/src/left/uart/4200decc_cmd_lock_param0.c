void cmd_lock_param0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,char *param_5
                 ,int param_6)

{
  char cVar1;
  
  if (param_6 != 0) {
    cVar1 = *param_5;
    lock_set(param_3,*(undefined4 *)(param_4 + 0xc),cVar1 == '1');
    if (cVar1 != '1') {
      catch_set(param_3,*(undefined4 *)(param_4 + 0xc),0);
      *DAT_42000dac = 0;
    }
    uart0_reply(param_1,param_2,0);
  }
  return;
}