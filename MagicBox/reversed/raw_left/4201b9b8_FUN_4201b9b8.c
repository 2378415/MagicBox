// 4201b9b8  FUN_4201b9b8  FUN_4201b9b8  size=557

int FUN_4201b9b8(int param_1,uint param_2,undefined4 param_3,int param_4,uint param_5,uint param_6)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  int *piVar10;
  uint uVar11;
  uint uStack_58;
  ushort uStack_54;
  undefined2 uStack_52;
  int iStack_50;
  int *piStack_4c;
  int iStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  int *piStack_3c;
  uint uStack_38;
  int iStack_34;
  int iStack_30;
  uint uStack_2c;
  
  uVar11 = *(int *)(param_1 + 0x30) - 1;
  uStack_44 = param_2 & 0xff;
  uStack_38 = param_6 & 0xff;
  if (((uVar11 < 0x7f) * uVar11 + (uint)(uVar11 >= 0x7f) * 0x7f & 0xffff) * 4000 < param_5) {
    return DAT_42001a58;
  }
  iStack_34 = param_1 + 0x10;
  iStack_50 = 0;
  uVar11 = 0;
  piStack_4c = (int *)0x0;
  piVar3 = (int *)0x0;
  iStack_48 = param_1;
  uStack_40 = param_3;
  iStack_30 = param_4;
  uStack_2c = param_5;
  do {
    iVar8 = *(int *)(iStack_48 + 0x14);
    uVar4 = FUN_4201dd20(iVar8);
    uVar2 = uStack_2c;
    if (uVar11 == 0) {
      do {
        if (uVar4 < uVar2) {
          if (399 < uVar4) goto LAB_4201ba78;
        }
        else if (uVar2 != 0 || uVar4 != 0) break;
        if (((*(int *)(iVar8 + 0xc) != -4) && (iVar8 = FUN_4201dcf0(iVar8), iVar8 != 0)) ||
           (iVar8 = FUN_4201ddd0(iStack_34), iVar8 != 0)) {
          return iVar8;
        }
        uVar5 = FUN_4201dd20(*(undefined4 *)(iStack_48 + 0x14));
        if (uVar5 == uVar4) {
          return DAT_42001a5c;
        }
        iVar8 = *(int *)(iStack_48 + 0x14);
        uVar4 = FUN_4201dd20(iVar8);
      } while( true );
    }
    if (uVar4 == 0) {
      iVar6 = DAT_42001a5c;
LAB_4201bb70:
      piVar3 = piStack_4c;
      if (piStack_4c == (int *)0x0) {
        return iVar6;
      }
      goto LAB_4201bb73;
    }
LAB_4201ba78:
    iVar7 = (param_5 < uVar4) * param_5 + (param_5 >= uVar4) * uVar4;
    iVar6 = FUN_4201cf28(iVar8,uStack_44,0x42,uStack_40,iStack_30 + iStack_50,iVar7,
                         uStack_38 + uVar11 & 0xff);
    param_5 = param_5 - iVar7;
    uVar11 = uVar11 + 1 & 0xff;
    if (iVar6 != 0) {
      if (iVar6 == DAT_42001a60) {
        return DAT_42001a60;
      }
      goto LAB_4201bb70;
    }
    piVar10 = (int *)(*(code *)PTR_FUN_4200056c)(0xc);
    if (piVar10 == (int *)0x0) {
      iVar6 = 0x101;
      goto LAB_4201bb70;
    }
    piVar10[2] = iVar8;
    if (piVar3 != (int *)0x0) {
      piVar3[1] = (int)piVar10;
    }
    piVar10[1] = 0;
    if (piStack_4c == (int *)0x0) {
      piStack_4c = piVar10;
    }
    *piVar10 = (int)piVar3;
    if ((param_5 == 0) && (0x1f < uVar4 - iVar7)) {
LAB_4201bae5:
      piVar3 = piStack_4c;
      uStack_54 = (ushort)uVar11 | (ushort)(uStack_38 << 8);
      uStack_58 = uStack_2c;
      uStack_52 = 0xffff;
      iVar6 = FUN_4201cf28(*(undefined4 *)(iStack_48 + 0x14),uStack_44,0x48,uStack_40,&uStack_58,8,
                           0xff);
      if (iVar6 == DAT_42001a60) {
        return DAT_42001a60;
      }
      if (iVar6 != 0) {
LAB_4201bb73:
        uVar1 = uStack_40;
        uVar11 = uStack_44;
        cVar9 = '\0';
        piVar10 = piVar3;
        do {
          FUN_4201d70c(piVar10[2],uVar11,0x42,uVar1,cVar9,0xff);
          piVar10 = (int *)piVar10[1];
          cVar9 = cVar9 + '\x01';
        } while (piVar10 != (int *)0x0);
      }
      while( true ) {
        while( true ) {
          iVar8 = *piVar3;
          piVar10 = (int *)piVar3[1];
          if (iVar8 == 0) break;
          *(int **)(iVar8 + 4) = piVar10;
          if (piVar10 != (int *)0x0) {
            *piVar10 = iVar8;
          }
          (*(code *)PTR_FUN_42000570)();
        }
        if (piVar10 == (int *)0x0) break;
        *piVar10 = 0;
        (*(code *)PTR_FUN_42000570)();
        piVar3 = piVar10;
      }
      iStack_50 = iVar6;
      (*(code *)PTR_FUN_42000570)(piVar3);
      return iStack_50;
    }
    piStack_3c = piVar10;
    if (((*(int *)(iVar8 + 0xc) != -4) && (iVar6 = FUN_4201dcf0(iVar8), iVar6 != 0)) ||
       (iVar6 = FUN_4201ddd0(iStack_34), iVar6 != 0)) {
      goto LAB_4201bb70;
    }
    iStack_50 = iStack_50 + iVar7;
    if (param_5 == 0) goto LAB_4201bae5;
    piVar3 = piStack_3c;
  } while( true );
}


