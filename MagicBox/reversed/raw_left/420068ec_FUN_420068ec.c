// 420068ec  FUN_420068ec  FUN_420068ec  size=216
// strings: &((&H;!

int FUN_420068ec(int param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (*(int *)(PTR_DAT_4200075c + 0xc) == 0) {
    return DAT_4200072c;
  }
  if (param_2 != *(uint *)(PTR_DAT_4200075c + 0x10)) {
    if (*(int *)(PTR_DAT_4200075c + 0xc) == 1) {
      return DAT_4200072c;
    }
    if (param_2 != *(uint *)(PTR_DAT_4200075c + 0x14)) {
      return DAT_4200072c;
    }
  }
  if (param_1 == 2) {
    if (param_2 == 0) {
      puVar2 = DAT_420007ac;
LAB_4200695f:
      memw();
      uVar3 = *puVar2;
      uVar4 = 1;
LAB_4200696b:
      memw();
      *puVar2 = uVar3 | uVar4;
      iVar1 = FUN_4200775c(param_2);
      goto joined_r0x42006978;
    }
    if (param_2 == 1) {
      puVar2 = DAT_420007b0;
      goto LAB_42006983;
    }
  }
  else {
    if (param_1 != 4) {
      if (param_1 != 1) {
        return DAT_42000728;
      }
      if (param_2 == 0) {
        memw();
        uVar4 = *DAT_420007a4;
        uVar3 = 1;
        puVar2 = DAT_420007a4;
        goto LAB_4200696b;
      }
      if (param_2 != 1) goto LAB_4200699f;
      puVar2 = DAT_420007a8;
LAB_42006983:
      memw();
      memw();
      *puVar2 = *puVar2 | param_2;
      iVar1 = FUN_4200775c(0);
joined_r0x42006978:
      if (iVar1 != 0) {
        return iVar1;
      }
      memw();
      memw();
      *puVar2 = *puVar2 & 0xfffffffe;
      uVar5 = 0;
      goto LAB_420069bf;
    }
    if (param_2 == 0) {
      puVar2 = DAT_420007b4;
      goto LAB_4200695f;
    }
    if (param_2 == 1) {
      puVar2 = DAT_420007b8;
      goto LAB_42006983;
    }
  }
LAB_4200699f:
  iVar1 = FUN_4200775c(7);
  uVar5 = 7;
  if (iVar1 != 0) {
    return iVar1;
  }
LAB_420069bf:
  iVar1 = FUN_4200775c(uVar5);
  return iVar1;
}


