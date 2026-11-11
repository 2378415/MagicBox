void FUN_4202647c(int *param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 < 0x20) {
    memw();
    *(int *)(*param_1 + 0x4c) = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  }
  else {
    memw();
    memw();
    *(uint *)(*param_1 + 0x58) =
         *(uint *)(*param_1 + 0x58) & 0xffc00000 | 1 << 0x20 - (0x20 - (param_2 & 0x1f)) & 0x3fffffU
    ;
  }
  iVar1 = (param_2 + 0x1c) * 4 + DAT_420014a8;
  memw();
  memw();
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & DAT_420014ac | DAT_42000804;
  return;
}