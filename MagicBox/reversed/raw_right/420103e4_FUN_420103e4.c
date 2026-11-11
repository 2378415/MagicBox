// 420103e4  FUN_420103e4  FUN_420103e4  size=125

undefined4 FUN_420103e4(void)

{
  undefined4 uVar1;
  int iVar2;
  
  (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000da8,0xffffffff);
  if (*DAT_42000dac == 0) {
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000da8);
    iVar2 = (*(code *)PTR_FUN_42000738)(1,0x10);
    if (iVar2 == 0) {
      uVar1 = 0x101;
    }
    else {
      (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000da8,0xffffffff);
      if (*DAT_42000dac == 0) {
        *DAT_42000dac = iVar2;
        *(undefined4 *)(iVar2 + 0xc) = 0;
        (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000da8);
        return 0;
      }
      (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000da8);
      uVar1 = 0;
    }
    (*(code *)PTR_FUN_420004c0)(iVar2);
  }
  else {
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000da8);
    uVar1 = 0;
  }
  return uVar1;
}


