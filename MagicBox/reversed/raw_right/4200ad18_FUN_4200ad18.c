// 4200ad18  FUN_4200ad18  FUN_4200ad18  size=230

void FUN_4200ad18(int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 unaff_retaddr;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 in_WindowBase;
  undefined1 in_WindowStart;
  undefined1 uVar9;
  undefined1 auStack_20 [32];
  
  uVar9 = 0;
  uVar3 = FUN_4200ac78();
  *DAT_420009c0 = *(undefined4 *)(param_1 + 0x1c);
  puVar1 = DAT_420009e8;
  *DAT_420009e8 = DAT_420009e4 & 0xfffffff0;
  (*DAT_42000240)(DAT_420009e0,0xa5,0x6a4);
  uVar4 = *puVar1;
  (*(code *)PTR_FUN_420009f4)();
  iVar2 = DAT_420009ec;
  uVar8 = rsr(uVar9);
  uVar7 = rsr(in_WindowBase);
  uVar5 = rsr(in_WindowStart);
  *(undefined1 **)DAT_420009ec = auStack_20;
  *(undefined4 *)(iVar2 + 4) = unaff_retaddr;
  *(undefined4 *)(iVar2 + 8) = uVar8;
  *(undefined4 *)(iVar2 + 0xc) = uVar7;
  *(undefined4 *)(iVar2 + 0x10) = uVar5;
  *(uint *)(uVar4 - 0x3c) = uVar4;
  uVar4 = rsr(uVar9);
  wsr(uVar9,uVar4 & DAT_420009f0);
  rsync();
  uVar4 = rsr(in_WindowBase);
  wsr(in_WindowStart,1 << 0x20 - (0x20 - (uVar4 & 0x1f)));
  rsync();
  uVar4 = rsr(uVar9);
  wsr(uVar9,uVar4 | DAT_420003b4);
  rsync();
  FUN_4200bbcc(param_1,uVar3);
  FUN_4200b88c();
  uVar4 = 0;
  for (pcVar6 = DAT_420009e0; (uVar4 < 0x6a4 && (*pcVar6 == -0x5b)); pcVar6 = pcVar6 + 1) {
    uVar4 = uVar4 + 1;
  }
  wsr(uVar9,*(uint *)(DAT_420009ec + 8) & DAT_420003b8);
  rsync();
  wsr(in_WindowBase,*(undefined4 *)(DAT_420009ec + 0xc));
  rsync();
  wsr(in_WindowStart,*(undefined4 *)(DAT_420009ec + 0x10));
  rsync();
  wsr(uVar9,*(uint *)(DAT_420009ec + 8));
  rsync();
  return;
}


