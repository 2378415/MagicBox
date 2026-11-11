// 40379200  FUN_40379200  FUN_40379200  size=93

void FUN_40379200(void)

{
  uint *puVar1;
  undefined *puVar2;
  uint *local_50 [20];
  
  puVar2 = PTR_DAT_40374a04;
  puVar1 = DAT_40374a00;
  memw();
  memw();
  *DAT_40374a00 = *DAT_40374a00 | 0x10;
  memw();
  memw();
  *puVar1 = *puVar1 | 3;
  memw();
  memw();
  *puVar1 = *puVar1 | 0xc;
  (*DAT_4037450c)(local_50,puVar2,0x24);
  memw();
  memw();
  *local_50[0] = *local_50[0] | DAT_40374a08;
  return;
}


