undefined4 FUN_4202434c(undefined4 *param_1,undefined1 *param_2,ushort param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 != (undefined1 *)0x0) {
    if (param_3 < 0x100) {
      *param_2 = (char)param_3;
      uVar1 = 1;
    }
    else {
      *param_1 = 0x8a;
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}