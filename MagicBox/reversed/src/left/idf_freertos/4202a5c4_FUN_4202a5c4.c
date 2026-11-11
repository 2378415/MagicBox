// strings: Balloc succeeded | `V YB

void FUN_4202a5c4(undefined4 param_1,int param_2,undefined *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  undefined4 *in_t0;
  ulonglong uVar12;
  
  iVar1 = (int)param_3 >> 5;
  iVar3 = iVar1 + *(int *)(param_2 + 0x10);
  iVar10 = *(int *)(param_2 + 4);
  iVar2 = iVar3 + 1;
  for (iVar4 = *(int *)(param_2 + 8); iVar4 < iVar2; iVar4 = iVar4 * 2) {
    iVar10 = iVar10 + 1;
  }
  iVar4 = FUN_4202a0d4(param_1,iVar10);
  puVar9 = (undefined4 *)(iVar4 + 0x14);
  puVar5 = (undefined4 *)0x0;
  uVar12 = ZEXT48(puVar9);
  if (iVar4 != 0) goto LAB_4202a611;
  param_3 = PTR_s_Balloc_succeeded_42001dc0;
  puVar5 = in_t0;
  uVar12 = (*(code *)PTR_FUN_420000a8)(PTR_s__builds_idf_crosstool_NG__build__42001db8,0x1de,0);
  puVar9 = puVar5;
  do {
    *puVar9 = (int)(uVar12 >> 0x20);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar9 = puVar9 + 1;
LAB_4202a611:
  } while ((int)puVar5 < iVar1);
  iVar10 = *(int *)(param_2 + 0x10);
  puVar8 = (uint *)((int)uVar12 + (uint)(-1 < iVar1) * iVar1 * 4);
  puVar6 = (uint *)(param_2 + 0x14);
  if (((uint)param_3 & 0x1f) == 0) {
    *puVar8 = *puVar6;
  }
  else {
    *puVar8 = *puVar6 << 0x20 - (0x20 - ((uint)param_3 & 0x1f));
    uVar11 = *puVar6 >> (-(((uint)param_3 & 0x1f) - 0x20) & 0x1f);
    uVar7 = 0;
    if ((-(param_2 + 0x14) & 0xffU) != 0) {
      uVar7 = (int)(puVar6 + iVar10) - (param_2 + 0x15) & 0xfffffffc;
    }
    *(uint *)((int)puVar8 + uVar7 + 4) = uVar11;
    if (uVar11 != 0) goto LAB_4202a6c0;
  }
  iVar2 = iVar3;
LAB_4202a6c0:
  *(int *)(iVar4 + 0x10) = iVar2;
  FUN_4202a15c(param_1,param_2);
  return;
}