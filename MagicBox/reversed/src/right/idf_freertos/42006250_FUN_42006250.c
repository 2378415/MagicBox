undefined4 FUN_42006250(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar2 = (int *)(*(code *)PTR_FUN_420006e0)(0xc);
  if (piVar2 == (int *)0x0) {
    uVar3 = 0xc;
  }
  else {
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_4200071c,0xffffffff);
    if ((int *)*DAT_42000720 == (int *)0x0) {
      iVar4 = 1;
    }
    else {
      iVar4 = *(int *)*DAT_42000720 + 1;
    }
    *piVar2 = iVar4;
    piVar2[1] = param_2;
    *param_1 = iVar4;
    piVar1 = DAT_42000720;
    piVar2[2] = *DAT_42000720;
    *piVar1 = (int)piVar2;
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_4200071c);
    uVar3 = 0;
  }
  return uVar3;
}