// 40377f28  esp_flash_erase_region  size=506
// strings: len_remain < len | esp_flash_api.c | esp_flash_erase_region | ||7@0Z

/* WARNING: Control flow encountered bad instruction data */

int esp_flash_erase_region(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  uint uVar8;
  undefined1 uVar9;
  uint local_40;
  uint uStack_3c;
  int iStack_30;
  uint uStack_2c;
  
  iStack_30 = param_1;
  iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 8))(&iStack_30);
  if (iVar2 == 0) {
    if (*(int *)(*(int *)(iStack_30 + 4) + 0x18) == 0) {
      iVar2 = DAT_4037488c;
    }
    else if (*(int *)(*(int *)(iStack_30 + 4) + 0x1c) == 0) {
      iVar2 = DAT_4037488c;
    }
    else {
      if ((iStack_30 != 0) &&
         (pcVar7 = *(code **)(*(int *)(iStack_30 + 8) + 8), pcVar7 != (code *)0x0)) {
        iVar3 = (*pcVar7)(*(undefined4 *)(iStack_30 + 0xc),param_2,param_3);
        if (iVar3 == 0x10d) {
          return 0x10d;
        }
        if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_40381ce0();
        }
      }
      iVar3 = *(int *)(iStack_30 + 4);
      if (*(int *)(iVar3 + 0x1c) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(uint *)(iVar3 + 0x24);
      }
      uVar6 = *(uint *)(iVar3 + 0x20);
      if (uVar6 == 0) {
        iVar2 = DAT_40374880;
      }
      else if (uVar5 % uVar6 == 0) {
        if (*(uint *)(iStack_30 + 0x14) < param_2) {
          iVar2 = 0x102;
        }
        else if (*(uint *)(iStack_30 + 0x14) < param_2 + param_3) {
          iVar2 = 0x102;
        }
        else if (param_2 % uVar6 == 0) {
          if (param_3 % uVar6 == 0) {
            if (param_3 != 0) {
              if ((*(int *)(iVar3 + 0x38) != 0) && (*(char *)(iVar3 + 0x30) != '\0')) {
                iVar2 = (*(code *)**(undefined4 **)PTR_PTR_4037487c)();
                if (iVar2 != 0) {
                  return iVar2;
                }
                local_40 = 0;
                uStack_3c = 0;
                iVar2 = (**(code **)(*(int *)(iStack_30 + 4) + 0x38))(iStack_30,&local_40);
                if ((iVar2 == 0) && (local_40 != 0 || uStack_3c != 0)) {
                  for (uVar4 = 0; (int)uVar4 < (int)(uint)*(byte *)(*(int *)(iStack_30 + 4) + 0x30);
                      uVar4 = uVar4 + 1) {
                    uVar8 = uStack_3c * 2 << 0x20 - (0x20 - ((uVar4 ^ 0xffffffff) & 0x1f)) |
                            local_40 >> (uVar4 & 0x1f);
                    if ((uVar4 & 0x20) != 0) {
                      uVar8 = uStack_3c >> (uVar4 & 0x1f);
                    }
                    if ((uVar8 & 1) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
                      halt_baddata();
                    }
                  }
                }
                iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 4))(iStack_30);
              }
              if (iVar2 == 0) {
                uVar4 = param_3;
                uStack_2c = param_2;
                do {
                  pcVar7 = *(code **)(*(int *)(iStack_30 + 4) + 0x68);
                  if ((pcVar7 != (code *)0x0) && (iVar2 = (*pcVar7)(iStack_30,0), iVar2 != 0)) {
                    return iVar2;
                  }
                  iVar2 = (*(code *)**(undefined4 **)PTR_PTR_4037487c)(iStack_30);
                  uVar8 = uStack_2c;
                  if (iVar2 != 0) {
                    uVar9 = 0;
                    goto LAB_403780e8;
                  }
                  if ((uVar5 - 1 < uVar4) && (uStack_2c % uVar5 == 0)) {
                    iVar2 = (**(code **)(*(int *)(iStack_30 + 4) + 0x1c))(iStack_30,uStack_2c);
                    uVar1 = uVar5;
                  }
                  else {
                    iVar2 = (**(code **)(*(int *)(iStack_30 + 4) + 0x18))(iStack_30,uStack_2c);
                    uVar1 = uVar6;
                  }
                  uStack_2c = uVar8 + uVar1;
                  uVar4 = uVar4 - uVar1;
                  if (param_3 <= uVar4) {
                    /* WARNING: Subroutine does not return */
                    FUN_40381d9c(PTR_s_esp_flash_api_c_3c034314_0x1b_403748a4,0x2a9,
                                 PTR_s_esp_flash_erase_region_403748a0,
                                 PTR_s_len_remain_<_len_4037489c);
                  }
                  uVar9 = 1;
                  if (iVar2 != 0 || uVar4 == 0) goto LAB_403780e8;
                  iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 4))(iStack_30,0);
                } while (iVar2 == 0);
                uVar9 = 1;
LAB_403780e8:
                iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 0xc))
                                  (iStack_30,iVar2,uVar9,param_2,param_3);
              }
            }
          }
          else {
            iVar2 = 0x102;
          }
        }
        else {
          iVar2 = 0x102;
        }
      }
      else {
        iVar2 = DAT_40374880;
      }
    }
  }
  return iVar2;
}


