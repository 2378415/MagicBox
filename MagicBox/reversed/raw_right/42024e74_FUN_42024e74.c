// 42024e74  FUN_42024e74  FUN_42024e74  size=37

void FUN_42024e74(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1 = param_1 + 3;
  for (iVar1 = 0x1c; -1 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined1 *)param_1 = 0xff;
    *param_1 = 0xff;
    param_1 = param_1 + 1;
  }
  return;
}


