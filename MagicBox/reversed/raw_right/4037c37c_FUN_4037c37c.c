// 4037c37c  FUN_4037c37c  FUN_4037c37c  size=129

void FUN_4037c37c(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 in_PRID;
  undefined8 uVar7;
  
  uVar3 = rsr(in_PRID);
  uVar4 = uVar3 >> 0xd & 1;
  do {
    memw();
    uVar2 = 1 << 0x20 - (0x20 - (uVar3 >> 0xd & 1));
    memw();
    *(uint *)(*param_1 + 0x6c) = *(uint *)(*param_1 + 0x6c) | uVar2;
    uVar7 = FUN_40380530(param_1);
    memw();
    iVar1 = (*DAT_403744c8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),
                            *(uint *)((uVar4 + 0xc) * 4 + *param_1 + 4) & 0x3ffffff,0);
    iVar6 = *(int *)(uVar4 * 4 + DAT_40374dbc);
    iVar5 = iVar1 - iVar6;
    if (iVar1 != iVar6) {
      if (iVar6 == 0) {
        *(int *)(uVar4 * 4 + DAT_40374dbc) = iVar5;
        iVar5 = 1;
      }
      else {
        *(int *)(uVar4 * 4 + DAT_40374dbc) = iVar1;
      }
      do {
        FUN_4037c354();
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    memw();
  } while ((uVar2 & *(uint *)(*param_1 + 0x70)) != 0);
  return;
}


