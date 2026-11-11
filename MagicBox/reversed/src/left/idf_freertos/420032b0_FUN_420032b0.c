void FUN_420032b0(undefined4 param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  piVar2 = DAT_420002b4;
  puVar1 = DAT_420002b0;
  memw();
  if ((DAT_420002b0[1] & 2) == 0) {
    iVar3 = *DAT_420002b4;
    do {
      if (499 < iVar3) break;
      (*DAT_420002b8)(100);
      memw();
      uVar4 = puVar1[1];
      iVar3 = *piVar2 + 1;
      *piVar2 = iVar3;
    } while ((uVar4 & 2) == 0);
  }
  memw();
  if ((puVar1[1] & 2) != 0) {
    memw();
    if ((puVar1[1] & 2) != 0) {
      memw();
      *puVar1 = param_1;
    }
    *DAT_420002b4 = 0;
  }
  return;
}