// 4201cd64  FUN_4201cd64  FUN_4201cd64  size=92

int FUN_4201cd64(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(uint *)(param_1 + 0x38) < 0x7e) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x18))
                      (*(int **)(param_1 + 0x50),
                       *(int *)(param_1 + 8) + 0x40 + *(uint *)(param_1 + 0x38) * 0x20,param_2,0x20)
    ;
    if (iVar1 == 0) {
      iVar1 = FUN_4202d7ec(param_1,*(undefined4 *)(param_1 + 0x38),2);
      if (iVar1 == 0) {
        if (*(int *)(param_1 + 0x3c) == -1) {
          *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x38);
        }
        *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + 1;
        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


