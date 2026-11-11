// 42002ee0  FUN_42002ee0  FUN_42002ee0  size=330

void FUN_42002ee0(void)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  iVar5 = (*DAT_420001c4)(0);
  iVar6 = (*DAT_420001c4)(1);
  puVar3 = DAT_42000228;
  puVar2 = DAT_4200021c;
  puVar1 = DAT_42000218;
  if (((((-(iVar5 + -0xc) & 0xffU) == 0) && (iVar5 != 0x11)) && ((-(iVar6 + -0xc) & 0xffU) == 0)) &&
     (iVar6 != 0x11)) {
    uVar11 = 0xfffffff1;
    uVar10 = 0xe;
    uVar7 = DAT_4200020c;
    uVar8 = DAT_42000210;
    uVar9 = DAT_42000208;
  }
  else {
    memw();
    memw();
    uVar11 = *DAT_42000218;
    memw();
    uVar10 = uVar11 ^ 0xffffffff;
    uVar7 = *DAT_42000214 & DAT_42000224;
    uVar8 = *DAT_42000214 ^ 0xffffffff | DAT_42000220;
    uVar9 = *DAT_4200021c;
  }
  memw();
  memw();
  *DAT_42000214 = *DAT_42000214 & uVar7;
  puVar4 = DAT_4200022c;
  memw();
  memw();
  *puVar3 = *puVar3 | uVar8;
  puVar3 = DAT_42000234;
  memw();
  memw();
  *puVar1 = *puVar1;
  memw();
  memw();
  *puVar4 = *puVar4;
  memw();
  memw();
  *puVar1 = *puVar1 & uVar11;
  puVar1 = DAT_42000238;
  memw();
  memw();
  *puVar4 = *puVar4 | uVar10;
  memw();
  memw();
  *puVar4 = *puVar4 & 0xfffffffe;
  memw();
  memw();
  *puVar2 = *puVar2 & uVar9;
  memw();
  memw();
  *puVar2 = *puVar2 | DAT_42000230;
  uVar7 = DAT_4200023c;
  memw();
  memw();
  *puVar3 = *puVar3 & 0xfffff000;
  memw();
  memw();
  *puVar1 = *puVar1 & uVar7;
  memw();
  memw();
  *puVar1 = *puVar1 | DAT_42000240;
  FUN_4202ddcc(0x19);
  return;
}


