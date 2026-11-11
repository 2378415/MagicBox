// 403834d8  FUN_403834d8  FUN_403834d8  size=40

undefined4 FUN_403834d8(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 >> 0x10 == 0xcd) {
    if ((param_2 >> 8 & 0xff) << 8 == DAT_4037523c) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x105;
    }
  }
  else {
    uVar1 = 0x105;
  }
  return uVar1;
}


