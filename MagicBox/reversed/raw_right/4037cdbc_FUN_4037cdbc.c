// 4037cdbc  FUN_4037cdbc  FUN_4037cdbc  size=279

void FUN_4037cdbc(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined1 in_PRID;
  
  memw();
  uVar2 = *DAT_40374e68;
  uVar3 = rsr(in_PRID);
  uVar3 = uVar3 >> 0xd & 1;
  memw();
  memw();
  if (*(int *)(*(int *)(uVar3 * 4 + DAT_40374d64) + 0x14) != DAT_40374e58) {
    piVar4 = (int *)(uVar3 * 4 + DAT_40374d64);
    memw();
    *(undefined1 *)(*piVar4 + 0x152) = 0;
    memw();
    FUN_4037c980(*piVar4 + 4);
    piVar4 = DAT_40374e6c;
    if (param_1 == -1 && param_2 != 0) {
      memw();
      iVar6 = DAT_40374e6c[1];
      piVar5 = (int *)(uVar3 * 4 + DAT_40374d64);
      memw();
      memw();
      *(int *)(*piVar5 + 8) = iVar6;
      memw();
      memw();
      memw();
      *(undefined4 *)(*piVar5 + 0xc) = *(undefined4 *)(iVar6 + 8);
      memw();
      memw();
      memw();
      *(int *)(*(int *)(iVar6 + 8) + 4) = *piVar5 + 4;
      memw();
      memw();
      *(int *)(iVar6 + 8) = *piVar5 + 4;
      memw();
      memw();
      *(int **)(*piVar5 + 0x14) = piVar4;
      memw();
      memw();
      *piVar4 = *piVar4 + 1;
    }
    else {
      uVar1 = uVar2 + param_1;
      memw();
      memw();
      *(uint *)(*(int *)(uVar3 * 4 + DAT_40374d64) + 4) = uVar1;
      if (uVar1 < uVar2) {
        memw();
        memw();
        FUN_4037c924(*DAT_40374e70,*(int *)(uVar3 * 4 + DAT_40374d64) + 4);
      }
      else {
        memw();
        memw();
        FUN_4037c924(*DAT_40374e1c,*(int *)(uVar3 * 4 + DAT_40374d64) + 4);
        memw();
        if (uVar1 < *DAT_40374e20) {
          memw();
          *DAT_40374e20 = uVar1;
        }
      }
    }
  }
  return;
}


