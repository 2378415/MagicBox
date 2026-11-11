undefined4 FUN_4202a0b4(undefined4 param_1,ushort *param_2,byte *param_3,int param_4)

{
  undefined4 uVar1;
  ushort local_30 [24];
  
  if (param_2 == (ushort *)0x0) {
    param_2 = local_30;
  }
  uVar1 = 0;
  if ((param_3 != (byte *)0x0) && (uVar1 = 0xfffffffe, param_4 != 0)) {
    uVar1 = 1;
    *param_2 = (ushort)*param_3;
    if (*param_3 == 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}