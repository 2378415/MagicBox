int FUN_4201cdc0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_50 [2];
  byte bStack_4e;
  uint uStack_30;
  
  uVar3 = *(uint *)(param_1 + 0x3c);
  if (uVar3 == 0xffffffff) {
    iVar1 = DAT_420011bc;
  }
  else {
    if (*(int *)(param_2 + 0xc) == -1) {
      iVar1 = FUN_4201ccf8(param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar3 = *(uint *)(param_1 + 0x3c);
    }
    if (uVar3 < 0x7e) {
      do {
        if ((*(uint *)((uVar3 >> 4) * 4 + param_1 + 0x18) >> (uVar3 & 0xf) * 2 & 3) == 2) {
          iVar2 = (uVar3 & 0xffff) * 0x20;
          iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x10))
                            (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + 0x40 + iVar2,
                             auStack_50,0x20);
          if (iVar1 != 0) {
            return iVar1;
          }
          iVar1 = FUN_4201cb6c(param_2 + 0x44,auStack_50,*(undefined4 *)(param_2 + 0x38));
          if (iVar1 != 0) {
            return iVar1;
          }
          iVar1 = FUN_4201cd64(param_2,auStack_50);
          if (iVar1 != 0) {
            return iVar1;
          }
          uStack_30 = bStack_4e + uVar3;
          if (0x7e < uStack_30) {
            return -1;
          }
          if (uVar3 + 1 < uStack_30) {
            uVar3 = uStack_30 & 0xffff;
            iVar2 = iVar2 + 0x20;
            do {
              iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x10))
                                (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + 0x40 + iVar2,
                                 auStack_50,0x20);
              if (iVar1 != 0) {
                return iVar1;
              }
              iVar1 = FUN_4201cd64(param_2,auStack_50);
              iVar2 = iVar2 + 0x20;
              if (iVar1 != 0) {
                return iVar1;
              }
            } while (uVar3 << 5 != iVar2);
          }
          uVar3 = uStack_30;
        }
        else {
          if (*(uint *)(param_1 + 0x3c) == uVar3) {
            return -1;
          }
          uVar3 = uVar3 + 1;
        }
      } while (uVar3 != 0x7e);
    }
    iVar1 = 0;
  }
  return iVar1;
}