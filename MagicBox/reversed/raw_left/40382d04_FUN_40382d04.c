// 40382d04  FUN_40382d04  FUN_40382d04  size=52

undefined4 FUN_40382d04(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 local_40 [3];
  undefined4 *puStack_34;
  undefined2 uStack_2c;
  undefined4 auStack_24 [9];
  
  auStack_24[0] = 0;
  local_40[0] = 0x10000;
  puStack_34 = auStack_24;
  uStack_2c = 5;
  uVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,local_40);
  *param_2 = auStack_24[0];
  return uVar1;
}


