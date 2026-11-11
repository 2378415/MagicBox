undefined4 FUN_42005b3c(int param_1,int param_2,uint param_3,uint param_4)

{
  undefined *puVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint local_60 [7];
  uint local_44 [4];
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  puVar5 = local_60;
  puVar6 = local_60;
  puVar7 = local_60;
  puVar8 = local_60;
  puVar3 = local_60;
  if (param_1 == 2) {
    uVar4 = 2;
    if (param_2 == 8) {
      if ((param_3 + DAT_4200074c <= DAT_42000734) && (uVar4 = 3, (param_3 & 0xff) == 0)) {
        (*DAT_42000064)(local_44,PTR_DAT_42000738);
        iVar2 = DAT_42000750;
        puVar1 = PTR_DAT_4200073c;
        puVar3 = local_44;
        iVar9 = 0;
        do {
          (*DAT_42000064)(local_60,puVar1,0x1c);
          iVar11 = *puVar8;
          puVar8 = puVar8 + 1;
          if (param_3 <= (uint)(iVar11 + iVar2)) {
            local_44[iVar9] = 2;
            break;
          }
          *puVar3 = 0;
          iVar9 = iVar9 + 1;
          puVar3 = puVar3 + 1;
        } while (iVar9 != 7);
        memw();
        *DAT_42000754 =
             (local_44[1] & 3) << 2 | local_44[0] & 3 | (local_44[2] & 3) << 4 |
             (local_44[3] & 3) << 6 | (uStack_34 & 3) << 8 | (uStack_30 & 3) << 10 |
             (uStack_2c & 3) << 0xc | ((param_3 & 0x3ffffff) >> 8 & 0xff) << 0xe;
        uVar4 = 0;
      }
    }
    else {
      if (param_2 != 0x10) {
        return DAT_42000724;
      }
      if ((param_3 + DAT_4200074c <= DAT_42000734) && (uVar4 = 3, (param_3 & 0xff) == 0)) {
        (*DAT_42000064)(local_44,PTR_DAT_42000738);
        iVar2 = DAT_42000750;
        puVar1 = PTR_DAT_4200073c;
        puVar5 = local_44;
        iVar9 = 0;
        do {
          (*DAT_42000064)(local_60,puVar1,0x1c);
          iVar11 = *puVar3;
          puVar3 = puVar3 + 1;
          if (param_3 <= (uint)(iVar11 + iVar2)) {
            local_44[iVar9] = 2;
            break;
          }
          *puVar5 = 0;
          iVar9 = iVar9 + 1;
          puVar5 = puVar5 + 1;
        } while (iVar9 != 7);
        memw();
        *DAT_42000758 =
             (local_44[1] & 3) << 2 | local_44[0] & 3 | (local_44[2] & 3) << 4 |
             (local_44[3] & 3) << 6 | (uStack_34 & 3) << 8 | (uStack_30 & 3) << 10 |
             (uStack_2c & 3) << 0xc | ((param_3 & 0x3ffffff) >> 8 & 0xff) << 0xe;
        uVar4 = 0;
      }
    }
  }
  else if (param_1 == 4) {
    if (param_2 != 1) {
      return DAT_42000724;
    }
    if (*(int *)(PTR_DAT_4200075c + 0xc) == 0) {
      return DAT_4200072c;
    }
    if (param_4 != *(uint *)(PTR_DAT_4200075c + 0x10)) {
      if (*(int *)(PTR_DAT_4200075c + 0xc) == 1) {
        return DAT_4200072c;
      }
      if (param_4 != *(uint *)(PTR_DAT_4200075c + 0x14)) {
        return DAT_4200072c;
      }
    }
    uVar4 = 2;
    if (((param_3 + DAT_42000368 <= DAT_4200036c) && (uVar4 = 3, (param_3 & 3) == 0)) &&
       (uVar4 = 7, param_4 < 2)) {
      puVar3 = DAT_4200071c;
      if (param_4 != 0) {
        puVar3 = DAT_42000720;
      }
      memw();
      memw();
      *puVar3 = *puVar3 & 0xfffff800;
      memw();
      memw();
      *puVar3 = param_3 >> 2 & (*puVar3 ^ 0x7ff) & 0x7ff ^ *puVar3;
      uVar4 = 0;
    }
  }
  else {
    if (param_1 != 1) {
      return DAT_42000728;
    }
    if (param_2 == 2) {
      if (DAT_42000734 < param_3 + DAT_42000730) {
        uVar4 = 2;
      }
      else {
        uVar4 = 3;
        if ((param_3 & 0xff) == 0) {
          (*DAT_42000064)(local_44,PTR_DAT_42000738);
          puVar1 = PTR_DAT_4200073c;
          puVar3 = local_44;
          iVar9 = 0;
          do {
            (*DAT_42000064)(local_60,puVar1,0x1c);
            uVar10 = *puVar6;
            puVar6 = puVar6 + 1;
            if (param_3 <= uVar10) {
              local_44[iVar9] = 2;
              break;
            }
            *puVar3 = 0;
            iVar9 = iVar9 + 1;
            puVar3 = puVar3 + 1;
          } while (iVar9 != 7);
          memw();
          *DAT_42000744 =
               (local_44[1] & 3) << 2 | local_44[0] & 3 | (local_44[2] & 3) << 4 |
               (local_44[3] & 3) << 6 | (uStack_34 & 3) << 8 | (uStack_30 & 3) << 10 |
               (uStack_2c & 3) << 0xc | ((param_3 & 0x3ffffff) >> 8 & 0xff) << 0xe;
          uVar4 = 0;
        }
      }
    }
    else if (param_2 == 4) {
      uVar4 = 2;
      if ((param_3 + DAT_42000730 <= DAT_42000734) && (uVar4 = 3, (param_3 & 0xff) == 0)) {
        (*DAT_42000064)(local_44,PTR_DAT_42000738);
        puVar1 = PTR_DAT_4200073c;
        puVar3 = local_44;
        iVar9 = 0;
        do {
          (*DAT_42000064)(local_60,puVar1,0x1c);
          uVar10 = *puVar7;
          puVar7 = puVar7 + 1;
          if (param_3 <= uVar10) {
            local_44[iVar9] = 2;
            break;
          }
          *puVar3 = 0;
          iVar9 = iVar9 + 1;
          puVar3 = puVar3 + 1;
        } while (iVar9 != 7);
        memw();
        *DAT_42000748 =
             (local_44[1] & 3) << 2 | local_44[0] & 3 | (local_44[2] & 3) << 4 |
             (local_44[3] & 3) << 6 | (uStack_34 & 3) << 8 | (uStack_30 & 3) << 10 |
             (uStack_2c & 3) << 0xc | ((param_3 & 0x3ffffff) >> 8 & 0xff) << 0xe;
        uVar4 = 0;
      }
    }
    else {
      if (param_2 != 1) {
        return DAT_42000724;
      }
      uVar4 = 2;
      if ((param_3 + DAT_42000730 <= DAT_42000734) && (uVar4 = 3, (param_3 & 0xff) == 0)) {
        (*DAT_42000064)(local_44,PTR_DAT_42000738);
        puVar1 = PTR_DAT_4200073c;
        puVar3 = local_44;
        iVar9 = 0;
        do {
          (*DAT_42000064)(local_60,puVar1,0x1c);
          uVar10 = *puVar5;
          puVar5 = puVar5 + 1;
          if (param_3 <= uVar10) {
            local_44[iVar9] = 2;
            break;
          }
          *puVar3 = 0;
          iVar9 = iVar9 + 1;
          puVar3 = puVar3 + 1;
        } while (iVar9 != 7);
        memw();
        *DAT_42000740 =
             (local_44[1] & 3) << 2 | local_44[0] & 3 | (local_44[2] & 3) << 4 |
             (local_44[3] & 3) << 6 | (uStack_34 & 3) << 8 | (uStack_30 & 3) << 10 |
             (uStack_2c & 3) << 0xc | ((param_3 & 0x3ffffff) >> 8 & 0xff) << 0xe;
        uVar4 = 0;
      }
    }
  }
  uVar4 = FUN_4200775c(uVar4);
  return uVar4;
}