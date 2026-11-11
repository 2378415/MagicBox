// 420264e0  FUN_420264e0  FUN_420264e0  size=90

void FUN_420264e0(int *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = (param_2 + 0x1c) * 4 + *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & DAT_420014ac;
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
  return;
}


