// 40382c1c  FUN_40382c1c  FUN_40382c1c  size=60

int FUN_40382c1c(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 local_40 [3];
  uint *puStack_34;
  undefined2 uStack_2c;
  uint auStack_24 [9];
  
  auStack_24[0] = 0;
  local_40[0] = 0x10000;
  puStack_34 = auStack_24;
  uStack_2c = 0x35;
  iVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,local_40);
  if (iVar1 == 0) {
    *param_2 = (auStack_24[0] >> 1 & 1) << 2;
  }
  return iVar1;
}


