void parse_range(int param_1,uint param_2,int *param_3,int *param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  bool bVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  uint local_40 [16];
  
  uVar2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  iVar3 = 0;
  if (param_2 == 0) {
    return;
  }
  do {
    pcVar4 = (char *)(param_1 + uVar2);
    uVar2 = uVar2 + 1;
    bVar9 = true;
    iVar7 = iVar3;
    if (*pcVar4 == ',') {
      iVar7 = iVar3 + 1;
      local_40[iVar3] = uVar2;
      bVar9 = true;
      if (iVar3 == 1) {
        bVar9 = false;
      }
    }
  } while ((uVar2 < param_2) && (iVar3 = iVar7, bVar9));
  if (iVar7 == 0) {
    return;
  }
  if (local_40[1] != 0) {
    uVar2 = local_40[1] - 1;
    iVar3 = 0;
    if (uVar2 <= local_40[0]) goto LAB_4200e8b0;
LAB_4200e7ac:
    iVar3 = uVar2 - local_40[0];
    if ((uVar2 < local_40[0] + 1) || (uVar2 == 0)) {
      iVar3 = 1;
    }
    do {
      pbVar6 = (byte *)(param_1 + local_40[0]);
      bVar1 = *pbVar6;
      if (bVar1 != 0x20 && bVar1 != 9) {
        if (local_40[0] < uVar2) {
          if (bVar1 == 0x2d) {
            local_40[0] = local_40[0] + 1;
            bVar9 = true;
            pbVar6 = (byte *)(param_1 + local_40[0]);
            if (local_40[0] < uVar2) goto LAB_4200e836;
            break;
          }
          bVar9 = false;
          if (bVar1 != 0x2b) goto LAB_4200e836;
          local_40[0] = local_40[0] + 1;
          pbVar6 = (byte *)(param_1 + local_40[0]);
          if (local_40[0] < uVar2) goto LAB_4200e836;
        }
        iVar3 = 0;
        goto LAB_4200e8b0;
      }
      local_40[0] = local_40[0] + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    goto LAB_4200e8a9;
  }
  uVar2 = param_2;
  if (local_40[0] < param_2) goto LAB_4200e7ac;
  if (iVar7 != 2) {
    return;
  }
LAB_4200e790:
  iVar3 = param_2 - local_40[1];
  if ((param_2 < local_40[1] + 1) || (param_2 == 0)) {
    iVar3 = 1;
  }
  do {
    pbVar6 = (byte *)(param_1 + local_40[1]);
    bVar1 = *pbVar6;
    bVar9 = bVar1 == 0x20 || bVar1 == 9;
    if (bVar1 != 0x20 && bVar1 != 9) {
      if (local_40[1] < param_2) {
        if (bVar1 == 0x2d) {
          bVar9 = true;
        }
        else if (bVar1 != 0x2b) goto LAB_4200e92b;
        local_40[1] = local_40[1] + 1;
        pbVar6 = (byte *)(param_1 + local_40[1]);
        if (local_40[1] < param_2) goto LAB_4200e92b;
      }
      break;
    }
    local_40[1] = local_40[1] + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
LAB_4200e8be:
  iVar3 = 0;
LAB_4200e992:
  *param_4 = iVar3;
  return;
LAB_4200e836:
  if (*pbVar6 != 0x20 && *pbVar6 != 9) goto LAB_4200e819;
  local_40[0] = local_40[0] + 1;
  if (uVar2 <= local_40[0]) goto LAB_4200e8a9;
  pbVar6 = (byte *)(param_1 + local_40[0]);
  goto LAB_4200e836;
LAB_4200e819:
  if (local_40[0] < uVar2) {
    iVar3 = (param_1 + uVar2) - (int)pbVar6;
    bVar5 = false;
    iVar8 = 0;
    do {
      uVar2 = (uint)*pbVar6;
      if ((uVar2 - 0x30 & 0xff) < 10) {
        iVar8 = iVar8 * 10 + (uVar2 - 0x30);
        bVar5 = true;
      }
      else if ((uVar2 != 0x20) && (uVar2 != 9)) break;
      pbVar6 = pbVar6 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = 0;
    if (bVar5) {
      if (bVar9) {
        iVar8 = -iVar8;
      }
      iVar3 = (uint)(iVar8 < DAT_42000db0) * DAT_42000db0 + (uint)(iVar8 >= DAT_42000db0) * iVar8;
      iVar3 = (uint)(iVar3 < DAT_42000a38) * iVar3 + (uint)(iVar3 >= DAT_42000a38) * DAT_42000a38;
    }
  }
  else {
LAB_4200e8a9:
    iVar3 = 0;
  }
LAB_4200e8b0:
  *param_3 = iVar3;
  if (iVar7 != 2) {
    return;
  }
  if (local_40[1] < param_2) goto LAB_4200e790;
  goto LAB_4200e8be;
LAB_4200e92b:
  if (*pbVar6 != 0x20 && *pbVar6 != 9) goto LAB_4200e916;
  local_40[1] = local_40[1] + 1;
  if (param_2 <= local_40[1]) goto LAB_4200e8be;
  pbVar6 = (byte *)(param_1 + local_40[1]);
  goto LAB_4200e92b;
LAB_4200e916:
  if (local_40[1] < param_2) {
    iVar7 = (param_1 + param_2) - (int)pbVar6;
    iVar3 = 0;
    bVar5 = false;
    do {
      uVar2 = (uint)*pbVar6;
      if ((uVar2 - 0x30 & 0xff) < 10) {
        iVar3 = iVar3 * 10 + (uVar2 - 0x30);
        bVar5 = true;
      }
      else if ((uVar2 != 0x20) && (uVar2 != 9)) break;
      pbVar6 = pbVar6 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    if (bVar5) {
      if (bVar9) {
        iVar3 = -iVar3;
      }
      iVar3 = (uint)(iVar3 < DAT_42000db0) * DAT_42000db0 + (uint)(iVar3 >= DAT_42000db0) * iVar3;
      iVar3 = (uint)(iVar3 < DAT_42000a38) * iVar3 + (uint)(iVar3 >= DAT_42000a38) * DAT_42000a38;
      goto LAB_4200e992;
    }
  }
  goto LAB_4200e8be;
}