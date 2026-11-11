void FUN_4037cff0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined1 in_PRID;
  
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  piVar4 = DAT_40374e5c;
  memw();
  memw();
  *DAT_40374e5c = *DAT_40374e5c + 1;
  memw();
  if (*piVar4 == 1) {
    FUN_4037cf88();
  }
  memw();
  if ((*DAT_40374d64 == 0) &&
     (*(int *)(param_1 + 0x44) == 0 || *(int *)(param_1 + 0x44) == DAT_403747f4)) {
    memw();
    *DAT_40374d64 = param_1;
  }
  else {
    memw();
    if ((DAT_40374d64[1] == 0) &&
       (*(int *)(param_1 + 0x44) == 1 || *(int *)(param_1 + 0x44) == DAT_403747f4)) {
      memw();
      DAT_40374d64[1] = param_1;
    }
    else {
      memw();
      if (*DAT_40374e8c == 0) {
        memw();
        if (((*DAT_40374d64 == 0) ||
            (*(int *)(param_1 + 0x44) != 0 && *(int *)(param_1 + 0x44) != DAT_403747f4)) ||
           (memw(), *(uint *)(param_1 + 0x2c) < *(uint *)(*DAT_40374d64 + 0x2c))) {
          memw();
          if (((DAT_40374d64[1] != 0) &&
              (*(int *)(param_1 + 0x44) == 1 || *(int *)(param_1 + 0x44) == DAT_403747f4)) &&
             (memw(), *(uint *)(DAT_40374d64[1] + 0x2c) <= *(uint *)(param_1 + 0x2c))) {
            memw();
            DAT_40374d64[1] = param_1;
          }
        }
        else {
          memw();
          *DAT_40374d64 = param_1;
        }
      }
    }
  }
  *DAT_40374e90 = *DAT_40374e90 + 1;
  uVar2 = *(uint *)(param_1 + 0x2c);
  memw();
  if (*DAT_40374e30 < uVar2) {
    memw();
    *DAT_40374e30 = uVar2;
  }
  iVar1 = DAT_40374e34;
  memw();
  iVar3 = *(int *)(uVar2 * 0x14 + DAT_40374e34 + 4);
  memw();
  *(int *)(param_1 + 8) = iVar3;
  memw();
  memw();
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar3 + 8);
  memw();
  memw();
  *(int *)(*(int *)(iVar3 + 8) + 4) = param_1 + 4;
  memw();
  *(int *)(iVar3 + 8) = param_1 + 4;
  piVar4 = (int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar1);
  memw();
  *(int **)(param_1 + 0x14) = piVar4;
  memw();
  memw();
  *(int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar1) = *piVar4 + 1;
  memw();
  if ((*DAT_40374e8c != 0) &&
     (iVar1 = FUN_4037ca58(param_1,*(undefined4 *)(param_1 + 0x2c),1), iVar1 == 1)) {
    uVar2 = rsr(in_PRID);
    FUN_403787f4(uVar2 >> 0xd & 1);
  }
  FUN_4037bd38(PTR_DAT_40374e54);
  return;
}