undefined4 FUN_4201cbe8(int *param_1,uint param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = (int *)*param_1;
LAB_4201cc61:
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  do {
    iVar4 = piVar5[2];
    bVar2 = false;
    iVar6 = 0;
    bVar1 = false;
    if (iVar4 != 0) {
      do {
        bVar3 = (bool)(bVar1 | *(byte *)(piVar5 + iVar6 + 3) != 0xff);
        if (param_2 == *(byte *)(piVar5 + iVar6 + 3)) {
          *(undefined1 *)(piVar5 + iVar6 + 3) = 0xff;
          bVar2 = true;
          bVar3 = bVar1;
        }
        else {
          bVar1 = (bool)(bVar3 & bVar2);
        }
        if (bVar1) {
          return 1;
        }
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + -1;
        bVar1 = bVar3;
      } while (iVar4 != 0);
      if (bVar3) break;
    }
    iVar4 = *piVar5;
    piVar5 = (int *)piVar5[1];
    if (iVar4 == 0) {
      *param_1 = (int)piVar5;
    }
    else {
      *(int **)(iVar4 + 4) = piVar5;
    }
    iVar6 = param_1[2];
    if (piVar5 == (int *)0x0) {
      param_1[1] = iVar4;
      param_1[2] = iVar6 + -1;
      (*(code *)PTR_FUN_42000570)();
      if (!bVar2) {
        return 0;
      }
      return 1;
    }
    *piVar5 = iVar4;
    param_1[2] = iVar6 + -1;
    (*(code *)PTR_FUN_42000570)();
    if (bVar2) {
      return 1;
    }
  } while( true );
  piVar5 = (int *)piVar5[1];
  if (bVar2) {
    return 1;
  }
  goto LAB_4201cc61;
}