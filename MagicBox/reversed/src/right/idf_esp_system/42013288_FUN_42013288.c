uint FUN_42013288(uint param_1)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = DAT_42000afc;
  }
  else {
    uVar1 = param_1 - 1 | ((param_1 >> 1) - 1 & 0xff) << 6 | (param_1 - 1 & 0xff) << 0xc;
  }
  return uVar1;
}