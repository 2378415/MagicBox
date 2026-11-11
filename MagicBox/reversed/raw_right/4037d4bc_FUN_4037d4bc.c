// 4037d4bc  FUN_4037d4bc  FUN_4037d4bc  size=166

void FUN_4037d4bc(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined1 in_PRID;
  
  iVar1 = FUN_4037bbc4();
  if (iVar1 == 0) {
    FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  }
  else {
    FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  }
  uVar2 = rsr(in_PRID);
  uVar2 = uVar2 >> 0xd & 1;
  memw();
  if (*(int *)(uVar2 * 4 + DAT_40374e18) == 0) {
    memw();
    *(undefined4 *)(uVar2 * 4 + DAT_40374eac) = 0;
    memw();
    piVar3 = *(int **)(*(int *)(uVar2 * 4 + DAT_40374d64) + 0x30);
    if ((((*piVar3 != DAT_40374eb4) || (piVar3[1] != DAT_40374eb4)) || (piVar3[2] != DAT_40374eb4))
       || (piVar3[3] != DAT_40374eb4)) {
      piVar3 = (int *)(uVar2 * 4 + DAT_40374d64);
      memw();
      memw();
      FUN_4037bde0(*piVar3,*piVar3 + 0x34);
    }
    FUN_4037caf4();
  }
  else {
    memw();
    *(undefined4 *)(uVar2 * 4 + DAT_40374eac) = 1;
  }
  iVar1 = FUN_4037bbc4();
  if (iVar1 == 0) {
    FUN_4037bd38(PTR_DAT_40374e54);
  }
  else {
    FUN_4037bd38(PTR_DAT_40374e54);
  }
  return;
}


