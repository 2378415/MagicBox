// 4037cb54  xTimerGenericCommand  FUN_4037cb54  size=103
// strings: xTimer

undefined4
FUN_4037cb54(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_t0;
  int local_30;
  undefined4 uStack_2c;
  int iStack_28;
  
  if (param_1 == 0) {
    param_1 = in_t0;
    FUN_40381ce4(PTR_s_timers_c_3c03b500_0x2a_40374ea0,0x1cc,PTR_s_xTimerGenericCommand_40374ec8,
                 PTR_s_xTimer_40374ec4);
  }
  piVar1 = DAT_40374e78;
  uVar2 = 0;
  if (*DAT_40374e78 != 0) {
    local_30 = param_2;
    uStack_2c = param_3;
    iStack_28 = param_1;
    if (param_2 < 6) {
      iVar3 = FUN_4037e0e0();
      if (iVar3 == 2) {
        uVar2 = FUN_4037b768(*piVar1,&local_30,param_5,0);
      }
      else {
        uVar2 = FUN_4037b768(*piVar1,&local_30,0,0);
      }
    }
    else {
      uVar2 = FUN_4037b988(*DAT_40374e78,&local_30,param_4,0);
    }
  }
  return uVar2;
}


