undefined4 FUN_420069a0(uint param_1,ushort *param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  ushort uVar4;
  uint local_30 [12];
  
  if (2 < param_1) {
    puVar2 = (undefined4 *)FUN_420180e4();
    *puVar2 = 9;
    return 0xffffffff;
  }
  if (param_2 == (ushort *)0x0) {
    puVar2 = (undefined4 *)FUN_420180e4();
    *puVar2 = 0x16;
    return 0xffffffff;
  }
  (*DAT_42000240)(param_2,0,0x1c);
  if (*(int *)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x18) == 0) {
    *param_2 = *param_2 | 8;
  }
  else if (*(int *)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x18) == 1) {
    *param_2 = *param_2 | 2;
  }
  iVar3 = FUN_42008300(param_1,local_30);
  if (iVar3 != 0) {
    puVar2 = (undefined4 *)FUN_420180e4();
    *puVar2 = 0x16;
    return 0xffffffff;
  }
  uVar1 = param_2[2];
  uVar4 = uVar1 & 0xfffc;
  param_2[2] = uVar4;
  if (local_30[0] == 2) {
    param_2[2] = uVar4 | 2;
  }
  else if (local_30[0] < 3) {
    if (local_30[0] != 0) {
      if (local_30[0] != 1) goto LAB_42006a57;
      param_2[2] = uVar4 | 1;
    }
  }
  else {
    if (local_30[0] != 3) {
LAB_42006a57:
      puVar2 = (undefined4 *)FUN_420180e4();
      *puVar2 = 0x58;
      return 0xffffffff;
    }
    param_2[2] = uVar1 | 3;
  }
  iVar3 = FUN_42008368(param_1,local_30);
  if (iVar3 != 0) {
    puVar2 = (undefined4 *)FUN_420180e4();
    *puVar2 = 0x16;
    return 0xffffffff;
  }
  if (local_30[0] != 1) {
    if (local_30[0] != 3) {
      puVar2 = (undefined4 *)FUN_420180e4();
      *puVar2 = 0x58;
      return 0xffffffff;
    }
    param_2[2] = param_2[2] | 4;
  }
  iVar3 = FUN_420083e8(param_1,local_30);
  if (iVar3 != 0) {
    puVar2 = (undefined4 *)FUN_420180e4();
    *puVar2 = 0x16;
    return 0xffffffff;
  }
  if (local_30[0] == 2) {
    param_2[2] = param_2[2] | 0x10;
  }
  else if (local_30[0] == 3) {
    param_2[2] = param_2[2] | 0x30;
  }
  else if (local_30[0] != 0) {
    puVar2 = (undefined4 *)FUN_420180e4();
    *puVar2 = 0x58;
    return 0xffffffff;
  }
  iVar3 = FUN_42008518(param_1,local_30);
  if (iVar3 != 0) {
    puVar2 = (undefined4 *)FUN_420180e4();
    *puVar2 = 0x16;
    return 0xffffffff;
  }
  uVar1 = param_2[2];
  param_2[2] = uVar1 | 0x300;
  if (local_30[0] == DAT_42000790) {
    local_30[0] = 0xf;
    goto LAB_42006d16;
  }
  if (DAT_42000790 < local_30[0]) {
    if (local_30[0] == DAT_42000698) {
      local_30[0] = 0x17;
      goto LAB_42006d16;
    }
    if (DAT_42000698 < local_30[0]) {
      if (local_30[0] == DAT_420007c0) {
        local_30[0] = 0x1b;
        goto LAB_42006d16;
      }
      if (DAT_420007c0 < local_30[0]) {
        if (local_30[0] == DAT_420007d0) {
          local_30[0] = 0x1d;
          goto LAB_42006d16;
        }
        if (local_30[0] == DAT_420007d4) {
          local_30[0] = 0x1e;
          goto LAB_42006d16;
        }
        if (local_30[0] == DAT_420007d8) {
          local_30[0] = 0x1c;
          goto LAB_42006d16;
        }
      }
      else {
        if (local_30[0] == DAT_420007c4) {
          local_30[0] = 0x19;
          goto LAB_42006d16;
        }
        if (local_30[0] == DAT_420007c8) {
          local_30[0] = 0x1a;
          goto LAB_42006d16;
        }
        if (local_30[0] == DAT_420007cc) {
          local_30[0] = 0x18;
          goto LAB_42006d16;
        }
      }
    }
    else {
      if (local_30[0] == DAT_420007a4) {
        local_30[0] = 0x13;
        goto LAB_42006d16;
      }
      if (DAT_420007a4 < local_30[0]) {
        if (local_30[0] == DAT_420007b4) {
          local_30[0] = 0x15;
          goto LAB_42006d16;
        }
        if (local_30[0] == DAT_420007b8) {
          local_30[0] = 0x16;
          goto LAB_42006d16;
        }
        if (local_30[0] == DAT_420007bc) {
          local_30[0] = 0x14;
          goto LAB_42006d16;
        }
      }
      else {
        if (local_30[0] == DAT_420007a8) {
          local_30[0] = 0x11;
          goto LAB_42006d16;
        }
        if (local_30[0] == DAT_420007ac) {
          local_30[0] = 0x12;
          goto LAB_42006d16;
        }
        if (local_30[0] == DAT_420007b0) {
          local_30[0] = 0x10;
          goto LAB_42006d16;
        }
      }
    }
  }
  else {
    if (local_30[0] == 300) {
      local_30[0] = 7;
      goto LAB_42006d16;
    }
    if (local_30[0] < 0x12d) {
      if (local_30[0] == 0x6e) {
        local_30[0] = 3;
        goto LAB_42006d16;
      }
      if (local_30[0] < 0x6f) {
        if (local_30[0] == 0x32) {
          local_30[0] = 1;
          goto LAB_42006d16;
        }
        if (local_30[0] == 0x4b) {
          local_30[0] = 2;
          goto LAB_42006d16;
        }
        if (local_30[0] == 0) goto LAB_42006d16;
      }
      else {
        if (local_30[0] == 0x96) {
          local_30[0] = 5;
          goto LAB_42006d16;
        }
        if (local_30[0] == 200) {
          local_30[0] = 6;
          goto LAB_42006d16;
        }
        if (local_30[0] == 0x86) {
          local_30[0] = 4;
          goto LAB_42006d16;
        }
      }
    }
    else {
      if (local_30[0] == DAT_42000794) {
        local_30[0] = 0xb;
        goto LAB_42006d16;
      }
      if (DAT_42000794 < local_30[0]) {
        if (local_30[0] == DAT_42000798) {
          local_30[0] = 0xd;
          goto LAB_42006d16;
        }
        if (local_30[0] == DAT_4200079c) {
          local_30[0] = 0xe;
          goto LAB_42006d16;
        }
        if (local_30[0] == DAT_420007a0) {
          local_30[0] = 0xc;
          goto LAB_42006d16;
        }
      }
      else {
        if (local_30[0] == 0x4b0) {
          local_30[0] = 9;
          goto LAB_42006d16;
        }
        if (local_30[0] == 0x708) {
          local_30[0] = 10;
          goto LAB_42006d16;
        }
        if (local_30[0] == 600) {
          local_30[0] = 8;
          goto LAB_42006d16;
        }
      }
    }
  }
  param_2[2] = uVar1 | 0x700;
LAB_42006d16:
  *(uint *)(param_2 + 0xc) = local_30[0];
  *(uint *)(param_2 + 10) = local_30[0];
  return 0;
}