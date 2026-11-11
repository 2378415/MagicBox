void FUN_42003da8(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  memw();
  uVar1 = (uint)(param_1 != 0);
  if (param_2 != 0) {
    uVar1 = uVar1 | 2;
  }
  if (param_3 != 0) {
    uVar1 = uVar1 | 4;
  }
  memw();
  *DAT_42000528 = *DAT_42000528 & DAT_42000530 | uVar1 << 0xf;
  return;
}