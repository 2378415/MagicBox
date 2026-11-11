// 42012404  FUN_42012404  FUN_42012404  size=124

undefined4 FUN_42012404(char *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  if (param_1 == (char *)0x0) {
    return 0;
  }
  if (*param_1 == '\0') {
    if (param_1[1] != '\0') {
      iVar3 = *(int *)(param_1 + 0x214);
      if (iVar3 == 0) {
        return 0;
      }
      *(char *)(iVar3 + 0x61) =
           (char)(*(int *)((uint)*(byte *)(iVar3 + 0x62) * 4 + DAT_42000f50) + 7U >> 3) +
           (*(byte *)(iVar3 + 0x62) != 0);
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x210);
    if (iVar3 == 0) {
      return 0;
    }
    if ((param_1[1] != '\0') && (*(int *)(param_1 + 0x214) == 0)) {
      return 0;
    }
    bVar1 = *(byte *)(iVar3 + 0x1d5);
    bVar2 = 1;
    if (bVar1 == 0) {
      bVar2 = bVar1;
    }
    *(byte *)(iVar3 + 0x1d6) = (char)(*(int *)((uint)bVar1 * 4 + DAT_42000f50) + 7U >> 3) + bVar2;
  }
  param_1[0x635] = '\x01';
  return 1;
}


