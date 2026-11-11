// 4202dc00  FUN_4202dc00  FUN_4202dc00  size=383
// strings: '9CfB | !MKF

int FUN_4202dc00(uint param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 0x13) {
    return 0x400;
  }
  if (param_1 < 0x14) {
    if (param_1 == 9) {
      return 0x100;
    }
    if (9 < param_1) {
      if (param_1 == 0xd) {
        return DAT_42000b50;
      }
      if (0xd < param_1) {
        if (param_1 == 0x11) {
          return DAT_42000988;
        }
        if (param_1 == 0x12) {
          return 0x200;
        }
        return (uint)(param_1 == 0x10) << 8;
      }
      if (param_1 == 0xb) {
        return DAT_42000288;
      }
      if (param_1 == 0xc) {
        return DAT_42000530;
      }
      return DAT_420009f8;
    }
    if (param_1 == 4) {
      return DAT_42000a9c;
    }
    if (4 < param_1) {
      if (param_1 == 7) {
        return 0x10;
      }
      if (param_1 == 8) {
        return DAT_42000b54;
      }
      if (param_1 == 5) {
        return 0x80;
      }
      return DAT_42000528;
    }
    if (param_1 != 1) {
      if (param_1 < 2) {
        return DAT_420006dc;
      }
      if (param_1 == 2) {
        return 0x20;
      }
      return 0x200;
    }
LAB_4202dd80:
    iVar1 = 4;
  }
  else {
    if (param_1 == 0x1f) {
      if (param_2 == 0) {
        return 2;
      }
      return 0x12;
    }
    if (param_1 < 0x20) {
      if (param_1 == 0x17) {
        return 0x80;
      }
      if (0x17 < param_1) {
        if (param_1 != 0x1a) {
          if (param_1 == 0x1b) {
            return DAT_42001df8;
          }
          return (uint)(param_1 == 0x18) << 0x13;
        }
        goto LAB_4202dd80;
      }
      if (param_1 != 0x15) {
        if (param_1 == 0x16) {
          return DAT_42000d30;
        }
        return 2;
      }
    }
    else {
      if (param_1 == 0x23) {
        if (param_2 == 0) {
          return 8;
        }
        return 0x18;
      }
      if (param_1 < 0x24) {
        if (param_1 == 0x21) {
          return 0x20;
        }
        if (param_1 == 0x22) {
          return 0x10;
        }
        if (param_2 == 0) {
          return 4;
        }
        return 0x34;
      }
      if (param_1 != 0x25) {
        if (param_1 < 0x26) {
          return DAT_42000540;
        }
        if (param_1 == 0x26) {
          return 0x80;
        }
        return (uint)(param_1 == 0x27) << 0x1c;
      }
    }
    iVar1 = 0x40;
  }
  return iVar1;
}


