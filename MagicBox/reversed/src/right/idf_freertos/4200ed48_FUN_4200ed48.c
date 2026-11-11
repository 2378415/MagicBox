// strings: zwpp | Failed to reset port %u,errorcode:%d | Failed to clear port %u reset change, errorcode:

void FUN_4200ed48(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  char cVar7;
  ushort uVar8;
  ushort uVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  char cVar13;
  ushort local_50;
  ushort uStack_4e;
  ushort auStack_4c [6];
  char *pcStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  if (*param_1 != '\0') {
    pcStack_40 = param_1;
    uVar4 = FUN_4200da44();
    (*DAT_420002fc)(auStack_4c,*(undefined4 *)(param_1 + 0x2b3c),2);
    FUN_4200da70(uVar4);
    for (uVar6 = 0; uVar6 < (byte)pcStack_40[5]; uVar6 = uVar6 + 1 & 0xff) {
      uStack_34 = uVar6 + 1;
      uStack_30 = uVar6;
      if (((uint)auStack_4c[0] & 1 << ((byte)uStack_34 & 0x1f)) != 0) {
        auStack_4c[0] = auStack_4c[0] & ((ushort)(1 << 0x20 - (0x20 - (uStack_34 & 0x1f))) ^ 0xffff)
        ;
        uStack_2c = uStack_34 & 0xff;
        uStack_3c = uStack_34 & 0xff;
        iVar5 = FUN_4200e7e4(pcStack_40,uStack_3c,&local_50);
        uVar8 = local_50;
        if (iVar5 < 0) {
          (*DAT_42000634)(PTR_DAT_42000c1c);
          (*DAT_42000634)(PTR_s_Failed_to_read_port__u_status__e_42000c94,uStack_34,iVar5);
          (*DAT_42000634)(PTR_DAT_42000c24);
        }
        else {
          cVar7 = '\x10';
          uVar3 = 1;
          uVar9 = uStack_4e;
          while (uVar9 != 0) {
            if ((uVar9 & uVar3) == 0) {
LAB_4200ee28:
              uVar3 = uVar3 * 2;
              cVar7 = cVar7 + '\x01';
            }
            else {
              iVar5 = FUN_4200ed04(pcStack_40,uStack_3c,cVar7);
              if (-1 < iVar5) {
                uVar9 = uVar9 & (uVar3 ^ 0xffff);
                goto LAB_4200ee28;
              }
              (*DAT_42000634)(PTR_DAT_42000c1c);
              (*DAT_42000634)(PTR_s_Failed_to_clear_port__u__change_m_42000c98,uStack_34,uVar3,iVar5
                             );
              (*DAT_42000634)(PTR_DAT_42000c24);
            }
          }
          if ((uStack_4e & 1) != 0) {
            uVar3 = 0;
            uStack_38 = 0;
            for (uVar10 = 0; uVar10 < 0x5dc; uVar10 = uVar10 + 0x19) {
              iVar5 = FUN_4200e7e4(pcStack_40,uStack_3c,&local_50);
              uVar9 = local_50;
              if (iVar5 < 0) {
                (*DAT_42000634)(PTR_DAT_42000c1c);
                (*DAT_42000634)(PTR_s_Failed_to_read_port__u_status__e_42000c94,uStack_34,iVar5);
                (*DAT_42000634)(PTR_DAT_42000c24);
              }
              else {
                if (((uStack_4e & 1) == 0) && (uVar3 == (local_50 & 1))) {
                  uStack_38 = uStack_38 + 0x19 & 0xffff;
                  uVar8 = local_50;
                  if (99 < uStack_38) break;
                }
                else {
                  uVar3 = local_50 & 1;
                  uStack_38 = 0;
                }
                if ((uStack_4e & 1) != 0) {
                  FUN_4200ed04(pcStack_40,uStack_3c,0x10);
                }
                FUN_4200da94(0x19);
                uVar8 = uVar9;
              }
            }
            if (uStack_38 < 100) {
              (*DAT_42000634)(PTR_DAT_42000c1c);
              (*DAT_42000634)(PTR_s_Failed_to_debounce_port__u_42000c9c,uStack_34);
              (*DAT_42000634)(PTR_DAT_42000c24);
              break;
            }
            if ((uVar8 & 1) == 0) {
              FUN_4200dee0(pcStack_40 + uStack_30 * DAT_42000bcc + 0x20);
              frame_build_ep0(0);
            }
            else {
              iVar5 = FUN_4200ea4c(pcStack_40,uStack_3c,4);
              if (iVar5 < 0) {
                (*DAT_42000634)(PTR_DAT_42000c1c);
                (*DAT_42000634)(PTR_s_Failed_to_reset_port__u_errorcod_42000ca0,uStack_30,iVar5);
                (*DAT_42000634)(PTR_DAT_42000c24);
              }
              else {
                FUN_4200da94(200);
                iVar5 = FUN_4200e7e4(pcStack_40,uStack_3c,&local_50);
                uVar8 = local_50;
                if (iVar5 < 0) {
                  (*DAT_42000634)(PTR_DAT_42000c1c);
                  (*DAT_42000634)(PTR_s_Failed_to_read_port__u_status__e_42000c94,uStack_34,iVar5);
                  (*DAT_42000634)(PTR_DAT_42000c24);
                }
                else if ((local_50 & 0x12) == 2) {
                  if (((uStack_4e & 0x10) != 0) &&
                     (iVar5 = FUN_4200ed04(pcStack_40,uStack_3c,0x14), iVar5 < 0)) {
                    (*DAT_42000634)(PTR_DAT_42000c1c);
                    (*DAT_42000634)(PTR_s_Failed_to_clear_port__u_reset_ch_42000ca4,uStack_30,iVar5)
                    ;
                    (*DAT_42000634)(PTR_DAT_42000c24);
                  }
                  pcVar1 = pcStack_40;
                  iVar5 = DAT_42000bcc;
                  if ((uVar8 & 0x100) == 0) {
                    if ((uVar8 & 0x200) == 0) goto LAB_4200f0a4;
                    cVar7 = '\x05';
                  }
                  else if ((uVar8 & 0x400) == 0) {
                    if ((uVar8 & 0x200) == 0) {
                      cVar7 = '\x02';
                    }
                    else {
                      cVar7 = '\x01';
                    }
                  }
                  else {
                    cVar7 = '\x03';
                  }
                  iVar12 = uStack_30 * DAT_42000bcc;
                  pcVar11 = pcStack_40 + iVar12 + 0x20;
                  FUN_4200dee0(pcVar11);
                  (*DAT_42000240)(pcVar11,0,iVar5);
                  pcVar2 = pcStack_40;
                  *(char **)(pcVar1 + DAT_42000c68 + iVar12) = pcVar1;
                  if (*(int *)(pcVar1 + 0x2af0) == 0) {
                    cVar13 = '\x01';
                  }
                  else {
                    cVar13 = *(char *)(*(int *)(pcVar1 + 0x2af0) + 4) + '\x01';
                  }
                  iVar5 = uStack_30 * DAT_42000bcc;
                  pcStack_40[iVar5 + 0x24] = cVar13;
                  pcStack_40[iVar5 + 0x20] = '\x01';
                  pcStack_40[iVar5 + 0x21] = (char)uStack_2c;
                  pcStack_40[iVar5 + 0x23] = cVar7;
                  *(undefined4 *)(pcStack_40 + DAT_42000c7c + iVar5) =
                       *(undefined4 *)(pcStack_40 + 0x2af4);
                  uVar4 = FUN_4200d824();
                  *(undefined4 *)(pcVar2 + DAT_42000ca8 + iVar5) = uVar4;
                  iVar5 = FUN_4200e008(pcVar11);
                  if (iVar5 < 0) {
                    FUN_4200dee0(pcVar11);
                    (*DAT_42000634)(PTR_DAT_42000c1c);
                    (*DAT_42000634)(PTR_s_Port__u_enumerate_fail_42000cac,
                                    pcStack_40[uStack_30 * DAT_42000bcc + 0x21]);
                    (*DAT_42000634)(PTR_DAT_42000c24);
                  }
                }
                else {
                  FUN_4200dee0(pcStack_40 + uStack_30 * DAT_42000bcc + 0x20);
                }
              }
            }
          }
        }
      }
LAB_4200f0a4:
    }
    if ((pcStack_40[1] == '\0') && (*pcStack_40 != '\0')) {
      FUN_4200d9f0(*(undefined4 *)(pcStack_40 + 0x2b40));
    }
  }
  return;
}