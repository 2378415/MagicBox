// 420027d4  FUN_420027d4  FUN_420027d4  size=216

undefined4 FUN_420027d4(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  if (param_1 < 2) {
    if (*(int *)(param_1 * 4 + DAT_42000328) == 0) {
      uVar5 = 0x103;
    }
    else {
      iVar1 = (*(code *)PTR_FUN_42000340)();
      if (iVar1 == 2) {
        (*(code *)PTR_FUN_42000344)();
        uVar2 = (*(code *)PTR_FUN_42000348)();
        uVar3 = (*(code *)PTR_FUN_42000348)(*(undefined4 *)(param_1 * 4 + DAT_42000328));
        if (uVar3 < uVar2) {
          (*(code *)PTR_FUN_4200034c)(*(undefined4 *)(param_1 * 4 + DAT_42000328),uVar2);
        }
        iVar1 = param_1 * 4;
        puVar4 = (undefined4 *)(param_1 * 4 + DAT_4200032c);
        (*(code *)PTR_FUN_42000350)(*puVar4,0xffffffff);
        puVar6 = (undefined4 *)(DAT_42000328 + iVar1);
        (*(code *)PTR_FUN_4200034c)(*puVar6,uVar2);
        memw();
        *(undefined4 *)(DAT_42000330 + iVar1) = param_3;
        memw();
        *(undefined4 *)(DAT_42000334 + iVar1) = param_4;
        memw();
        *(undefined4 *)(DAT_42000338 + iVar1) = param_2;
        (*(code *)PTR_FUN_42000354)(*puVar6,0,0,2);
        (*(code *)PTR_FUN_42000350)(*(undefined4 *)(DAT_4200033c + iVar1),0xffffffff);
        (*(code *)PTR_FUN_42000358)(*puVar4,0,0);
        uVar5 = 0;
      }
      else {
        uVar5 = 0x103;
      }
    }
  }
  else {
    uVar5 = 0x102;
  }
  return uVar5;
}


