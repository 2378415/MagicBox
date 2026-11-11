// strings: &(<&Hi!4

undefined4 FUN_42006628(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    return 0x102;
  }
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
      memw();
      bVar1 = *DAT_42000794 == 1;
    }
    else {
      if (param_3 != 1) goto LAB_420066c5;
      memw();
      bVar1 = *DAT_42000798 == 1;
    }
  }
  else if (param_1 == 4) {
    if (param_3 == 0) {
      memw();
      bVar1 = *DAT_4200079c == 1;
    }
    else {
      if (param_3 != 1) goto LAB_420066c5;
      memw();
      bVar1 = *DAT_420007a0 == 1;
    }
  }
  else {
    if (param_1 != 1) {
      return DAT_42000728;
    }
    if (param_3 == 0) {
      memw();
      bVar1 = *DAT_4200078c == 1;
    }
    else {
      if (param_3 != 1) {
LAB_420066c5:
        uVar2 = 7;
        goto LAB_420066f9;
      }
      memw();
      bVar1 = *DAT_42000790 == 1;
    }
  }
  *(bool *)param_2 = bVar1;
  uVar2 = 0;
LAB_420066f9:
  uVar2 = FUN_4200775c(uVar2);
  return uVar2;
}