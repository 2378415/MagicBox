undefined4 FUN_4201b060(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar1 = DAT_42001a38;
  piVar4 = (int *)*DAT_42001a38;
  do {
    if (piVar4 == (int *)0x0) {
LAB_4201b0c2:
      uVar2 = FUN_4201c7b0();
      uVar2 = FUN_4201c990(uVar2,param_1);
      return uVar2;
    }
    uVar2 = FUN_4202d788(piVar4[2]);
    iVar3 = (*DAT_42000c68)(uVar2,param_1,0x10);
    if (iVar3 == 0) {
      do {
        iVar3 = *piVar4;
        piVar5 = (int *)piVar4[1];
        if (iVar3 == 0) {
          *piVar1 = (int)piVar5;
          piVar4 = piVar5;
        }
        else {
          piVar4 = (int *)*piVar1;
          *(int **)(iVar3 + 4) = piVar5;
        }
        if (piVar5 == (int *)0x0) {
          piVar1[1] = iVar3;
        }
        else {
          *piVar5 = iVar3;
        }
        piVar1[2] = piVar1[2] + -1;
        while( true ) {
          if (piVar4 == (int *)0x0) goto LAB_4201b0c2;
          uVar2 = FUN_4202d788(piVar4[2]);
          iVar3 = (*DAT_42000c68)(uVar2,param_1,0x10);
          if (iVar3 == 0) break;
          piVar4 = (int *)piVar4[1];
        }
      } while( true );
    }
    piVar4 = (int *)piVar4[1];
  } while( true );
}