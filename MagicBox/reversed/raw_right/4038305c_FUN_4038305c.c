// 4038305c  FUN_4038305c  FUN_4038305c  size=137

int FUN_4038305c(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_40 [3];
  undefined1 uStack_3d;
  undefined4 uStack_3c;
  undefined2 uStack_2c;
  
  iVar1 = (**(code **)(param_1[1] + 0x2c))(param_1,0);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4));
  }
  if (iVar1 == 0 || iVar1 == 0x106) {
    (*DAT_4037448c)(auStack_40,0,0x1c);
    uStack_3d = 0x20;
    uStack_2c = (undefined2)DAT_4037527c;
    uStack_3c = param_2;
    (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,auStack_40);
    param_1[7] = param_1[7] | 1;
    iVar1 = (**(code **)(param_1[1] + 0x54))
                      (param_1,*(undefined4 *)(*(int *)(param_1[1] + 4) + 0xc));
    if (iVar1 == 0x106) {
      iVar1 = (**(code **)(param_1[1] + 0x2c))(param_1,1);
    }
  }
  return iVar1;
}


