// 42025084  FUN_42025084  FUN_42025084  size=32

void FUN_42025084(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  *param_2 = 0;
  puVar1 = (undefined4 *)*param_1;
  param_2[1] = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  *param_1 = param_2;
  if (param_1[1] == 0) {
    param_1[1] = param_2;
  }
  param_1[2] = param_1[2] + 1;
  return;
}


