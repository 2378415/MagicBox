// 40376208  FUN_40376208  FUN_40376208  size=36

void FUN_40376208(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined1 in_PRID;
  
  uVar3 = rsr(in_PRID);
  iVar4 = (uVar3 >> 0xd & 1) * 0x20;
  iVar1 = DAT_4037467c + 0x20;
  puVar2 = (undefined4 *)(iVar4 + DAT_4037467c);
  do {
    if ((code *)*puVar2 != (code *)0x0) {
      (*(code *)*puVar2)();
    }
    puVar2 = puVar2 + 1;
  } while (puVar2 != (undefined4 *)(iVar1 + iVar4));
  return;
}


