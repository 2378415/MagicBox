void FUN_40375a54(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  uVar1 = DAT_40374574;
  uVar2 = rsr(in_PRID);
  if ((uVar2 >> 0xd & 1) == 0) {
    memw();
    if (*DAT_403744f0 != '\0') {
      (*DAT_40374550)(DAT_40374574);
      (*DAT_40374554)(uVar1,0,600,1);
      (*DAT_40374554)(uVar1,1,0x4b0,3);
      (*DAT_40374578)(uVar1);
      (*DAT_4037455c)(uVar1);
      memw();
      *DAT_403744f0 = '\0';
    }
  }
  else {
    memw();
    *DAT_403744f0 = '\x01';
  }
  return;
}