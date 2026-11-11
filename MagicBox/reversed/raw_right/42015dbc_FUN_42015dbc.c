// 42015dbc  FUN_42015dbc  FUN_42015dbc  size=613

int FUN_42015dbc(int param_1,uint param_2,uint param_3,int param_4,uint *param_5,byte *param_6,
                byte param_7,byte param_8)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined1 auStack_60 [32];
  uint uStack_40;
  int iStack_3c;
  uint uStack_38;
  uint uStack_34;
  int iStack_30;
  uint uStack_2c;
  uint *puStack_28;
  
  param_2 = param_2 & 0xff;
  uStack_40 = param_3 & 0xff;
  uStack_38 = (uint)param_7;
  uStack_2c = (uint)param_8;
  iVar6 = *(int *)(param_1 + 0xc);
  if (((iVar6 != -0x10 && iVar6 != 0) && (iVar6 != -1)) && (uVar5 = *param_5, uVar5 < 0x7e)) {
    if (uVar5 <= *(uint *)(param_1 + 0x3c)) {
      uVar5 = *(uint *)(param_1 + 0x3c);
    }
    uVar3 = *(uint *)(param_1 + 0x38);
    if (0x7e < uVar3) {
      uVar3 = 0x7e;
    }
    iStack_3c = param_4;
    uStack_34 = param_2;
    puStack_28 = param_5;
    if (param_2 == 0xff || param_4 == 0) {
    }
    else if (!(uStack_40 == 0x42 && uStack_38 == 0xff)) {
      FUN_42015668(auStack_60,param_2,uStack_40,0,param_4,uStack_38);
      uVar5 = FUN_42015508(param_1 + 0x44,uVar5,auStack_60);
      if (0x7d < uVar5) {
        return DAT_42000cd4;
      }
    }
    while (uVar5 < uVar3) {
      uVar4 = uVar5 + 1;
      if (0x7d < uVar5) {
        return -1;
      }
      if ((*(uint *)((uVar5 >> 4) * 4 + param_1 + 0x18) >> (uVar5 & 0xf) * 2 & 3) == 2) {
        iStack_30 = FUN_42024fd8(param_1,uVar5,param_6);
        if (iStack_30 != 0) {
          *(undefined4 *)(param_1 + 0xc) = 0;
          return iStack_30;
        }
        iVar6 = FUN_42016bd4(param_6,uVar5 & 0xff);
        if (iVar6 == 0) {
          iVar6 = FUN_42015c90(param_1,uVar5);
          if (iVar6 != 0) {
            *(undefined4 *)(param_1 + 0xc) = 0;
            return iVar6;
          }
        }
        else {
          uVar2 = (uint)param_6[1];
          if ((uVar2 == 0x41 || uVar2 == 0x21) || (uVar2 == 0x42)) {
            uVar4 = param_6[2] + uVar5;
          }
          if (((((uStack_34 == 0xff) || (*param_6 == uStack_34)) &&
               ((iStack_3c == 0 || (iVar6 = (*DAT_4200099c)(iStack_3c,param_6 + 8,0xf), iVar6 == 0))
               )) && ((uStack_38 == 0xff || uStack_40 != 0x42 || (param_6[3] == uStack_38)))) &&
             ((bVar1 = uStack_38 != 0xff, uStack_40 != 0x42 || bVar1 || (uVar2 == 0x42)))) {
            if ((!bVar1 && uStack_40 == 0x41) && (uVar2 == 0x48)) {
              return DAT_420010ec;
            }
            if ((((bVar1 || uStack_40 != 0x41) || (uVar2 != 0x42)) &&
                ((uStack_40 != 0x48 || (param_6[3] == 0xff)))) &&
               ((uStack_40 != 0x48 || uStack_2c == 0xff || (param_6[0x1d] == uStack_2c)))) {
              if ((uStack_40 == 0xff) || (uVar2 == uStack_40)) {
                *puStack_28 = uVar5;
                return iStack_30;
              }
              if ((iStack_3c != 0 || uStack_34 != 0xff) || (uStack_38 != 0xff)) {
                *puStack_28 = uVar5;
                return DAT_420010ec;
              }
            }
          }
        }
      }
      uVar5 = uVar4;
    }
  }
  return DAT_42000cd4;
}


