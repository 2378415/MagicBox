void FUN_40383710(undefined4 param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  ushort uStack_30;
  byte bStack_2e;
  byte abStack_2d [45];
  
  (*DAT_403753bc)(PTR_DAT_403753b0);
  puVar1 = DAT_40374860;
  (*DAT_403753c0)(*DAT_40374860);
  uStack_30 = 0;
  abStack_2d[0] = 0;
  bStack_2e = 0;
  (*DAT_403753c4)(1,4,5,8,0,0,0,0,0,abStack_2d,8,1,0);
  (*DAT_403753c4)(1,4,0x15,8,0,0,0,0,0,&bStack_2e,8,1,0);
  uStack_30 = (ushort)abStack_2d[0] | (bStack_2e | 7) << 8;
  (*DAT_403753c8)(*puVar1);
  (*DAT_403753c4)(1,4,1,8,0,0,0,&uStack_30,0x10,0,0,1,0);
  (*DAT_403753c0)(*puVar1);
  puVar2 = DAT_403753b4;
  memw();
  memw();
  *DAT_40374a00 = *DAT_40374a00 | 0xc;
  memw();
  memw();
  *puVar2 = *puVar2 | DAT_40374a08;
  uStack_30 = CONCAT11(uStack_30._1_1_,1);
  (*DAT_403753c8)(*puVar1);
  (*DAT_403753c4)(1,4,0x72,8,0,0x20,0,&uStack_30,8,0,0,1,0);
  FUN_4037b230(param_1,*DAT_403753b8 + 0x54);
  (*DAT_403753ac)(0,0,0);
  (*DAT_403753ac)(1,0,0);
  (*DAT_403753cc)();
  return;
}