// 42002b00  FUN_42002b00  FUN_42002b00  size=114
// strings: efuse

undefined4 FUN_42002b00(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  
  iVar7 = 1;
  puVar5 = PTR_DAT_420000cc;
  puVar6 = PTR_DAT_420000d4;
  do {
    iVar1 = FUN_4202ce28(iVar7);
    if (iVar1 == 3) {
      piVar8 = *(int **)(puVar6 + 8);
      do {
        if (*(int **)(puVar6 + 0xc) < piVar8) goto LAB_42002b65;
        memw();
        iVar1 = *piVar8;
        piVar8 = piVar8 + 1;
      } while (iVar1 == 0);
      uVar9 = *(uint *)(puVar5 + 0xc);
      uVar4 = *(uint *)(puVar5 + 8);
      if (uVar4 <= uVar9) {
        iVar1 = 0;
        do {
          iVar2 = FUN_420026dc(iVar7,iVar1);
          uVar4 = uVar4 + 4;
          if (iVar2 != 0) {
            uVar3 = (*(code *)PTR_FUN_4200005c)();
            (*(code *)PTR_FUN_42000118)
                      (1,PTR_s_efuse_42000124,PTR_DAT_42000150,uVar3,PTR_s_efuse_42000124);
            return DAT_420000e0;
          }
          iVar1 = iVar1 + 1;
        } while (uVar4 <= uVar9);
      }
    }
LAB_42002b65:
    iVar7 = iVar7 + 1;
    puVar6 = puVar6 + 8;
    puVar5 = puVar5 + 8;
    if (iVar7 == 0xb) {
      return 0;
    }
  } while( true );
}


