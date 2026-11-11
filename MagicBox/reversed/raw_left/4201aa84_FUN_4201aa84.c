// 4201aa84  FUN_4201aa84  FUN_4201aa84  size=58

void FUN_4201aa84(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_42000284;
  *param_1 = DAT_420019a0;
  uVar2 = DAT_42000a9c;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | DAT_42000a9c;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | uVar2;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_42000aa0;
  return;
}


