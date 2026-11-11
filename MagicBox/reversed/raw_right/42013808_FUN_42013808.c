// 42013808  FUN_42013808  FUN_42013808  size=58

void FUN_42013808(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  
  *param_1 = DAT_42001048;
  uVar2 = DAT_42000850;
  iVar1 = DAT_4200015c;
  memw();
  memw();
  *(uint *)(DAT_4200015c + 0x18) = *(uint *)(DAT_4200015c + 0x18) | DAT_42000850;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | uVar2;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_42000854;
  return;
}


