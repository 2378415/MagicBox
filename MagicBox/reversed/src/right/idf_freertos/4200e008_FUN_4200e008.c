// strings: Failed to get device descriptor,errorcode:%d | Failed to get full device descriptor,errorcode:% | Failed to get config descriptor,errorcode:%d | Failed to get full config descriptor,errorcode:% | Parse config fail | No memory to alloc for raw_config_desc | do not support Class:0x%02x,Subclass:0x%02x,Prot

int FUN_4200e008(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  ushort uVar6;
  int iVar7;
  
  puVar5 = (undefined1 *)
           ((((uint)*(byte *)(*(int *)(param_1 + 0xa64) + 4) * 2 +
             (*(byte *)(*(int *)(param_1 + 0xa5c) + 2) - 1)) * 4 + (*(byte *)(param_1 + 1) - 1)) * 8
           + DAT_42000be8);
  *(undefined1 **)(param_1 + 0xa58) = puVar5;
  *(undefined1 *)(param_1 + 0xa6a) = 0;
  *(undefined1 *)(param_1 + 0xa69) = 5;
  *(undefined1 *)(param_1 + 0xa6b) = 0;
  uVar2 = FUN_42024868(*(undefined1 *)(param_1 + 3));
  *(char *)(param_1 + 0xa6c) = (char)uVar2;
  *(char *)(param_1 + 0xa6d) = (char)((ushort)uVar2 >> 8);
  *(undefined1 *)(param_1 + 0xa6e) = 0;
  *(undefined1 *)(param_1 + 0xa68) = 7;
  *(undefined1 *)(param_1 + 2) = 0;
  *puVar5 = 0x80;
  puVar5[1] = 6;
  puVar5[2] = 0;
  puVar5[3] = 1;
  puVar5[4] = 0;
  puVar5[5] = 0;
  puVar5[6] = 8;
  puVar5[7] = 0;
  iVar3 = FUN_4200df94(param_1,puVar5,
                       DAT_42000bec + (uint)*(byte *)(*(int *)(param_1 + 0xa64) + 4) * 0x800);
  iVar7 = DAT_42000bec;
  if (iVar3 < 0) {
    (*DAT_42000634)(PTR_DAT_42000ba0);
    (*DAT_42000634)(PTR_s_Failed_to_get_device_descriptor__42000bf0,iVar3);
    (*DAT_42000634)(PTR_DAT_42000ba8);
  }
  else {
    FUN_4200db58(param_1,DAT_42000bec + (uint)*(byte *)(*(int *)(param_1 + 0xa64) + 4) * 0x800,8);
    iVar7 = (uint)*(byte *)(*(int *)(param_1 + 0xa64) + 4) * 0x800 + iVar7;
    if (*(ushort *)(iVar7 + 2) < 0x300) {
      uVar6 = (ushort)*(byte *)(iVar7 + 7);
    }
    else {
      uVar6 = (ushort)(1 << 0x20 - (0x20 - (*(byte *)(iVar7 + 7) & 0x1f)));
    }
    *(char *)(param_1 + 0xa6c) = (char)uVar6;
    *(char *)(param_1 + 0xa6d) = (char)(uVar6 >> 8);
    iVar7 = FUN_420247d8(*(int *)(param_1 + 0xa64) + DAT_42000b94);
    if (iVar7 < 0) {
      (*DAT_42000634)(PTR_DAT_42000ba0);
      (*DAT_42000634)(PTR_s_Failed_to_allocate_devaddr_error_42000bf4,iVar3);
      (*DAT_42000634)(PTR_DAT_42000ba8);
    }
    else {
      *puVar5 = 0;
      puVar5[1] = 5;
      puVar5[2] = (char)iVar7;
      puVar5[3] = (char)((uint)iVar7 >> 8);
      puVar5[4] = 0;
      puVar5[5] = 0;
      puVar5[6] = 0;
      puVar5[7] = 0;
      iVar3 = FUN_4200df94(param_1,puVar5,0);
      if (iVar3 < 0) {
        (*DAT_42000634)(PTR_DAT_42000ba0);
        (*DAT_42000634)(PTR_s_Failed_to_set_devaddr_errorcode__42000bf8,iVar3);
        (*DAT_42000634)(PTR_DAT_42000ba8);
      }
      else {
        FUN_4200da94(2);
        *(char *)(param_1 + 2) = (char)iVar7;
        *puVar5 = 0x80;
        puVar5[1] = 6;
        puVar5[2] = 0;
        puVar5[3] = 1;
        puVar5[4] = 0;
        puVar5[5] = 0;
        puVar5[6] = 0x12;
        puVar5[7] = 0;
        iVar3 = FUN_4200df94(param_1,puVar5,
                             DAT_42000bec + (uint)*(byte *)(*(int *)(param_1 + 0xa64) + 4) * 0x800);
        iVar7 = DAT_42000bec;
        if (iVar3 < 0) {
          (*DAT_42000634)(PTR_DAT_42000ba0);
          (*DAT_42000634)(PTR_s_Failed_to_get_full_device_descri_42000bfc,iVar3);
          (*DAT_42000634)(PTR_DAT_42000ba8);
        }
        else {
          FUN_4200db58(param_1,DAT_42000bec + (uint)*(byte *)(*(int *)(param_1 + 0xa64) + 4) * 0x800
                       ,0x12);
          *puVar5 = 0x80;
          puVar5[1] = 6;
          puVar5[2] = 0;
          puVar5[3] = 2;
          puVar5[4] = 0;
          puVar5[5] = 0;
          puVar5[6] = 9;
          puVar5[7] = 0;
          iVar3 = FUN_4200df94(param_1,puVar5,
                               iVar7 + (uint)*(byte *)(*(int *)(param_1 + 0xa64) + 4) * 0x800);
          iVar7 = DAT_42000bec;
          if (iVar3 < 0) {
            (*DAT_42000634)(PTR_DAT_42000ba0);
            (*DAT_42000634)(PTR_s_Failed_to_get_config_descriptor__42000c00,iVar3);
            (*DAT_42000634)(PTR_DAT_42000ba8);
          }
          else {
            FUN_4200dc2c(param_1,DAT_42000bec +
                                 (uint)*(byte *)(*(int *)(param_1 + 0xa64) + 4) * 0x800,9);
            uVar6 = *(ushort *)((uint)*(byte *)(*(int *)(param_1 + 0xa64) + 4) * 0x800 + iVar7 + 2);
            uVar4 = (uint)uVar6;
            if (DAT_420004fc < uVar4) {
              (*DAT_42000634)(PTR_DAT_42000ba0);
              (*DAT_42000634)(PTR_s_wTotalLength__d_is_overflow__def_42000c04,uVar4,DAT_420004fc);
              (*DAT_42000634)(PTR_DAT_42000ba8);
              iVar3 = -1;
            }
            else {
              *puVar5 = 0x80;
              puVar5[1] = 6;
              puVar5[2] = 0;
              puVar5[3] = 2;
              puVar5[4] = 0;
              puVar5[5] = 0;
              puVar5[6] = (char)uVar6;
              puVar5[7] = (char)(uVar6 >> 8);
              iVar3 = FUN_4200df94(param_1,puVar5,
                                   DAT_42000bec +
                                   (uint)*(byte *)(*(int *)(param_1 + 0xa64) + 4) * 0x800);
              if (iVar3 < 0) {
                (*DAT_42000634)(PTR_DAT_42000ba0);
                (*DAT_42000634)(PTR_s_Failed_to_get_full_config_descri_42000c08,iVar3);
                (*DAT_42000634)(PTR_DAT_42000ba8);
              }
              else {
                iVar3 = FUN_4200dc2c(param_1,DAT_42000bec +
                                             (uint)*(byte *)(*(int *)(param_1 + 0xa64) + 4) * 0x800,
                                     uVar4);
                if (iVar3 < 0) {
                  (*DAT_42000634)(PTR_DAT_42000ba0);
                  (*DAT_42000634)(PTR_s_Parse_config_fail_42000c0c);
                  (*DAT_42000634)(PTR_DAT_42000ba8);
                }
                else {
                  iVar7 = FUN_4200dab4(uVar4 + 1);
                  *(int *)(param_1 + 0xa54) = iVar7;
                  if (iVar7 == 0) {
                    (*DAT_42000634)(PTR_DAT_42000ba0);
                    (*DAT_42000634)(PTR_s_No_memory_to_alloc_for_raw_confi_42000c10);
                    (*DAT_42000634)(PTR_DAT_42000ba8);
                    iVar3 = -1;
                  }
                  else {
                    iVar3 = (uint)*(byte *)(*(int *)(param_1 + 0xa64) + 4) * 0x800 + DAT_42000bec;
                    uVar1 = *(undefined1 *)(iVar3 + 5);
                    (*DAT_420002fc)(iVar7,iVar3,uVar4);
                    *(undefined1 *)(*(int *)(param_1 + 0xa54) + uVar4) = 0;
                    *puVar5 = 0;
                    puVar5[1] = 9;
                    puVar5[2] = uVar1;
                    puVar5[3] = 0;
                    puVar5[4] = 0;
                    puVar5[5] = 0;
                    puVar5[6] = 0;
                    puVar5[7] = 0;
                    iVar3 = FUN_4200df94(param_1,puVar5,0);
                    if (iVar3 < 0) {
                      (*DAT_42000634)(PTR_DAT_42000ba0);
                      (*DAT_42000634)(PTR_s_Failed_to_set_configuration_erro_42000c14,iVar3);
                      (*DAT_42000634)(PTR_DAT_42000ba8);
                    }
                    else {
                      frame_build_ep0(1);
                      for (uVar4 = 0; uVar4 < *(byte *)(param_1 + 0x20); uVar4 = uVar4 + 1 & 0xff) {
                        iVar7 = uVar4 * 0x144 + param_1;
                        iVar7 = FUN_4200daf0(*(undefined1 *)(iVar7 + 0x45),
                                             *(undefined1 *)(iVar7 + 0x46),
                                             *(undefined1 *)(iVar7 + 0x47),
                                             (*(uint *)(param_1 + 0x10) & 0xff) << 8 |
                                             (uint)*(byte *)(param_1 + 0xf),
                                             *(uint *)(param_1 + 0x10) >> 8 & 0xffff);
                        if (iVar7 == 0) {
                          (*DAT_42000634)(PTR_DAT_42000ba0);
                          iVar7 = uVar4 * 0x144 + param_1;
                          (*DAT_42000634)(PTR_s_do_not_support_Class_0x_02x_Subc_42000c18,
                                          *(undefined1 *)(iVar7 + 0x45),
                                          *(undefined1 *)(iVar7 + 0x46),
                                          *(undefined1 *)(iVar7 + 0x47));
                          (*DAT_42000634)(PTR_DAT_42000ba8);
                        }
                        else {
                          *(int *)(uVar4 * 0x144 + param_1 + 0x38) = iVar7;
                          iVar3 = (**(code **)(iVar7 + 4))(param_1,uVar4);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (*(int *)(param_1 + 0xa54) != 0) {
    FUN_4200dac4();
    *(undefined4 *)(param_1 + 0xa54) = 0;
  }
  return iVar3;
}