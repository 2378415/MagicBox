int FUN_42004cb4(uint param_1,uint *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  byte local_30;
  byte bStack_2f;
  byte abStack_2e [46];
  
  if (param_2 == (uint *)0x0) {
    return 0x102;
  }
  local_30 = 0;
  bStack_2f = 0;
  abStack_2e[0] = 0;
  if (param_1 == 0x40) {
    memw();
    local_30 = (byte)(*DAT_42000590 >> 4) & 1;
    bStack_2f = (byte)(*DAT_42000590 >> 5) & 1;
  }
  else if (param_1 < 0x41) {
    if (param_1 == 8) {
      memw();
      uVar2 = *DAT_42000528;
      local_30 = (byte)(uVar2 >> 9) & 1;
      bStack_2f = (byte)(uVar2 >> 10) & 1;
      abStack_2e[0] = (byte)(uVar2 >> 0xb) & 1;
    }
    else if (param_1 < 9) {
      if (param_1 == 2) {
        memw();
        uVar2 = *DAT_42000528;
        local_30 = (byte)(uVar2 >> 3) & 1;
        bStack_2f = (byte)(uVar2 >> 4) & 1;
        abStack_2e[0] = (byte)(uVar2 >> 5) & 1;
      }
      else if (param_1 == 4) {
        memw();
        uVar2 = *DAT_42000528;
        local_30 = (byte)(uVar2 >> 6) & 1;
        bStack_2f = (byte)(uVar2 >> 7) & 1;
        abStack_2e[0] = (byte)(uVar2 >> 8) & 1;
      }
      else {
        if (param_1 != 1) {
          return DAT_420005b4;
        }
        memw();
        uVar2 = *DAT_42000528;
        local_30 = (byte)uVar2 & 1;
        bStack_2f = (byte)(uVar2 >> 1) & 1;
        abStack_2e[0] = (byte)(uVar2 >> 2) & 1;
      }
    }
    else if (param_1 == 0x10) {
      memw();
      local_30 = (byte)*DAT_42000590 & 1;
      bStack_2f = (byte)(*DAT_42000590 >> 1) & 1;
    }
    else {
      if (param_1 != 0x20) {
        return DAT_420005b4;
      }
      memw();
      local_30 = (byte)(*DAT_42000590 >> 2) & 1;
      bStack_2f = (byte)(*DAT_42000590 >> 3) & 1;
    }
  }
  else {
    if (param_1 == 0x200) {
      iVar1 = FUN_42004798(param_3);
      if (iVar1 != 0) {
        return iVar1;
      }
      FUN_42004288(param_3,&local_30,&bStack_2f,abStack_2e);
      iVar1 = FUN_42005ab0();
    }
    else {
      if (0x200 < param_1) {
        if (param_1 == 0x400) {
          memw();
          uVar2 = *DAT_42000528;
          local_30 = (byte)(uVar2 >> 0xc) & 1;
          bStack_2f = (byte)(uVar2 >> 0xd) & 1;
          abStack_2e[0] = (byte)(uVar2 >> 0xe) & 1;
        }
        else {
          if (param_1 != DAT_420004fc) {
            return DAT_420005b4;
          }
          memw();
          uVar2 = *DAT_42000528;
          local_30 = (byte)(uVar2 >> 0xf) & 1;
          bStack_2f = (byte)(uVar2 >> 0x10) & 1;
          abStack_2e[0] = (byte)(uVar2 >> 0x11) & 1;
        }
        goto LAB_42004e92;
      }
      if (param_1 == 0x80) {
        memw();
        local_30 = (byte)(*DAT_42000590 >> 6) & 1;
        bStack_2f = (byte)(*DAT_42000590 >> 7) & 1;
        goto LAB_42004e92;
      }
      if (param_1 != 0x100) {
        return DAT_420005b4;
      }
      iVar1 = FUN_42004798(param_3);
      if (iVar1 != 0) {
        return iVar1;
      }
      FUN_42004288(param_3,&local_30,&bStack_2f,abStack_2e,1);
      iVar1 = FUN_42005ab0();
    }
    if (iVar1 != 0) {
      return iVar1;
    }
  }
LAB_42004e92:
  *param_2 = 0;
  if (local_30 != 0) {
    *param_2 = 1;
  }
  if (bStack_2f != 0) {
    *param_2 = *param_2 | 2;
  }
  if (abStack_2e[0] != 0) {
    *param_2 = *param_2 | 4;
  }
  return 0;
}