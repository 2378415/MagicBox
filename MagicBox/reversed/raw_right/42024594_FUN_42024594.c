// 42024594  FUN_42024594  FUN_42024594  size=26

uint FUN_42024594(undefined4 *param_1)

{
  uint uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xffffffff;
  }
  else if ((uint *)*param_1 == (uint *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(uint *)*param_1 >> 0x10 & 1;
  }
  return uVar1;
}


