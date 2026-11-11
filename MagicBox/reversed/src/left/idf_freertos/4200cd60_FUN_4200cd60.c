void FUN_4200cd60(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_retaddr;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 in_WindowBase;
  undefined1 in_WindowStart;
  undefined1 uVar10;
  undefined1 auStack_20 [32];
  
  uVar10 = 0;
  FUN_4202d048();
  iVar3 = (*(code *)PTR_FUN_42000434)();
  puVar1 = DAT_42000ca4;
  bVar5 = 0;
  if (iVar3 != 0) {
    bVar5 = *DAT_42000c84 ^ 1;
  }
  *DAT_42000c88 = *(undefined4 *)(param_1 + 0x1c);
  uVar7 = DAT_42000cac;
  *puVar1 = DAT_42000ca8 & 0xfffffff0;
  (*DAT_42000094)(uVar7,0xa5,0x6a4);
  uVar4 = *puVar1;
  (*(code *)PTR_FUN_42000cb8)();
  puVar2 = DAT_42000cb0;
  uVar9 = rsr(uVar10);
  uVar8 = rsr(in_WindowBase);
  uVar7 = rsr(in_WindowStart);
  *(uint *)(uVar4 - 0x3c) = uVar4;
  puVar2[3] = uVar8;
  puVar2[4] = uVar7;
  uVar4 = DAT_42000cb4;
  *puVar2 = auStack_20;
  puVar2[1] = unaff_retaddr;
  puVar2[2] = uVar9;
  uVar6 = rsr(uVar10);
  wsr(uVar10,uVar6 & uVar4);
  rsync();
  uVar4 = rsr(in_WindowBase);
  wsr(in_WindowStart,1 << 0x20 - (0x20 - (uVar4 & 0x1f)));
  rsync();
  uVar4 = rsr(uVar10);
  wsr(uVar10,uVar4 | DAT_42000528);
  rsync();
  FUN_4200d724(param_1,bVar5);
  FUN_4200d628();
  wsr(uVar10,puVar2[2] & DAT_4200052c);
  rsync();
  wsr(in_WindowBase,puVar2[3]);
  rsync();
  wsr(in_WindowStart,puVar2[4]);
  rsync();
  wsr(uVar10,puVar2[2]);
  rsync();
  FUN_4202d050(puVar2[3],puVar2[4],*puVar2,puVar2[1]);
  return;
}