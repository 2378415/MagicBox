int FUN_40380898(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 == 0 || param_1 == 0) {
    iVar1 = 0;
  }
  else {
    FUN_40380854(param_1);
    iVar1 = FUN_40380d74(*(undefined4 *)(param_1 + 0x10),param_2);
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
  return iVar1;
}