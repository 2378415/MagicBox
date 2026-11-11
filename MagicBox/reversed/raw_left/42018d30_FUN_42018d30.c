// 42018d30  FUN_42018d30  FUN_42018d30  size=72

undefined4 FUN_42018d30(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  piVar1 = DAT_42001690;
  if ((((*DAT_42001690 == 0) && (iVar4 = FUN_42018ab8(), iVar4 != 0)) ||
      ((param_1 == 0xff && (param_2 != 0xff)))) ||
     (piVar3 = (int *)(*(code *)PTR_FUN_4200056c)(0x14), piVar3 == (int *)0x0)) {
    uVar2 = 0;
  }
  else {
    iVar4 = *piVar1;
    *piVar3 = param_1;
    piVar3[3] = iVar4;
    piVar3[1] = param_2;
    piVar3[2] = param_3;
    piVar3[4] = 0;
    uVar2 = FUN_42018ca8();
  }
  return uVar2;
}


