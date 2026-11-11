uint FUN_40382c58(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_40 [3];
  uint *puStack_34;
  undefined2 uStack_2c;
  uint auStack_24 [9];
  
  auStack_24[0] = 0;
  local_40[0] = 0x10000;
  uStack_2c = 0x35;
  puStack_34 = auStack_24;
  uVar2 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,local_40);
  uVar1 = auStack_24[0];
  if (uVar2 == 0) {
    local_40[0] = 0x10000;
    uStack_2c = 5;
    puStack_34 = auStack_24;
    auStack_24[0] = uVar2;
    uVar2 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,local_40);
    if (uVar2 == 0) {
      *param_2 = (uVar1 & 0xff) << 8 | auStack_24[0] & 0xff;
    }
  }
  return uVar2;
}