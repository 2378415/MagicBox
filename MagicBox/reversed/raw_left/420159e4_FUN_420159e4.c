// 420159e4  FUN_420159e4  FUN_420159e4  size=59

undefined4 FUN_420159e4(uint param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(int *)((param_1 & 0xff) * 8 + DAT_420013e0 + 4) + 0x800);
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffff80f;
  memw();
  memw();
  *puVar1 = (param_2 & 0x7f) << 4 | *puVar1;
  return 0;
}


