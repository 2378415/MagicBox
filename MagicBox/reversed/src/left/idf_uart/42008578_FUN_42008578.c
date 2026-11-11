undefined4 FUN_42008578(uint param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  ushort uVar5;
  uint local_30 [12];
  
  if (2 < param_1) {
    puVar3 = (undefined4 *)FUN_42020b54();
    *puVar3 = 9;
    return 0xffffffff;
  }
  if (param_2 == (ushort *)0x0) {
LAB_4200858b:
    puVar3 = (undefined4 *)FUN_42020b54();
    *puVar3 = 0x16;
    return 0xffffffff;
  }
  (*DAT_42000094)(param_2,0,0x1c);
  if (*(int *)(*(int *)(PTR_PTR_42000978 + param_1 * 4) + 0x18) == 0) {
    *param_2 = *param_2 | 8;
  }
  else if (*(int *)(*(int *)(PTR_PTR_42000978 + param_1 * 4) + 0x18) == 1) {
    *param_2 = *param_2 | 2;
  }
  iVar4 = FUN_42009bac(param_1,local_30);
  if (iVar4 != 0) goto LAB_4200858b;
  uVar1 = param_2[2];
  uVar5 = uVar1 & 0xfffc;
  param_2[2] = uVar5;
  if (local_30[0] == 2) {
    param_2[2] = uVar5 | 2;
  }
  else if (local_30[0] < 3) {
    if (local_30[0] != 0) {
      param_2[2] = uVar5 | 1;
    }
  }
  else {
    if (local_30[0] != 3) goto LAB_42008678;
    param_2[2] = uVar1 | 3;
  }
  iVar4 = FUN_42009c60(param_1,local_30);
  if (iVar4 != 0) goto LAB_4200858b;
  if (local_30[0] != 1) {
    if (local_30[0] != 3) goto LAB_42008678;
    param_2[2] = param_2[2] | 4;
  }
  iVar4 = FUN_42009d18(param_1,local_30);
  if (iVar4 != 0) goto LAB_4200858b;
  if (local_30[0] == 2) {
    param_2[2] = param_2[2] | 0x10;
  }
  else if (local_30[0] == 3) {
    param_2[2] = param_2[2] | 0x30;
  }
  else if (local_30[0] != 0) {
LAB_42008678:
    puVar3 = (undefined4 *)FUN_42020b54();
    *puVar3 = 0x58;
    return 0xffffffff;
  }
  iVar4 = FUN_42009e9c(param_1,local_30);
  uVar2 = DAT_42000998;
  if (iVar4 != 0) goto LAB_4200858b;
  uVar1 = param_2[2];
  param_2[2] = uVar1 | 0x300;
  if (local_30[0] == uVar2) {
    local_30[0] = 0xf;
    goto LAB_42008890;
  }
  if (uVar2 < local_30[0]) {
    if (local_30[0] == DAT_4200087c) {
      local_30[0] = 0x17;
      goto LAB_42008890;
    }
    if (DAT_4200087c < local_30[0]) {
      if (local_30[0] == DAT_420009c8) {
        local_30[0] = 0x1b;
        goto LAB_42008890;
      }
      if (DAT_420009c8 < local_30[0]) {
        if (local_30[0] == DAT_420009d8) {
          local_30[0] = 0x1d;
          goto LAB_42008890;
        }
        if (local_30[0] == DAT_420009dc) {
          local_30[0] = 0x1e;
          goto LAB_42008890;
        }
        if (local_30[0] == DAT_420009e0) {
          local_30[0] = 0x1c;
          goto LAB_42008890;
        }
      }
      else {
        if (local_30[0] == DAT_420009cc) {
          local_30[0] = 0x19;
          goto LAB_42008890;
        }
        if (local_30[0] == DAT_420009d0) {
          local_30[0] = 0x1a;
          goto LAB_42008890;
        }
        if (local_30[0] == DAT_420009d4) {
          local_30[0] = 0x18;
          goto LAB_42008890;
        }
      }
    }
    else {
      if (local_30[0] == DAT_420009ac) {
        local_30[0] = 0x13;
        goto LAB_42008890;
      }
      if (DAT_420009ac < local_30[0]) {
        if (local_30[0] == DAT_420009bc) {
          local_30[0] = 0x15;
          goto LAB_42008890;
        }
        if (local_30[0] == DAT_420009c0) {
          local_30[0] = 0x16;
          goto LAB_42008890;
        }
        if (local_30[0] == DAT_420009c4) {
          local_30[0] = 0x14;
          goto LAB_42008890;
        }
      }
      else {
        if (local_30[0] == DAT_420009b0) {
          local_30[0] = 0x11;
          goto LAB_42008890;
        }
        if (local_30[0] == DAT_420009b4) {
          local_30[0] = 0x12;
          goto LAB_42008890;
        }
        if (local_30[0] == DAT_420009b8) {
          local_30[0] = 0x10;
          goto LAB_42008890;
        }
      }
    }
  }
  else {
    if (local_30[0] == 300) {
      local_30[0] = 7;
      goto LAB_42008890;
    }
    if (local_30[0] < 0x12d) {
      if (local_30[0] == 0x6e) {
        local_30[0] = 3;
        goto LAB_42008890;
      }
      if (local_30[0] < 0x6f) {
        if (local_30[0] == 0x32) {
          local_30[0] = 1;
          goto LAB_42008890;
        }
        if (local_30[0] == 0x4b) {
          local_30[0] = 2;
          goto LAB_42008890;
        }
        if (local_30[0] == 0) goto LAB_42008890;
      }
      else {
        if (local_30[0] == 0x96) {
          local_30[0] = 5;
          goto LAB_42008890;
        }
        if (local_30[0] == 200) {
          local_30[0] = 6;
          goto LAB_42008890;
        }
        if (local_30[0] == 0x86) {
          local_30[0] = 4;
          goto LAB_42008890;
        }
      }
    }
    else {
      if (local_30[0] == DAT_4200099c) {
        local_30[0] = 0xb;
        goto LAB_42008890;
      }
      if (DAT_4200099c < local_30[0]) {
        if (local_30[0] == DAT_420009a0) {
          local_30[0] = 0xd;
          goto LAB_42008890;
        }
        if (local_30[0] == DAT_420009a4) {
          local_30[0] = 0xe;
          goto LAB_42008890;
        }
        if (local_30[0] == DAT_420009a8) {
          local_30[0] = 0xc;
          goto LAB_42008890;
        }
      }
      else {
        if (local_30[0] == 0x4b0) {
          local_30[0] = 9;
          goto LAB_42008890;
        }
        if (local_30[0] == 0x708) {
          local_30[0] = 10;
          goto LAB_42008890;
        }
        if (local_30[0] == 600) {
          local_30[0] = 8;
          goto LAB_42008890;
        }
      }
    }
  }
  param_2[2] = uVar1 | 0x700;
LAB_42008890:
  *(uint *)(param_2 + 0xc) = local_30[0];
  *(uint *)(param_2 + 10) = local_30[0];
  return 0;
}