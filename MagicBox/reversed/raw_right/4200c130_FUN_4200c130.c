// 4200c130  FUN_4200c130  FUN_4200c130  size=102

undefined4 FUN_4200c130(int param_1,int param_2)

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
  *(uint *)(*(int *)(param_1 + 8) + 0x10) = param_2 << 6 | 0x20;
  do {
    memw();
    local_30 = local_30 + 1;
    memw();
    if (DAT_42000af4 < local_30) {
      return 0xffffffff;
    }
    memw();
  } while ((*(uint *)(*(int *)(param_1 + 8) + 0x10) & 0x20) != 0);
  return 0;
}


