undefined4 FUN_420063d8(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  for (cVar4 = '\x01'; uVar2 = DAT_42000754, cVar4 != '\0'; cVar4 = cVar4 + -1) {
    iVar3 = FUN_420257f8(0x24);
    uVar5 = DAT_420003d0;
    iVar1 = DAT_4200015c;
    if (iVar3 == 0) {
      memw();
      memw();
      *(uint *)(DAT_4200015c + 0x18) = *(uint *)(DAT_4200015c + 0x18) | DAT_420003d0;
      memw();
      memw();
      *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | uVar5;
      memw();
      memw();
      *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_420003d4;
    }
    FUN_4202580c(0x24,iVar3);
  }
  local_30 = *(undefined4 *)PTR_PTR_42000750;
  uStack_2c = *(undefined4 *)(PTR_PTR_42000750 + 4);
  (*(code *)PTR_FUN_42000758)(DAT_42000754);
  (*(code *)PTR_FUN_4200075c)(uVar2,&local_30);
  (*(code *)PTR_FUN_42000760)(uVar2,0);
  (*(code *)PTR_FUN_42000764)(uVar2,2,0);
  (*(code *)PTR_FUN_42000768)(uVar2,2,0);
  for (uVar5 = 0; uVar5 < 2; uVar5 = uVar5 + 1) {
    (*(code *)PTR_FUN_4200076c)(DAT_42000754,0,uVar5,1);
  }
  return 0;
}