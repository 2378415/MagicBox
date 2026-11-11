void FUN_42010ad4(undefined4 param_1,int param_2,uint param_3)

{
  uint *puVar1;
  
  if (param_2 - 0x11U < 2) {
    param_3 = param_3 * 2 & 2 | param_3 >> 1 & 1;
  }
  puVar1 = (uint *)((param_2 + DAT_42000de8) * 4);
  memw();
  memw();
  *puVar1 = *puVar1 & DAT_42000dec | (param_3 & 3) << 10;
  return;
}