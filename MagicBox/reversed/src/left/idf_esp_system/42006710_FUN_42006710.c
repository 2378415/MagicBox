// strings: &(6fH

undefined4 FUN_42006710(int param_1,char param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*(int *)(PTR_DAT_4200075c + 0xc) == 0) {
    return DAT_4200072c;
  }
  if (param_3 != *(int *)(PTR_DAT_4200075c + 0x10)) {
    if (*(int *)(PTR_DAT_4200075c + 0xc) == 1) {
      return DAT_4200072c;
    }
    if (param_3 != *(int *)(PTR_DAT_4200075c + 0x14)) {
      return DAT_4200072c;
    }
  }
  if (param_1 == 2) {
    if (param_3 == 0) {
      if (param_2 == '\0') {
        memw();
        memw();
        *DAT_420007ac = *DAT_420007ac & 0xfffffffd;
      }
      else {
        memw();
        memw();
        *DAT_420007ac = *DAT_420007ac | 2;
      }
    }
    else {
      if (param_3 != 1) goto LAB_420067d6;
      if (param_2 == '\0') {
        memw();
        memw();
        *DAT_420007b0 = *DAT_420007b0 & 0xfffffffd;
      }
      else {
        memw();
        memw();
        *DAT_420007b0 = *DAT_420007b0 | 2;
      }
    }
  }
  else {
    if (param_1 == 4) {
      if (param_3 == 0) {
        memw();
        uVar2 = *DAT_420007b4;
        puVar1 = DAT_420007b4;
      }
      else {
        if (param_3 != 1) {
LAB_420067d6:
          uVar3 = 7;
          goto LAB_42006810;
        }
        memw();
        uVar2 = *DAT_420007b8;
        puVar1 = DAT_420007b8;
      }
    }
    else {
      if (param_1 != 1) {
        return DAT_42000728;
      }
      if (param_3 == 0) {
        memw();
        uVar2 = *DAT_420007a4;
        puVar1 = DAT_420007a4;
      }
      else {
        if (param_3 != 1) goto LAB_420067d6;
        memw();
        uVar2 = *DAT_420007a8;
        puVar1 = DAT_420007a8;
      }
    }
    if (param_2 == '\0') {
      memw();
      *puVar1 = uVar2 & 0xfffffffd;
    }
    else {
      memw();
      *puVar1 = uVar2 | 2;
    }
  }
  uVar3 = 0;
LAB_42006810:
  uVar3 = FUN_4200775c(uVar3);
  return uVar3;
}