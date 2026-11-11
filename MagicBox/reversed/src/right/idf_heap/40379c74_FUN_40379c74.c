undefined4 FUN_40379c74(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x102;
  }
  else {
    uVar2 = param_1 & 0x400;
    if ((param_1 & 0x400) != 0) {
      uVar2 = 1;
    }
    uVar1 = FUN_4037ed80(uVar2,0);
    *param_2 = uVar1;
    uVar1 = 0;
  }
  return uVar1;
}