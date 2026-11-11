void FUN_42010b14(int param_1,int param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  
  param_1 = (param_2 + 0x154) * 4 + param_1;
  memw();
  memw();
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffbff;
  memw();
  memw();
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & DAT_42000df0 | (param_4 & 1) << 0xb;
  if ((param_2 - 0x13U & 0xff) < 2) {
    memw();
    memw();
    *DAT_42000df4 = *DAT_42000df4 & DAT_4200016c;
  }
  puVar1 = (uint *)((param_2 + DAT_42000de8) * 4);
  memw();
  memw();
  *puVar1 = *puVar1 & DAT_4200052c | (param_3 & 7) << 0xc;
  return;
}