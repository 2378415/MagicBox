undefined4 FUN_40382d68(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_40 [2];
  undefined4 *puStack_38;
  undefined2 uStack_2c;
  undefined4 auStack_24 [9];
  
  local_40[0] = 0x100;
  puStack_38 = auStack_24;
  uStack_2c = 0x31;
  auStack_24[0] = param_2;
  uVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,local_40);
  return uVar1;
}