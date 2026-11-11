// 420030a4  FUN_420030a4  FUN_420030a4  size=273

int FUN_420030a4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int in_WindowStart;
  int local_50;
  uint uStack_4c;
  undefined1 *puStack_30;
  int iStack_2c;
  int iStack_28;
  
  iVar6 = *(int *)PTR_DAT_42000458 * 0x14;
  iVar1 = (uint)(in_WindowStart == 0) * (int)&local_50;
  iVar3 = (uint)(in_WindowStart != 0) * ((int)&local_50 - (iVar6 + 0xfU & 0xfffffff0));
  puStack_30 = (undefined1 *)(iVar1 + iVar3);
  piVar8 = (int *)(iVar1 + iVar3);
  iStack_28 = param_1;
  (*DAT_420002fc)(iVar1 + iVar3,PTR_DAT_4200045c,iVar6);
  uVar7 = FUN_42002fec();
  iVar2 = (uint)(in_WindowStart == 0) * (iVar1 + iVar3);
  iVar1 = (uint)(in_WindowStart != 0) * ((iVar1 + iVar3) - (uVar7 * 8 + 0xf & 0xfffffff0));
  FUN_42003000(iVar2 + iVar1,uVar7);
  iStack_2c = param_1;
  do {
    if (piVar8 == (int *)(puStack_30 + iVar6)) {
      return (iStack_2c - iStack_28 >> 2) * DAT_42000460;
    }
    (*DAT_420002fc)(&local_50,piVar8,0x14);
    iVar3 = iStack_2c;
    iVar12 = local_50;
    iVar14 = local_50 + uStack_4c;
    for (uVar9 = 0; uVar9 < uVar7; uVar9 = uVar9 + 1) {
      piVar10 = (int *)(uVar9 * 8 + iVar2 + iVar1);
      iVar13 = piVar10[1];
      iVar11 = iVar14;
      if (iVar12 < iVar13) {
        iVar11 = *piVar10;
        if (iVar14 <= iVar11) {
          bVar5 = true;
          bVar4 = true;
          goto LAB_4200317b;
        }
        if ((iVar11 <= iVar12) && (iVar14 <= iVar13)) {
          bVar5 = true;
          bVar4 = false;
          goto LAB_4200317b;
        }
        if ((iVar12 < iVar11) && (iVar13 < iVar14)) {
          uStack_4c = iVar11 - iVar12;
          piVar8[1] = piVar8[1] - (iVar13 - *piVar8);
          *piVar8 = *(int *)(uVar9 * 8 + iVar2 + iVar1 + 4);
          bVar5 = false;
          bVar4 = true;
          goto LAB_4200317b;
        }
        if (iVar12 < iVar11) {
          uStack_4c = iVar11 - iVar12;
        }
        else {
          uStack_4c = iVar14 - iVar13;
          iVar12 = iVar13;
          iVar11 = iVar14;
          local_50 = iVar13;
        }
      }
      iVar14 = iVar11;
    }
    bVar5 = true;
    bVar4 = true;
LAB_4200317b:
    if ((0x10 < uStack_4c) && (bVar4)) {
      iStack_2c = iStack_2c + 0x14;
      (*DAT_420002fc)(iVar3,&local_50,0x14);
    }
    if (bVar5) {
      piVar8 = piVar8 + 5;
    }
  } while( true );
}


