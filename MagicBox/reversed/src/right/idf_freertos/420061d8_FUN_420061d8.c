void FUN_420061d8(int param_1)

{
  int *piVar1;
  
  (*(code *)PTR_FUN_420003a8)(PTR_DAT_4200071c,0xffffffff);
  for (piVar1 = (int *)*DAT_42000720; (piVar1 != (int *)0x0 && (*piVar1 != param_1));
      piVar1 = (int *)piVar1[2]) {
  }
  (*(code *)PTR_FUN_420003ac)(PTR_DAT_4200071c);
  return;
}