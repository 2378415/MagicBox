int FUN_40380788(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else if (param_2 == 0) {
    iVar1 = 0;
  }
  else if ((param_3 - 1 & param_3) == 0) {
    if (param_3 == 0) {
      iVar1 = 0;
    }
    else {
      FUN_40380854(param_1);
      iVar1 = FUN_40381144(*(undefined4 *)(param_1 + 0x10),param_3,param_2,param_4);
      if (iVar1 != 0) {
        iVar2 = FUN_4038096c();
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - iVar2;
        iVar2 = FUN_40380964();
        uVar3 = *(int *)(param_1 + 4) - iVar2;
        *(uint *)(param_1 + 4) = uVar3;
        if (uVar3 < *(uint *)(param_1 + 8)) {
          *(uint *)(param_1 + 8) = uVar3;
        }
      }
      FUN_40380878(param_1);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}