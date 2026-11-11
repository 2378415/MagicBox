void cmd_wheel(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,uint param_6)

{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar5 = 0;
  if (param_6 != 0) {
    uVar6 = param_6;
    do {
      pbVar4 = (byte *)(param_5 + uVar5);
      bVar2 = *pbVar4;
      bVar3 = bVar2 == 0x20 || bVar2 == 9;
      if (bVar2 != 0x20 && bVar2 != 9) {
        if (uVar5 < param_6) {
          if (bVar2 == 0x2d) {
            bVar3 = true;
          }
          else if (bVar2 != 0x2b) goto LAB_4200e3c2;
          uVar5 = uVar5 + 1;
          if (uVar5 < param_6) {
            pbVar4 = (byte *)(param_5 + uVar5);
            goto LAB_4200e3c2;
          }
        }
        break;
      }
      uVar5 = uVar5 + 1;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
LAB_4200e43e:
    uVar5 = 0;
  }
LAB_4200e449:
  wheel_write(param_3,uVar5);
  uart0_reply(param_1,param_2,0);
  return;
LAB_4200e3c2:
  if (*pbVar4 != 0x20 && *pbVar4 != 9) goto code_r0x4200e3db;
  uVar5 = uVar5 + 1;
  if (param_6 == uVar5) goto LAB_4200e43e;
  pbVar4 = (byte *)(param_5 + uVar5);
  goto LAB_4200e3c2;
code_r0x4200e3db:
  if (uVar5 < param_6) {
    uVar6 = *pbVar4 - 0x30;
    bVar1 = 9 < (uVar6 & 0xff);
    if (bVar1) {
      uVar6 = 0;
    }
    uVar5 = 0;
    if (!bVar1) {
      if (bVar3) {
        uVar6 = -uVar6;
      }
      iVar7 = (uint)((int)uVar6 < DAT_42000db0) * DAT_42000db0 +
              ((int)uVar6 >= DAT_42000db0) * uVar6;
      uVar5 = (uint)(char)((iVar7 < DAT_42000a38) * (char)iVar7 +
                          (iVar7 >= DAT_42000a38) * (char)DAT_42000a38);
    }
  }
  else {
    uVar5 = 0;
  }
  goto LAB_4200e449;
}