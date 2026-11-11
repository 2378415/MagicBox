// 420139c4  FUN_420139c4  FUN_420139c4  size=114

void FUN_420139c4(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  (*(code *)PTR_FUN_420003a8)(PTR_DAT_4200107c,0xffffffff);
  iVar2 = DAT_42001080;
  *(undefined1 *)(DAT_42001080 + param_1) = 0;
  uVar3 = *(uint *)(iVar2 + 0x18);
  uVar1 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
  if ((param_1 & 0x20) != 0) {
    uVar1 = 0;
  }
  uVar3 = uVar1 & uVar3 ^ uVar3;
  *(uint *)(iVar2 + 0x18) = uVar3;
  if (uVar3 == 0) {
    for (iVar2 = 1; iVar2 != 0; iVar2 = iVar2 + -1) {
      (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000e08,0xffffffff);
      memw();
      memw();
      *(uint *)(DAT_42001084 + 0x104) = *(uint *)(DAT_42001084 + 0x104) & 0x7fffffff;
      (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000e08);
    }
  }
  (*(code *)PTR_FUN_420003ac)(PTR_DAT_4200107c);
  return;
}


