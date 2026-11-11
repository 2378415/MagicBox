void FUN_4202d660(int *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(*param_1 + 0x14);
  memw();
  memw();
  memw();
  *param_2 = (uint)(param_3 << 4) /
             (((*(uint *)(*param_1 + 0x78) >> 0xc & 0xff) + 1) *
             ((uVar1 & 0xfff) << 4 | uVar1 >> 0x14 & 0xf));
  return;
}