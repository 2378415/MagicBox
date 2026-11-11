// 42024718  FUN_42024718  FUN_42024718  size=60

undefined4 * FUN_42024718(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 in_EPS2;
  undefined1 in_EPS3;
  undefined1 in_EPS4;
  undefined1 in_EPS5;
  undefined1 in_EPS6;
  
  *param_1 = 0xc2;
  uVar1 = rsr(in_EPS2);
  param_1[1] = uVar1;
  param_1[2] = 0xc3;
  uVar1 = rsr(in_EPS3);
  param_1[3] = uVar1;
  param_1[4] = 0xc4;
  uVar1 = rsr(in_EPS4);
  param_1[5] = uVar1;
  param_1[6] = 0xc5;
  uVar1 = rsr(in_EPS5);
  param_1[7] = uVar1;
  param_1[8] = 0xc6;
  uVar1 = rsr(in_EPS6);
  param_1[9] = uVar1;
  return param_1 + 10;
}


