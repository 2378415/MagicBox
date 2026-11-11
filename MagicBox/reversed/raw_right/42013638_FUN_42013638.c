// 42013638  FUN_42013638  FUN_42013638  size=110

void FUN_42013638(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((param_2 & 1) == 0) {
    memw();
    memw();
    *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & DAT_4200103c;
  }
  else {
    memw();
    memw();
    *(uint *)(iVar1 + 0x60) = *(uint *)(iVar1 + 0x60) & DAT_42001034 | (param_3 & 0xff) << 7;
    memw();
    memw();
    *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) | DAT_42001038;
  }
  if ((param_2 & 2) == 0) {
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_42000164;
  }
  else {
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | DAT_42000160;
  }
  return;
}


