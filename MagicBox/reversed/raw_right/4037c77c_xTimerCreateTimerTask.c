// 4037c77c  xTimerCreateTimerTask  FUN_4037c77c  size=86
// strings: timers.c | xTimerCreateTimerTask | xReturn

undefined4 FUN_4037c77c(void)

{
  int iVar1;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 auStack_28 [10];
  
  FUN_4037c6fc();
  if (*DAT_40374dd0 != 0) {
    auStack_28[0] = 0;
    uStack_2c = 0;
    FUN_4037c1bc(auStack_28,&uStack_2c,&local_30);
    iVar1 = FUN_4037e718(PTR_FUN_40374dfc,PTR_s_Tmr_Svc_40374df8,local_30,0,1,uStack_2c,
                         auStack_28[0],DAT_403747f4);
    *DAT_40374e00 = iVar1;
    if (iVar1 != 0) {
      return 1;
    }
  }
  FUN_40381d9c(PTR_s_timers_c_3c035ea0_0x2a_40374ddc,0x15a,PTR_s_xTimerCreateTimerTask_40374e08,
               PTR_s_xReturn_40374e04);
  return 1;
}


