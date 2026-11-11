undefined4 FUN_420090ec(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  int *piVar6;
  int iVar7;
  int local_30 [12];
  
  if (param_1 < 3) {
    iVar4 = *(int *)(param_1 * 4 + DAT_42000844);
    if (iVar4 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      (*(code *)PTR_FUN_42000350)(*(undefined4 *)(iVar4 + 0x68),0xffffffff);
      puVar1 = PTR_DAT_42000848;
      puVar5 = PTR_DAT_42000848 + param_1 * 0x18 + 0xc;
      (*(code *)PTR_FUN_420003a8)(puVar5,0xffffffff);
      memw();
      memw();
      *(uint *)(*(int *)(puVar1 + param_1 * 0x18 + 8) + 0xc) =
           *(uint *)(*(int *)(puVar1 + param_1 * 0x18 + 8) + 0xc) & 0xfffffefe;
      (*(code *)PTR_FUN_420003ac)(puVar5);
      while (iVar2 = (*(code *)PTR_FUN_42000904)(*(undefined4 *)(iVar4 + 0x60),local_30,0),
            iVar2 != 0) {
        (*(code *)PTR_FUN_420003a8)(puVar5,0xffffffff);
        piVar6 = (int *)(param_1 * 4 + DAT_42000844);
        iVar7 = *piVar6;
        *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) - local_30[0];
        FUN_42007458(param_1);
        (*(code *)PTR_FUN_420003ac)(puVar5);
        (*(code *)PTR_FUN_42000900)(*(undefined4 *)(iVar4 + 0x60),iVar2);
        iVar2 = *piVar6;
        if ((*(char *)(iVar2 + 0x1c) != '\0') &&
           (iVar2 = (*(code *)PTR_FUN_42000878)
                              (*(undefined4 *)(iVar2 + 0x60),*(undefined4 *)(iVar2 + 0x20),
                               *(undefined1 *)(iVar2 + 0x24),0), iVar2 == 1)) {
          (*(code *)PTR_FUN_420003a8)(puVar5,0xffffffff);
          iVar2 = *(int *)(param_1 * 4 + DAT_42000844);
          *(uint *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + (uint)*(byte *)(iVar2 + 0x24);
          *(undefined1 *)(iVar2 + 0x1c) = 0;
          (*(code *)PTR_FUN_420003ac)(puVar5);
        }
      }
      (*(code *)PTR_FUN_420003a8)(puVar5,0xffffffff);
      iVar2 = *(int *)(param_1 * 4 + DAT_42000844);
      if (*(int *)(iVar2 + 0x14) != 0) {
        *(undefined4 *)(iVar2 + 0x14) = 0;
      }
      *(undefined1 *)(iVar2 + 0x1c) = 0;
      (*(code *)PTR_FUN_420003ac)(puVar5);
      FUN_42002b78(PTR_DAT_42000848 + param_1 * 0x18 + 8);
      FUN_42007498(param_1,0x101);
      (*(code *)PTR_FUN_42000358)(*(undefined4 *)(iVar4 + 0x68),0,0);
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}