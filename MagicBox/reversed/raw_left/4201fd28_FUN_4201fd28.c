// 4201fd28  FUN_4201fd28  FUN_4201fd28  size=305

undefined4 FUN_4201fd28(uint *param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  int *piVar8;
  
  uVar5 = (uint)(short)*(ushort *)(param_2 + 3);
  if ((uVar5 & 8) == 0) {
    *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x800;
    if ((param_2[1] < 1) && (param_2[0x10] < 1)) {
      return 0;
    }
    pcVar6 = (code *)param_2[0xb];
    if (pcVar6 == (code *)0x0) {
      return 0;
    }
    uVar3 = *param_1;
    *param_1 = 0;
    if ((uVar5 >> 0xc & 1) == 0) {
      iVar2 = (*pcVar6)(param_1,param_2[8],0,1);
      if ((iVar2 == -1) && (uVar5 = *param_1, uVar5 != 0)) {
        if ((uVar5 == 0x1d) || (uVar5 == 0x16 || uVar5 == 0x1d)) {
          *param_1 = uVar3;
          return 0;
        }
LAB_4201fd95:
        uVar1 = *(ushort *)(param_2 + 3);
        goto LAB_4201fda0;
      }
    }
    else {
      iVar2 = param_2[0x15];
    }
    if (((*(ushort *)(param_2 + 3) & 4) != 0) && (iVar2 = iVar2 - param_2[1], param_2[0xd] != 0)) {
      iVar2 = iVar2 - param_2[0x10];
    }
    iVar2 = (*(code *)param_2[0xb])(param_1,param_2[8],iVar2,0);
    uVar1 = *(ushort *)(param_2 + 3);
    if ((iVar2 == -1) && ((0x1d < *param_1 || ((DAT_42001c40 & 1 << ((byte)*param_1 & 0x1f)) == 0)))
       ) {
LAB_4201fda0:
      *(ushort *)(param_2 + 3) = uVar1 | 0x40;
      return 0xffffffff;
    }
    *(ushort *)(param_2 + 3) = uVar1 & 0xf7ff;
    param_2[1] = 0;
    *param_2 = param_2[4];
    if (((uVar1 & 0x1000) != 0) && ((iVar2 != -1 || (*param_1 == 0)))) {
      param_2[0x15] = iVar2;
    }
    piVar8 = (int *)param_2[0xd];
    *param_1 = uVar3;
    if (piVar8 != (int *)0x0) {
      if (piVar8 != param_2 + 0x11) {
        (*(code *)PTR_FUN_42001c38)(param_1);
      }
      param_2[0xd] = 0;
    }
  }
  else {
    iVar2 = param_2[4];
    if (iVar2 != 0) {
      iVar4 = *param_2;
      *param_2 = iVar2;
      iVar4 = iVar4 - iVar2;
      iVar7 = 0;
      if ((uVar5 & 3) == 0) {
        iVar7 = param_2[5];
      }
      param_2[2] = iVar7;
      for (; 0 < iVar4; iVar4 = iVar4 - iVar7) {
        iVar7 = (*(code *)param_2[10])(param_1,param_2[8],iVar2,iVar4);
        if (iVar7 < 1) goto LAB_4201fd95;
        iVar2 = iVar2 + iVar7;
      }
    }
  }
  return 0;
}


