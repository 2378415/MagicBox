// 4200c2f8  FUN_4200c2f8  FUN_4200c2f8  size=184

void FUN_4200c2f8(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  uint uStack_2c;
  
  param_2 = param_2 * 0x20;
  iVar1 = *(int *)(param_1 + 8) + param_2;
  memw();
  memw();
  memw();
  uStack_2c = 0;
  memw();
  if (((*(uint *)(*(int *)(param_1 + 8) + 8) & 0x20) == 0) || (memw(), *(int *)(iVar1 + 0x500) < 0))
  {
    memw();
    *(undefined4 *)(iVar1 + 0x50c) = 0;
    puVar2 = (uint *)(param_2 + *(int *)(param_1 + 8) + 0x500);
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *puVar2 = (*puVar2 | DAT_420000a0) & 0x7fffffff & DAT_42000164;
    do {
      memw();
      uStack_2c = uStack_2c + 1;
      memw();
      if (DAT_42000af4 < uStack_2c) break;
      memw();
    } while (*(int *)(param_2 + *(int *)(param_1 + 8) + 0x500) < 0);
    param_2 = param_2 + *(int *)(param_1 + 8);
    memw();
    memw();
    *(undefined4 *)(param_2 + 0x508) = *(undefined4 *)(param_2 + 0x508);
  }
  return;
}


