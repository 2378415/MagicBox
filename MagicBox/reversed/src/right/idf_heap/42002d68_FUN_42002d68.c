void FUN_42002d68(void)

{
  int iVar1;
  
  for (iVar1 = *DAT_420003e8; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
    if (*(int *)(iVar1 + 0x1c) == 0) {
      FUN_42002d40(iVar1);
      if (*(int *)(iVar1 + 0x1c) != 0) {
        (*(code *)PTR_FUN_420003fc)(*(int *)(iVar1 + 0x1c),iVar1 + 0x14);
      }
    }
  }
  return;
}