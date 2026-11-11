// 4200a268  uart_set_pin  FUN_4200a268  size=1419
// strings: uart_set_pin | uart | `p`P | 0s 0S 

undefined4 FUN_4200a268(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  
  uVar11 = CONCAT44(param_2,param_2);
  if (2 < param_1) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar4 = 0x2cb;
    puVar7 = PTR_DAT_42000a58;
    goto LAB_4200a2cc;
  }
  if ((int)param_2 < 0) {
    if (-1 < (int)param_3) {
LAB_4200a334:
      uVar9 = param_3 & 0x20;
      uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_3 ^ 0xffffffff) & 0x1f)) |
              DAT_42000b10 >> (param_3 & 0x1f);
      if (uVar9 != 0) {
        uVar3 = DAT_42000b14 >> (param_3 & 0x1f);
      }
      uVar8 = uVar3 & 1;
      if ((uVar3 & 1) != 0) {
        uVar1 = (*(code *)PTR_FUN_4200005c)();
        uVar4 = 0x2ce;
        puVar7 = PTR_DAT_42000b1c;
        goto LAB_4200a2cc;
      }
      if (-1 < (int)param_4) goto LAB_4200a3d4;
      if (-1 < (int)param_5) {
LAB_4200a484:
        uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_5 ^ 0xffffffff) & 0x1f)) |
                DAT_42000b10 >> (param_5 & 0x1f);
        if ((param_5 & 0x20) != 0) {
          uVar3 = DAT_42000b14 >> (param_5 & 0x1f);
        }
        uVar8 = uVar3 & 1;
        if ((uVar3 & 1) != 0) goto LAB_4200a4ac;
        uVar3 = uVar8;
        if ((int)param_2 < 1) {
        }
        else {
          uVar9 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
          if ((param_2 & 0x20) == 0) {
            uVar8 = uVar9;
          }
          else {
            uVar3 = uVar9;
          }
        }
        if ((int)param_3 < 1) goto LAB_4200a559;
        goto LAB_4200a52c;
      }
      if ((int)param_2 < 1) {
        if (param_3 != 0) {
          iVar2 = 1 << 0x20 - (0x20 - (param_3 & 0x1f));
          uVar10 = CONCAT44(uVar3,iVar2) & 0x1ffffffff;
          if (uVar9 != 0) {
            uVar10 = CONCAT44(iVar2,uVar3) & 0xffffffff00000001;
          }
          goto LAB_4200a599;
        }
        uVar11 = 0;
        if (param_2 != 0) {
          uVar11 = 0;
          goto LAB_4200a59f;
        }
        goto LAB_4200a76d;
      }
      uVar3 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
      if ((param_2 & 0x20) == 0) {
        uVar6 = uVar3;
        uVar3 = uVar8;
      }
      else {
        uVar6 = uVar8;
      }
      uVar11 = CONCAT44(uVar3,uVar6);
      if (param_3 != 0) {
        uVar5 = 1 << 0x20 - (0x20 - (param_3 & 0x1f));
        if (uVar9 == 0) {
          uVar9 = uVar5;
          uVar5 = uVar8;
        }
        else {
          uVar9 = uVar8;
        }
        uVar10 = CONCAT44(uVar3 | uVar5,uVar6 | uVar9);
        goto LAB_4200a599;
      }
      iVar2 = FUN_42008ef8(param_1,param_2,0);
      if (iVar2 == 0) goto LAB_4200a7a6;
LAB_4200a59f:
      iVar2 = FUN_42008ef8(param_1,param_3,1);
      if (iVar2 == 0) {
        puVar7 = PTR_DAT_42000a30;
        goto LAB_4200a5d4;
      }
      goto LAB_4200a620;
    }
    if ((int)param_4 < 0) {
      if ((int)param_5 < 0) {
        uVar11 = 0;
        goto LAB_4200a6ae;
      }
      uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_5 ^ 0xffffffff) & 0x1f)) |
              DAT_42000b10 >> (param_5 & 0x1f);
      if ((param_5 >> 5 & 1) != 0) {
        uVar3 = DAT_42000b14 >> (param_5 & 0x1f);
      }
      if ((uVar3 & 1) != 0) {
LAB_4200a4ac:
        uVar1 = (*(code *)PTR_FUN_4200005c)();
        uVar4 = 0x2d0;
        puVar7 = PTR_DAT_42000b24;
        goto LAB_4200a2cc;
      }
      if (param_5 != 0) {
        uVar11 = (*DAT_42000b2c)(1,uVar3 & 1,param_5);
        goto joined_r0x4200a59c;
      }
