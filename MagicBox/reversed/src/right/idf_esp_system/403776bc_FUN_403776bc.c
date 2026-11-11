undefined4 FUN_403776bc(void)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar3 = DAT_403747f4;
  piVar2 = DAT_403747cc;
  memw();
  memw();
  DAT_403747cc[4] = DAT_403747cc[4] & DAT_403747f4;
  iVar4 = DAT_403747f8;
  memw();
  memw();
  *(uint *)(DAT_403747f8 + 0x10) = *(uint *)(DAT_403747f8 + 0x10) & uVar3;
  uVar1 = DAT_4037450c;
  memw();
  memw();
  piVar2[4] = piVar2[4] | DAT_4037450c;
  memw();
  memw();
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) | uVar1;
  memw();
  memw();
  piVar2[4] = piVar2[4] & uVar3;
  memw();
  memw();
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) & uVar3;
  FUN_40377670(5,0,0);
  memw();
  if (*piVar2 == 0) {
    FUN_40377670(0x66,0,0);
    FUN_40377670(0x99,0,0);
    uVar5 = 0;
  }
  else {
    uVar5 = 0xffffffff;
  }
  return uVar5;
}