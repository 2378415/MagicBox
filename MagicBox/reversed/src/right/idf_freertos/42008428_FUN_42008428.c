int FUN_42008428(uint param_1,uint param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 local_30;
  uint uStack_2c;
  uint uStack_28;
  
  if (param_1 < 3) {
    FUN_42024a10(PTR_DAT_42000848 + param_1 * 0x18 + 8,&local_30);
    iVar2 = FUN_42013a38(local_30,0,&uStack_2c);
    puVar1 = PTR_DAT_42000848;
    if (iVar2 == 0) {
      puVar4 = PTR_DAT_42000848 + param_1 * 0x18 + 0xc;
      (*(code *)PTR_FUN_420003a8)(puVar4,0xffffffff);
      iVar3 = *(int *)(puVar1 + param_1 * 0x18 + 8);
      iVar8 = (int)((ulonglong)param_2 * (ulonglong)DAT_420008c0 >> 0x20);
      uVar5 = uStack_2c + param_2 * DAT_420008c0;
      if (uVar5 < uStack_2c) {
        iVar8 = iVar8 + 1;
      }
      iVar6 = uVar5 - 1;
      iVar7 = iVar8 + -1;
      if (iVar6 != -1) {
        iVar7 = iVar8;
      }
      iVar8 = (*DAT_420000d0)(iVar6,iVar7);
      if (iVar8 == 0) {
        iVar8 = (*(code *)PTR_FUN_4200006c)();
      }
      uVar5 = (uStack_2c << 4) / (param_2 * iVar8);
      memw();
      memw();
      *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffff000 | uVar5 >> 4 & 0xfff;
      memw();
      memw();
      *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & DAT_420008c4 | (uVar5 & 0xf) << 0x14;
      memw();
      memw();
      memw();
      uStack_28 = *(uint *)(iVar3 + 0x78) & DAT_420008c8 | (iVar8 - 1U & 0xff) << 0xc;
      memw();
      memw();
      memw();
      *(uint *)(iVar3 + 0x78) = uStack_28;
      (*(code *)PTR_FUN_420003ac)(puVar4);
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}