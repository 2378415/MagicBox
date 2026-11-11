void cmd_move(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 char *param_5,uint param_6)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  short local_50 [2];
  uint uStack_4c;
  undefined2 uStack_48;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  int iStack_34;
  char *pcStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uVar6 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uVar4 = 0;
  uVar13 = 0;
  uVar12 = 0;
  pcVar5 = param_5;
LAB_4200e04a:
  uVar4 = uVar4 + 1;
  if (param_6 == uVar6) {
LAB_4200e068:
    uVar7 = uVar12 + 1;
    sVar9 = 0;
    if (uVar13 < uVar6) {
      iVar10 = uVar6 - uVar13;
      do {
        pbVar8 = (byte *)(param_5 + uVar13);
        bVar3 = *pbVar8;
        uStack_38 = uVar12;
        if (bVar3 != 0x20 && bVar3 != 9) {
          if (uVar6 <= uVar13) {
            sVar9 = 0;
            goto LAB_4200e152;
          }
          if (bVar3 == 0x2d) {
            iVar10 = 1;
          }
          else {
            iVar10 = 0;
            if (bVar3 != 0x2b) goto LAB_4200e0e8;
          }
          uVar13 = uVar13 + 1;
          pbVar8 = (byte *)(param_5 + uVar13);
          if (uVar13 < uVar6) goto LAB_4200e0e8;
          goto LAB_4200e0d8;
        }
        uVar13 = uVar13 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      sVar9 = 0;
    }
    goto LAB_4200e152;
  }
  cVar2 = *pcVar5;
  if ((cVar2 == ',') || (uVar7 = uVar12, cVar2 == ')' || cVar2 == ',')) goto LAB_4200e068;
  goto LAB_4200e15c;
LAB_4200e0e8:
  if (*pbVar8 != 0x20 && *pbVar8 != 9) goto LAB_4200e0dd;
  uVar13 = uVar13 + 1;
  if (uVar13 == uVar6) {
    sVar9 = 0;
    goto LAB_4200e152;
  }
  pbVar8 = (byte *)(param_5 + uVar13);
  goto LAB_4200e0e8;
LAB_4200e0dd:
  uVar11 = 0;
  if (uVar13 < uVar6) {
    bVar1 = (*pbVar8 - 0x30 & 0xff) < 10;
    if (bVar1) {
      uVar11 = *pbVar8 - 0x30;
    }
    sVar9 = 0;
    iStack_34 = iVar10;
    pcStack_30 = pcVar5;
    if (bVar1) {
      if (iVar10 != 0) {
        uVar11 = -uVar11;
      }
      iVar10 = (uint)((int)uVar11 < DAT_42000db0) * DAT_42000db0 +
               ((int)uVar11 >= DAT_42000db0) * uVar11;
      sVar9 = (ushort)(iVar10 < DAT_42000a38) * (short)iVar10 +
              (ushort)(iVar10 >= DAT_42000a38) * (short)DAT_42000a38;
    }
  }
  else {
LAB_4200e0d8:
    sVar9 = 0;
  }
LAB_4200e152:
  local_50[uVar12] = sVar9;
  uVar13 = uVar4;
  uStack_3c = uVar7;
LAB_4200e15c:
  uVar6 = uVar6 + 1;
  pcVar5 = pcVar5 + 1;
  if (((-(param_6 - 1) & 0xff) == 0) || (uVar12 = uVar7, uVar7 == 5)) goto LAB_4200e178;
  goto LAB_4200e04a;
LAB_4200e178:
  if (uVar7 < 2) {
    return;
  }
  uStack_40 = param_6;
  uStack_2c = param_3;
  uStack_28 = param_1;
  uStack_24 = param_2;
  if (uVar7 == 2) {
LAB_4200e19e:
    uVar12 = 1;
  }
  else {
    uVar12 = uStack_4c & 0xffff;
    if (uVar7 == 5) {
      mouse_submit_ext();
      goto LAB_4200e1a4;
    }
    if (uVar12 < 2) goto LAB_4200e19e;
  }
  mouse_move(param_3,(int)local_50[0],(int)local_50[1],uVar12);
LAB_4200e1a4:
  uart0_reply(uStack_28,uStack_24,0);
  return;
}