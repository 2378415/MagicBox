int usb_xfer_submit(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  char *pcVar6;
  
  if (param_1 == 0) {
    iVar2 = -2;
  }
  else {
    pcVar6 = *(char **)(param_1 + 8);
    if (pcVar6 == (char *)0x0) {
      iVar2 = -2;
    }
    else if (*(int *)(param_1 + 0xc) == 0) {
      iVar2 = -2;
    }
    else {
      iVar2 = *(int *)(pcVar6 + 0xa64);
      if (iVar2 == 0) {
        iVar2 = -2;
      }
      else if ((*(uint *)(param_1 + 0x14) & 3) == 0) {
        if ((*(uint *)(param_1 + 0x18) & 3) == 0) {
          memw();
          if ((*(uint *)(*(int *)(iVar2 + 8) + 0x440) & 1) == 0) {
            iVar2 = -4;
          }
          else if (*pcVar6 == '\0') {
            iVar2 = -4;
          }
          else if (*(int *)(param_1 + 0x2c) == -6) {
            iVar2 = -6;
          }
          else {
            uVar1 = FUN_4200c920(iVar2);
            if (uVar1 == 0xffffffff) {
              iVar2 = -1;
            }
            else {
              iVar4 = *(int *)(param_1 + 0xc);
              if (*(char *)(iVar4 + 2) < '\0') {
                if (0x140 < (*(ushort *)(iVar4 + 4) & 0x7ff)) {
                  return -7;
                }
              }
              else {
                bVar5 = *(byte *)(iVar4 + 3) & 3;
                if ((bVar5 == 1 || bVar5 == 3) && (0xf0 < (*(ushort *)(iVar4 + 4) & 0x7ff))) {
                  return -7;
                }
                if (0xf0 < (*(ushort *)(iVar4 + 4) & 0x7ff)) {
                  return -7;
                }
              }
              FUN_4200da44();
              uVar3 = (uint)*(byte *)(iVar2 + 0xc);
              iVar4 = uVar1 * 0x18 + uVar3 * 0xc4 + DAT_42000af8;
              *(char *)(iVar4 + 0xc) = (char)uVar1;
              *(int *)(iVar4 + 0x14) = param_1;
              *(int *)(param_1 + 4) = iVar4 + 4;
              *(undefined4 *)(param_1 + 0x2c) = 0xfffffffa;
              *(undefined4 *)(param_1 + 0x24) = 0;
              FUN_4200da70();
              bVar5 = *(byte *)(*(int *)(param_1 + 0xc) + 3);
              if ((bVar5 & 3) == 0) {
                *(undefined1 *)(DAT_42000af8 + uVar1 * 0x18 + uVar3 * 0xc4 + 4) = 0;
                FUN_4200c4a8(iVar2,uVar1 & 0xff,param_1,*(undefined4 *)(param_1 + 0x14),
                             *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
              }
              else if ((byte)((bVar5 & 3) - 2) < 2) {
                FUN_4200c7b8(iVar2,uVar1 & 0xff,param_1,*(undefined4 *)(param_1 + 0x18),
                             *(undefined4 *)(param_1 + 0x1c));
              }
              if (*(int *)(param_1 + 0x28) == 0) {
                iVar2 = 0;
              }
              else {
                iVar2 = FUN_4200d790(*(undefined4 *)
                                      (DAT_42000af8 + uVar1 * 0x18 + uVar3 * 0xc4 + 0x10));
                if (iVar2 < 0) {
                  *(undefined4 *)(param_1 + 0x28) = 0;
                  FUN_4200d388(param_1);
                }
                else {
                  *(undefined4 *)(param_1 + 0x28) = 0;
                  iVar2 = *(int *)(param_1 + 0x2c);
                  FUN_4200c978(iVar4 + 4);
                }
              }
            }
          }
        }
        else {
          iVar2 = -2;
        }
      }
      else {
        iVar2 = -2;
      }
    }
  }
  return iVar2;
}