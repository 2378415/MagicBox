// 4037c594  FUN_4037c594  FUN_4037c594  size=141

void FUN_4037c594(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 in_PRID;
  undefined8 uVar9;
  
  uVar2 = rsr(in_PRID);
  uVar3 = uVar2 >> 0xd & 1;
  iVar5 = *param_1;
  uVar2 = 1 << 0x20 - (0x20 - (uVar2 >> 0xd & 1));
  piVar4 = (int *)(uVar3 * 4 + DAT_40374e54);
  do {
    memw();
    memw();
    *(uint *)(iVar5 + 0x6c) = *(uint *)(iVar5 + 0x6c) | uVar2;
    uVar9 = FUN_40380640(param_1,1);
    iVar5 = *param_1;
    memw();
    iVar1 = (*DAT_40374500)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),
                            *(uint *)(iVar5 + (uVar3 + 0xc) * 4 + 4) & 0x3ffffff,0);
    iVar6 = *piVar4;
    if (iVar1 != iVar6) {
      iVar8 = iVar1 - iVar6;
      iVar5 = 1;
      if (iVar6 != 0) {
        iVar8 = iVar1;
        iVar5 = iVar1 - iVar6;
      }
      *piVar4 = iVar8;
      do {
        FUN_40376208();
        uVar7 = rsr(in_PRID);
        if ((uVar7 >> 0xd & 1) == 0) {
          iVar1 = FUN_4037d5c8();
        }
        else {
          iVar1 = FUN_4037e9f4();
        }
        if (iVar1 != 0) {
          FUN_4037c210();
        }
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      iVar5 = *param_1;
    }
    memw();
  } while ((uVar2 & *(uint *)(iVar5 + 0x70)) != 0);
  return;
}


