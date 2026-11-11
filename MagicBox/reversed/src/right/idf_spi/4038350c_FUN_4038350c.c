undefined4 FUN_4038350c(undefined4 *param_1,undefined4 param_2,uint param_3,undefined1 param_4)

{
  undefined4 uVar1;
  undefined1 uStack_40;
  undefined1 uStack_3f;
  undefined1 uStack_3d;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  
  (*DAT_4037448c)(&uStack_40,0,0x1c);
  if (DAT_40375214 < param_3) {
    uStack_3d = 0x20;
  }
  else {
    uStack_3d = 0x18;
  }
  uStack_30 = 8;
  if (DAT_40375214 < param_3) {
    uStack_2c = 0x12;
  }
  else {
    uStack_2c = 2;
  }
  uStack_3f = param_4;
  uStack_3c = param_3;
  uStack_38 = param_2;
  uVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,&uStack_40);
  return uVar1;
}