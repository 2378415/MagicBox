// 40383608  FUN_40383608  FUN_40383608  size=109

int FUN_40383608(undefined4 *param_1,undefined4 param_2,uint param_3,byte param_4)

{
  int iVar1;
  undefined1 uVar2;
  int3 local_40;
  undefined1 uStack_3d;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  
  iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4));
  if (iVar1 == 0) {
    if (DAT_403752d4 < param_3) {
      uVar2 = 0x20;
      uStack_2c = 0x12;
    }
    else {
      uVar2 = 0x18;
      uStack_2c = 2;
    }
    _local_40 = CONCAT13(uVar2,(uint3)param_4 << 8);
    uStack_30 = 8;
    uStack_3c = param_3;
    uStack_38 = param_2;
    iVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,&local_40);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(param_1[1] + 0x54))
                        (param_1,*(undefined4 *)(*(int *)(param_1[1] + 4) + 0x10));
    }
  }
  return iVar1;
}


