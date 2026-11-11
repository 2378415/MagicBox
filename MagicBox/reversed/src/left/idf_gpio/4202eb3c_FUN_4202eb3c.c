void FUN_4202eb3c(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = param_2 * 4 + iVar2;
  memw();
  memw();
  *(uint *)(iVar1 + 0x74) = *(uint *)(iVar1 + 0x74) & DAT_42001f5c;
  if (param_2 < 0x20) {
    memw();
    *(int *)(iVar2 + 0x4c) = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  }
  else {
    memw();
    memw();
    *(int *)(iVar2 + 0x58) =
         (int)(CONCAT44(*(uint *)(iVar2 + 0x58) >> 0x16,
                        (1 << 0x20 - (0x20 - (param_2 & 0x1f))) << 10) >> 10);
  }
  return;
}