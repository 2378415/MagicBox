void FUN_42002a10(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  code *pcVar5;
  undefined1 in_PRID;
  
  uVar3 = rsr(in_PRID);
  bVar1 = true;
  for (iVar4 = 0; iVar4 < 8; iVar4 = iVar4 + 1) {
    pcVar5 = *(code **)(((uVar3 >> 0xd & 1) * 8 + iVar4) * 4 + DAT_4200039c);
    if ((pcVar5 != (code *)0x0) && (iVar2 = (*pcVar5)(), iVar2 == 0)) {
      bVar1 = false;
    }
  }
  if (bVar1) {
    (*(code *)PTR_FUN_420003a0)();
  }
  return;
}