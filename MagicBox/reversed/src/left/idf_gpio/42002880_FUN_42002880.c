// strings: efuse

int FUN_42002880(uint param_1,uint param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined *puVar7;
  int iVar8;
  uint *puVar9;
  int *piVar10;
  int *piVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  undefined1 auStack_70 [48];
  undefined1 *puStack_40;
  int iStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint *puStack_30;
  int iStack_2c;
  uint uStack_28;
  uint uStack_24;
  
  uStack_38 = param_2 & 0xff;
  uStack_24 = param_1 & 0xff;
  FUN_420041a8(0);
  uStack_34 = param_1 & 0xff ^ 1;
  iVar8 = 10;
  iStack_3c = 0;
  piVar1 = (int *)PTR_DAT_42000120;
  puVar9 = (uint *)PTR_DAT_4200011c;
LAB_420028ac:
  piVar4 = (int *)*puVar9;
  piVar10 = (int *)puVar9[1];
  if (piVar4 <= piVar10) {
    piVar11 = piVar4;
    do {
      memw();
      iVar14 = *piVar11;
      piVar11 = piVar11 + 1;
      if (iVar14 != 0) {
        if (iStack_3c == 0) {
          FUN_420042a8();
          iVar14 = FUN_4202ce28(iVar8);
          puStack_40 = auStack_70;
          if (iVar14 == 3) {
            FUN_420043f0(piVar4,auStack_70);
            (*DAT_42000064)(DAT_4200012c,auStack_70,0xc);
          }
          iStack_2c = (piVar1[1] + 4) - *piVar1;
          (*DAT_42000064)(DAT_42000130,piVar4,(int)piVar10 + (4 - (int)piVar4));
          (*DAT_42000064)(puStack_40,DAT_42000130,0x2c);
          if ((uStack_24 == 0) &&
             (puStack_30 = (uint *)FUN_42004400(iVar8), puStack_30 != (uint *)0x0)) {
            uVar2 = (*(code *)PTR_FUN_4200005c)();
            puVar7 = PTR_s_efuse_42000124;
            (*(code *)PTR_FUN_42000118)
                      (2,PTR_s_efuse_42000124,PTR_DAT_42000134,uVar2,PTR_s_efuse_42000124,iVar8);
            puVar12 = puStack_30;
          }
          else {
            puVar7 = PTR_s_efuse_42000124;
            puVar12 = (uint *)0;
          }
          iVar14 = 1;
          puStack_30 = puVar9;
          goto LAB_42002978;
        }
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (1,PTR_s_efuse_42000124,PTR_DAT_42000128,uVar2,PTR_s_efuse_42000124,iVar8);
        break;
      }
    } while (piVar11 <= piVar10);
  }
  goto LAB_42002ac8;
  while( true ) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(2,puVar7,PTR_DAT_42000140,uVar2,puVar7,iVar8,iVar14);
    iVar14 = iVar14 + 1;
    (*DAT_42000064)(DAT_42000130,puStack_40,0x2c);
    puVar9 = puStack_30;
    if (iVar14 == 4) break;
LAB_42002978:
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(3,puVar7,PTR_DAT_42000138,uVar2,puVar7,iVar8);
    FUN_420042b4(iVar8);
    iVar5 = 5;
    do {
      FUN_4200420c();
      iVar3 = FUN_42004400(iVar8);
      iVar5 = iVar5 + -1;
      if (iVar3 != 0) {
        uVar13 = ((uint)puVar12 ^ 1) & 0xff;
        goto LAB_420029b6;
      }
    } while (iVar5 != 0);
    uVar13 = (uint)puVar12;
LAB_420029b6:
    uVar6 = uStack_34 & uVar13;
    if (((uStack_34 & uVar13) == 0) || (puVar12 != (uint *)0x0)) {
      if ((uStack_38 == 0) || (iVar5 = FUN_420027d8(iVar8,iStack_2c), iVar5 != 0)) {
        puVar9 = puStack_30;
        goto LAB_42002ac8;
      }
      uStack_28 = 0;
      uVar6 = 0;
    }
    else {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)(2,puVar7,PTR_DAT_4200013c,uVar2,puVar7,iVar8);
      uStack_28 = uVar6;
      if (uStack_38 != 0) {
        uStack_28 = FUN_420027d8(iVar8,iStack_2c);
        uVar6 = uStack_38;
      }
    }
  }
  if (uVar6 == 0) {
    if (uStack_28 != 0) goto LAB_42002ac8;
  }
  else {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(2,puVar7,PTR_DAT_42000144,uVar2,puVar7);
    if (iVar8 == 0) {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)(1,puVar7,PTR_DAT_42000148,uVar2,puVar7);
      if (uStack_28 != 0) {
        iStack_3c = -1;
        goto LAB_42002ae2;
      }
    }
    else if (uStack_28 != 0) {
      iVar8 = iVar8 + -1;
      puVar9 = puVar9 + -2;
      piVar1 = piVar1 + -2;
      goto LAB_420028ac;
    }
  }
  uVar2 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)(1,puVar7,PTR_DAT_4200014c,uVar2,puVar7);
  iStack_3c = -1;
LAB_42002ac8:
  iVar8 = iVar8 + -1;
  puVar9 = puVar9 + -2;
  piVar1 = piVar1 + -2;
  if (iVar8 == -1) {
LAB_42002ae2:
    FUN_42002550();
    return iStack_3c;
  }
  goto LAB_420028ac;
}