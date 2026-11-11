// 4037850c  esp_flash_erase_region  FUN_4037850c  size=537
// strings: len_remain < len | (q8a | esp_flash_api.c | esp_flash_erase_region

int FUN_4037850c(int param_1,uint param_2,uint param_3)

{
  undefined *puVar1;
  int iVar2;
  int extraout_a3;
  uint uVar3;
  code *pcVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  uint local_50;
  uint uStack_4c;
  int iStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  
  puVar1 = PTR_PTR_403748f8;
  iStack_40 = param_1;
  iVar2 = (**(code **)(*(int *)PTR_PTR_403748f8 + 8))(&iStack_40);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = *(int *)(iStack_40 + 4);
  if ((*(int *)(iVar2 + 0x18) == 0) || (*(int *)(iVar2 + 0x1c) == 0)) {
    return DAT_40374914;
  }
  pcVar4 = *(code **)(*(int *)(iStack_40 + 8) + 8);
  if (pcVar4 == (code *)0x0) {
LAB_40378562:
    uStack_38 = *(uint *)(iVar2 + 0x20);
    if ((uStack_38 == 0) || (uStack_3c = *(uint *)(iVar2 + 0x24), uStack_3c % uStack_38 != 0)) {
      return DAT_403748fc;
    }
  }
  else {
    iVar2 = (*pcVar4)(*(undefined4 *)(iStack_40 + 0xc),param_2,param_3);
    if (iVar2 == 0x10d) {
      return 0x10d;
    }
    if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_40381c60();
    }
    iVar2 = *(int *)(iStack_40 + 4);
    if (*(int *)(iVar2 + 0x1c) != 0) goto LAB_40378562;
    uStack_38 = *(uint *)(iVar2 + 0x20);
    uStack_3c = 0;
    if (uStack_38 == 0) {
      return DAT_403748fc;
    }
  }
  if ((((*(uint *)(iStack_40 + 0x14) < param_2) || (*(uint *)(iStack_40 + 0x14) < param_2 + param_3)
       ) || (param_2 % uStack_38 != 0)) || (param_3 % uStack_38 != 0)) {
    return 0x102;
  }
  if (param_3 == 0) {
    return 0;
  }
  uVar7 = uStack_38;
  uVar8 = uStack_3c;
  if ((*(int *)(iVar2 + 0x38) == 0) || (*(char *)(iVar2 + 0x30) == '\0')) {
LAB_40378594:
    uVar6 = uVar8 - 1;
    uStack_34 = 0;
    uVar3 = param_3;
    uStack_3c = uVar6;
    uStack_38 = param_2;
    while( true ) {
      pcVar4 = *(code **)(*(int *)(iStack_40 + 4) + 0x68);
      if (pcVar4 != (code *)0x0) {
        uVar9 = (*pcVar4)(iStack_40,0);
        uVar6 = (uint)((ulonglong)uVar9 >> 0x20);
        if ((int)uVar9 != 0) {
          return (int)uVar9;
        }
      }
      iVar2 = (*(code *)**(undefined4 **)puVar1)(iStack_40,uVar6);
      if (iVar2 != 0) break;
      if ((uStack_3c < uVar3) && (param_2 % uVar8 == 0)) {
        iVar2 = (**(code **)(*(int *)(iStack_40 + 4) + 0x1c))(iStack_40,param_2);
        uVar6 = uVar8;
      }
      else {
        iVar2 = (**(code **)(*(int *)(iStack_40 + 4) + 0x18))(iStack_40,param_2);
        uVar6 = uVar7;
      }
      uVar3 = uVar3 - uVar6;
      param_2 = param_2 + uVar6;
      if (param_3 <= uVar3) {
        FUN_40381ce4(PTR_s_esp_flash_api_c_3c03a5d8_0x1b_40374940,0x2a9,
                     PTR_s_esp_flash_erase_region_4037493c,PTR_s_len_remain_<_len_40374938);
        iVar2 = extraout_a3;
      }
      if (((iVar2 != 0) || (uVar3 == 0)) ||
         (iVar2 = (**(code **)(*(int *)puVar1 + 4))(iStack_40), iVar2 != 0)) {
        uVar7 = 1;
LAB_40378705:
        iVar2 = (**(code **)(*(int *)puVar1 + 0xc))(iStack_40,iVar2,uVar7,uStack_38,param_3);
        return iVar2;
      }
      uVar6 = 0;
    }
    uVar7 = uStack_34;
    goto LAB_40378705;
  }
  iVar2 = (*(code *)**(undefined4 **)puVar1)();
  if (iVar2 == 0) {
    local_50 = 0;
    uStack_4c = 0;
    iVar2 = (**(code **)(*(int *)(iStack_40 + 4) + 0x38))(iStack_40,&local_50);
    if ((iVar2 == 0) && (local_50 != 0 || uStack_4c != 0)) {
      uVar7 = (uint)*(byte *)(*(int *)(iStack_40 + 4) + 0x30);
      if (uVar7 != 0) {
        puVar5 = *(uint **)(*(int *)(iStack_40 + 4) + 0x34);
        iStack_30 = uStack_4c * 2;
        uStack_34 = uStack_38;
        uVar8 = 0;
        do {
          uVar6 = iStack_30 << 0x20 - (0x20 - ((uVar8 ^ 0xffffffff) & 0x1f)) |
                  local_50 >> (uVar8 & 0x1f);
          if ((uVar8 & 0x20) != 0) {
            uVar6 = uStack_4c >> (uVar8 & 0x1f);
          }
          uStack_2c = 0;
          if ((((uVar6 & 1) != 0) && (param_2 < *puVar5 + puVar5[1])) &&
             (*puVar5 < param_2 + param_3)) {
            iVar2 = DAT_40374934;
            goto LAB_4037865d;
          }
          uVar8 = uVar8 + 1;
          puVar5 = puVar5 + 2;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
    }
LAB_4037865d:
    iVar2 = (**(code **)(*(int *)puVar1 + 4))(iStack_40,iVar2);
    uVar7 = uStack_38;
    uVar8 = uStack_3c;
    if (iVar2 == 0) goto LAB_40378594;
  }
  return iVar2;
}


