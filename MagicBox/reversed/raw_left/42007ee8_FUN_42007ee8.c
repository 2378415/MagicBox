// 42007ee8  FUN_42007ee8  FUN_42007ee8  size=41

int FUN_42007ee8(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)PTR_FUN_42000908)(0);
  if (piVar1 != (int *)0x0) {
    for (piVar1 = (int *)*piVar1; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
      if (param_1 == *piVar1) {
        return piVar1[1];
      }
    }
  }
  return 0;
}


