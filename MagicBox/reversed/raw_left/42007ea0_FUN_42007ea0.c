// 42007ea0  FUN_42007ea0  FUN_42007ea0  size=69

undefined4 FUN_42007ea0(int *param_1,int param_2)

{
  undefined *puVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  
  piVar3 = (int *)(*(code *)PTR_FUN_4200056c)(0xc);
  if (piVar3 == (int *)0x0) {
    uVar4 = 0xc;
  }
  else {
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_420008f4,0xffffffff);
    piVar2 = DAT_420008f8;
    iVar5 = 1;
    piVar6 = (int *)*DAT_420008f8;
    if (piVar6 != (int *)0x0) {
      iVar5 = *piVar6 + 1;
    }
    *param_1 = iVar5;
    puVar1 = PTR_DAT_420008f4;
    *piVar3 = iVar5;
    piVar3[1] = param_2;
    piVar3[2] = (int)piVar6;
    *piVar2 = (int)piVar3;
    (*(code *)PTR_FUN_420004e0)(puVar1);
    uVar4 = 0;
  }
  return uVar4;
}


