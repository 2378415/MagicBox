undefined4 FUN_4037e3b0(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined1 in_PRID;
  
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  iVar1 = DAT_40374e18;
  uVar3 = rsr(in_PRID);
  uVar3 = uVar3 >> 0xd & 1;
  piVar4 = (int *)(uVar3 * 4 + DAT_40374e18);
  memw();
  if (*piVar4 != 0) {
    memw();
    iVar5 = *piVar4;
    *(int *)(iVar5 + 0x50) = *(int *)(iVar5 + 0x50) + 1;
  }
  memw();
  uVar2 = *(undefined4 *)(iVar1 + uVar3 * 4);
  FUN_4037c094(PTR_DAT_40374ef4);
  return uVar2;
}