// 42010244  FUN_42010244  FUN_42010244  size=98

void FUN_42010244(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 4) != 0)) &&
     (bVar1 = *(byte *)(*(int *)(param_1 + 4) + 2), uVar2 = bVar1 & 0xf, (bVar1 & 8) == 0)) {
    memw();
    memw();
    *(undefined1 *)(uVar2 + DAT_42000d6c) = 0;
    memw();
    memw();
    *(undefined4 *)(uVar2 * 4 + DAT_42000d70) = 0;
    iVar3 = *(int *)(uVar2 * 4 + DAT_42000d64);
    if (iVar3 != 0) {
      (*(code *)PTR_FUN_42000d10)(iVar3,0);
    }
  }
  memw();
  memw();
  if (*DAT_42000d84 == param_1) {
    memw();
    memw();
    *DAT_42000d84 = 0;
  }
  return;
}


