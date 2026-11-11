void cmd_lock_axis(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_3 != 0) {
    uVar2 = *param_4;
    uVar3 = param_4[1];
    uVar1 = lock_axis_get(param_3,param_4[3]);
    cmd_reply_status(uVar2,uVar3,uVar1);
  }
  return;
}