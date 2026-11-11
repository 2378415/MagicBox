// 4200ea04  FUN_4200ea04  FUN_4200ea04  size=276

void FUN_4200ea04(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,uint param_6)

{
  bool bVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if (param_6 == 0) {
    return;
  }
  iVar4 = FUN_4200e458(param_5,param_6);
  uVar7 = 0;
  if (2 < param_6) {
    param_6 = param_6 - 2;
    uVar6 = param_6;
    do {
      iVar5 = param_5 + uVar7;
      cVar2 = *(char *)(iVar5 + 2);
      bVar3 = cVar2 == ' ' || cVar2 == '\t';
      if (cVar2 != ' ' && cVar2 != '\t') {
        if (uVar7 < param_6) {
          if (cVar2 == '-') {
            bVar3 = true;
          }
          else if (cVar2 != '+') goto LAB_4200ea80;
          uVar7 = uVar7 + 1;
          if (uVar7 < param_6) {
            iVar5 = param_5 + uVar7;
            goto LAB_4200ea80;
          }
        }
        break;
      }
      uVar7 = uVar7 + 1;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
LAB_4200eafc:
    uVar7 = 0;
  }
LAB_4200eb05:
  if (iVar4 != 0) {
    FUN_4202d4a8(param_3,iVar4,uVar7);
    FUN_420143e8(param_1,param_2,0);
  }
  return;
LAB_4200ea80:
  if (*(char *)(iVar5 + 2) != ' ' && *(char *)(iVar5 + 2) != '\t') goto code_r0x4200ea99;
  uVar7 = uVar7 + 1;
  if (param_6 == uVar7) goto LAB_4200eafc;
  iVar5 = param_5 + uVar7;
  goto LAB_4200ea80;
code_r0x4200ea99:
  if (uVar7 < param_6) {
    uVar6 = *(byte *)(param_5 + uVar7 + 2) - 0x30;
    bVar1 = 9 < (uVar6 & 0xff);
    if (bVar1) {
      uVar6 = 0;
    }
    uVar7 = 0;
    if (!bVar1) {
      if (bVar3) {
        uVar6 = -uVar6;
      }
      iVar5 = (uint)((int)uVar6 < DAT_42000db0) * DAT_42000db0 +
              ((int)uVar6 >= DAT_42000db0) * uVar6;
      uVar7 = (uint)(iVar5 < DAT_42000a38) * iVar5 + (uint)(iVar5 >= DAT_42000a38) * DAT_42000a38 &
              0xff;
    }
  }
  else {
    uVar7 = 0;
  }
  goto LAB_4200eb05;
}


