// 42015288  FUN_42015288  FUN_42015288  size=143

int FUN_42015288(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  uVar1 = (**(code **)(*param_2 + 8))(param_2);
  iVar2 = FUN_42015278(param_1,uVar1);
  if (iVar2 == 0) {
    iVar3 = (*(code *)PTR_FUN_420006e0)(0x68);
    if (iVar3 == 0) {
      return 0x101;
    }
    FUN_4201520c(iVar3,param_2);
    iVar2 = iVar3;
  }
  else {
    for (piVar4 = *(int **)(param_1 + 0x1c); piVar4 != (int *)0x0; piVar4 = (int *)piVar4[2]) {
      if (param_2 == piVar4) {
        FUN_42024da8(param_1 + 0x1c);
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 4))(param_2);
        }
        break;
      }
    }
    iVar3 = 0;
  }
  iVar2 = FUN_42014818(iVar2,param_3,param_4);
  if (iVar3 != 0) {
    if (iVar2 == 0) {
      FUN_42024dcc(param_1 + 0x10,iVar3);
    }
    else {
      FUN_42014808(iVar3);
      (*(code *)PTR_FUN_420004c0)(iVar3);
    }
  }
  return iVar2;
}


