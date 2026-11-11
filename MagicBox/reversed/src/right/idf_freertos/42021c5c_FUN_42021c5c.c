// strings: Balloc succeeded | /builds/idf/crosstool-NG/.build/xtensa-esp-elf/s

void FUN_42021c5c(undefined4 param_1,int param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  
  iVar1 = FUN_42021c20(param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = FUN_42021628(param_1,0);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x10) = 1;
      *(undefined4 *)(iVar1 + 0x14) = 0;
      return;
    }
    uVar8 = 0x237;
    iVar1 = 0;
  }
  else {
    iVar2 = param_2;
    if (iVar1 < 0) {
      iVar2 = param_3;
      param_3 = param_2;
    }
    param_2 = iVar2;
    param_5 = (uint)(iVar1 < 0);
    iVar1 = FUN_42021628(param_1,*(undefined4 *)(param_2 + 4));
    iVar2 = iVar1;
    if (iVar1 != 0) goto LAB_42021cb2;
    uVar8 = 0x245;
  }
  iVar2 = (*(code *)PTR_FUN_42000044)
                    (PTR_s__builds_idf_crosstool_NG__build__4200130c,uVar8,0,
                     PTR_s_Balloc_succeeded_42001314);
LAB_42021cb2:
  *(uint *)(iVar2 + 0xc) = param_5;
  iVar7 = *(int *)(param_3 + 0x10);
  iVar13 = *(int *)(param_2 + 0x10);
  iVar12 = param_2 + 0x14;
  puVar11 = (uint *)(iVar13 * 4 + iVar12);
  uVar9 = (*(uint *)(param_2 + 0x14) & 0xffff) - (*(uint *)(param_3 + 0x14) & 0xffff);
  iVar2 = ((*(uint *)(param_2 + 0x14) >> 0x10) - (*(uint *)(param_3 + 0x14) >> 0x10)) +
          ((int)uVar9 >> 0x10);
  *(uint *)(iVar1 + 0x14) = uVar9 & 0xffff | iVar2 * 0x10000;
  iVar5 = 0;
  if ((-(param_3 + 0x14) & 0xffU) != 0) {
    iVar5 = iVar7 * 4 + -4;
  }
  puVar10 = (uint *)(iVar12 + iVar5 + 4);
  puVar4 = puVar10;
  while( true ) {
    iVar7 = iVar2 >> 0x10;
    puVar3 = (uint *)((int)puVar4 + ((iVar1 + 0x14) - iVar12));
    if (puVar11 <= puVar4) break;
    uVar9 = *puVar4;
    iVar2 = ((int)((uVar9 & 0xffff) + iVar7) >> 0x10) + (uVar9 >> 0x10);
    puVar4 = puVar4 + 1;
    *puVar3 = uVar9 + iVar7 & 0xffff | iVar2 * 0x10000;
  }
  uVar9 = 0;
  if ((-(iVar12 + iVar5) & 0xffU) != 0) {
    uVar9 = (int)puVar11 + (3 - (int)puVar10) & 0xfffffffc;
  }
  piVar6 = (int *)(uVar9 + iVar1 + 0x14 + iVar5 + 4);
  while (piVar6 = piVar6 + -1, *piVar6 == 0) {
    iVar13 = iVar13 + -1;
  }
  *(int *)(iVar1 + 0x10) = iVar13;
  return;
}