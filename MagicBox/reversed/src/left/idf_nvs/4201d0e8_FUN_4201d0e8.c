int FUN_4201d0e8(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_40 [2];
  byte bStack_3e;
  
  if (0x7d < param_2) {
    return -1;
  }
  if ((*(uint *)((param_2 >> 4) * 4 + param_1 + 0x18) >> (param_2 & 0xf) * 2 & 3) == 2) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x10))
                      (*(int **)(param_1 + 0x50),param_2 * 0x20 + 0x40 + *(int *)(param_1 + 8),
                       auStack_40,0x20);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = FUN_4201e2d4(auStack_40,param_2);
    if (iVar1 != 0) {
      FUN_4201cbe8(param_1 + 0x44,param_2);
      uVar2 = param_2 + bStack_3e;
      uVar6 = uVar2 - 1;
      if ((int)param_2 <= (int)uVar6) {
        if (0x7d < (int)uVar6) {
          return -1;
        }
        sVar4 = *(short *)(param_1 + 0x42);
        do {
          uVar3 = uVar6 >> 4;
          uVar5 = uVar6 & 0xf;
          sVar4 = sVar4 + 1;
          uVar6 = uVar6 - 1;
          if ((*(uint *)(uVar3 * 4 + param_1 + 0x18) >> uVar5 * 2 & 3) == 2) {
            *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + -1;
          }
          *(short *)(param_1 + 0x42) = sVar4;
        } while ((int)param_2 <= (int)uVar6);
      }
      if (bStack_3e == 1) {
        iVar1 = FUN_4202d7ec(param_1,param_2,0);
      }
      else {
        iVar1 = FUN_4202d844(param_1,param_2,uVar2,0);
      }
      if (iVar1 != 0) {
        return iVar1;
      }
      goto LAB_4201d1f4;
    }
    FUN_4201cbe8(param_1 + 0x44,param_2);
    iVar1 = FUN_4202d7ec(param_1,param_2,0);
    *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + -1;
    *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
  }
  else {
    iVar1 = FUN_4202d7ec(param_1,param_2,0);
  }
  if (iVar1 != 0) {
    return iVar1;
  }
  uVar2 = param_2 + 1;
LAB_4201d1f4:
  uVar6 = *(uint *)(param_1 + 0x38);
  if (((*(uint *)(param_1 + 0x3c) == param_2) &&
      (*(undefined4 *)(param_1 + 0x3c) = 0xffffffff,
      uVar2 < (uVar6 < 0x7e) * uVar6 + (uint)(uVar6 >= 0x7e) * 0x7e)) &&
     ((*(uint *)((uVar2 >> 4) * 4 + param_1 + 0x18) >> (uVar2 & 0xf) * 2 & 3) == 2)) {
    *(uint *)(param_1 + 0x3c) = uVar2;
  }
  if (uVar6 < uVar2) {
    *(uint *)(param_1 + 0x38) = uVar2;
  }
  return 0;
}