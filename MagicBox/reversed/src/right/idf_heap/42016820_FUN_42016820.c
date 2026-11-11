int FUN_42016820(int *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1[5] == 0) {
    iVar2 = DAT_420010e0;
  }
  else if ((uint)param_1[5] < 2) {
    iVar4 = 0;
    uVar6 = 0;
    for (iVar2 = *param_1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      uVar5 = -(*(ushort *)(iVar2 + 0x40) - 0x7e);
      if (uVar6 < uVar5) {
        iVar4 = iVar2;
        uVar6 = uVar5;
      }
    }
    if (uVar6 == 0) {
      iVar2 = DAT_420010a4;
    }
    else {
      iVar2 = FUN_420167dc(param_1);
      if (iVar2 == 0) {
        iVar3 = param_1[1];
        sVar1 = *(short *)(iVar4 + 0x40);
        iVar2 = FUN_420157f0(iVar4);
        if (((iVar2 == 0) &&
            (iVar2 = FUN_42015920(iVar4,iVar3), iVar2 == 0 || iVar2 == DAT_42000cd4)) &&
           (iVar2 = FUN_420157b4(iVar4), iVar2 == 0)) {
          if (sVar1 == *(short *)(iVar3 + 0x40)) {
            FUN_42025060(param_1,iVar4);
            FUN_4202503c(param_1 + 3,iVar4);
          }
          else {
            iVar2 = -1;
          }
        }
      }
    }
  }
  else {
    iVar2 = FUN_420167dc(param_1);
  }
  return iVar2;
}