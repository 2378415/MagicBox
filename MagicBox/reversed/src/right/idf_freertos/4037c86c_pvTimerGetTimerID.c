// strings: xTimer

undefined4 FUN_4037c86c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_timers_c_3c035ea0_0x2a_40374ddc,0x44f,PTR_s_pvTimerGetTimerID_40374e14,
                 PTR_s_xTimer_40374e0c);
  }
  FUN_4037bbe8(PTR_DAT_40374dcc,0xffffffff);
  uVar1 = *(undefined4 *)(param_1 + 0x1c);
  FUN_4037bd38(PTR_DAT_40374dcc);
  return uVar1;
}