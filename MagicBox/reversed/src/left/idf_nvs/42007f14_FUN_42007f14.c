undefined4 FUN_42007f14(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_420008f4,0xffffffff);
  piVar1 = (int *)*DAT_420008f8;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      (*(code *)PTR_FUN_420004e0)(PTR_DAT_420008f4);
      return 2;
    }
    if (param_1 == *piVar1) break;
    piVar1 = (int *)piVar1[2];
  }
  (*(code *)PTR_FUN_420004e0)(PTR_DAT_420008f4);
  piVar1 = (int *)(*(code *)PTR_FUN_42000908)(0);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)(*(code *)PTR_FUN_42000910)(1,4);
    if (piVar1 == (int *)0x0) {
      return 0xc;
    }
    (*(code *)PTR_FUN_42000914)(0,0,piVar1,PTR_LAB_4200090c);
  }
  piVar4 = (int *)*piVar1;
  if (piVar4 != (int *)0x0) {
    piVar5 = piVar4;
    do {
      if (param_1 == *piVar5) {
        if (param_2 != 0) {
          piVar5[1] = param_2;
          return 0;
        }
        if (piVar4 == piVar5) {
          *piVar1 = piVar5[2];
        }
        else {
          do {
            piVar1 = piVar4;
            piVar4 = (int *)piVar1[2];
          } while (piVar4 != piVar5);
          piVar1[2] = piVar5[2];
        }
        (*(code *)PTR_FUN_42000570)();
        return 0;
      }
      piVar5 = (int *)piVar5[2];
    } while (piVar5 != (int *)0x0);
  }
  if (param_2 != 0) {
    piVar4 = (int *)(*(code *)PTR_FUN_4200056c)(0xc);
    if (piVar4 == (int *)0x0) {
      return 0xc;
    }
    iVar2 = *piVar1;
    *piVar4 = param_1;
    piVar4[1] = param_2;
    if (iVar2 == 0) {
      piVar4[2] = 0;
      *piVar1 = (int)piVar4;
    }
    else {
      do {
        iVar3 = iVar2;
        iVar2 = *(int *)(iVar3 + 8);
      } while (iVar2 != 0);
      piVar4[2] = 0;
      *(int **)(iVar3 + 8) = piVar4;
    }
  }
  return 0;
}