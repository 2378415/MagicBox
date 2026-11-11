undefined4 FUN_42024fd8(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 < 0x7e) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x10))
                      (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + param_2 * 0x20 + 0x40,
                       param_3,0x20);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}