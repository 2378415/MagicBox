undefined4
FUN_4200b708(undefined4 param_1,uint *param_2,uint *param_3,undefined4 *param_4,undefined4 param_5,
            undefined4 param_6,int *param_7)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  
  *param_7 = 0;
  iVar3 = FUN_4200bc70();
  if (iVar3 == 0) {
    return 0x103;
  }
  puVar4 = (undefined4 *)(*(code *)PTR_FUN_42000660)(0x2c,DAT_42000988);
  if (puVar4 == (undefined4 *)0x0) {
    return 0x101;
  }
  uVar5 = param_2[1];
  puVar4[5] = *param_2;
  puVar4[6] = uVar5;
  uVar5 = param_3[1];
  puVar4[7] = *param_3;
  puVar4[8] = uVar5;
  uVar8 = *param_4;
  uVar6 = param_4[1];
  *puVar4 = param_5;
  puVar4[4] = param_4;
  puVar4[1] = param_6;
  puVar4[9] = uVar8;
  puVar4[10] = uVar6;
  puVar4[2] = param_2;
  puVar4[3] = param_3;
  param_2[1] = 0;
  *param_2 = 0;
  param_3[1] = 0;
  *param_3 = 0;
  puVar1 = PTR_DAT_42000bf4;
  param_4[1] = 0;
  *param_4 = 0;
  (*(code *)PTR_FUN_420004dc)(puVar1,0xffffffff);
  piVar2 = DAT_42000bf8;
  iVar7 = *DAT_42000bf8;
  iVar3 = (*(code *)PTR_FUN_42000990)(*DAT_42000bfc,(iVar7 + 1) * 4,DAT_42000988);
  if (iVar3 == 0) {
    (*(code *)PTR_FUN_420004e0)(PTR_DAT_42000bf4);
    (*(code *)PTR_FUN_42000570)(puVar4);
    return 0x101;
  }
  iVar9 = *piVar2;
  if (iVar9 == 0) {
    FUN_4200bc80(PTR_FUN_42000c00);
    iVar9 = *piVar2;
  }
  puVar1 = PTR_DAT_42000bf4;
  *DAT_42000bfc = iVar3;
  *(undefined4 **)(iVar9 * 4 + iVar3) = puVar4;
  *piVar2 = iVar7 + 1;
  (*(code *)PTR_FUN_420004e0)(puVar1);
  if (((puVar4[5] & 1) == 0) || (iVar3 = FUN_4200bc90(), iVar3 == 0)) {
    if (((puVar4[7] & 1) == 0) || (iVar3 = FUN_4200bcb8(), iVar3 == 0)) goto LAB_4200b80e;
LAB_4200b7f2:
    *param_3 = *param_3 | 1;
  }
  else {
    *param_2 = *param_2 | 1;
    if (((puVar4[7] & 1) != 0) && (iVar3 = FUN_4200bcb8(), iVar3 != 0)) goto LAB_4200b7f2;
  }
  FUN_4200c758(*puVar4,puVar4[1]);
LAB_4200b80e:
  *param_7 = (int)puVar4;
  return 0;
}