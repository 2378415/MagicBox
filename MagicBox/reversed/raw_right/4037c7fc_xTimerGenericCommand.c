// 4037c7fc  xTimerGenericCommand  FUN_4037c7fc  size=108
// strings: xTimer

undefined4
FUN_4037c7fc(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int local_30;
  undefined4 uStack_2c;
  int iStack_28;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_timers_c_3c035ea0_0x2a_40374ddc,0x1cc,PTR_s_xTimerGenericCommand_40374e10,
                 PTR_s_xTimer_40374e0c);
  }
  if (*DAT_40374dd0 == 0) {
    uVar2 = 0;
  }
  else {
    local_30 = param_2;
    uStack_2c = param_3;
    iStack_28 = param_1;
    if (param_2 < 6) {
      iVar1 = FUN_4037db0c();
      if (iVar1 == 2) {
        uVar2 = FUN_4037b39c(*DAT_40374dd0,&local_30,param_5,0);
      }
      else {
        uVar2 = FUN_4037b39c(*DAT_40374dd0,&local_30,0);
      }
    }
    else {
      uVar2 = FUN_4037b588(*DAT_40374dd0,&local_30,param_4,0);
    }
  }
  return uVar2;
}


