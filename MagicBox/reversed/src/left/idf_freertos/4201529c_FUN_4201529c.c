void FUN_4201529c(uint param_1,uint param_2,undefined4 param_3)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(DAT_4200135c + (param_2 & 0x7f) * 0xc + (param_1 & 0xff) * DAT_42001360 +
                     DAT_420013c8);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_1 & 0xff,param_2 & 0xff,param_3);
  }
  return;
}