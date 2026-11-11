// 4201dc84  FUN_4201dc84  FUN_4201dc84  size=55

int FUN_4201dc84(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x1c))
                    (*(int **)(param_1 + 0x50),*(undefined4 *)(param_1 + 8),*DAT_42001aa4);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    FUN_4201cb28(param_1 + 0x44);
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return iVar1;
}


