// 420157b4  FUN_420157b4  FUN_420157b4  size=60

int FUN_420157b4(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x1c))
                    (*(int **)(param_1 + 0x50),*(undefined4 *)(param_1 + 8),*DAT_420010dc);
  if (iVar1 == 0) {
    *(undefined2 *)(param_1 + 0x40) = 0;
    *(undefined2 *)(param_1 + 0x42) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    FUN_42015550(param_1 + 0x44);
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return iVar1;
}


