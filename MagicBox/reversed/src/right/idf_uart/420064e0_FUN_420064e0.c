uint FUN_420064e0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  byte local_30 [48];
  
  puVar3 = (undefined4 *)**(undefined4 **)(PTR_PTR_42000770 + param_1 * 4);
  memw();
  if ((puVar3[7] & 0x3ff) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    for (iVar2 = 0; iVar2 < 1; iVar2 = iVar2 + 1) {
      memw();
      local_30[iVar2] = (byte)*puVar3;
    }
    uVar1 = (uint)local_30[0];
  }
  return uVar1;
}