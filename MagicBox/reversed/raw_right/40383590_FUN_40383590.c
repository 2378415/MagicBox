// 40383590  FUN_40383590  FUN_40383590  size=69

undefined4 FUN_40383590(undefined4 *param_1,uint param_2)

{
  undefined4 uVar1;
  undefined1 auStack_40 [3];
  undefined1 uStack_3d;
  uint uStack_3c;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  
  (*DAT_4037448c)(auStack_40,0,0x1c);
  if (DAT_40375214 < param_2) {
    uStack_3d = 0x20;
  }
  else {
    uStack_3d = 0x18;
  }
  uStack_30 = 8;
  if (DAT_40375214 < param_2) {
    uStack_2c = 0x21;
  }
  else {
    uStack_2c = 0x20;
  }
  uStack_3c = param_2;
  uVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,auStack_40);
  return uVar1;
}


