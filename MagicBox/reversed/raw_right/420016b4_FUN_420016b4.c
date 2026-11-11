// 420016b4  FUN_420016b4  FUN_420016b4  size=36

void FUN_420016b4(void)

{
  uint uVar1;
  int iVar2;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  for (iVar2 = 0; iVar2 < 99; iVar2 = iVar2 + 1) {
    (*DAT_4200005c)(uVar1 >> 0xd & 1,iVar2,6);
  }
  return;
}


