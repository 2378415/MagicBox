undefined4 FUN_40382258(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 >> 0x10 == 0x68) {
    if ((param_2 >> 8 & 0xff) << 8 == DAT_40374450) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x105;
    }
  }
  else {
    uVar1 = 0x105;
  }
  return uVar1;
}