LAB_4200a7e5:
      uVar11 = 0;
      goto LAB_4200a620;
    }
    uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_4 ^ 0xffffffff) & 0x1f)) |
            DAT_42000b10 >> (param_4 & 0x1f);
    if ((param_4 >> 5 & 1) != 0) {
      uVar3 = DAT_42000b14 >> (param_4 & 0x1f);
    }
    if ((uVar3 & 1) != 0) {
LAB_4200a400:
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      uVar4 = 0x2cf;
      puVar7 = PTR_DAT_42000b20;
LAB_4200a2cc:
      (*(code *)PTR_FUN_42000118)
                (1,PTR_DAT_42000a54,puVar7,uVar1,PTR_DAT_42000a54,PTR_s_uart_set_pin_42000b08,uVar4)
      ;
      return 0xffffffff;
    }
    if (-1 < (int)param_5) goto LAB_4200a484;
LAB_4200a4e0:
    uVar8 = 0;
    uVar3 = 0;
    uVar10 = 0;
    uVar11 = 0;
    if (0 < (int)param_3) {
LAB_4200a52c:
      uVar9 = 1 << 0x20 - (0x20 - (param_3 & 0x1f));
      if ((param_3 & 0x20) == 0) {
        uVar6 = uVar9;
        uVar9 = 0;
      }
      else {
        uVar6 = 0;
      }
      uVar8 = uVar8 | uVar6;
      uVar3 = uVar3 | uVar9;
      uVar11 = CONCAT44(uVar3,uVar8);
      if (0 < (int)param_4) goto LAB_4200a55c;
      if (0 < (int)param_5) goto LAB_4200a57c;
      uVar10 = uVar11;
      if ((int)param_2 < 0) goto LAB_4200a59f;
      goto LAB_4200a5bb;
    }
    if (0 < (int)param_4) {
      uVar10 = (*DAT_42000b2c)(1,0,param_4);
      goto LAB_4200a599;
    }
    if (param_2 == 0) goto LAB_4200a5bb;
    if (param_3 == 0) goto LAB_4200a59f;
LAB_4200a623:
    iVar2 = FUN_42008ef8(param_1,param_4,2);
    if (iVar2 == 0) {
      FUN_4201897c(param_4,1);
      (*DAT_42000b34)(param_4,*(uint *)(PTR_DAT_42000a30 + param_1 * 0x14 + 8) >> 0x14,0,0);
    }
  }
  else {
    uVar9 = param_2 & 0x20;
    uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_2 ^ 0xffffffff) & 0x1f)) |
            DAT_42000b10 >> (param_2 & 0x1f);
    if (uVar9 != 0) {
      uVar3 = DAT_42000b14 >> (param_2 & 0x1f);
    }
    if ((uVar3 & 1) != 0) {
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      uVar4 = 0x2cd;
      puVar7 = PTR_DAT_42000b18;
      goto LAB_4200a2cc;
    }
    if (-1 < (int)param_3) goto LAB_4200a334;
    if ((int)param_4 < 0) {
      if (-1 < (int)param_5) {
        uVar3 = DAT_42000b0c << 0x20 - (0x20 - ((param_5 ^ 0xffffffff) & 0x1f)) |
                DAT_42000b10 >> (param_5 & 0x1f);
        if ((param_5 & 0x20) != 0) {
          uVar3 = DAT_42000b14 >> (param_5 & 0x1f);
        }
        uVar8 = uVar3 & 1;
        if ((uVar3 & 1) != 0) goto LAB_4200a4ac;
        if (param_2 == 0) {
          uVar3 = 0;
          uVar8 = 0;
        }
        else {
          uVar6 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
          if (uVar9 == 0) {
            uVar3 = uVar8;
            uVar8 = uVar6;
          }
          else {
            uVar3 = uVar6;
          }
        }
LAB_4200a559:
        if (0 < (int)param_4) goto LAB_4200a55c;
        goto LAB_4200a579;
      }
      if (param_2 != 0) {
        iVar2 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
        uVar11 = CONCAT44(uVar3,iVar2) & 0x1ffffffff;
        if (uVar9 != 0) {
          uVar11 = CONCAT44(iVar2,uVar3) & 0xffffffff00000001;
        }
        goto LAB_4200a5c1;
      }
      iVar2 = FUN_42008ef8(param_1,0,0);
      if (iVar2 != 0) goto LAB_4200a7e5;
LAB_4200a7a6:
      FUN_4201897c(param_2,1);
      (*DAT_42000b34)(param_2,*(uint *)(PTR_DAT_42000a30 + param_1 * 0x14) >> 0x14,0);
joined_r0x4200a59c:
      if ((int)param_3 < 0) goto LAB_4200a620;
      goto LAB_4200a59f;
    }
LAB_4200a3d4:
    uVar9 = DAT_42000b0c << 0x20 - (0x20 - ((param_4 ^ 0xffffffff) & 0x1f)) |
            DAT_42000b10 >> (param_4 & 0x1f);
    if ((param_4 & 0x20) != 0) {
      uVar9 = DAT_42000b14 >> (param_4 & 0x1f);
    }
    if ((uVar9 & 1) != 0) goto LAB_4200a400;
    if (-1 < (int)param_5) goto LAB_4200a484;
    if ((int)param_2 < 1) goto LAB_4200a4e0;
    uVar3 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
    if ((param_2 & 0x20) == 0) {
      uVar8 = uVar3;
      uVar3 = uVar9 & 1;
    }
    else {
      uVar8 = uVar9 & 1;
    }
    uVar10 = CONCAT44(uVar3,uVar8);
    if (0 < (int)param_3) goto LAB_4200a52c;
    if (param_4 == 0) goto LAB_4200a599;
