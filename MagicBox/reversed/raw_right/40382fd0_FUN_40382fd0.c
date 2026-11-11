// 40382fd0  FUN_40382fd0  FUN_40382fd0  size=138

int FUN_40382fd0(undefined4 *param_1)

{
  int iVar1;
  undefined1 auStack_40 [20];
  undefined2 uStack_2c;
  
  iVar1 = (**(code **)(param_1[1] + 0x2c))(param_1,0);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4));
  }
  if (iVar1 == 0 || iVar1 == 0x106) {
    (*DAT_4037448c)(auStack_40,0,0x1c);
    uStack_2c = (undefined2)DAT_40375278;
    (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,auStack_40);
    param_1[7] = param_1[7] | 1;
    iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,*(undefined4 *)(*(int *)(param_1[1] + 4) + 4));
    if (iVar1 == 0x106) {
      (**(code **)(param_1[1] + 0x2c))(param_1,1);
    }
  }
  return iVar1;
}


