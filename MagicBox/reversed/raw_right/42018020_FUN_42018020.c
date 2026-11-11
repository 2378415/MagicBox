// 42018020  FUN_42018020  FUN_42018020  size=195

void FUN_42018020(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*(int *)PTR_PTR_420011bc != param_1) {
    if (*(int *)(param_1 + 0x24) != 0) {
      if (*(int *)(*(int *)(param_1 + 0x24) + 0xc) != 0) {
        iVar1 = 0;
        do {
          puVar2 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x24) + 0xc) + iVar1);
          while (puVar2 != (undefined4 *)0x0) {
            puVar2 = (undefined4 *)*puVar2;
            (*(code *)PTR_FUN_4200115c)(param_1);
          }
          iVar1 = iVar1 + 4;
        } while (iVar1 != 0x80);
        (*(code *)PTR_FUN_4200115c)(param_1,*(undefined4 *)(*(int *)(param_1 + 0x24) + 0xc));
      }
      if (**(int **)(param_1 + 0x24) != 0) {
        (*(code *)PTR_FUN_4200115c)(param_1);
      }
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      (*(code *)PTR_FUN_4200115c)(param_1);
    }
    if (*(int *)(param_1 + 0x24) != 0) {
      (*(code *)PTR_FUN_4200115c)(param_1);
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      (*(code *)PTR_FUN_4200115c)(param_1);
    }
    if (*(int *)(param_1 + 0x3c) != 0) {
      (*(code *)PTR_FUN_4200115c)(param_1);
    }
    if (*(int *)(param_1 + 0x40) != 0) {
      (*(code *)PTR_FUN_4200115c)(param_1);
    }
    if (*(int *)(param_1 + 0xec) != 0) {
      (*(code *)PTR_FUN_4200115c)(param_1);
    }
    if (*(int *)(param_1 + 0xe8) != 0) {
      (*(code *)PTR_FUN_4200115c)(param_1);
    }
    if (*(int *)(param_1 + 0x34) != 0) {
      (*(code *)PTR_FUN_4200115c)(param_1);
    }
    if (*(code **)(param_1 + 0x28) != (code *)0x0) {
      (**(code **)(param_1 + 0x28))(param_1);
    }
  }
  return;
}


