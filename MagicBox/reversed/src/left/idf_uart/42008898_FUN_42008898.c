undefined4 FUN_42008898(uint param_1,int param_2,ushort *param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 uVar6;
  uint uVar7;
  
  if (2 < param_1) {
    puVar2 = (undefined4 *)FUN_42020b54();
    *puVar2 = 9;
    return 0xffffffff;
  }
  if (param_3 == (ushort *)0x0) goto LAB_420088b0;
  if (param_2 == 1) {
    iVar5 = FUN_4200abe0(param_1,0xffffffff);
    if (iVar5 != 0) goto LAB_420088b0;
LAB_420088dc:
    param_2 = FUN_4200af94(param_1);
  }
  else if (param_2 == 2) goto LAB_420088dc;
  if (param_2 == 0) {
    iVar5 = 0;
    if ((*param_3 & 8) == 0) {
      iVar5 = ((*param_3 & 2) == 0) + 1;
    }
    uVar3 = param_3[2];
    *(int *)(*(int *)(PTR_PTR_42000978 + param_1 * 4) + 0x18) = iVar5;
    uVar3 = uVar3 & 3;
    uVar6 = 2;
    if ((uVar3 != 2) && (uVar6 = 3, uVar3 != 3)) {
      uVar6 = uVar3 == 1;
    }
    iVar5 = FUN_42009b38(param_1,uVar6);
    if (iVar5 == 0) {
      uVar4 = 1;
      if ((param_3[2] >> 2 & 1) != 0) {
        uVar4 = 3;
      }
      iVar5 = FUN_42009bec(param_1,uVar4);
      if (iVar5 == 0) {
        uVar4 = 0;
        if (((param_3[2] & 0x10) != 0) && (uVar4 = 3, (param_3[2] >> 5 & 1) == 0)) {
          uVar4 = 2;
        }
        iVar5 = FUN_42009cbc(param_1,uVar4);
        if (iVar5 == 0) {
          if ((param_3[2] >> 8 & 3) == 0) {
            return 0;
          }
          uVar7 = *(uint *)(param_3 + 10);
          if (uVar7 == *(uint *)(param_3 + 0xc)) {
            if ((param_3[2] & 0x400) == 0) {
              if (uVar7 == 0xf) {
                uVar7 = DAT_42000998;
              }
              else if (uVar7 < 0x10) {
                if (uVar7 == 7) {
                  uVar7 = 300;
                }
                else if (uVar7 < 8) {
                  if (uVar7 == 3) {
                    uVar7 = 0x6e;
                  }
                  else if (uVar7 < 4) {
                    if (uVar7 == 1) {
                      uVar7 = 0x32;
                    }
                    else {
                      bVar1 = uVar7 != 2;
                      uVar7 = 0x4b;
                      if (bVar1) {
                        uVar7 = 0;
                      }
                    }
                  }
                  else if (uVar7 == 5) {
                    uVar7 = 0x96;
                  }
                  else {
                    bVar1 = uVar7 != 6;
                    uVar7 = 200;
                    if (bVar1) {
                      uVar7 = 0x86;
                    }
                  }
                }
                else if (uVar7 == 0xb) {
                  uVar7 = DAT_4200099c;
                }
                else if (uVar7 < 0xc) {
                  if (uVar7 == 9) {
                    uVar7 = 0x4b0;
                  }
                  else {
                    bVar1 = uVar7 != 10;
                    uVar7 = 0x708;
                    if (bVar1) {
                      uVar7 = 600;
                    }
                  }
                }
                else if (uVar7 == 0xd) {
                  uVar7 = DAT_420009a0;
                }
                else {
                  bVar1 = uVar7 == 0xe;
                  uVar7 = DAT_420009a8;
                  if (bVar1) {
                    uVar7 = DAT_420009a4;
                  }
                }
              }
              else if (uVar7 == 0x17) {
                uVar7 = DAT_4200087c;
              }
              else if (uVar7 < 0x18) {
                if (uVar7 == 0x13) {
                  uVar7 = DAT_420009ac;
                }
                else if (uVar7 < 0x14) {
                  if (uVar7 == 0x11) {
                    uVar7 = DAT_420009b0;
                  }
                  else {
                    bVar1 = uVar7 == 0x12;
                    uVar7 = DAT_420009b8;
                    if (bVar1) {
                      uVar7 = DAT_420009b4;
                    }
                  }
                }
                else if (uVar7 == 0x15) {
                  uVar7 = DAT_420009bc;
                }
                else {
                  bVar1 = uVar7 == 0x16;
                  uVar7 = DAT_420009c4;
                  if (bVar1) {
                    uVar7 = DAT_420009c0;
                  }
                }
              }
              else if (uVar7 == 0x1b) {
                uVar7 = DAT_420009c8;
              }
              else if (uVar7 < 0x1c) {
                if (uVar7 == 0x19) {
                  uVar7 = DAT_420009cc;
                }
                else {
                  bVar1 = uVar7 == 0x1a;
                  uVar7 = DAT_420009d4;
                  if (bVar1) {
                    uVar7 = DAT_420009d0;
                  }
                }
              }
              else if (uVar7 == 0x1d) {
                uVar7 = DAT_420009d8;
              }
              else if (uVar7 == 0x1e) {
                uVar7 = DAT_420009dc;
              }
              else {
                if (uVar7 != 0x1c) goto LAB_420088b0;
                uVar7 = DAT_420009e0;
              }
            }
            iVar5 = FUN_42009d74(param_1,uVar7);
            if (iVar5 == 0) {
              return 0;
            }
          }
        }
      }
    }
  }
LAB_420088b0:
  puVar2 = (undefined4 *)FUN_42020b54();
  *puVar2 = 0x16;
  return 0xffffffff;
}