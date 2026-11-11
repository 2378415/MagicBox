undefined4 FUN_40382378(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_2 >> 0x10 == 200) {
    uVar2 = param_2 >> 8 & 0xff;
    if (uVar2 == 0x40 || uVar2 == 0x60) {
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