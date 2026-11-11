// 403831fc  FUN_403831fc  FUN_403831fc  size=50

undefined4 FUN_403831fc(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((param_1[4] & 0xffff) == 0x10) {
    uVar2 = 0x14;
    uVar1 = DAT_40375288;
  }
  else {
    if ((param_1[4] & 0xffff) != 0x11) {
      return DAT_40374880;
    }
    uVar2 = 0x28;
    uVar1 = DAT_4037528c;
  }
  uVar1 = (**(code **)(*(int *)*param_1 + 0x3c))((int *)*param_1,uVar1,0x20,uVar2);
  return uVar1;
}


