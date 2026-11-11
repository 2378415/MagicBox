undefined4 FUN_42009f90(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x40) {
    uVar1 = FUN_42009f6c((int)(char)PTR_DAT_420009a0[param_1 * 3 + 1]);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}