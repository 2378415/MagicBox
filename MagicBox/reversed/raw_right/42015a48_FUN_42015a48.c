// 42015a48  FUN_42015a48  FUN_42015a48  size=125

int FUN_42015a48(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((param_3 & 0x1f) == 0) {
    uVar2 = *(uint *)(param_1 + 0x38);
    if (uVar2 == 0xffffffff) {
      iVar1 = -1;
    }
    else if (*(int *)(param_1 + 0x3c) == -1) {
      iVar1 = -1;
    }
    else {
      if (uVar2 < 0x7e) {
        iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x18))
                          (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + uVar2 * 0x20 + 0x40,
                           param_2,param_3);
      }
      else {
        iVar1 = -1;
      }
      if (iVar1 == 0) {
        uVar2 = param_3 >> 5 & 0xffff;
        iVar1 = FUN_420159d4(param_1,*(int *)(param_1 + 0x38),*(int *)(param_1 + 0x38) + uVar2,2);
        if (iVar1 == 0) {
          *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + (short)(param_3 >> 5);
          *(uint *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + uVar2;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0xc) = 0;
      }
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


