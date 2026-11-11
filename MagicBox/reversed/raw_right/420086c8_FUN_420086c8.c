// 420086c8  FUN_420086c8  FUN_420086c8  size=373
// strings: @d VF

uint FUN_420086c8(int param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  undefined *puVar1;
  uint uVar2;
  undefined *puVar3;
  undefined *puVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_30;
  
  if (param_3 == 0) {
    param_3 = 0;
  }
  else {
    piVar5 = (int *)(param_1 * 4 + DAT_42000844);
    uStack_30 = param_5;
    (*(code *)PTR_FUN_42000350)(*(undefined4 *)(*piVar5 + 0x6c),0xffffffff);
    iVar8 = *piVar5;
    *(undefined1 *)(iVar8 + 0x10) = 0;
    if (*(int *)(iVar8 + 0x3c) < 1) {
      uVar7 = param_3;
      while (puVar1 = PTR_DAT_42000848, uVar2 = DAT_4200077c, uVar7 != 0) {
        iVar8 = (*(code *)PTR_FUN_42000350)
                          (*(undefined4 *)(*(int *)(param_1 * 4 + DAT_42000844) + 0x70),0xffffffff);
        if (iVar8 == 1) {
          uVar2 = FUN_420077e0(param_1,param_2,uVar7);
          if (uVar2 < uVar7) {
            *(undefined1 *)(*(int *)(param_1 * 4 + DAT_42000844) + 0x40) = 1;
            FUN_42008664(param_1,1,10);
          }
          uVar7 = uVar7 - uVar2;
          param_2 = param_2 + uVar2;
        }
      }
      if (param_4 != 0) {
        puVar3 = PTR_DAT_42000848 + param_1 * 0x18 + 8;
        memw();
        *(uint *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0x10) = DAT_4200077c;
        puVar4 = puVar1 + param_1 * 0x18 + 0xc;
        (*(code *)PTR_FUN_420003a8)(puVar4,0xffffffff);
        FUN_42024484(puVar3,uStack_30);
        iVar8 = *(int *)(puVar1 + param_1 * 0x18 + 8);
        memw();
        memw();
        *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) | uVar2;
        (*(code *)PTR_FUN_420003ac)(puVar4);
        (*(code *)PTR_FUN_42000350)
                  (*(undefined4 *)(*(int *)(param_1 * 4 + DAT_42000844) + 0x78),0xffffffff);
      }
      (*(code *)PTR_FUN_42000358)(*(undefined4 *)(*(int *)(param_1 * 4 + DAT_42000844) + 0x70),0,0);
    }
    else {
      uStack_30 = (*(code *)PTR_FUN_420008cc)(*(undefined4 *)(iVar8 + 100));
      if (param_4 == 0) {
        local_40 = 0;
      }
      else {
        local_40 = 6;
      }
      uStack_3c = param_5;
      uStack_38 = param_3;
      (*(code *)PTR_FUN_42000878)
                (*(undefined4 *)(*(int *)(param_1 * 4 + DAT_42000844) + 100),&local_40,0xc,
                 0xffffffff);
      iVar8 = 0;
      for (uVar7 = param_3; uVar7 != 0; uVar7 = uVar7 - iVar6) {
        uVar2 = uStack_30 >> 1;
        iVar6 = (uVar2 < uVar7) * uVar2 + (uVar2 >= uVar7) * uVar7;
        (*(code *)PTR_FUN_42000878)
                  (*(undefined4 *)(*(int *)(param_1 * 4 + DAT_42000844) + 100),param_2 + iVar8,iVar6
                   ,0xffffffff);
        iVar8 = iVar8 + iVar6;
        FUN_42008664(param_1,1,10);
      }
    }
    (*(code *)PTR_FUN_42000358)(*(undefined4 *)(*(int *)(param_1 * 4 + DAT_42000844) + 0x6c),0,0);
  }
  return param_3;
}


