void FUN_420064a8(int param_1,byte param_2)

{
  int iVar1;
  uint *puVar2;
  byte local_30 [48];
  
  puVar2 = (uint *)**(undefined4 **)(PTR_PTR_42000770 + param_1 * 4);
  local_30[0] = param_2;
  do {
    memw();
  } while (-((puVar2[7] >> 0x10 & 0x3ff) - 0x80) < 2);
  for (iVar1 = 0; iVar1 < 1; iVar1 = iVar1 + 1) {
    memw();
    *puVar2 = (uint)local_30[iVar1];
  }
  return;
}