undefined4 FUN_4201c990(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  
  piVar1 = (int *)FUN_4201c81c(param_1,param_2);
  if (piVar1 == (int *)0x0) {
    uVar2 = DAT_42001a70;
  }
  else {
    iVar3 = *(int *)(param_1 + 4);
    while (iVar3 != 0) {
      iVar5 = *(int *)(iVar3 + 8);
      if (*(int **)(iVar3 + 0xc) == piVar1) {
        iVar6 = *(int *)(iVar3 + 4);
        *(undefined1 *)(iVar3 + 0x12) = 0;
        if (iVar6 == 0) {
          *(int *)(param_1 + 4) = iVar5;
          iVar3 = iVar5;
        }
        else {
          *(int *)(iVar6 + 8) = iVar5;
          iVar3 = *(int *)(iVar3 + 8);
        }
        if (iVar5 == 0) {
          *(int *)(param_1 + 8) = iVar6;
        }
        else {
          *(int *)(iVar5 + 4) = iVar6;
        }
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
      }
      else {
        iVar3 = iVar5;
      }
    }
    iVar3 = *piVar1;
    piVar4 = (int *)piVar1[1];
    if (iVar3 == 0) {
      *(int **)(param_1 + 0x10) = piVar4;
    }
    else {
      *(int **)(iVar3 + 4) = piVar4;
    }
    if (piVar4 == (int *)0x0) {
      *(int *)(param_1 + 0x14) = iVar3;
    }
    else {
      *piVar4 = iVar3;
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
    FUN_4201b438(piVar1);
    (*(code *)PTR_FUN_42000570)(piVar1);
    piVar1 = *(int **)(param_1 + 0x1c);
    do {
      piVar4 = piVar1;
      if (piVar4 == (int *)0x0) goto LAB_4201ca48;
      uVar2 = (**(code **)(*piVar4 + 8))(piVar4);
      iVar3 = (*DAT_42000568)(uVar2,param_2);
      piVar1 = (int *)piVar4[2];
    } while (iVar3 != 0);
    iVar3 = piVar4[1];
    if (iVar3 == 0) {
      *(int **)(param_1 + 0x1c) = piVar1;
    }
    else {
      *(int **)(iVar3 + 8) = piVar1;
    }
    if (piVar1 == (int *)0x0) {
      *(int *)(param_1 + 0x20) = iVar3;
    }
    else {
      piVar1[1] = iVar3;
    }
    pcVar7 = *(code **)(*piVar4 + 4);
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
    (*pcVar7)(piVar4);
LAB_4201ca48:
    uVar2 = 0;
  }
  return uVar2;
}