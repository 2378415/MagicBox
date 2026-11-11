uint FUN_42016bd4(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = FUN_42016b6c(param_1);
  if (iVar1 != iVar2) {
    return 0;
  }
  uVar3 = (uint)*(byte *)(param_1 + 1);
  if (0x42 < uVar3) {
    if (uVar3 != 0x48) {
      return 0;
    }
    if (*(char *)(param_1 + 2) != '\x01') {
      return 0;
    }
    if (*(char *)(param_1 + 3) != -1) {
      return 0;
    }
    if (DAT_42001100 < *(uint *)(param_1 + 0x18)) {
      return 0;
    }
    return 1;
  }
  if (uVar3 < 0x41) {
    if (uVar3 < 3) {
      if (*(byte *)(param_1 + 1) == 0) {
        return 0;
      }
    }
    else {
      if (0x21 < uVar3) {
        return 0;
      }
      if (uVar3 < 4) {
        return 0;
      }
      uVar4 = 1 << 0x20 - (0x20 - (uVar3 - 4 & 0x1f));
      if ((uVar4 & DAT_420010fc) == 0) {
        if ((uVar4 & 0x20000000) == 0) {
          return uVar4 >> 0x1d & 1;
        }
        goto LAB_42016c62;
      }
    }
    if (*(char *)(param_1 + 2) == '\x01') {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
LAB_42016c62:
    if ((uVar3 == 0x42) && (*(char *)(param_1 + 3) == -1)) {
      uVar3 = 0;
    }
    else if ((((param_2 & 0xff) - 0x7d) * -0x20 & 0xffff) < (uint)*(ushort *)(param_1 + 0x18)) {
      uVar3 = 0;
    }
    else if ((-((param_2 & 0xff) - 0x7e) & 0xff) < (uint)*(byte *)(param_1 + 2)) {
      uVar3 = 0;
    }
    else if ((uint)*(byte *)(param_1 + 2) ==
             ((*(ushort *)(param_1 + 0x18) + 0x1f >> 5 & 0xff) + 1 & 0xff)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}