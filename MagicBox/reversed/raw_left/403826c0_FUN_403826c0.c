// 403826c0  FUN_403826c0  FUN_403826c0  size=176

int FUN_403826c0(int param_1,int param_2,uint param_3,uint param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR_PTR_40375334;
  if ((*DAT_40374900 == param_1) &&
     (iVar3 = (**(code **)(PTR_PTR_40375334 + 0x14))(param_3,param_4), iVar3 != 0)) {
    (**(code **)puVar1)();
    for (; param_4 != 0; param_4 = param_4 - iVar3) {
      if ((param_3 & 0x3f) == 0) {
        iVar3 = 0x40;
        if (param_4 < 0x40) {
LAB_4038270d:
          iVar3 = 0x20;
          if (param_4 < 0x20) {
            iVar3 = 0x10;
          }
        }
      }
      else {
        iVar3 = 0x10;
        if ((param_3 & 0x1f) == 0) goto LAB_4038270d;
      }
      (**(code **)(puVar1 + 8))(param_3,param_2,iVar3);
      iVar2 = (**(code **)(*(int *)(param_1 + 4) + 0x2c))(param_1,0);
      if (iVar2 != 0) {
        return iVar2;
      }
      (**(code **)(puVar1 + 0xc))();
      iVar2 = (**(code **)(*(int *)(param_1 + 4) + 0x44))(param_1,param_2,param_3,param_4);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = (**(code **)(*(int *)(param_1 + 4) + 0x54))
                        (param_1,*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x10));
      if (iVar2 != 0) {
        return iVar2;
      }
      (**(code **)(puVar1 + 0x10))();
      param_2 = param_2 + iVar3;
      param_3 = param_3 + iVar3;
    }
    (**(code **)(puVar1 + 4))();
    iVar3 = 0;
  }
  else {
    iVar3 = 0x106;
  }
  return iVar3;
}


