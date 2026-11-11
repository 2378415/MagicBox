// 4202185c  FUN_4202185c  FUN_4202185c  size=107

int FUN_4202185c(uint *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  if ((uVar2 & 7) == 0) {
    iVar1 = 0;
    if ((uVar2 & 0xffff) == 0) {
      uVar2 = uVar2 >> 0x10;
      iVar1 = 0x10;
    }
    if ((uVar2 & 0xff) == 0) {
      iVar1 = iVar1 + 8;
      uVar2 = uVar2 >> 8;
    }
    if ((uVar2 & 0xf) == 0) {
      iVar1 = iVar1 + 4;
      uVar2 = uVar2 >> 4;
    }
    if ((uVar2 & 3) == 0) {
      iVar1 = iVar1 + 2;
      uVar2 = uVar2 >> 2;
    }
    if ((uVar2 & 1) == 0) {
      uVar2 = uVar2 >> 1;
      iVar1 = iVar1 + 1;
      if (uVar2 == 0) {
        return 0x20;
      }
    }
    *param_1 = uVar2;
  }
  else {
    iVar1 = 0;
    if ((uVar2 & 1) == 0) {
      if ((uVar2 & 2) == 0) {
        *param_1 = uVar2 >> 2;
        iVar1 = 2;
      }
      else {
        *param_1 = uVar2 >> 1;
        iVar1 = 1;
      }
    }
  }
  return iVar1;
}


