// 42015920  FUN_42015920  FUN_42015920  size=176

int FUN_42015920(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_40 [2];
  byte bStack_3e;
  
  if (*(int *)(param_1 + 0x3c) == -1) {
    iVar1 = DAT_42000cd4;
  }
  else if ((*(int *)(param_2 + 0xc) != -1) || (iVar1 = FUN_420156fc(param_2), iVar1 == 0)) {
    uVar3 = *(uint *)(param_1 + 0x3c);
    while (uVar3 < 0x7e) {
      if ((*(uint *)((uVar3 >> 4) * 4 + param_1 + 0x18) >> (uVar3 & 0xf) * 2 & 3) == 2) {
        iVar1 = FUN_42024fd8(param_1,uVar3,auStack_40);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = FUN_420155ec(param_2 + 0x44,auStack_40,*(undefined4 *)(param_2 + 0x38));
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = FUN_420158c0(param_2,auStack_40);
        if (iVar1 != 0) {
          return iVar1;
        }
        uVar2 = uVar3 + bStack_3e;
        if (0x7e < uVar2) {
          return -1;
        }
        while (uVar3 = uVar3 + 1, uVar3 < uVar2) {
          iVar1 = FUN_42024fd8(param_1,uVar3,auStack_40);
          if (iVar1 != 0) {
            return iVar1;
          }
          iVar1 = FUN_420158c0(param_2,auStack_40);
          if (iVar1 != 0) {
            return iVar1;
          }
        }
        uVar3 = uVar2;
      }
      else {
        if (*(uint *)(param_1 + 0x3c) == uVar3) {
          return -1;
        }
        uVar3 = uVar3 + 1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}


