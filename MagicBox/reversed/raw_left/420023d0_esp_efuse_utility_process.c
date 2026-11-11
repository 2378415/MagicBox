// 420023d0  esp_efuse_utility_process  FUN_420023d0  size=133

uint FUN_420023d0(undefined4 *param_1,undefined4 param_2,uint param_3,code *param_4)

{
  byte bVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int extraout_a3;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int aiStack_50 [4];
  uint uStack_40;
  int iStack_3c;
  code *pcStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  aiStack_50[0] = 0;
  pcStack_38 = param_4;
  uStack_34 = param_2;
  uVar3 = FUN_4202cdf0(param_1);
  puVar2 = PTR_DAT_42000028;
  if (param_3 != 0) {
    uVar3 = (uVar3 < param_3) * uVar3 + (uVar3 >= param_3) * param_3;
  }
  memw();
  uVar7 = *DAT_420000e4;
  puVar8 = (undefined1 *)*param_1;
  iVar12 = aiStack_50[0];
  if ((aiStack_50[0] < (int)uVar3) && (puVar8 != (undefined1 *)0x0)) {
    uVar6 = param_3;
    uStack_2c = uVar7;
    do {
      while( true ) {
        bVar1 = puVar8[1];
        uVar7 = (uint)*(ushort *)(puVar8 + 2) + (uint)bVar1;
        if (0x100 < uVar7) {
          if (*(int *)PTR_DAT_42000028 != 0) {
            uVar4 = (*(code *)PTR_FUN_4200005c)();
            (*DAT_42000060)(PTR_DAT_420000ec,uVar4,PTR_s_efuse_420000e8);
            iVar12 = aiStack_50[0];
          }
          memw();
          uVar5 = DAT_420000e0;
          goto LAB_42002524;
        }
        iVar9 = uVar7 - 1;
        iVar10 = uVar7 + 0x1e;
        if (-1 < iVar9) {
          iVar10 = iVar9;
        }
        uVar6 = (uint)(bVar1 >> 5);
        uVar5 = iVar10 >> 5;
        uVar7 = bVar1 & 0x1f;
        if ((int)uVar5 < (int)uVar6) break;
        uStack_30 = uVar5 + 1;
        iStack_3c = iVar9 % 0x20;
        uStack_40 = uVar5;
        do {
          iVar10 = 0x1f;
          if (uStack_40 == uVar6) {
            iVar10 = iStack_3c;
          }
          iVar10 = (iVar10 - uVar7) + 1;
          if ((int)uVar3 < iVar10 + iVar12) {
            iVar10 = uVar3 - iVar12;
          }
          if (3 < *(uint *)puVar2) {
            uVar4 = (*(code *)PTR_FUN_4200005c)();
            (*DAT_42000060)(PTR_DAT_420000f0,uVar4,PTR_s_efuse_420000e8,*puVar8,uVar6,uVar7,
                            iVar10 + uVar7 + -1,iVar10);
          }
          uVar5 = (*pcStack_38)(uVar6,*puVar8,uVar7,iVar10,uStack_34,aiStack_50);
          iVar12 = aiStack_50[0];
          if (uVar5 != 0) {
            memw();
            uVar6 = uVar3;
            goto LAB_42002524;
          }
          param_3 = uVar3;
          uVar7 = uStack_2c;
          if ((int)uVar3 <= aiStack_50[0]) goto LAB_420024f1;
          uVar6 = uVar6 + 1;
          uVar7 = 0;
        } while (uVar6 != uStack_30);
        puVar8 = puVar8 + 4;
        uVar6 = uVar3;
      }
      puVar8 = puVar8 + 4;
      param_3 = uVar6;
      uVar7 = uStack_2c;
    } while (iVar12 < (int)uVar3);
  }
LAB_420024f1:
  do {
    memw();
    uVar6 = param_3;
    if (pcStack_38 == (code *)PTR_FUN_4200008c) {
LAB_42002515:
      uVar5 = DAT_42000090;
      if ((*DAT_420000e4 == uVar7) && ((*DAT_420000e4 & 1) == 0)) {
        uVar5 = 0;
      }
    }
    else {
      uVar11 = 1;
      if (pcStack_38 != (code *)PTR_FUN_420000f4) {
        uVar11 = (uint)(pcStack_38 == (code *)PTR_FUN_4200008c);
      }
      uVar5 = (uint)(pcStack_38 == (code *)PTR_FUN_4200008c);
      if (uVar11 != 0) goto LAB_42002515;
    }
LAB_42002524:
    if (iVar12 <= (int)uVar3) {
      return uVar5;
    }
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_esp_efuse_utility_c_3c03036c_0x1b_420000c8,0x54,
               PTR_s_esp_efuse_utility_process_420000fc,PTR_s_bits_counter_<__req_size_420000f8);
    uVar3 = uVar6;
    param_3 = uVar6;
    uVar7 = uStack_2c;
    iVar12 = extraout_a3;
  } while( true );
}


