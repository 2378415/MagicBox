// 4200c0ac  FUN_4200c0ac  FUN_4200c0ac  size=32

undefined4 FUN_4200c0ac(int param_1)

{
  undefined4 uVar1;
  
  memw();
  memw();
  *(uint *)(*(int *)(param_1 + 8) + 0xc) = *(uint *)(*(int *)(param_1 + 8) + 0xc) | 0x40;
  uVar1 = FUN_4200c040(param_1);
  return uVar1;
}


