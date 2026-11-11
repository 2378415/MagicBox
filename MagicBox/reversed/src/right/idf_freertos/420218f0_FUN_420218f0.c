// strings: Balloc succeeded | /builds/idf/crosstool-NG/.build/xtensa-esp-elf/s

int FUN_420218f0(undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int extraout_a3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  uint *puVar16;
  uint *in_t0;
  uint uStack_2c;
  int iStack_28;
  
  iVar6 = *(int *)(param_2 + 0x10);
  iVar4 = *(int *)(param_3 + 0x10);
  iVar2 = param_2;
  iVar5 = iVar4;
  if (iVar4 <= iVar6) {
    iVar2 = param_3;
    param_3 = param_2;
    iVar5 = iVar6;
    iVar6 = iVar4;
  }
  iVar4 = iVar5 + iVar6;
  iVar10 = *(int *)(param_3 + 4);
  if (*(int *)(param_3 + 8) < iVar4) {
    iVar10 = iVar10 + 1;
  }
  iVar10 = FUN_42021628(param_1,iVar10);
  if (iVar10 == 0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s__builds_idf_crosstool_NG__build__4200130c,0x162,0,
               PTR_s_Balloc_succeeded_42001314);
  }
  piVar11 = (int *)(iVar10 + 0x14);
  piVar1 = piVar11 + iVar4;
  for (; piVar11 < piVar1; piVar11 = piVar11 + 1) {
    *piVar11 = 0;
  }
  uVar3 = iVar2 + 0x14;
  uVar7 = iVar6 * 4 + uVar3;
  puVar12 = (uint *)(param_3 + 0x14);
  uStack_2c = 0;
  if ((-(param_3 + 0x14) & 0xffU) != 0) {
    uStack_2c = (int)puVar12 + (iVar5 * 4 - (param_3 + 0x15)) & 0xfffffffc;
  }
  for (; uVar3 < uVar7; uVar3 = uVar3 + 4) {
    func_0x42071a80();
    cust0();
    *in_t0 = (uint)in_t0;
    uVar8 = (*puVar12 & 0xffff) * ((uint)in_t0 & 0xffff) + (*in_t0 & 0xffff);
    uVar13 = (*puVar12 >> 0x10) * ((uint)in_t0 & 0xffff) + (*in_t0 >> 0x10) + (uVar8 >> 0x10);
    *in_t0 = uVar13 * 0x10000 | uVar8 & 0xffff;
    *(uint *)((int)in_t0 + uStack_2c + 4) = uVar13 >> 0x10;
    uVar8 = (uint)*(ushort *)(uVar3 + 2);
    if (uVar8 != 0) {
      iStack_28 = ((int)in_t0 + ((uint)puVar12 ^ 0xffffffff) >> 2) + 1;
      uVar9 = *in_t0;
      uVar13 = 0;
      puVar15 = in_t0;
      puVar16 = puVar12;
      if (((uint *)((int)in_t0 + 3) < puVar12 + 1) || (uVar14 = uVar9, in_t0 == (uint *)0x0)) {
        iStack_28 = 1;
        uVar14 = uVar9;
      }
      do {
        uVar13 = (*puVar16 & 0xffff) * uVar8 + uVar13 + (uVar14 >> 0x10);
        *puVar15 = uVar13 * 0x10000 | uVar9 & 0xffff;
        uVar14 = puVar15[1];
        uVar9 = *(ushort *)((int)puVar16 + 2) * uVar8 + (uVar14 & 0xffff) + (uVar13 >> 0x10);
        uVar13 = uVar9 >> 0x10;
        puVar16 = puVar16 + 1;
        puVar15 = puVar15 + 1;
        iStack_28 = iStack_28 + -1;
      } while (iStack_28 != 0);
      *(uint *)((int)in_t0 + uStack_2c + 4) = uVar9;
    }
    iVar4 = extraout_a3;
  }
  while ((0 < iVar4 && (piVar1 = piVar1 + -1, *piVar1 == 0))) {
    iVar4 = iVar4 + -1;
  }
  *(int *)(iVar10 + 0x10) = iVar4;
  return iVar10;
}