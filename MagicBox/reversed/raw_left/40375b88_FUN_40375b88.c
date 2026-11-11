// 40375b88  FUN_40375b88  FUN_40375b88  size=307

void FUN_40375b88(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 in_PRID;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 auStack_30 [48];
  
  FUN_40383bfc(0xffffffff);
  (*DAT_40374590)(auStack_30,0,0);
  uVar1 = FUN_403794f0();
  (*DAT_40374594)(auStack_30);
  (*DAT_40374598)(auStack_30,0,uVar1,3);
  (*DAT_40374598)(auStack_30,1,uVar1,4);
  (*DAT_4037459c)(auStack_30,1);
  (*DAT_403745a0)(auStack_30);
  uStack_38 = *(undefined4 *)PTR_DAT_4037456c;
  uStack_34 = *(undefined4 *)(PTR_DAT_4037456c + 4);
  (*DAT_40374594)(&uStack_38);
  (*DAT_403745a4)(&uStack_38);
  (*DAT_403745a0)(&uStack_38);
  local_40 = *(undefined4 *)PTR_DAT_40374570;
  uStack_3c = *(undefined4 *)(PTR_DAT_40374570 + 4);
  (*DAT_40374594)(&local_40);
  (*DAT_403745a4)(&local_40);
  (*DAT_403745a0)(&local_40);
  uVar2 = rsr(in_PRID);
  uVar2 = uVar2 >> 0xd & 1;
  (*DAT_403745a8)(uVar2 == 0);
  FUN_40378ff8(uVar2 == 0);
  (*DAT_403745ac)();
  (*DAT_403745b0)();
  memw();
  *DAT_40374574 = 0x30;
  memw();
  *DAT_40374578 = 0x30;
  memw();
  *DAT_4037457c = 0x30;
  memw();
  *DAT_40374580 = 0x30;
  memw();
  *DAT_40374584 = 0x30;
  memw();
  *DAT_40374588 = 0x30;
  FUN_40375aa0();
  FUN_40379b3c();
  memw();
  *DAT_4037458c = 0;
  if (uVar2 == 0) {
    (*DAT_403745a8)(1);
    (*DAT_403745a8)(0);
  }
  else {
    (*DAT_403745a8)(0);
    FUN_40379064(0);
    (*DAT_403745a8)(1);
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


