// 40383098  FUN_40383098  FUN_40383098  size=50

undefined4 FUN_40383098(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((param_1[4] & 0xffff) == 0x10) {
    uVar2 = 0x14;
    uVar1 = DAT_4037536c;
  }
  else {
    if ((param_1[4] & 0xffff) != 0x11) {
      return DAT_403748fc;
    }
    uVar2 = 0x28;
    uVar1 = DAT_40375370;
  }
  uVar1 = (**(code **)(*(int *)*param_1 + 0x3c))((int *)*param_1,uVar1,0x20,uVar2);
  return uVar1;
}


