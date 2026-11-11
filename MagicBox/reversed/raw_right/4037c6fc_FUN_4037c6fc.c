// 4037c6fc  FUN_4037c6fc  FUN_4037c6fc  size=72

void FUN_4037c6fc(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_4037bbe8(PTR_DAT_40374dcc,0xffffffff);
  uVar1 = DAT_40374de0;
  if (*DAT_40374dd0 == 0) {
    FUN_4037c8b8(DAT_40374de0);
    uVar2 = DAT_40374de4;
    FUN_4037c8b8(DAT_40374de4);
    *DAT_40374dc0 = uVar1;
    *DAT_40374dc4 = uVar2;
    iVar3 = FUN_4037b1c0(10,0x10,DAT_40374dec,DAT_40374de8,0);
    *DAT_40374dd0 = iVar3;
  }
  FUN_4037bd38(PTR_DAT_40374dcc);
  return;
}


