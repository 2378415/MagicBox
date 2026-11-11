int FUN_40383160(undefined4 *param_1,undefined4 param_2,undefined4 param_3,byte param_4)

{
  int iVar1;
  int3 local_40;
  undefined1 uStack_3d;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_2c;
  
  iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4));
  if ((iVar1 == 0) || (iVar1 == 0x106 || iVar1 == 0)) {
    _local_40 = CONCAT13(0x20,(uint3)param_4 << 8);
    uStack_2c = (undefined2)DAT_40375374;
    uStack_3c = param_3;
    uStack_38 = param_2;
    (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,&local_40);
    param_1[7] = param_1[7] | 1;
    iVar1 = (**(code **)(param_1[1] + 0x54))
                      (param_1,*(undefined4 *)(*(int *)(param_1[1] + 4) + 0x10));
    if (iVar1 == 0x106) {
      iVar1 = (**(code **)(param_1[1] + 0x2c))(param_1,1);
    }
  }
  return iVar1;
}