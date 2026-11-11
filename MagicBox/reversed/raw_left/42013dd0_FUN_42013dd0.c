// 42013dd0  FUN_42013dd0  FUN_42013dd0  size=313

undefined4 FUN_42013dd0(undefined4 param_1,byte *param_2,int *param_3,uint *param_4)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  int local_40;
  int iStack_3c;
  uint uStack_38;
  int iStack_30;
  
  bVar1 = param_2[3];
  uVar3 = *(ushort *)(param_2 + 4);
  if ((*param_2 & 0x80) == 0) {
    iVar4 = FUN_42013d1c(param_2,*param_3,*param_4,0);
  }
  else {
    iVar4 = FUN_42013d1c(param_2,0,0,*param_3,param_4);
  }
  if (iVar4 != 0) {
    return 0;
  }
  bVar7 = *param_2;
  if (bVar7 == 0x80) {
    if (param_2[1] != 6) {
      return 1;
    }
    bVar7 = param_2[3];
    bVar2 = param_2[2];
    if (*(short *)(param_2 + 2) == 0x100) {
      *(undefined1 *)(*param_3 + 7) = 0x40;
      bVar7 = *param_2;
      if (bVar7 != 0x80) goto LAB_42013ea8;
      if (param_2[1] != 6) {
        return 1;
      }
      bVar2 = param_2[2];
      bVar7 = param_2[3];
    }
    if (CONCAT11(bVar7,bVar2) != 0x200) {
      return 1;
    }
    (*DAT_42000064)(DAT_42001200,*param_3,*param_4);
    uVar6 = *param_4;
    if (9 < uVar6) {
      iVar4 = *param_3;
      if (((*(uint *)(DAT_4200121c + 0x40) < 10) || (uVar6 != *(uint *)(DAT_4200121c + 0x40))) ||
         (iStack_30 = iVar4, iVar5 = (*DAT_42000114)(DAT_42001218,iVar4,uVar6), iVar4 = iStack_30,
         iVar5 != 0)) {
        FUN_420135c0(iVar4,uVar6);
      }
    }
    bVar7 = *param_2;
  }
LAB_42013ea8:
  if (((bVar7 == 0x81) && (bVar1 == 0x22)) && (param_2[1] == 6)) {
    uVar6 = uVar3 & 0xff;
    iVar4 = uVar6 * 0x800 + DAT_42001290;
    (*DAT_42000064)(iVar4,*param_3,*param_4);
    if (uVar6 < 6) {
      uStack_38 = *param_4;
      local_40 = uVar6 * 0x738 + DAT_42000e84;
      iStack_3c = iVar4;
      (*(code *)PTR_FUN_42000488)(*DAT_42001260,&local_40,0);
    }
  }
  return 1;
}


