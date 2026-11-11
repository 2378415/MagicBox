undefined4 FUN_40383408(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x105;
  if ((param_2 >> 0x10 == 0xcd) && ((param_2 >> 8 & 0xff) == 0x60)) {
    uVar1 = 0;
  }
  return uVar1;
}