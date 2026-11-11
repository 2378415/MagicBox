// strings: &((&HE!_

undefined4 FUN_42006580(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(PTR_DAT_4200075c + 0xc) == 0) {
    return DAT_4200072c;
  }
  if (param_2 != *(int *)(PTR_DAT_4200075c + 0x10)) {
    if (*(int *)(PTR_DAT_4200075c + 0xc) == 1) {
      return DAT_4200072c;
    }
    if (param_2 != *(int *)(PTR_DAT_4200075c + 0x14)) {
      return DAT_4200072c;
    }
  }
  if (param_1 == 2) {
    if (param_2 == 0) {
      memw();
      *DAT_42000794 = 1;
    }
    else {
      if (param_2 != 1) goto LAB_420065f5;
      memw();
      *DAT_42000798 = 1;
    }
  }
  else if (param_1 == 4) {
    if (param_2 == 0) {
      memw();
      *DAT_4200079c = 1;
    }
    else {
      if (param_2 != 1) goto LAB_420065f5;
      memw();
      *DAT_420007a0 = 1;
    }
  }
  else {
    if (param_1 != 1) {
      return DAT_42000728;
    }
    if (param_2 == 0) {
      memw();
      *DAT_4200078c = 1;
    }
    else {
      if (param_2 != 1) {
LAB_420065f5:
        uVar1 = 7;
        goto LAB_42006617;
      }
      memw();
      *DAT_42000790 = 1;
    }
  }
  uVar1 = 0;
LAB_42006617:
  uVar1 = FUN_4200775c(uVar1);
  return uVar1;
}