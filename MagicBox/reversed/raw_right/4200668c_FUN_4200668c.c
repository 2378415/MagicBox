// 4200668c  FUN_4200668c  FUN_4200668c  size=427

int FUN_4200668c(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 param_5,undefined4 param_6,int *param_7)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int local_40 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  iVar1 = (uint)(param_1 < 3) * param_1 + (uint)(param_1 >= 3) * 3;
  uVar4 = 0;
  *param_7 = 0;
  uStack_30 = param_5;
  uStack_2c = param_6;
  do {
    if (iVar1 <= (int)uVar4) {
      puVar2 = (undefined4 *)(*(code *)PTR_FUN_42000484)(0x2c,DAT_4200077c);
      if (puVar2 == (undefined4 *)0x0) {
        iVar1 = 0x101;
      }
      else {
        *puVar2 = uStack_30;
        puVar2[1] = uStack_2c;
        puVar2[2] = param_2;
        puVar2[3] = param_3;
        puVar2[4] = param_4;
        uVar5 = param_2[1];
        puVar2[5] = *param_2;
        puVar2[6] = uVar5;
        uVar5 = param_3[1];
        puVar2[7] = *param_3;
        puVar2[8] = uVar5;
        uVar5 = param_4[1];
        puVar2[9] = *param_4;
        puVar2[10] = uVar5;
        iVar6 = 2;
        while (iVar6 != 0) {
          iVar6 = iVar6 + -1;
          param_2[iVar6] = 0;
        }
        iVar6 = 2;
        while (iVar6 != 0) {
          iVar6 = iVar6 + -1;
          param_3[iVar6] = 0;
        }
        iVar6 = 2;
        while (iVar6 != 0) {
          iVar6 = iVar6 + -1;
          param_4[iVar6] = 0;
        }
        uVar5 = FUN_42009400();
        (*(code *)PTR_FUN_420003a8)(uVar5,0xffffffff);
        for (uVar4 = 0; (int)uVar4 < iVar1; uVar4 = uVar4 + 1) {
          if (uVar4 < 0x40) {
            uVar8 = uVar4 + 0x1f;
            if (-1 < (int)uVar4) {
              uVar8 = uVar4;
            }
            iVar6 = (int)uVar8 >> 5;
            uVar8 = 1 << 0x20 - (0x20 - (uVar4 & 0x1f));
            if ((((puVar2[iVar6 + 5] & uVar8) != 0) || ((uVar8 & puVar2[iVar6 + 7]) != 0)) ||
               ((uVar8 & puVar2[iVar6 + 9]) != 0)) {
              if (*(int *)(uVar4 * 4 + DAT_42000788) == 0) {
                FUN_420093e8(uVar4,PTR_FUN_4200078c);
              }
              piVar7 = (int *)(uVar4 * 4 + DAT_42000788);
              *piVar7 = *piVar7 + 1;
            }
          }
        }
        for (uVar4 = 0; (int)uVar4 < iVar1; uVar4 = uVar4 + 1) {
          if (uVar4 < 0x40) {
            uVar8 = uVar4 + 0x1f;
            if (-1 < (int)uVar4) {
              uVar8 = uVar4;
            }
            uVar3 = 1 << 0x20 - (0x20 - (uVar4 & 0x1f));
            if ((((puVar2[((int)uVar8 >> 5) + 5] & uVar3) != 0) &&
                (iVar6 = FUN_420090a4(uVar4,local_40), iVar6 == 0)) && (local_40[0] != 0)) {
              param_2[(int)uVar8 >> 5] = uVar3 | param_2[(int)uVar8 >> 5];
              FUN_4200a690(*puVar2,puVar2[1]);
            }
          }
        }
        iVar1 = FUN_42006634(puVar2);
        if (iVar1 == 0) {
          FUN_42009400();
          (*(code *)PTR_FUN_420003ac)();
          *param_7 = (int)puVar2;
        }
        else {
          FUN_42009400();
          (*(code *)PTR_FUN_420003ac)();
          (*(code *)PTR_FUN_420004c0)(puVar2);
        }
      }
      return iVar1;
    }
    if (uVar4 < 0x40) {
      uVar8 = uVar4 + 0x1f;
      if (-1 < (int)uVar4) {
        uVar8 = uVar4;
      }
      iVar6 = (int)uVar8 >> 5;
      uVar8 = 1 << 0x20 - (0x20 - (uVar4 & 0x1f));
      if (((((param_2[iVar6] & uVar8) != 0) || ((uVar8 & param_3[iVar6]) != 0)) ||
          ((uVar8 & param_4[iVar6]) != 0)) && (iVar6 = FUN_420093c8(uVar4), iVar6 == 0)) {
        return 0x103;
      }
    }
    uVar4 = uVar4 + 1;
  } while( true );
}


