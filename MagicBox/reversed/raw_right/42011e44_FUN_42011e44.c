// 42011e44  FUN_42011e44  FUN_42011e44  size=58

undefined4 FUN_42011e44(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_42011d50();
  if (iVar1 == 0) {
    if (param_1 == 0xff && param_2 != 0xff) {
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_42011d84(param_1,param_2,param_3);
      uVar2 = 0;
      if (iVar1 != 0) {
        uVar2 = FUN_42011db8();
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


