// strings: ( xTimerPeriodInTicks > 0 )

void FUN_4037c744(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 *param_6)

{
  if (param_2 == 0) {
    FUN_40381d9c(PTR_s_timers_c_3c035ea0_0x2a_40374ddc,0x1ac,PTR_s_prvInitialiseNewTimer_40374df4,
                 PTR_s___xTimerPeriodInTicks_>_0___40374df0);
  }
  FUN_4037c6fc();
  *param_6 = param_1;
  param_6[6] = param_2;
  param_6[7] = param_4;
  param_6[8] = param_5;
  FUN_4037c8dc(param_6 + 1);
  if (param_3 != 0) {
    *(byte *)(param_6 + 9) = *(byte *)(param_6 + 9) | 4;
  }
  return;
}