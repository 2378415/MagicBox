void FUN_420049cc(void)

{
  int iVar1;
  
  for (iVar1 = *DAT_42000598; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
    if (*(int *)(iVar1 + 0x1c) == 0) {
      FUN_42004980(iVar1);
      if (*(int *)(iVar1 + 0x1c) != 0) {
        (*(code *)PTR_FUN_420005b4)(*(int *)(iVar1 + 0x1c),iVar1 + 0x14);
      }
    }
  }
  return;
}