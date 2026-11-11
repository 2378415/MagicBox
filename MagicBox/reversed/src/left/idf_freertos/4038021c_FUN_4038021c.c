undefined4 FUN_4038021c(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  
  (*DAT_4037450c)(param_1 + 0x1c,param_2,8);
  iVar2 = DAT_40374850;
  memw();
  memw();
  memw();
  memw();
  memw();
  bVar1 = *(byte *)(param_2 + 6);
  memw();
  *(uint *)(DAT_40374850 + 0xa0) =
       *(uint *)(DAT_40374850 + 0xa0) & DAT_403751b0 | (uint)*(byte *)(param_2 + 5) << 9;
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  *(uint *)(iVar2 + 0xa0) = *(uint *)(iVar2 + 0xa0) & 0xfffffe01 | (uint)bVar1 * 2;
  return 0;
}