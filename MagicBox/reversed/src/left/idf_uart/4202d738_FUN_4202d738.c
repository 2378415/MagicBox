void FUN_4202d738(int *param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  memw();
  if ((*(uint *)(*param_1 + 0x20) & 2) != 0) {
    memw();
    uVar1 = *(uint *)(*param_1 + 0x20) & 1 | 2;
  }
  *param_2 = uVar1;
  return;
}