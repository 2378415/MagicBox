// strings: timers.c | xTimerCreateTimerTask | xReturn

undefined4 FUN_4037cab4(void)

{
  int iVar1;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 auStack_28 [10];
  
  FUN_4037c768();
  if (*DAT_40374e78 != 0) {
    auStack_28[0] = 0;
    uStack_2c = 0;
    FUN_4037c554(auStack_28,&uStack_2c,&local_30);
    iVar1 = FUN_4037eb00(PTR_FUN_40374ea8,PTR_s_Tmr_Svc_40374ea4,local_30,0,1,uStack_2c,
                         auStack_28[0],DAT_40374eac);
    *DAT_40374eb0 = iVar1;
    if (iVar1 != 0) {
      return 1;
    }
  }
  FUN_40381ce4(PTR_s_timers_c_3c03b500_0x2a_40374ea0,0x15a,PTR_s_xTimerCreateTimerTask_40374eb8,
               PTR_s_xReturn_40374eb4);
  return 1;
}