// 4200c0cc  FUN_4200c0cc  FUN_4200c0cc  size=98

undefined4 FUN_4200c0cc(int param_1)

{
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
    memw();
  } while (-1 < *(int *)(*(int *)(param_1 + 8) + 0x10));
  memw();
  local_30 = 0;
  memw();
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x10) = 0x10;
  do {
    memw();
    local_30 = local_30 + 1;
    memw();
    if (DAT_42000af4 < local_30) {
      return 0xffffffff;
    }
    memw();
  } while ((*(uint *)(*(int *)(param_1 + 8) + 0x10) & 0x10) != 0);
  return 0;
}


