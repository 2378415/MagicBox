void FUN_40375f3c(void)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  for (iVar2 = 0; iVar2 < 8; iVar2 = iVar2 + 1) {
    pcVar3 = *(code **)(((uVar1 >> 0xd & 1) * 8 + iVar2) * 4 + DAT_4037463c);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)();
    }
  }
  return;
}