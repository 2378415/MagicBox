int FUN_420069d0(byte *param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = PTR_DAT_4200075c;
  if (param_1 == (byte *)0x0) {
    return 0x102;
  }
  uVar4 = *(uint *)(PTR_DAT_4200075c + 8);
  if ((uVar4 & 1) != 0) {
    memw();
    memw();
    iVar2 = *(int *)(PTR_DAT_4200075c + 0xc);
    *param_1 = (*DAT_420007bc == 1 || *DAT_42000760 == 1) | *param_1;
    if (iVar2 == 0) {
      return DAT_4200072c;
    }
    if (*(int *)(puVar1 + 0x10) != 0) {
      if (iVar2 == 1) {
        return DAT_4200072c;
      }
      if (*(int *)(puVar1 + 0x14) != 0) {
        return DAT_4200072c;
      }
    }
    memw();
    iVar3 = *DAT_4200078c;
    iVar2 = FUN_4200775c(0);
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar4 = *(uint *)(puVar1 + 0xc);
    *param_1 = iVar3 == 1 | *param_1;
    if (uVar4 < 2) {
      uVar4 = *(uint *)(puVar1 + 8);
    }
    else {
      if ((*(int *)(puVar1 + 0x10) != 1) && (*(int *)(puVar1 + 0x14) != 1)) {
        return DAT_4200072c;
      }
      memw();
      iVar3 = *DAT_42000790;
      iVar2 = FUN_4200775c(0);
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar4 = *(uint *)(puVar1 + 8);
      *param_1 = iVar3 == 1 | *param_1;
    }
  }
  if ((uVar4 & 2) != 0) {
    memw();
    memw();
    iVar2 = *(int *)(puVar1 + 0xc);
    *param_1 = (*DAT_420007bc == 1 || *DAT_42000764 == 1) | *param_1;
    if (iVar2 == 0) {
      return DAT_4200072c;
    }
    if (*(int *)(puVar1 + 0x10) != 0) {
      if (iVar2 == 1) {
        return DAT_4200072c;
      }
      if (*(int *)(puVar1 + 0x14) != 0) {
        return DAT_4200072c;
      }
    }
    memw();
    iVar3 = *DAT_42000794;
    iVar2 = FUN_4200775c(0);
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar4 = *(uint *)(puVar1 + 0xc);
    *param_1 = iVar3 == 1 | *param_1;
    if (uVar4 < 2) {
      uVar4 = *(uint *)(puVar1 + 8);
    }
    else {
      if ((*(int *)(puVar1 + 0x10) != 1) && (*(int *)(puVar1 + 0x14) != 1)) {
        return DAT_4200072c;
      }
      memw();
      iVar3 = *DAT_42000798;
      iVar2 = FUN_4200775c(0);
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar4 = *(uint *)(puVar1 + 8);
      *param_1 = iVar3 == 1 | *param_1;
    }
  }
  if ((uVar4 & 4) == 0) {
    return 0;
  }
  if ((*(int *)(puVar1 + 0xc) != 0) &&
     ((*(int *)(puVar1 + 0x10) == 0 ||
      ((*(int *)(puVar1 + 0xc) != 1 && (*(int *)(puVar1 + 0x14) == 0)))))) {
    memw();
    iVar3 = *DAT_42000768;
    iVar2 = FUN_4200775c(0);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = *(int *)(puVar1 + 0xc);
    *param_1 = iVar3 == 1 | *param_1;
    if ((iVar2 != 0) &&
       ((*(int *)(puVar1 + 0x10) == 0 || ((iVar2 != 1 && (*(int *)(puVar1 + 0x14) == 0)))))) {
      memw();
      iVar3 = *DAT_4200079c;
      iVar2 = FUN_4200775c(0);
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar4 = *(uint *)(puVar1 + 0xc);
      *param_1 = iVar3 == 1 | *param_1;
      if (uVar4 < 2) {
        return 0;
      }
      if ((*(int *)(puVar1 + 0x10) == 1) || (*(int *)(puVar1 + 0x14) == 1)) {
        memw();
        iVar3 = *DAT_4200076c;
        iVar2 = FUN_4200775c(0);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = *(int *)(puVar1 + 0xc);
        *param_1 = iVar3 == 1 | *param_1;
        if ((iVar2 != 0) &&
           ((*(int *)(puVar1 + 0x10) == 1 || ((iVar2 != 1 && (*(int *)(puVar1 + 0x14) == 1)))))) {
          memw();
          iVar3 = *DAT_420007a0;
          iVar2 = FUN_4200775c(0);
          if (iVar2 == 0) {
            *param_1 = iVar3 == 1 | *param_1;
            return 0;
          }
          return iVar2;
        }
      }
    }
  }
  return DAT_4200072c;
}