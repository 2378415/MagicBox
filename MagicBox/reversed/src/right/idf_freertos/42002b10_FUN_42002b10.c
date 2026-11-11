void FUN_42002b10(int param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 < 2) {
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_420003a4,0xffffffff);
    for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
      if (*(int *)((param_2 * 8 + iVar1) * 4 + DAT_4200039c) == param_1) {
        *(undefined4 *)((param_2 * 8 + iVar1) * 4 + DAT_4200039c) = 0;
      }
    }
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_420003a4);
  }
  return;
}