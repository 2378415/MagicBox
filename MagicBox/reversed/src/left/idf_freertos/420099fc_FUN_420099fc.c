// strings: *U`U | (j7@

void FUN_420099fc(uint param_1)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar2 = PTR_DAT_42000a3c;
  puVar4 = PTR_DAT_42000a3c + (param_1 & 0xffff) * 0x18;
  (*(code *)PTR_FUN_420008d8)(puVar4);
  if (puVar2[param_1 * 0x18 + 0x14] != '\0') goto LAB_42009b2e;
  if (param_1 < 3) {
    (*(code *)PTR_FUN_42000aa8)();
    iVar1 = DAT_42000284;
    if (param_1 == 1) {
      memw();
      memw();
      *(uint *)(DAT_42000284 + 0x18) = *(uint *)(DAT_42000284 + 0x18) | 0x20;
      (*(code *)PTR_FUN_42000aac)();
      (*(code *)PTR_FUN_42000aa8)();
      iVar3 = DAT_42000a98;
      memw();
      memw();
      *(uint *)(DAT_42000a98 + 0x78) = *(uint *)(DAT_42000a98 + 0x78) | DAT_42000a9c;
      memw();
      memw();
      *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | 0x20;
      memw();
      memw();
      *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xffffffdf;
      memw();
      memw();
      *(uint *)(iVar3 + 0x78) = *(uint *)(iVar3 + 0x78) & DAT_42000aa0;
    }
    else {
      if (param_1 != 2) {
        memw();
        memw();
        *(uint *)(DAT_42000284 + 0x18) = *(uint *)(DAT_42000284 + 0x18) | 4;
        (*(code *)PTR_FUN_42000aac)();
        goto LAB_42009b24;
      }
      memw();
      memw();
      *(uint *)(DAT_42000284 + 0x1c) = *(uint *)(DAT_42000284 + 0x1c) | 0x200;
      (*(code *)PTR_FUN_42000aac)();
      (*(code *)PTR_FUN_42000aa8)();
      iVar3 = DAT_42000aa4;
      memw();
      memw();
      *(uint *)(DAT_42000aa4 + 0x78) = *(uint *)(DAT_42000aa4 + 0x78) | DAT_42000a9c;
      memw();
      memw();
      *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) | 0x200;
      memw();
      memw();
      *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & 0xfffffdff;
      memw();
      memw();
      *(uint *)(iVar3 + 0x78) = *(uint *)(iVar3 + 0x78) & DAT_42000aa0;
    }
    (*(code *)PTR_FUN_42000aac)();
  }
LAB_42009b24:
  puVar2[param_1 * 0x18 + 0x14] = 1;
LAB_42009b2e:
  (*(code *)PTR_FUN_420008dc)(puVar4);
  return;
}