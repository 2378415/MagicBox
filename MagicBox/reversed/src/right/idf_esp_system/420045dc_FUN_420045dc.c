void FUN_420045dc(int param_1,int param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = (uint)(param_1 != 0);
  if (param_2 != 0) {
    uVar1 = uVar1 | 2;
  }
  memw();
  *DAT_42000590 = *DAT_42000590 & 0xffffffcf | uVar1 << 4;
  return;
}