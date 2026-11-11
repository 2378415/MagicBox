uint lock_status_get(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (((param_1 == 0) || (iVar3 = *(int *)(param_1 + 0x210), iVar3 == 0)) || (4 < param_3 - 1U)) {
    uVar2 = 0;
    uVar4 = 0;
    uVar1 = 0;
  }
  else if ((param_2 & 0xfffffffb) == 1) {
    uVar2 = (uint)(*(int *)(param_3 * 4 + iVar3 + 0x54) != 0);
    if (param_2 == 5) {
      iVar3 = (param_3 - 1U) * 4 + iVar3;
      uVar4 = (uint)(*(int *)(iVar3 + 0x16c) != 0);
      uVar1 = (uint)(*(int *)(iVar3 + 0xa0) != 0);
    }
    else {
      uVar1 = 0;
      uVar4 = 0;
    }
  }
  else if (param_2 == 0xb) {
    uVar2 = 0;
    uVar4 = (uint)(*(int *)(param_3 * 4 + iVar3 + 0x168) != 0);
    uVar1 = 0;
  }
  else {
    uVar2 = 0;
    uVar1 = 0;
    uVar4 = 0;
  }
  return uVar2 | uVar4 << 8 | uVar1 << 0x10;
}