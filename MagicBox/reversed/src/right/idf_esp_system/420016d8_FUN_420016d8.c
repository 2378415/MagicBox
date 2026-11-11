void FUN_420016d8(void)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  undefined1 auStack_30 [10];
  byte bStack_26;
  
  FUN_42003d3c(auStack_30);
  if (bStack_26 < 2) {
    (*(code *)PTR_FUN_4200006c)();
  }
  (*(code *)PTR_FUN_42000070)(1);
  puVar1 = DAT_42000060;
  memw();
  if ((*DAT_42000060 & 2) == 0) {
    memw();
    memw();
    *DAT_42000060 = *DAT_42000060 | 2;
    memw();
    memw();
    *puVar1 = *puVar1 & 0xfffffffe;
    memw();
    memw();
    *puVar1 = *puVar1 | 4;
    memw();
    memw();
    *puVar1 = *puVar1 & 0xfffffffb;
  }
  (*DAT_42000074)(PTR_LAB_42000064);
  bVar2 = 0;
  while (bVar2 == 0) {
    bVar2 = 1;
    for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
      memw();
      bVar2 = bVar2 & *(byte *)(DAT_42000068 + iVar3);
    }
    (*DAT_42000078)(100);
  }
  return;
}