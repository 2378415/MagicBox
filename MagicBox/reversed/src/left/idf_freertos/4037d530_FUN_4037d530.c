void FUN_4037d530(void)

{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  undefined1 in_PRID;
  
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  puVar1 = PTR_DAT_40374ef4;
  uVar2 = rsr(in_PRID);
  piVar3 = (int *)((uVar2 >> 0xd & 1) * 4 + DAT_40374ed8);
  memw();
  memw();
  *piVar3 = *piVar3 + 1;
  FUN_4037c094(puVar1);
  return;
}