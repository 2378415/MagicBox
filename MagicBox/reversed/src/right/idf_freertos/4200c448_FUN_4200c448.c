void FUN_4200c448(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 undefined2 param_6,undefined1 param_7)

{
  undefined4 uVar1;
  
  memw();
  *(undefined4 *)(*(int *)(param_1 + 8) + param_2 * 0x20 + 0x508) = 0xffffffff;
  if (param_5 == 3) {
    uVar1 = 0x12;
  }
  else {
    uVar1 = 2;
  }
  memw();
  *(undefined4 *)(param_2 * 0x20 + *(int *)(param_1 + 8) + 0x50c) = uVar1;
  memw();
  memw();
  *(uint *)(*(int *)(param_1 + 8) + 0x418) =
       *(uint *)(*(int *)(param_1 + 8) + 0x418) | 1 << 0x20 - (0x20 - (param_2 & 0xf));
  FUN_4200c3b0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}