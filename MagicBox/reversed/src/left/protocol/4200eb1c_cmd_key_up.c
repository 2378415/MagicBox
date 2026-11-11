void cmd_key_up(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 char *param_5,uint param_6)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  
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
    uVar4 = char_to_usage(param_5[1]);
    goto LAB_4200ec32;
  }
  uVar6 = param_6;
  while( true ) {
    pbVar3 = (byte *)(param_5 + uVar4);
    bVar1 = *pbVar3;
    bVar2 = bVar1 == 0x20 || bVar1 == 9;
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
    bVar2 = true;
LAB_4200ebac:
    uVar4 = uVar4 + 1;
    if (param_6 <= uVar4) {
      return;
    }
    pbVar3 = (byte *)(param_5 + uVar4);
  }
  else if (bVar1 == 0x2b) goto LAB_4200ebac;
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
  if (bVar2) {
    iVar7 = -iVar7;
  }
  iVar7 = (uint)(iVar7 < DAT_42000db0) * DAT_42000db0 + (uint)(iVar7 >= DAT_42000db0) * iVar7;
  uVar4 = (uint)(iVar7 < DAT_42000a38) * iVar7 + (uint)(iVar7 >= DAT_42000a38) * DAT_42000a38 &
          0xffff;
LAB_4200ec32:
  if (uVar4 != 0) {
    hid_key_up(param_3);
    uart0_reply(param_1,param_2,0);
  }
  return;
}