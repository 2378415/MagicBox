// 42004014  FUN_42004014  FUN_42004014  size=51

void FUN_42004014(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined1 in_PRID;
  
  uVar4 = rsr(in_PRID);
  iVar5 = (uVar4 >> 0xd & 1) * 0x20;
  iVar2 = DAT_420004d0 + 0x20;
  puVar3 = (undefined4 *)(iVar5 + DAT_420004d0);
  uVar4 = 1;
  do {
    if ((code *)*puVar3 != (code *)0x0) {
      uVar1 = (*(code *)*puVar3)();
      uVar4 = uVar1 & uVar4;
    }
    puVar3 = puVar3 + 1;
  } while (puVar3 != (undefined4 *)(iVar2 + iVar5));
  if (uVar4 != 0) {
    (*(code *)PTR_FUN_420004d4)();
  }
  return;
}


