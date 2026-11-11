undefined4 FUN_40377c7c(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = DAT_40374878;
  piVar2 = DAT_40374850;
  uVar1 = DAT_40374550;
  memw();
  memw();
  DAT_40374850[4] = DAT_40374850[4] & 0x7fffffff;
  memw();
  memw();
  *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) & 0x7fffffff;
  memw();
  memw();
  piVar2[4] = piVar2[4] | uVar1;
  memw();
  memw();
  *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) | uVar1;
  memw();
  memw();
  piVar2[4] = piVar2[4] & 0x7fffffff;
  memw();
  memw();
  *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) & 0x7fffffff;
  FUN_403779d0(5,0,0,0,0,0,0);
  memw();
  if (*piVar2 == 0) {
    FUN_403779d0(0x66,0,0,0,0,0,0);
    FUN_403779d0(0x99,0,0,0,0,0,0);
    uVar4 = 0;
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}