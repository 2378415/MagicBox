// 42006d1c  FUN_42006d1c  FUN_42006d1c  size=825

undefined4 FUN_42006d1c(uint param_1,int param_2,ushort *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  ushort uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if (2 < param_1) {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 9;
    return 0xffffffff;
  }
  if (param_3 == (ushort *)0x0) {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 0x16;
    return 0xffffffff;
  }
  if (param_2 == 1) {
    iVar2 = FUN_42008df4(param_1,0xffffffff);
    if (iVar2 != 0) {
      puVar1 = (undefined4 *)FUN_420180e4();
      *puVar1 = 0x16;
      return 0xffffffff;
    }
LAB_42006d69:
    iVar2 = FUN_420090ec(param_1);
    if (iVar2 != 0) {
      puVar1 = (undefined4 *)FUN_420180e4();
      *puVar1 = 0x16;
      return 0xffffffff;
    }
  }
  else {
    if (param_2 == 2) goto LAB_42006d69;
    if (param_2 != 0) {
      puVar1 = (undefined4 *)FUN_420180e4();
      *puVar1 = 0x16;
      return 0xffffffff;
    }
  }
  if ((*param_3 & 8) == 0) {
    if ((*param_3 & 2) == 0) {
      *(undefined4 *)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x18) = 2;
    }
    else {
      *(undefined4 *)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x18) = 1;
    }
  }
  else {
    *(undefined4 *)(*(int *)(PTR_PTR_42000770 + param_1 * 4) + 0x18) = 0;
  }
  uVar3 = param_3[2] & 3;
  if (uVar3 == 2) {
    uVar4 = 2;
  }
  else if (uVar3 < 3) {
    if ((param_3[2] & 3) == 0) {
      uVar4 = 0;
    }
    else {
      if (uVar3 != 1) goto LAB_42006ddb;
      uVar4 = 1;
    }
  }
  else {
    if (uVar3 != 3) {
LAB_42006ddb:
      puVar1 = (undefined4 *)FUN_420180e4();
      *puVar1 = 0x16;
      return 0xffffffff;
    }
    uVar4 = 3;
  }
  iVar2 = FUN_420082bc(param_1,uVar4);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 0x16;
    return 0xffffffff;
  }
  if ((param_3[2] & 4) == 0) {
    uVar4 = 1;
  }
  else {
    uVar4 = 3;
  }
  iVar2 = FUN_42008324(param_1,uVar4);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 0x16;
    return 0xffffffff;
  }
  if ((param_3[2] & 0x10) == 0) {
    uVar4 = 0;
  }
  else if ((param_3[2] & 0x20) == 0) {
    uVar4 = 2;
  }
  else {
    uVar4 = 3;
  }
  iVar2 = FUN_420083a8(param_1,uVar4);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 0x16;
    return 0xffffffff;
  }
  if ((param_3[2] >> 8 & 3) == 0) {
    return 0;
  }
  uVar5 = *(uint *)(param_3 + 10);
  if (uVar5 != *(uint *)(param_3 + 0xc)) {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 0x16;
    return 0xffffffff;
  }
  if ((param_3[2] & 0x400) == 0) {
    if (uVar5 == 0xf) {
      uVar5 = DAT_42000790;
    }
    else if (uVar5 < 0x10) {
      if (uVar5 == 7) {
        uVar5 = 300;
      }
      else if (uVar5 < 8) {
        if (uVar5 == 3) {
          uVar5 = 0x6e;
        }
        else if (uVar5 < 4) {
          if (uVar5 == 1) {
            uVar5 = 0x32;
          }
          else if (uVar5 == 2) {
            uVar5 = 0x4b;
          }
          else if (uVar5 != 0) {
LAB_42006f91:
            puVar1 = (undefined4 *)FUN_420180e4();
            *puVar1 = 0x16;
            return 0xffffffff;
          }
        }
        else if (uVar5 == 5) {
          uVar5 = 0x96;
        }
        else if (uVar5 == 6) {
          uVar5 = 200;
        }
        else {
          if (uVar5 != 4) goto LAB_42006f91;
          uVar5 = 0x86;
        }
      }
      else if (uVar5 == 0xb) {
        uVar5 = DAT_42000794;
      }
      else if (uVar5 < 0xc) {
        if (uVar5 == 9) {
          uVar5 = 0x4b0;
        }
        else if (uVar5 == 10) {
          uVar5 = 0x708;
        }
        else {
          if (uVar5 != 8) goto LAB_42006f91;
          uVar5 = 600;
        }
      }
      else if (uVar5 == 0xd) {
        uVar5 = DAT_42000798;
      }
      else if (uVar5 == 0xe) {
        uVar5 = DAT_4200079c;
      }
      else {
        if (uVar5 != 0xc) goto LAB_42006f91;
        uVar5 = DAT_420007a0;
      }
    }
    else if (uVar5 == 0x17) {
      uVar5 = DAT_42000698;
    }
    else if (uVar5 < 0x18) {
      if (uVar5 == 0x13) {
        uVar5 = DAT_420007a4;
      }
      else if (uVar5 < 0x14) {
        if (uVar5 == 0x11) {
          uVar5 = DAT_420007a8;
        }
        else if (uVar5 == 0x12) {
          uVar5 = DAT_420007ac;
        }
        else {
          if (uVar5 != 0x10) goto LAB_42006f91;
          uVar5 = DAT_420007b0;
        }
      }
      else if (uVar5 == 0x15) {
        uVar5 = DAT_420007b4;
      }
      else if (uVar5 == 0x16) {
        uVar5 = DAT_420007b8;
      }
      else {
        if (uVar5 != 0x14) goto LAB_42006f91;
        uVar5 = DAT_420007bc;
      }
    }
    else if (uVar5 == 0x1b) {
      uVar5 = DAT_420007c0;
    }
    else if (uVar5 < 0x1c) {
      if (uVar5 == 0x19) {
        uVar5 = DAT_420007c4;
      }
      else if (uVar5 == 0x1a) {
        uVar5 = DAT_420007c8;
      }
      else {
        if (uVar5 != 0x18) goto LAB_42006f91;
        uVar5 = DAT_420007cc;
      }
    }
    else if (uVar5 == 0x1d) {
      uVar5 = DAT_420007d0;
    }
    else if (uVar5 == 0x1e) {
      uVar5 = DAT_420007d4;
    }
    else {
      if (uVar5 != 0x1c) goto LAB_42006f91;
      uVar5 = DAT_420007d8;
    }
  }
  iVar2 = FUN_42008428(param_1,uVar5);
  uVar4 = 0;
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 0x16;
    uVar4 = 0xffffffff;
  }
  return uVar4;
}


