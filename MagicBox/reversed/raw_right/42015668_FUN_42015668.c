// 42015668  FUN_42015668  FUN_42015668  size=79

void FUN_42015668(undefined1 *param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 int param_5,undefined1 param_6)

{
  undefined4 *puVar1;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_6;
  for (puVar1 = (undefined4 *)(param_1 + 8); (undefined4 *)(param_1 + 0x18) != puVar1;
      puVar1 = puVar1 + 1) {
    *puVar1 = 0xffffffff;
  }
  for (puVar1 = (undefined4 *)(param_1 + 0x18); (undefined4 *)(param_1 + 0x20) != puVar1;
      puVar1 = puVar1 + 1) {
    *puVar1 = 0xffffffff;
  }
  if (param_5 == 0) {
    param_1[8] = 0;
  }
  else {
    (*DAT_42000cfc)(param_1 + 8,param_5,0xf);
    param_1[0x17] = 0;
  }
  return;
}