LAB_4200a55c:
    uVar9 = 1 << 0x20 - (0x20 - (param_4 & 0x1f));
    if ((param_4 & 0x20) == 0) {
      uVar6 = uVar9;
      uVar9 = 0;
    }
    else {
      uVar6 = 0;
    }
    uVar8 = uVar8 | uVar6;
    uVar3 = uVar3 | uVar9;
LAB_4200a579:
    uVar10 = CONCAT44(uVar3,uVar8);
    if (0 < (int)param_5) {
LAB_4200a57c:
      uVar9 = 1 << 0x20 - (0x20 - (param_5 & 0x1f));
      if ((param_5 & 0x20) == 0) {
        uVar6 = uVar9;
        uVar9 = 0;
      }
      else {
        uVar6 = 0;
      }
      uVar10 = CONCAT44(uVar3 | uVar9,uVar8 | uVar6);
    }
LAB_4200a599:
    uVar11 = uVar10;
    if ((int)param_2 < 0) goto joined_r0x4200a59c;
LAB_4200a5bb:
    uVar11 = uVar10;
    if (param_3 != param_2) {
LAB_4200a5c1:
      iVar2 = FUN_42008ef8(param_1,param_2,0);
      if (iVar2 == 0) goto LAB_4200a7a6;
      goto joined_r0x4200a59c;
    }
LAB_4200a76d:
    FUN_4201897c(param_2,1);
    puVar7 = PTR_DAT_42000a30;
    (*DAT_42000b34)(param_2,*(uint *)(PTR_DAT_42000a30 + param_1 * 0x14) >> 0x14,0);
LAB_4200a5d4:
    uVar9 = (uint)(uVar11 >> 0x20);
    uVar3 = 1 << 0x20 - (0x20 - (param_3 & 0x1f));
    if ((param_3 & 0x20) == 0) {
      uVar8 = uVar3;
      uVar3 = 0;
    }
    else {
      uVar8 = 0;
    }
    uVar11 = CONCAT44(uVar3 & uVar9 ^ uVar9,uVar8 & (uint)uVar11 ^ (uint)uVar11);
    FUN_4201897c(param_3);
    FUN_42017c90(param_3);
    (*DAT_42000b30)(param_3,*(uint *)(puVar7 + param_1 * 0x14 + 4) >> 0x14,0);
LAB_4200a620:
    if (-1 < (int)param_4) goto LAB_4200a623;
  }
  uVar3 = (uint)(uVar11 >> 0x20);
  if ((-1 < (int)param_5) && (iVar2 = FUN_42008ef8(param_1,param_5,3), iVar2 == 0)) {
    uVar9 = 1 << 0x20 - (0x20 - (param_5 & 0x1f));
    if ((param_5 & 0x20) == 0) {
      uVar8 = uVar9;
      uVar9 = 0;
    }
    else {
      uVar8 = 0;
    }
    uVar11 = CONCAT44(uVar9 & uVar3 ^ uVar3,uVar8 & (uint)uVar11 ^ (uint)uVar11);
    FUN_4201897c(param_5);
    FUN_4201780c(param_5);
    FUN_42017c90(param_5);
    (*DAT_42000b30)(param_5,*(uint *)(PTR_DAT_42000a30 + param_1 * 0x14 + 0xc) >> 0x14,0);
  }
LAB_4200a6ae:
  uVar10 = FUN_4201ac2c((int)uVar11,(int)(uVar11 >> 0x20));
  uVar11 = uVar11 & uVar10;
  if (uVar11 != 0) {
    do {
      uVar3 = (uint)(uVar11 >> 0x20);
      uVar9 = (uint)uVar11;
      iVar2 = LZCOUNT(-uVar9 & uVar9) + -0x1f;
      if (uVar9 == 0) {
        iVar2 = LZCOUNT(-uVar3 & uVar3) + -0x3f;
      }
      uVar6 = -iVar2;
      uVar8 = 1 << 0x20 - (0x20 - (uVar6 & 0x1f));
      if ((uVar6 & 0x20) == 0) {
        uVar5 = uVar8;
        uVar8 = 0;
      }
      else {
        uVar5 = 0;
      }
      uVar3 = uVar8 & uVar3 ^ uVar3;
      uVar9 = uVar5 & uVar9 ^ uVar9;
      uVar11 = CONCAT44(uVar3,uVar9);
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)(2,PTR_DAT_42000a54,PTR_DAT_42000b28,uVar1,PTR_DAT_42000a54,uVar6);
    } while (uVar9 != 0 || uVar3 != 0);
  }
  return 0;
}


