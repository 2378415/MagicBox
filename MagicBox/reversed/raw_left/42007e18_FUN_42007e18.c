// 42007e18  FUN_42007e18  FUN_42007e18  size=102

void FUN_42007e18(int *param_1)

{
  undefined *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  piVar2 = DAT_420008f8;
  puVar1 = PTR_DAT_420008f4;
  piVar3 = (int *)*param_1;
  do {
    if (piVar3 == (int *)0x0) {
      (*(code *)PTR_FUN_42000570)(param_1);
      return;
    }
    *param_1 = piVar3[2];
    iVar4 = *piVar3;
    (*(code *)PTR_FUN_420004dc)(puVar1,0xffffffff);
    for (piVar5 = (int *)*piVar2; piVar5 != (int *)0x0; piVar5 = (int *)piVar5[2]) {
      if (iVar4 == *piVar5) {
        (*(code *)PTR_FUN_420004e0)(puVar1);
        if ((code *)piVar5[1] != (code *)0x0) {
          (*(code *)piVar5[1])(piVar3[1]);
        }
        goto LAB_42007e4b;
      }
    }
    (*(code *)PTR_FUN_420004e0)(puVar1);
LAB_42007e4b:
    (*(code *)PTR_FUN_42000570)(piVar3);
    piVar3 = (int *)*param_1;
  } while( true );
}


