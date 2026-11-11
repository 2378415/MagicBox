void FUN_4202cf08(undefined4 *param_1,undefined1 *param_2,uint *param_3)

{
  uint uVar1;
  
  param_1 = (undefined4 *)*param_1;
  if ((int)*param_3 < 1) {
    memw();
    uVar1 = param_1[7] & 0x3ff;
    *param_3 = uVar1;
    if (uVar1 == 0) {
      return;
    }
  }
  memw();
  *param_2 = (char)*param_1;
  return;
}