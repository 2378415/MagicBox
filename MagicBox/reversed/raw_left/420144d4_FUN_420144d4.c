// 420144d4  FUN_420144d4  FUN_420144d4  size=132

void FUN_420144d4(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 uStack_70;
  undefined1 uStack_6f;
  undefined1 uStack_6e;
  undefined1 auStack_6c [64];
  undefined1 auStack_2c [4];
  undefined *puStack_28;
  
  iVar2 = DAT_42001334;
  piVar1 = DAT_42001330;
  iVar6 = 0;
LAB_420144e7:
  do {
    iVar3 = *piVar1;
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        iVar7 = (iVar5 + iVar6) % iVar3;
        iVar4 = FUN_42014480(iVar2 + iVar7 * 0x120,&uStack_70);
        iVar5 = iVar5 + 1;
        iVar3 = *piVar1;
        if (iVar4 != 0) {
          auStack_2c[0] = uStack_6f;
          puStack_28 = PTR_FUN_42001338;
          FUN_42015324(0,auStack_2c);
          iVar6 = FUN_42015380(0);
          if (iVar6 != 0) {
            FUN_42015ec8(0,uStack_6f,auStack_6c,uStack_6e);
            FUN_42016a8c(*DAT_42001328,3);
          }
          iVar6 = (iVar7 + 1) % iVar3;
          goto LAB_420144e7;
        }
      } while (iVar5 < iVar3);
    }
    (*(code *)PTR_FUN_42000eb8)(0,1,500);
  } while( true );
}


