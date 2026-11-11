// 42018570  FUN_42018570  FUN_42018570  size=128

void FUN_42018570(uint param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  
  param_1 = param_1 & 0xff;
  iVar2 = **(int **)PTR_PTR_420015e0 + param_1 * 4 + 0x550;
  memw();
  memw();
  *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) & 0xfffffbff;
  memw();
  memw();
  *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) & DAT_4200164c | (param_3 & 1) << 0xb;
  if ((param_1 - 0x13 & 0xff) < 2) {
    memw();
    memw();
    *DAT_420015cc = *DAT_420015cc & DAT_42000294;
  }
  puVar1 = (uint *)(param_1 * 4 + DAT_420015c0);
  memw();
  memw();
  *puVar1 = (param_2 & 7) << 0xc | *puVar1 & DAT_42000784;
  return;
}


