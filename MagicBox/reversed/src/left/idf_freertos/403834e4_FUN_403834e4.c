int FUN_403834e4(undefined4 *param_1,uint param_2)

{
  int iVar1;
  code *pcVar2;
  byte bVar3;
  int local_40;
  uint uStack_3c;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  
  iVar1 = (**(code **)(param_1[1] + 0x2c))(param_1,0);
  if ((iVar1 == 0) &&
     (iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4)),
     iVar1 == 0)) {
    if (DAT_403752d4 < param_2) {
      bVar3 = 0x20;
      uStack_2c = 0xdc;
    }
    else {
      bVar3 = 0x18;
      uStack_2c = 0xd8;
    }
    local_40 = (uint)bVar3 << 0x18;
    uStack_30 = 8;
    uStack_3c = param_2;
    iVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,&local_40);
    if (iVar1 == 0) {
      pcVar2 = *(code **)(*(int *)*param_1 + 0x44);
      if ((pcVar2 == (code *)0x0) ||
         (iVar1 = (*pcVar2)((int *)*param_1,param_2,*(undefined4 *)(param_1[1] + 0x24)), iVar1 == 0)
         ) {
        iVar1 = (**(code **)(param_1[1] + 0x54))
                          (param_1,*(undefined4 *)(*(int *)(param_1[1] + 4) + 8));
      }
    }
  }
  return iVar1;
}