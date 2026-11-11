// 4200fab4  FUN_4200fab4  FUN_4200fab4  size=507
// strings: 'jJ'j9

void FUN_4200fab4(int param_1,char *param_2)

{
  undefined *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  short sVar11;
  uint uVar12;
  char local_40 [16];
  int *piStack_30;
  int *piStack_2c;
  
  puVar1 = PTR_DAT_42000e50;
  if (*(char *)(*(int *)(param_2 + 0x210) + 0x1d6) != *(char *)(param_1 + 2)) {
    return;
  }
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000e50,0xffffffff);
  iVar6 = param_1 + 4;
  (*DAT_42000064)(param_2 + 0x52e,iVar6,*(undefined1 *)(param_1 + 2));
  *(uint *)(param_2 + 0x630) = (uint)*(byte *)(param_1 + 2);
  (*(code *)PTR_FUN_420004e0)(puVar1);
  memw();
  memw();
  param_2[0x52d] = '\x01';
  memw();
  memw();
  memw();
  *DAT_42000e04 = 1;
  memw();
  memw();
  *DAT_42000dc0 = param_2;
  memw();
  memw();
  *DAT_42000e4c = 0;
  memw();
  if ((*param_2 != '\0') && (piVar5 = *(int **)(param_2 + 0x210), piVar5 != (int *)0x0)) {
    piStack_30 = piVar5 + 0x40;
    uVar7 = (uint)*(byte *)(param_1 + 2);
    if (uVar7 == *(byte *)((int)piVar5 + 0x1d6)) {
      iVar4 = 0;
      if (param_2[0x20c] != '\0') {
        if ((uVar7 != 0) && (*(char *)(param_1 + 4) != *(char *)((int)piVar5 + 0x1d5)))
        goto LAB_4200fc9a;
        iVar4 = 8;
      }
      local_40[0] = '\0';
      uVar7 = uVar7 << 3;
      uVar8 = iVar4 + *piVar5;
      uVar12 = 0;
      if (uVar8 < uVar7) {
        uVar8 = (int)(uint)*(byte *)(iVar6 + (uVar8 >> 3)) >> (uVar8 & 7);
        uVar12 = uVar8 & 1;
        if ((uVar8 & 1) != 0) {
          local_40[0] = '\x01';
          uVar12 = 1;
        }
      }
      piVar5[0x4a] = uVar12;
      piVar5[0x39] = uVar12;
      memw();
      memw();
      memw();
      if (*DAT_42000e8c != '\0') {
        memw();
        memw();
        memw();
        if (*DAT_42000e90 != local_40[0]) {
          memw();
          memw();
          *DAT_42000e90 = local_40[0];
          memw();
          FUN_420143e8(local_40,1,0,5,1);
        }
      }
      iVar3 = piVar5[0x6e];
      piVar10 = (int *)0x0;
      if (iVar4 + piVar5[0x6c] + (uint)*(byte *)(piStack_30 + 0x2d) <= uVar7) {
        uVar12 = FUN_4202d090(iVar6);
        piVar10 = (int *)(uVar12 & 0xffff);
      }
      piVar9 = (int *)0x0;
      if (iVar4 + iVar3 + (uint)*(byte *)(piStack_30 + 0x2f) <= uVar7) {
        piStack_2c = piVar10;
        uVar12 = FUN_4202d090(iVar6,iVar4 + iVar3);
        piVar9 = (int *)(uVar12 & 0xffff);
        piVar10 = piStack_2c;
      }
      sVar11 = 0;
      if (*(byte *)(piStack_30 + 0x31) != 0) {
        if (iVar4 + piVar5[0x70] + (uint)*(byte *)(piStack_30 + 0x31) <= uVar7) {
          piStack_30 = piVar10;
          piStack_2c = piVar9;
          cVar2 = FUN_4202d090(iVar6);
          sVar11 = (short)cVar2;
          piVar9 = piStack_2c;
          piVar10 = piStack_30;
        }
      }
      memw();
      memw();
      *DAT_42000e94 = (short)piVar10;
      memw();
      memw();
      memw();
      *DAT_42000e98 = (short)piVar9;
      memw();
      memw();
      memw();
      *DAT_42000e9c = sVar11;
      memw();
      memw();
      memw();
      *DAT_42000e4c = 0;
      memw();
    }
  }
LAB_4200fc9a:
  if (*DAT_42000e08 != 0) {
    (*(code *)PTR_FUN_42000484)(*DAT_42000e08,0,0,2);
  }
  return;
}


