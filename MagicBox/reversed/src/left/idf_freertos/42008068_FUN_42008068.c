undefined4 FUN_42008068(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  iVar4 = FUN_4202dd8c(0x24);
  uVar2 = DAT_42000540;
  iVar1 = DAT_42000284;
  if (iVar4 == 0) {
    memw();
    memw();
    *(uint *)(DAT_42000284 + 0x18) = *(uint *)(DAT_42000284 + 0x18) | DAT_42000540;
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | uVar2;
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_42000544;
  }
  FUN_4202ddac(0x24,iVar4);
  uVar3 = DAT_42000934;
  local_30 = *(undefined4 *)PTR_PTR_42000930;
  uStack_2c = *(undefined4 *)(PTR_PTR_42000930 + 4);
  (*(code *)PTR_FUN_42000938)(DAT_42000934);
  (*(code *)PTR_FUN_4200093c)(uVar3,&local_30);
  (*(code *)PTR_FUN_42000940)(uVar3,0);
  (*(code *)PTR_FUN_42000944)(uVar3,2,0);
  (*(code *)PTR_FUN_42000948)(uVar3,2,0);
  (*(code *)PTR_FUN_4200094c)(uVar3,0,0,1);
  (*(code *)PTR_FUN_4200094c)(uVar3,0,1);
  return 0;
}