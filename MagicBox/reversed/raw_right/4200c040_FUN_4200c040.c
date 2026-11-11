// 4200c040  FUN_4200c040  FUN_4200c040  size=106

undefined4 FUN_4200c040(int param_1)

{
  int iVar1;
  uint local_30;
  
  memw();
  local_30 = 0;
  do {
    memw();
    local_30 = local_30 + 1;
    memw();
    if (DAT_42000af4 < local_30) {
      return 0xffffffff;
    }
    iVar1 = *(int *)(param_1 + 8);
    memw();
  } while (-1 < *(int *)(iVar1 + 0x10));
  memw();
  local_30 = 0;
  memw();
  memw();
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 1;
  do {
    memw();
    local_30 = local_30 + 1;
    memw();
    if (DAT_42000af4 < local_30) {
      return 0xffffffff;
    }
    memw();
  } while ((*(uint *)(*(int *)(param_1 + 8) + 0x10) & 1) != 0);
  return 0;
}


