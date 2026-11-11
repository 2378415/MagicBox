// 42015dec  FUN_42015dec  FUN_42015dec  size=158

undefined4 FUN_42015dec(uint param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  
  param_1 = param_1 & 0xff;
  uVar1 = param_2 & 0x7f;
  iVar3 = *(int *)(param_1 * 8 + DAT_420013e0 + 4);
  if ((param_2 & 0x80) == 0) {
    puVar2 = (uint *)(iVar3 + 0xb00 + uVar1 * 0x20);
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_42001438;
    if ((byte)(*(char *)(DAT_420013f8 + (param_1 * 0x10 + uVar1 + 7) * 0x10 + 10) - 2U) < 2) {
      memw();
      memw();
      *puVar2 = *puVar2 | DAT_4200143c;
    }
  }
  else {
    puVar2 = (uint *)(iVar3 + 0x900 + uVar1 * 0x20);
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_42001438;
    if ((byte)(*(char *)(DAT_420013f8 + (param_1 * 0x10 + uVar1) * 0x10 + 10) - 2U) < 2) {
      memw();
      memw();
      *puVar2 = *puVar2 | DAT_4200143c;
    }
  }
  return 0;
}


