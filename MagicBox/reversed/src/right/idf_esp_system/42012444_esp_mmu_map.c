// strings: 8a7@ | found | esp_mmu_map.c | esp_mmu_map | pw7@\x7@

int FUN_42012444(uint param_1,int param_2,uint param_3,uint param_4,uint param_5,uint *param_6)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int *extraout_a3;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  undefined4 uVar11;
  int *piVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined4 *puStack_28;
  undefined4 *puStack_24;
  
  if (param_6 == (uint *)0x0) {
    return 0x102;
  }
  if ((param_1 & 0xffff) != 0) {
    return 0x102;
  }
  iVar3 = FUN_4202498c(param_4);
  if (iVar3 != 0) {
    return iVar3;
  }
  uVar1 = (uint)(param_2 + DAT_42000a78) >> 0x10;
  uVar5 = uVar1 * 0x10000;
  iVar3 = FUN_420249a8(DAT_42000ec4,*DAT_42000ebc,uVar5,param_4,param_3);
  if (iVar3 == -1) {
    return 0x105;
  }
  if (DAT_42000ebc[iVar3 * 10 + 9] == 0) {
    puStack_28 = (undefined4 *)(*(code *)PTR_FUN_420008b8)(1,0x2c,DAT_42000424);
    puVar2 = DAT_42000ebc;
    if (puStack_28 == (undefined4 *)0x0) goto LAB_4201269a;
    uVar11 = DAT_42000ebc[iVar3 * 10 + 5];
    *puStack_28 = uVar11;
    puStack_28[1] = uVar11;
    puStack_28[4] = 0;
    puStack_28[5] = param_4;
    iVar8 = puVar2[iVar3 * 10 + 9];
    puStack_28[9] = iVar8;
    if (iVar8 == 0) {
      DAT_42000ebc[iVar3 * 10 + 10] = puStack_28 + 9;
    }
    else {
      *(undefined4 **)(iVar8 + 0x28) = puStack_28 + 9;
    }
    puVar2 = DAT_42000ebc;
    DAT_42000ebc[iVar3 * 10 + 9] = puStack_28;
    puStack_28[10] = puVar2 + iVar3 * 10 + 9;
    puStack_24 = (undefined4 *)(*(code *)PTR_FUN_420008b8)(1,0x2c,DAT_42000424);
    puVar2 = DAT_42000ebc;
    if (puStack_24 == (undefined4 *)0x0) goto LAB_4201269a;
    uVar11 = DAT_42000ebc[iVar3 * 10 + 3];
    *puStack_24 = uVar11;
    puStack_24[1] = uVar11;
    puStack_24[4] = 0;
    puStack_24[5] = param_4;
    puStack_24[9] = 0;
    piVar12 = (int *)puVar2[iVar3 * 10 + 10];
    puStack_24[10] = piVar12;
    *piVar12 = (int)puStack_24;
    puVar2[iVar3 * 10 + 10] = puStack_24 + 9;
  }
  else {
    puStack_24 = (undefined4 *)0x0;
    puStack_28 = (undefined4 *)0x0;
  }
  for (iVar8 = DAT_42000ebc[iVar3 * 10 + 9]; iVar8 != 0; iVar8 = *(int *)(iVar8 + 0x24)) {
    if (*(uint *)(iVar8 + 0x20) == param_3) {
      uVar6 = *(undefined4 *)(iVar8 + 0x18);
      uVar11 = *(undefined4 *)(iVar8 + 0x1c);
      iVar15 = FUN_420249d4(uVar6,uVar11,param_1,uVar5);
      if (iVar15 != 0) {
        uVar9 = 0;
        goto LAB_4201259f;
      }
      if (((param_5 & 1) == 0) && (uVar9 = FUN_420249f4(uVar6,uVar11,param_1,uVar5), uVar9 != 0)) {
        iVar15 = 0;
        goto LAB_4201259f;
      }
    }
  }
  uVar9 = 0;
  iVar15 = 0;
LAB_4201259f:
  if (iVar15 != 0) {
    *param_6 = *(int *)(iVar8 + 8) + (param_1 - *(int *)(iVar8 + 0x18));
    return 0x103;
  }
  uVar13 = param_5 & 1 ^ 1;
  uVar7 = uVar13 & uVar9;
  if ((uVar13 & uVar9) != 0) {
    return 0x102;
  }
  puVar4 = (uint *)(*(code *)PTR_FUN_420008b8)(1,0x2c,DAT_42000424);
  if (puVar4 != (uint *)0x0) {
    piVar10 = (int *)DAT_42000ebc[iVar3 * 10 + 9];
    uVar13 = piVar10[1];
    piVar12 = (int *)0x0;
    uVar9 = 0;
    for (; piVar10 != (int *)0x0; piVar10 = (int *)piVar10[9]) {
      uVar14 = *piVar10 - uVar13;
      if ((uVar7 == 0) && (uVar5 <= uVar14)) {
        uVar14 = uVar14 + uVar1 * -0x10000;
        *puVar4 = uVar13;
        uVar7 = 1;
        piVar12 = piVar10;
      }
      uVar9 = (uVar9 < uVar14) * uVar14 + (uVar9 >= uVar14) * uVar9;
      uVar13 = piVar10[1];
    }
    if (uVar7 == 0) {
      (*(code *)PTR_FUN_42000044)
                (PTR_s_esp_mmu_map_c_3c034030_0x18_42000e9c,0x228,PTR_s_esp_mmu_map_42000ecc,
                 PTR_s_found_42000ec8);
      piVar12 = extraout_a3;
    }
    puVar4[10] = piVar12[10];
    puVar4[9] = (uint)piVar12;
    *(uint **)piVar12[10] = puVar4;
    piVar12[10] = (int)(puVar4 + 9);
    DAT_42000ebc[iVar3 * 10 + 6] = uVar9;
    uVar13 = *puVar4;
    uVar7 = uVar5 + uVar13;
    puVar4[1] = uVar7;
    puVar4[4] = uVar5;
    puVar4[5] = param_4;
    puVar4[6] = param_1;
    puVar4[7] = uVar5 + param_1;
    puVar4[8] = param_3;
    uVar9 = DAT_42000ed4;
    uVar1 = DAT_42000ed0;
    if ((param_4 & 1) == 0) {
      puVar4[2] = uVar13 | DAT_42000ed4;
      puVar4[3] = uVar7 | uVar9;
    }
    else {
      puVar4[2] = uVar13 | DAT_42000ed0;
      puVar4[3] = uVar7 | uVar1;
    }
    (*(code *)PTR_FUN_42000ed8)(param_3,puVar4[2],param_1,uVar5);
    *param_6 = puVar4[2];
    return 0;
  }
  if (puStack_24 != (undefined4 *)0x0) {
    (*(code *)PTR_FUN_420004c0)(puStack_24);
  }
LAB_4201269a:
  if (puStack_28 != (undefined4 *)0x0) {
    (*(code *)PTR_FUN_420004c0)();
  }
  return 0x101;
}