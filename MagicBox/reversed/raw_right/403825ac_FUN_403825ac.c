// 403825ac  FUN_403825ac  FUN_403825ac  size=201

int FUN_403825ac(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  
  if (*DAT_40374884 == param_1) {
    iVar2 = (**(code **)(PTR_PTR_40375258 + 0x14))(param_3,param_4);
    if (iVar2 == 0) {
      iVar2 = 0x106;
    }
    else {
      (**(code **)PTR_PTR_40375258)();
      for (; iVar2 = 0, param_4 != 0; param_4 = param_4 - iVar2) {
        if (((param_3 & 0x3f) == 0) && (0x3f < param_4)) {
          iVar2 = 0x40;
        }
        else if ((param_3 & 0x1f) == 0) {
          if (param_4 < 0x20) {
            iVar2 = 0x10;
          }
          else {
            iVar2 = 0x20;
          }
        }
        else {
          iVar2 = 0x10;
        }
        (**(code **)(PTR_PTR_40375258 + 8))(param_3,param_2,iVar2);
        iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x2c))(param_1,0);
        if (iVar1 != 0) {
          return iVar1;
        }
        (**(code **)(PTR_PTR_40375258 + 0xc))();
        iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x44))(param_1,param_2,param_3,param_4);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x54))
                          (param_1,*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x10));
        if (iVar1 != 0) {
          return iVar1;
        }
        (**(code **)(PTR_PTR_40375258 + 0x10))();
        param_2 = param_2 + iVar2;
        param_3 = param_3 + iVar2;
      }
      (**(code **)(PTR_PTR_40375258 + 4))();
    }
  }
  else {
    iVar2 = 0x106;
  }
  return iVar2;
}


