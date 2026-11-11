undefined4 FUN_42002aa0(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 < 2) {
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_420003a4,0xffffffff);
    for (iVar2 = 0; iVar2 < 8; iVar2 = iVar2 + 1) {
      if (*(int *)((param_2 * 8 + iVar2) * 4 + DAT_420003b0) == 0) {
        *(undefined4 *)((param_2 * 8 + iVar2) * 4 + DAT_420003b0) = param_1;
        (*(code *)PTR_FUN_420003ac)(PTR_DAT_420003a4);
        return 0;
      }
    }
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_420003a4);
    uVar1 = 0x101;
  }
  else {
    uVar1 = 0x102;
  }
  return uVar1;
}