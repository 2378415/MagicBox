undefined4 FUN_4200c8a4(int param_1)

{
  uint *puVar1;
  uint uVar2;
  
  memw();
  puVar1 = (uint *)(*(int *)(param_1 + 8) + 0x440);
  memw();
  uVar2 = *puVar1;
  memw();
  memw();
  memw();
  memw();
  memw();
  *puVar1 = uVar2 & 0xffffffd1 | 0x100;
  FUN_4200da94(200);
  memw();
  memw();
  *(uint *)(*(int *)(param_1 + 8) + 0x440) = uVar2 & 0xfffffed1;
  FUN_4200da94(10);
  while (memw(), (*(uint *)(*(int *)(param_1 + 8) + 0x440) & 4) == 0) {
    FUN_4200da94(10);
  }
  return 0;
}