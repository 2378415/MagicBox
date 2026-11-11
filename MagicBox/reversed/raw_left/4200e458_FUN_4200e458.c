// 4200e458  FUN_4200e458  FUN_4200e458  size=272

uint FUN_4200e458(char *param_1,uint param_2)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  
  uVar3 = 0;
  if (param_2 != 0) {
    uVar6 = 0;
    if (*param_1 == '\'') {
      if ((2 < param_2) && (param_1[param_2 - 1] == '\'')) {
        uVar3 = FUN_4202d2a0(param_1[1]);
      }
    }
    else {
      uVar3 = param_2;
      do {
        pbVar5 = (byte *)(param_1 + uVar6);
        bVar1 = *pbVar5;
        bVar2 = bVar1 == 0x20 || bVar1 == 9;
        if (bVar1 != 0x20 && bVar1 != 9) {
          if (uVar6 < param_2) {
            if (bVar1 == 0x2d) {
              bVar2 = true;
            }
            else if (bVar1 != 0x2b) goto LAB_4200e4ec;
            uVar6 = uVar6 + 1;
            if (uVar6 < param_2) {
              pbVar5 = (byte *)(param_1 + uVar6);
LAB_4200e4ec:
              while( true ) {
                if (*pbVar5 != 0x20 && *pbVar5 != 9) {
                  if (param_2 <= uVar6) {
                    return 0;
                  }
                  uVar3 = *pbVar5 - 0x30;
                  if (9 < (uVar3 & 0xff)) {
                    return 0;
                  }
                  if (bVar2) {
                    uVar3 = -uVar3;
                  }
                  iVar4 = (uint)((int)uVar3 < DAT_42000db0) * DAT_42000db0 +
                          ((int)uVar3 >= DAT_42000db0) * uVar3;
                  return (uint)(iVar4 < DAT_42000a38) * iVar4 +
                         (uint)(iVar4 >= DAT_42000a38) * DAT_42000a38 & 0xffff;
                }
                uVar6 = uVar6 + 1;
                if (param_2 == uVar6) break;
                pbVar5 = (byte *)(param_1 + uVar6);
              }
            }
          }
          break;
        }
        uVar6 = uVar6 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
      uVar3 = 0;
    }
  }
  return uVar3;
}


