// 42013904  FUN_42013904  FUN_42013904  size=87

undefined4 FUN_42013904(void)

{
  int iVar1;
  
  (*(code *)PTR_FUN_420003a8)(PTR_DAT_42001054,0xffffffff);
  if (*DAT_42001058 == '\0') {
    (*(code *)PTR_FUN_42001060)();
    iVar1 = FUN_42005d14(2);
    *DAT_4200105c = iVar1;
    if (iVar1 == 0) {
      (*(code *)PTR_FUN_42001064)();
      (*(code *)PTR_FUN_420003ac)(PTR_DAT_42001054);
      return 0;
    }
  }
  *DAT_42001058 = *DAT_42001058 + '\x01';
  (*(code *)PTR_FUN_420003ac)(PTR_DAT_42001054);
  return 1;
}


