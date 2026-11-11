void FUN_42004148(int param_1,uint param_2)

{
  int *piVar1;
  
  if (param_2 < 2) {
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_420004d8,0xffffffff);
    piVar1 = (int *)(param_2 * 0x20 + DAT_420004d0);
    if (param_1 == *piVar1) {
      *piVar1 = 0;
    }
    (*(code *)PTR_FUN_420004e0)(PTR_DAT_420004d8);
  }
  return;
}