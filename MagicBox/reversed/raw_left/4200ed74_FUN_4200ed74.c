// 4200ed74  FUN_4200ed74  FUN_4200ed74  size=327

void FUN_4200ed74(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 char *param_5,uint param_6)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  char acStack_50 [32];
  int iStack_30;
  
  if (param_6 == 0) {
    return;
  }
  uVar4 = 0;
  if (*param_5 == '\'') {
    if (param_6 < 3) {
      return;
    }
    if (param_5[param_6 - 1] != '\'') {
      return;
    }
    uVar4 = FUN_4202d2a0(param_5[1]);
    goto LAB_4200ee88;
  }
  uVar6 = param_6;
  while( true ) {
    pbVar3 = (byte *)(param_5 + uVar4);
    bVar1 = *pbVar3;
    if (bVar1 != 0x20 && bVar1 != 9) break;
    uVar4 = uVar4 + 1;
    uVar6 = uVar6 - 1;
    if (uVar6 == 0) {
      return;
    }
  }
  if (param_6 <= uVar4) {
    return;
  }
  if (bVar1 == 0x2d) {
    iStack_30 = 1;
LAB_4200ee02:
    uVar4 = uVar4 + 1;
    if (param_6 <= uVar4) {
      return;
    }
    pbVar3 = (byte *)(param_5 + uVar4);
  }
  else {
    iStack_30 = 0;
    if (bVar1 == 0x2b) goto LAB_4200ee02;
  }
  while (*pbVar3 == 0x20 || *pbVar3 == 9) {
    uVar4 = uVar4 + 1;
    if (param_6 == uVar4) {
      return;
    }
    pbVar3 = (byte *)(param_5 + uVar4);
  }
  if (param_6 <= uVar4) {
    return;
  }
  param_5 = param_5 + (param_6 - (int)pbVar3);
  bVar5 = false;
  iVar7 = 0;
  do {
    uVar4 = (uint)*pbVar3;
    if ((uVar4 - 0x30 & 0xff) < 10) {
      iVar7 = iVar7 * 10 + (uVar4 - 0x30);
      bVar5 = true;
    }
    else if ((uVar4 != 0x20) && (uVar4 != 9)) break;
    pbVar3 = pbVar3 + 1;
    param_5 = param_5 + -1;
  } while (param_5 != (char *)0x0);
  if (!bVar5) {
    return;
  }
  if (iStack_30 != 0) {
    iVar7 = -iVar7;
  }
  iVar7 = (uint)(iVar7 < DAT_42000db0) * DAT_42000db0 + (uint)(iVar7 >= DAT_42000db0) * iVar7;
  uVar4 = (uint)(iVar7 < DAT_42000a38) * iVar7 + (uint)(iVar7 >= DAT_42000a38) * DAT_42000a38 &
          0xffff;
LAB_4200ee88:
  if (uVar4 != 0) {
    cVar2 = FUN_4201100c(param_3);
    iVar7 = param_4[1];
    if (iVar7 + 2U < 0x21) {
      (*DAT_42000064)(acStack_50,*param_4,iVar7);
      acStack_50[iVar7 + 1] = cVar2 + '0';
      acStack_50[iVar7] = '\n';
      FUN_420143e8(acStack_50,iVar7 + 2U,0);
    }
  }
  return;
}


