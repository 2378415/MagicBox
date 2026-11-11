// 420246d0  FUN_420246d0  FUN_420246d0  size=70

undefined4 * FUN_420246d0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 in_EPC1;
  undefined1 in_EPC2;
  undefined1 in_EPC3;
  undefined1 in_EPC4;
  undefined1 in_EPC5;
  undefined1 in_EPC6;
  
  *param_1 = 0xb1;
  uVar1 = rsr(in_EPC1);
  param_1[1] = uVar1;
  param_1[2] = 0xb2;
  uVar1 = rsr(in_EPC2);
  param_1[3] = uVar1;
  param_1[4] = 0xb3;
  uVar1 = rsr(in_EPC3);
  param_1[5] = uVar1;
  param_1[6] = 0xb4;
  uVar1 = rsr(in_EPC4);
  param_1[7] = uVar1;
  param_1[8] = 0xb5;
  uVar1 = rsr(in_EPC5);
  param_1[9] = uVar1;
  param_1[10] = 0xb6;
  uVar1 = rsr(in_EPC6);
  param_1[0xb] = uVar1;
  return param_1 + 0xc;
}


