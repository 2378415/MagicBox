// 420207ac  FUN_420207ac  FUN_420207ac  size=705
// strings:  n7@

undefined4 FUN_420207ac(undefined4 *param_1,int *param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  ushort uVar4;
  undefined4 uVar5;
  ushort uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined1 auStack_90 [4];
  uint uStack_8c;
  int iStack_80;
  int iStack_48;
  uint uStack_30;
  
  if ((param_1 != (undefined4 *)0x0) && (param_1[10] == 0)) {
    FUN_420200c4(param_1);
  }
  if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
    (*(code *)PTR_FUN_42001c30)(param_2[0x16]);
  }
  if ((~*(ushort *)(param_2 + 3) & 0x108) == 0) {
    FUN_4201fe5c(param_1,param_2);
  }
  pcVar3 = (code *)param_2[0xb];
  uVar5 = 0x1d;
  if (pcVar3 == (code *)0x0) {
LAB_42020872:
    *param_1 = uVar5;
LAB_42020825:
    if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
      (*(code *)PTR_FUN_42001c34)(param_2[0x16]);
    }
    uVar5 = 0xffffffff;
  }
  else {
    if (param_4 == 1) {
      FUN_4201fe5c(param_1,param_2);
      if ((*(ushort *)(param_2 + 3) & 0x1000) == 0) {
        iVar2 = (*pcVar3)(param_1,param_2[8],0,1);
        if (iVar2 == -1) goto LAB_42020825;
      }
      else {
        iVar2 = param_2[0x15];
      }
      if ((*(ushort *)(param_2 + 3) & 4) == 0) {
        if (((*(ushort *)(param_2 + 3) & 8) != 0) && (*param_2 != 0)) {
          iVar2 = iVar2 + (*param_2 - param_2[4]);
        }
      }
      else {
        iVar2 = iVar2 - param_2[1];
        if (param_2[0xd] != 0) {
          iVar2 = iVar2 - param_2[0x10];
        }
      }
      param_3 = param_3 + iVar2;
      uStack_30 = 1;
      param_4 = 0;
    }
    else {
      uVar5 = 0x16;
      if ((param_4 & 0xfffffffd) != 0) goto LAB_42020872;
      uStack_30 = 0;
      iVar2 = 0;
    }
    if (param_2[4] == 0) {
      FUN_420290a4(param_1,param_2);
    }
    if ((*(ushort *)(param_2 + 3) & 0x81a) == 0) {
      if ((*(ushort *)(param_2 + 3) & 0x400) == 0) {
        if ((((pcVar3 != (code *)PTR_FUN_42001c50) || (*(short *)((int)param_2 + 0xe) < 0)) ||
            (iVar1 = FUN_4200c41c(param_1,(int)*(short *)((int)param_2 + 0xe),auStack_90),
            iVar1 != 0)) || ((uStack_8c >> 0xc & 0xf) != 8)) {
          *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x800;
          goto LAB_42020a01;
        }
        param_2[0x14] = iStack_48;
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x400;
      }
      uVar7 = param_3;
      if (param_4 != 0) {
        iVar1 = FUN_4200c41c(param_1,(int)*(short *)((int)param_2 + 0xe),auStack_90);
        if (iVar1 != 0) goto LAB_42020a01;
        uVar7 = param_3 + iStack_80;
      }
      if (uStack_30 == 0) {
        if ((*(ushort *)(param_2 + 3) & 0x1000) == 0) {
          uStack_30 = uVar7;
          iVar2 = (*pcVar3)(param_1,param_2[8],0,1);
          uVar7 = uStack_30;
          if (iVar2 == -1) goto LAB_42020a01;
        }
        else {
          iVar2 = param_2[0x15];
        }
        iVar2 = iVar2 - param_2[1];
        if (param_2[0xd] != 0) {
          iVar2 = iVar2 - param_2[0x10];
        }
      }
      piVar8 = (int *)param_2[0xd];
      iVar9 = param_2[4];
      iVar1 = param_2[1];
      if (piVar8 == (int *)0x0) {
        iVar10 = *param_2 - iVar9;
        iVar2 = iVar2 - iVar10;
      }
      else {
        iVar2 = iVar2 + iVar1;
        iVar10 = param_2[0xf] - iVar9;
        iVar1 = param_2[0x10];
        iVar2 = iVar2 - iVar10;
      }
      if ((iVar2 <= (int)uVar7) && (uVar7 < (uint)(iVar2 + iVar1 + iVar10))) {
        *param_2 = iVar9 + (uVar7 - iVar2);
        param_2[1] = (iVar1 + iVar10) - (uVar7 - iVar2);
        if (piVar8 != (int *)0x0) {
          if (piVar8 != param_2 + 0x11) {
            (*(code *)PTR_FUN_42001c38)(param_1);
          }
          param_2[0xd] = 0;
        }
        uVar4 = *(ushort *)(param_2 + 3);
        uVar6 = 0xffdf;
        goto LAB_42020a4a;
      }
      iVar1 = param_2[0x14];
      uStack_30 = uVar7;
      iVar2 = (*pcVar3)(param_1,param_2[8],-iVar1 & uVar7,0);
      if (iVar2 == -1) goto LAB_42020a01;
      param_2[1] = 0;
      *param_2 = param_2[4];
      if ((int *)param_2[0xd] != (int *)0x0) {
        if ((int *)param_2[0xd] != param_2 + 0x11) {
          (*(code *)PTR_FUN_42001c38)(param_1);
        }
        param_2[0xd] = 0;
      }
      *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xffdf;
      uVar7 = uStack_30 - (-iVar1 & uVar7);
      if (uVar7 != 0) {
        iVar2 = FUN_4202914c(param_1,param_2);
        if ((iVar2 != 0) || ((uint)param_2[1] < uVar7)) goto LAB_42020a01;
        *param_2 = *param_2 + uVar7;
        param_2[1] = param_2[1] - uVar7;
      }
    }
    else {
LAB_42020a01:
      iVar2 = FUN_4201fe5c(param_1,param_2);
      if ((iVar2 != 0) || (iVar2 = (*pcVar3)(param_1,param_2[8],param_3,param_4), iVar2 == -1))
      goto LAB_42020825;
      if ((int *)param_2[0xd] != (int *)0x0) {
        if ((int *)param_2[0xd] != param_2 + 0x11) {
          (*(code *)PTR_FUN_42001c38)(param_1);
        }
        param_2[0xd] = 0;
      }
      *param_2 = param_2[4];
      param_2[1] = 0;
      uVar4 = *(ushort *)(param_2 + 3);
      uVar6 = 0xf7df;
LAB_42020a4a:
      *(ushort *)(param_2 + 3) = uVar4 & uVar6;
    }
    (*DAT_42000094)(param_2 + 0x17,0,8);
    if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
      (*(code *)PTR_FUN_42001c34)(param_2[0x16]);
    }
    uVar5 = 0;
  }
  return uVar5;
}


