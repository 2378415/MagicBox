// strings: ( xTimerPeriodInTicks > 0 )

void FUN_4037cb0c(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_4037c428(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined1 *)(puVar1 + 9) = 0;
    if (param_2 == 0) {
      FUN_40381ce4(PTR_s_timers_c_3c03b500_0x2a_40374ea0,0x1ac,PTR_s_prvInitialiseNewTimer_40374ec0,
                   PTR_s___xTimerPeriodInTicks_>_0___40374ebc);
    }
    FUN_4037c768();
    *puVar1 = param_1;
    puVar1[6] = param_2;
    puVar1[7] = param_4;
    puVar1[8] = param_5;
    FUN_4037cbe0(puVar1 + 1);
    if (param_3 != 0) {
      *(byte *)(puVar1 + 9) = *(byte *)(puVar1 + 9) | 4;
    }
  }
  return;
}