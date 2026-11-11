undefined8 FUN_4037bee0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 in_CPENABLE;
  undefined1 uVar6;
  undefined1 in_VECBASE;
  undefined1 in_PRID;
  undefined8 uVar7;
  
  uVar6 = 0;
  FUN_4037d4bc();
  uVar4 = rsr(in_PRID);
  puVar2 = (undefined4 *)((uVar4 >> 0xd & 1) * 4 + DAT_40374d64);
  uVar5 = *puVar2;
  piVar1 = *(int **)uVar5;
  *puVar2 = uVar5;
  if (*piVar1 == 0) {
    wur(in_VECBASE,piVar1[3]);
    rsync();
    wsr(uVar6,piVar1[2]);
    return CONCAT44(piVar1[2],piVar1[3]);
  }
  uVar4 = rsr(in_PRID);
  puVar3 = (ushort *)
           (*(int *)(*(int *)((uVar4 >> 0xd & 1) * 4 + DAT_40374d64) + *(int *)PTR_DAT_40374d70) -
            *(int *)PTR_DAT_40374d74 & 0xfffffff0);
  uVar4 = (uint)*puVar3;
  wsr(in_CPENABLE,uVar4);
  uVar7 = FUN_40383c20(puVar3,uVar4);
  rsync();
  return uVar7;
}