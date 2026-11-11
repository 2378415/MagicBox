undefined4 FUN_420076a4(uint param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(PTR_DAT_42000860 + (param_1 * 5 + param_3) * 4);
  if ((~uVar2 & DAT_42000864) == 0) {
    uVar1 = 0;
  }
  else if ((uVar2 & 0x7fff) == DAT_42000868) {
    uVar1 = 0;
  }
  else if ((int)(short)((int)(uVar2 << 0x11) >> 0x11) == param_2) {
    if (param_1 < 3) {
      FUN_420117fc(param_2 & 0xff,(int)(uVar2 << 0xd) >> 0x1c,0);
      if ((uVar2 & 0x80000) == 0) {
        uVar1 = 1;
      }
      else {
        FUN_420117c0(param_2,*(uint *)(PTR_DAT_42000860 + (param_1 * 5 + param_3) * 4) >> 0x14);
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}