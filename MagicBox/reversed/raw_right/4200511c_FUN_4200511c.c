// 4200511c  FUN_4200511c  FUN_4200511c  size=389

int FUN_4200511c(byte *param_1)

{
  int iVar1;
  byte local_30 [48];
  
  if (param_1 == (byte *)0x0) {
    return 0x102;
  }
  local_30[0] = 0;
  if ((*(uint *)(PTR_DAT_420005a8 + 8) & 1) != 0) {
    iVar1 = FUN_42004a10(1,local_30,0xffffffff);
    if (iVar1 != 0) {
      return iVar1;
    }
    *param_1 = *param_1 | local_30[0];
    iVar1 = FUN_42004adc(1,local_30,0xffffffff);
    if (iVar1 != 0) {
      return iVar1;
    }
    *param_1 = *param_1 | local_30[0];
    iVar1 = FUN_42004f88(1,local_30,0);
    if (iVar1 != 0) {
      return iVar1;
    }
    *param_1 = *param_1 | local_30[0];
    if (1 < *(uint *)(PTR_DAT_420005a8 + 0xc)) {
      iVar1 = FUN_42004f88(1,local_30);
      if (iVar1 != 0) {
        return iVar1;
      }
      *param_1 = *param_1 | local_30[0];
    }
  }
  if ((*(uint *)(PTR_DAT_420005a8 + 8) & 2) != 0) {
    iVar1 = FUN_42004a10(2,local_30,0xffffffff);
    if (iVar1 != 0) {
      return iVar1;
    }
    *param_1 = *param_1 | local_30[0];
    iVar1 = FUN_42004adc(2,local_30,0xffffffff);
    if (iVar1 != 0) {
      return iVar1;
    }
    *param_1 = *param_1 | local_30[0];
    iVar1 = FUN_42004f88(2,local_30,0);
    if (iVar1 != 0) {
      return iVar1;
    }
    *param_1 = *param_1 | local_30[0];
    if (1 < *(uint *)(PTR_DAT_420005a8 + 0xc)) {
      iVar1 = FUN_42004f88(2,local_30,1);
      if (iVar1 != 0) {
        return iVar1;
      }
      *param_1 = *param_1 | local_30[0];
    }
  }
  if ((*(uint *)(PTR_DAT_420005a8 + 8) & 4) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_42004adc(4,local_30,0);
    if (iVar1 == 0) {
      *param_1 = *param_1 | local_30[0];
      iVar1 = FUN_42004f88(4,local_30,0);
      if (((iVar1 == 0) &&
          (*param_1 = *param_1 | local_30[0], 1 < *(uint *)(PTR_DAT_420005a8 + 0xc))) &&
         (iVar1 = FUN_42004adc(4,local_30,1), iVar1 == 0)) {
        *param_1 = *param_1 | local_30[0];
        iVar1 = FUN_42004f88(4,local_30,1);
        if (iVar1 == 0) {
          *param_1 = *param_1 | local_30[0];
        }
      }
    }
  }
  return iVar1;
}


