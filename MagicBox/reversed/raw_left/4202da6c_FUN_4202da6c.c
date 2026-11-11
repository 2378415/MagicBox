// 4202da6c  FUN_4202da6c  FUN_4202da6c  size=387
// strings: '9CfB | !'Lf

int FUN_4202da6c(uint param_1)

{
  int iVar1;
  
  if (param_1 == 0x13) {
    iVar1 = 0x400;
  }
  else if (param_1 < 0x14) {
    if (param_1 == 9) {
      iVar1 = 0x100;
    }
    else if (param_1 < 10) {
      if (param_1 == 4) {
        iVar1 = DAT_42000a9c;
      }
      else if (param_1 < 5) {
        iVar1 = 0x20;
        if (((param_1 != 2) && (iVar1 = 0x200, param_1 != 3)) &&
           (iVar1 = DAT_420006dc, param_1 != 0)) {
          iVar1 = 4;
        }
      }
      else if (param_1 == 7) {
        iVar1 = 0x10;
      }
      else {
        iVar1 = DAT_42000b54;
        if ((param_1 != 8) && (iVar1 = 0x80, param_1 != 5)) {
          iVar1 = DAT_42000528;
        }
      }
    }
    else if (param_1 == 0xd) {
      iVar1 = DAT_42000b50;
    }
    else if (param_1 < 0xe) {
      if (param_1 == 0xb) {
        iVar1 = DAT_42000288;
      }
      else {
        iVar1 = DAT_420009f8;
        if (param_1 == 0xc) {
          iVar1 = DAT_42000530;
        }
      }
    }
    else {
      iVar1 = DAT_42000988;
      if ((param_1 != 0x11) && (iVar1 = 0x200, param_1 != 0x12)) {
        iVar1 = (uint)(param_1 == 0x10) << 8;
      }
    }
  }
  else if (param_1 == 0x1e) {
    iVar1 = DAT_42001df0;
  }
  else if (param_1 < 0x1f) {
    if (param_1 == 0x18) {
      iVar1 = DAT_42000a7c;
    }
    else if (param_1 < 0x19) {
      iVar1 = DAT_42000d30;
      if (((param_1 != 0x16) && (iVar1 = 0x80, param_1 != 0x17)) && (iVar1 = 0x40, param_1 == 0x14))
      {
        iVar1 = 2;
      }
    }
    else {
      iVar1 = DAT_42001df4;
      if ((param_1 != 0x1c) && (iVar1 = DAT_420006dc, param_1 != 0x1d)) {
        iVar1 = (uint)(param_1 == 0x19) << 0xf;
      }
    }
  }
  else if (param_1 == 0x23) {
    iVar1 = 8;
  }
  else if (param_1 < 0x24) {
    iVar1 = 0x20;
    if (((param_1 != 0x21) && (iVar1 = 0x10, param_1 != 0x22)) && (iVar1 = 4, param_1 == 0x1f)) {
      iVar1 = 2;
    }
  }
  else if (param_1 == 0x25) {
    iVar1 = 0x40;
  }
  else {
    iVar1 = DAT_42000540;
    if ((0x25 < param_1) && (iVar1 = 0x80, param_1 != 0x26)) {
      iVar1 = (uint)(param_1 == 0x27) << 0x1c;
    }
  }
  return iVar1;
}


