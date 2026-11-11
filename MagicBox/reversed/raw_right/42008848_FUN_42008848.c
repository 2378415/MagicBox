// 42008848  FUN_42008848  FUN_42008848  size=779

undefined4 FUN_42008848(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  uint local_30;
  
  if (param_1 < 3) {
    if (-1 < (int)param_2) {
      uVar4 = DAT_42000504 << 0x20 - (0x20 - ((param_2 ^ 0xffffffff) & 0x1f)) |
              DAT_42000508 >> (param_2 & 0x1f);
      if ((param_2 & 0x20) != 0) {
        uVar4 = DAT_4200050c >> (param_2 & 0x1f);
      }
      if ((uVar4 & 1) == 0) {
        return 0xffffffff;
      }
    }
    if (-1 < (int)param_3) {
      uVar4 = DAT_42000504 << 0x20 - (0x20 - ((param_3 ^ 0xffffffff) & 0x1f)) |
              DAT_42000508 >> (param_3 & 0x1f);
      if ((param_3 & 0x20) != 0) {
        uVar4 = DAT_4200050c >> (param_3 & 0x1f);
      }
      if ((uVar4 & 1) == 0) {
        return 0xffffffff;
      }
    }
    if (-1 < (int)param_4) {
      uVar4 = DAT_42000504 << 0x20 - (0x20 - ((param_4 ^ 0xffffffff) & 0x1f)) |
              DAT_42000508 >> (param_4 & 0x1f);
      if ((param_4 & 0x20) != 0) {
        uVar4 = DAT_4200050c >> (param_4 & 0x1f);
      }
      if ((uVar4 & 1) == 0) {
        return 0xffffffff;
      }
    }
    if (-1 < (int)param_5) {
      uVar4 = DAT_42000504 << 0x20 - (0x20 - ((param_5 ^ 0xffffffff) & 0x1f)) |
              DAT_42000508 >> (param_5 & 0x1f);
      if ((param_5 & 0x20) != 0) {
        uVar4 = DAT_4200050c >> (param_5 & 0x1f);
      }
      if ((uVar4 & 1) == 0) {
        return 0xffffffff;
      }
    }
    if ((int)param_2 < 1) {
      uVar4 = 0;
      uVar5 = 0;
    }
    else {
      uVar3 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
      uVar4 = uVar3;
      uVar5 = 0;
      if ((param_2 & 0x20) != 0) {
        uVar4 = 0;
        uVar5 = uVar3;
      }
    }
    if ((int)param_3 < 1) {
      uVar3 = 0;
      uVar9 = 0;
    }
    else {
      uVar6 = 1 << 0x20 - (0x20 - (param_3 & 0x1f));
      uVar3 = uVar6;
      uVar9 = 0;
      if ((param_3 & 0x20) != 0) {
        uVar3 = 0;
        uVar9 = uVar6;
      }
    }
    if ((int)param_4 < 1) {
      uVar6 = 0;
      uVar10 = 0;
    }
    else {
      uVar7 = 1 << 0x20 - (0x20 - (param_4 & 0x1f));
      uVar6 = uVar7;
      uVar10 = 0;
      if ((param_4 & 0x20) != 0) {
        uVar6 = 0;
        uVar10 = uVar7;
      }
    }
    if ((int)param_5 < 1) {
      uVar7 = 0;
      local_30 = 0;
    }
    else {
      uVar8 = 1 << 0x20 - (0x20 - (param_5 & 0x1f));
      uVar7 = uVar8;
      local_30 = 0;
      if ((param_5 & 0x20) != 0) {
        uVar7 = 0;
        local_30 = uVar8;
      }
    }
    uVar7 = uVar4 | uVar3 | uVar6 | uVar7;
    local_30 = uVar5 | uVar9 | uVar10 | local_30;
    if ((-1 < (int)param_2) &&
       ((param_2 == param_3 || (iVar1 = FUN_420076a4(param_1,param_2,0), iVar1 == 0)))) {
      FUN_42011a24(param_2,1);
      (*DAT_420008d0)(param_2,*(uint *)(PTR_DAT_42000860 + param_1 * 0x14) >> 0x14,0);
    }
    if ((-1 < (int)param_3) &&
       ((param_2 == param_3 || (iVar1 = FUN_420076a4(param_1,param_3,1), iVar1 == 0)))) {
      uVar4 = 1 << 0x20 - (0x20 - (param_3 & 0x1f));
      if ((param_3 & 0x20) == 0) {
        uVar5 = uVar4;
        uVar4 = 0;
      }
      else {
        uVar5 = 0;
      }
      uVar7 = uVar5 & uVar7 ^ uVar7;
      local_30 = uVar4 & local_30 ^ local_30;
      FUN_42011a24(param_3);
      FUN_4201131c(param_3);
      (*DAT_420008d4)(param_3,*(uint *)(PTR_DAT_42000860 + param_1 * 0x14 + 4) >> 0x14,0);
    }
    if ((-1 < (int)param_4) && (iVar1 = FUN_420076a4(param_1,param_4,2), iVar1 == 0)) {
      FUN_42011a24(param_4,1);
      (*DAT_420008d0)(param_4,*(uint *)(PTR_DAT_42000860 + param_1 * 0x14 + 8) >> 0x14,0);
    }
    if ((-1 < (int)param_5) && (iVar1 = FUN_420076a4(param_1,param_5,3), iVar1 == 0)) {
      uVar4 = 1 << 0x20 - (0x20 - (param_5 & 0x1f));
      if ((param_5 & 0x20) == 0) {
        uVar5 = uVar4;
        uVar4 = 0;
      }
      else {
        uVar5 = 0;
      }
      uVar7 = uVar5 & uVar7 ^ uVar7;
      local_30 = uVar4 & local_30 ^ local_30;
      FUN_42011a24(param_5);
      FUN_42010f38(param_5);
      FUN_4201131c(param_5);
      (*DAT_420008d4)(param_5,*(uint *)(PTR_DAT_42000860 + param_1 * 0x14 + 0xc) >> 0x14,0);
    }
    uVar11 = FUN_420139ac(uVar7,local_30);
    local_30 = (uint)((ulonglong)uVar11 >> 0x20) & local_30;
    for (uVar7 = (uint)uVar11 & uVar7; uVar7 != 0 || local_30 != 0; uVar7 = uVar5 & uVar7 ^ uVar7) {
      if (uVar7 == 0) {
        iVar1 = LZCOUNT(-local_30 & local_30) + -0x3f;
      }
      else {
        iVar1 = LZCOUNT(-uVar7 & uVar7) + -0x1f;
      }
      uVar4 = 1 << 0x20 - (0x20 - (-iVar1 & 0x1fU));
      if ((-iVar1 & 0x20U) == 0) {
        uVar5 = uVar4;
        uVar4 = 0;
      }
      else {
        uVar5 = 0;
      }
      local_30 = uVar4 & local_30 ^ local_30;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


