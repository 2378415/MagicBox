// 4201ceb0  FUN_4201ceb0  FUN_4201ceb0  size=116

int FUN_4201ceb0(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((param_3 & 0x1f) == 0) {
    uVar2 = *(uint *)(param_1 + 0x38);
    if (uVar2 == 0xffffffff) {
      iVar1 = -1;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x3c);
      if (iVar1 != -1) {
        if (uVar2 < 0x7e) {
          iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x18))
                            (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + 0x40 + uVar2 * 0x20,
                             param_2,param_3);
          if (iVar1 == 0) {
            uVar2 = param_3 >> 5 & 0xffff;
            iVar1 = FUN_4202d844(param_1,*(int *)(param_1 + 0x38),*(int *)(param_1 + 0x38) + uVar2,2
                                );
            if (iVar1 == 0) {
              *(short *)(param_1 + 0x40) = (short)(param_3 >> 5) + *(short *)(param_1 + 0x40);
              *(uint *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + uVar2;
              return 0;
            }
            return iVar1;
          }
        }
        else {
          iVar1 = -1;
        }
        *(undefined4 *)(param_1 + 0xc) = 0;
      }
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


