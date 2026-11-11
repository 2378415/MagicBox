undefined4 FUN_4038009c(int param_1,int param_2)

{
  int iVar1;
  
  (*DAT_403744d4)(param_1 + 0x1c,param_2,8);
  iVar1 = DAT_403747cc;
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  *(uint *)(DAT_403747cc + 0xa0) =
       *(uint *)(DAT_403747cc + 0xa0) & DAT_403750f0 | (uint)*(byte *)(param_2 + 5) << 9;
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  *(uint *)(iVar1 + 0xa0) = *(uint *)(iVar1 + 0xa0) & 0xfffffe01 | (uint)*(byte *)(param_2 + 6) * 2;
  return 0;
}