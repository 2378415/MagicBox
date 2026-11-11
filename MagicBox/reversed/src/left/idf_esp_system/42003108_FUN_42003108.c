void FUN_42003108(void)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  uVar1 = uVar1 >> 0xd & 1;
  (*(code *)PTR_FUN_42000264)(0x19);
  (*DAT_42000268)(uVar1,0x38,0x19);
  puVar2 = DAT_42000250;
  memw();
  memw();
  *DAT_4200024c = *DAT_4200024c | 0x3f;
  memw();
  memw();
  *puVar2 = *puVar2 | 0x3f;
  if (uVar1 == 0) {
    (*DAT_42000268)(0,0x5e);
    memw();
    uVar1 = *DAT_42000254;
    puVar2 = DAT_42000258;
    puVar3 = DAT_42000254;
  }
  else {
    (*DAT_42000268)(uVar1,0x5f,0x19);
    memw();
    uVar1 = *DAT_4200025c;
    puVar2 = DAT_42000260;
    puVar3 = DAT_4200025c;
  }
  memw();
  *puVar3 = uVar1 | 0x1f;
  memw();
  memw();
  *puVar2 = *puVar2 | 0x1f;
  (*(code *)PTR_FUN_4200026c)(0x19);
  return;
}