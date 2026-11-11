int FUN_4201c840(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  code *pcVar7;
  
  uVar2 = (**(code **)(*param_2 + 8))(param_2);
  iVar3 = FUN_4201c81c(param_1,uVar2);
  if (iVar3 == 0) {
    piVar4 = (int *)(*(code *)PTR_FUN_4200056c)(0x68);
    if (piVar4 == (int *)0x0) {
      iVar3 = 0x101;
    }
    else {
      *piVar4 = 0;
      piVar4[1] = 0;
      piVar4[4] = 0;
      piVar4[5] = 0;
      piVar4[6] = 0;
      piVar4[7] = 0;
      piVar4[8] = 0;
      piVar4[9] = 0;
      piVar4[10] = 0;
      piVar4[0xe] = 0;
      piVar4[0xf] = 0;
      piVar4[0x10] = 0;
      piVar4[0x19] = 0;
      piVar4[2] = (int)param_2;
      iVar3 = FUN_4201b810(piVar4,param_3,param_4);
      if (iVar3 == 0) {
        iVar6 = *(int *)(param_1 + 0x14);
        if (iVar6 != 0) {
          *(int **)(iVar6 + 4) = piVar4;
        }
        *piVar4 = iVar6;
        iVar6 = *(int *)(param_1 + 0x10);
        piVar4[1] = 0;
        *(int **)(param_1 + 0x14) = piVar4;
        if (iVar6 == 0) {
          *(int **)(param_1 + 0x10) = piVar4;
        }
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
      }
      else {
        FUN_4201b438(piVar4);
        (*(code *)PTR_FUN_42000570)(piVar4);
      }
    }
  }
  else {
    piVar4 = *(int **)(param_1 + 0x1c);
    do {
      if (piVar4 == (int *)0x0) goto LAB_4201c8c2;
      piVar5 = (int *)piVar4[2];
      bVar1 = piVar4 != param_2;
      piVar4 = piVar5;
    } while (bVar1);
    iVar6 = param_2[1];
    if (iVar6 == 0) {
      *(int **)(param_1 + 0x1c) = piVar5;
    }
    else {
      *(int **)(iVar6 + 8) = piVar5;
    }
    if (piVar5 == (int *)0x0) {
      *(int *)(param_1 + 0x20) = iVar6;
    }
    else {
      piVar5[1] = iVar6;
    }
    pcVar7 = *(code **)(*param_2 + 4);
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
    (*pcVar7)(param_2);
LAB_4201c8c2:
    iVar3 = FUN_4201b810(iVar3,param_3,param_4);
  }
  return iVar3;
}