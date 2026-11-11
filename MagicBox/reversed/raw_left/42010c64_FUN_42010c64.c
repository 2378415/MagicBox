// 42010c64  FUN_42010c64  FUN_42010c64  size=32

undefined1 FUN_42010c64(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if ((param_1 != 0) && (uVar1 = 0, *(int *)(param_1 + 0x210) != 0)) {
    memw();
    memw();
    uVar1 = *DAT_42000e8c;
    memw();
  }
  return uVar1;
}


