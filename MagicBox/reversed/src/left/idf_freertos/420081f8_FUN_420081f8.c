uint FUN_420081f8(int param_1)

{
  uint uVar1;
  
  memw();
  if ((((uint *)**(undefined4 **)(PTR_PTR_42000978 + param_1 * 4))[7] & 0x3ff) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    memw();
    uVar1 = *(uint *)**(undefined4 **)(PTR_PTR_42000978 + param_1 * 4) & 0xff;
  }
  return uVar1;
}