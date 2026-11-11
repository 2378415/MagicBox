// 4202eadc  FUN_4202eadc  FUN_4202eadc  size=92

void FUN_4202eadc(int *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_2 < 0x20) {
    memw();
    *(int *)(iVar1 + 0x4c) = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  }
  else {
    memw();
    memw();
    *(int *)(iVar1 + 0x58) =
         (int)(CONCAT44(*(uint *)(iVar1 + 0x58) >> 0x16,
                        (1 << 0x20 - (0x20 - (param_2 & 0x1f))) << 10) >> 10);
  }
  iVar1 = (param_2 + 0x1c) * 4 + DAT_42001f58;
  memw();
  memw();
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & DAT_42001f5c | DAT_420009f8;
  return;
}


