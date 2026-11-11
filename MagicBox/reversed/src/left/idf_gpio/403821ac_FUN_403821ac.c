undefined4 FUN_403821ac(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x105;
  if ((param_2 >> 0x10 == 0x68) && ((param_2 >> 8 & 0xff) == 0x40)) {
    uVar1 = 0;
  }
  return uVar1;
}