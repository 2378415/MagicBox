void FUN_4202ebe0(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  (*DAT_42000094)(param_2,0,0x1c);
  if (param_1 != (int *)0x0) {
    iVar4 = *param_1;
    if (iVar4 != 0) {
      (*(code *)PTR_FUN_420004c8)();
      (*(code *)PTR_FUN_420004dc)(iVar4,0xffffffff);
    }
    uVar1 = (*(code *)PTR_FUN_42001f74)(param_1[4]);
    FUN_4202eca8(uVar1,PTR_FUN_42001f70,param_2);
    iVar3 = param_2[4];
    iVar4 = (*(code *)PTR_FUN_42001f78)();
    iVar5 = param_1[3];
    iVar2 = (*(code *)PTR_FUN_42001f6c)(param_1[4]);
    iVar6 = param_1[1];
    iVar8 = param_1[2];
    iVar7 = param_1[4];
    param_2[1] = ((iVar5 - iVar6) - iVar2) - iVar3 * iVar4;
    param_2[3] = iVar8;
    *param_2 = iVar6;
    iVar4 = FUN_4202ecfc(iVar7,param_2[2]);
    iVar2 = *param_1;
    param_2[2] = iVar4;
    if (iVar2 != 0) {
      (*(code *)PTR_FUN_420004c8)();
      (*(code *)PTR_FUN_420004e0)(iVar2);
    }
  }
  return;
}