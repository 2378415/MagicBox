// 403837d0  FUN_403837d0  FUN_403837d0  size=46

undefined4 FUN_403837d0(uint param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 >> 0x10 == 0xc2) {
    if ((param_1 >> 0xc & 0xf) << 0xc == DAT_40374454) {
      *param_2 = 0xc2;
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


