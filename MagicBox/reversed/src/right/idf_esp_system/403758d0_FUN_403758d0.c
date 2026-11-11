void FUN_403758d0(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 in_PRID;
  undefined1 auStack_40 [8];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  FUN_40383d28(0xffffffff);
  (*DAT_4037454c)(auStack_40,0,0);
  uVar1 = FUN_4037918c();
  uVar2 = (*DAT_403744c8)(uVar1 * 1000,(int)((ulonglong)uVar1 * 1000 >> 0x20),1000,0);
  (*DAT_40374550)(auStack_40);
  (*DAT_40374554)(auStack_40,0,uVar2,3);
  (*DAT_40374554)(auStack_40,1,uVar2,4);
  (*DAT_40374558)(auStack_40,1);
  (*DAT_4037455c)(auStack_40);
  uStack_38 = *(undefined4 *)PTR_DAT_40374528;
  uStack_34 = *(undefined4 *)(PTR_DAT_40374528 + 4);
  (*DAT_40374550)(&uStack_38);
  (*DAT_40374560)(&uStack_38);
  (*DAT_4037455c)(&uStack_38);
  uStack_30 = *(undefined4 *)PTR_DAT_4037452c;
  uStack_2c = *(undefined4 *)(PTR_DAT_4037452c + 4);
  (*DAT_40374550)(&uStack_30);
  (*DAT_40374560)(&uStack_30);
  (*DAT_4037455c)(&uStack_30);
  uVar1 = rsr(in_PRID);
  uVar1 = uVar1 >> 0xd & 1;
  (*DAT_40374564)(uVar1 == 0);
  FUN_40378910(uVar1 == 0);
  (*DAT_40374568)();
  (*DAT_4037456c)();
  memw();
  *DAT_40374530 = 0x30;
  memw();
  *DAT_40374534 = 0x30;
  memw();
  *DAT_40374538 = 0x30;
  memw();
  *DAT_4037453c = 0x30;
  memw();
  *DAT_40374540 = 0x30;
  memw();
  *DAT_40374544 = 0x30;
  FUN_40375808();
  FUN_40379614();
  memw();
  *DAT_40374548 = 0;
  if (uVar1 == 0) {
    (*DAT_40374564)(1);
    (*DAT_40374564)(0);
  }
  else {
    (*DAT_40374564)(0);
    FUN_40378994(0);
    (*DAT_40374564)(1);
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}