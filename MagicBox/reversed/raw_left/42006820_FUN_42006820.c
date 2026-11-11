// 42006820  FUN_42006820  FUN_42006820  size=189
// strings: &(2&HW!

undefined4 FUN_42006820(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (param_2 == (byte *)0x0) {
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
      bVar1 = (byte)(*DAT_420007ac >> 1) & 1;
    }
    else {
      if (param_3 != 1) goto LAB_420068ab;
      memw();
      bVar1 = (byte)(*DAT_420007b0 >> 1) & 1;
    }
  }
  else if (param_1 == 4) {
    if (param_3 == 0) {
      memw();
      bVar1 = (byte)(*DAT_420007b4 >> 1) & 1;
    }
    else {
      if (param_3 != 1) goto LAB_420068ab;
      memw();
      bVar1 = (byte)(*DAT_420007b8 >> 1) & 1;
    }
  }
  else {
    if (param_1 != 1) {
      return DAT_42000728;
    }
    if (param_3 == 0) {
      memw();
      bVar1 = (byte)(*DAT_420007a4 >> 1) & 1;
    }
    else {
      if (param_3 != 1) {
LAB_420068ab:
        uVar2 = 7;
        goto LAB_420068d2;
      }
      memw();
      bVar1 = (byte)(*DAT_420007a8 >> 1) & 1;
    }
  }
  *param_2 = bVar1;
  uVar2 = 0;
LAB_420068d2:
  uVar2 = FUN_4200775c(uVar2);
  return uVar2;
}


