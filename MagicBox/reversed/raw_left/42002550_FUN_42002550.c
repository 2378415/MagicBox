// 42002550  FUN_42002550  FUN_42002550  size=65

void FUN_42002550(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  piVar1 = DAT_420000e4;
  memw();
  memw();
  *DAT_420000e4 = *DAT_420000e4 + 1;
  FUN_42002874();
  puVar4 = (undefined4 *)PTR_DAT_420000d4;
  memw();
  memw();
  *piVar1 = *piVar1 + 1;
  puVar5 = (undefined4 *)((int)puVar4 + 0x58);
  do {
    puVar3 = (undefined4 *)puVar4[1];
    for (puVar2 = (undefined4 *)*puVar4; puVar2 <= puVar3; puVar2 = puVar2 + 1) {
      memw();
      *puVar2 = 0;
    }
    puVar4 = puVar4 + 2;
  } while (puVar4 != puVar5);
  return;
}


