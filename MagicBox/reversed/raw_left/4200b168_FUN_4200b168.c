// 4200b168  FUN_4200b168  FUN_4200b168  size=387
// strings: uart_driver_delete | uart | *3P3 | (j7@

undefined4 FUN_4200b168(uint param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int aiStack_40 [4];
  undefined *puStack_30;
  
  if (param_1 < 3) {
    puStack_30 = (undefined *)(param_1 << 2);
    piVar3 = (int *)(param_1 * 4 + DAT_42000a40);
    if (*piVar3 == 0) {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)(3,PTR_DAT_42000a54,PTR_DAT_42000ba0,uVar2,PTR_DAT_42000a54);
    }
    else {
      FUN_42005814(*(undefined4 *)(*piVar3 + 8));
      puVar1 = PTR_DAT_42000a3c;
      iVar6 = param_1 * 0x18;
      puVar5 = PTR_DAT_42000a3c + iVar6 + 0xc;
      (*(code *)PTR_FUN_420004dc)(puVar5,0xffffffff);
      puStack_30 = puVar1 + iVar6;
      iVar8 = *(int *)(puStack_30 + 8);
      memw();
      uVar7 = *(uint *)(iVar8 + 0xc);
      *(uint *)(*piVar3 + 0x28) = *(uint *)(*piVar3 + 0x28) & 0xfffffefe;
      memw();
      *(uint *)(iVar8 + 0xc) = uVar7 & 0xfffffefe;
      (*(code *)PTR_FUN_420004e0)(puVar5);
      (*(code *)PTR_FUN_420004dc)(puVar5,0xffffffff);
      iVar8 = *(int *)(puStack_30 + 8);
      memw();
      uVar7 = *(uint *)(iVar8 + 0xc);
      *(uint *)(*piVar3 + 0x28) = *(uint *)(*piVar3 + 0x28) & 0xfffffffd;
      memw();
      *(uint *)(iVar8 + 0xc) = uVar7 & 0xfffffffd;
      (*(code *)PTR_FUN_420004e0)(puVar5);
      (*(code *)PTR_FUN_420004dc)(puVar5,0xffffffff);
      iVar8 = *piVar3;
      puStack_30 = *(undefined **)(iVar8 + 0x38);
      if (puStack_30 != (undefined *)0x0) {
        *(undefined4 *)(iVar8 + 0x38) = 0;
        *(undefined4 *)(iVar8 + 0x2c) = 0;
        *(undefined4 *)(iVar8 + 0x30) = 0;
      }
      (*(code *)PTR_FUN_420004e0)(puVar5);
      (*(code *)PTR_FUN_42000570)(puStack_30);
      puVar4 = (undefined4 *)(DAT_42000a40 + param_1 * 4);
      FUN_42008fcc(*puVar4);
      *puVar4 = 0;
      aiStack_40[0] = 0;
      FUN_4202d63c(puVar1 + iVar6 + 8,aiStack_40);
      if (aiStack_40[0] == 9) {
        FUN_4201abe4();
      }
      (*(code *)PTR_FUN_420008d8)(puVar1 + iVar6);
      if (puVar1[param_1 * 0x18 + 0x14] != '\0') {
        if (param_1 - 1 < 2) {
          (*(code *)PTR_FUN_42000aa8)();
          if (param_1 == 2) {
            memw();
            memw();
            *(uint *)(DAT_42000284 + 0x1c) = *(uint *)(DAT_42000284 + 0x1c) & 0xfffffdff;
          }
          else {
            memw();
            memw();
            *(uint *)(DAT_42000284 + 0x18) = *(uint *)(DAT_42000284 + 0x18) & 0xffffffdf;
          }
          (*(code *)PTR_FUN_42000aac)();
        }
        puVar1[param_1 * 0x18 + 0x14] = 0;
      }
      (*(code *)PTR_FUN_420008dc)(puVar1 + iVar6);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_42000a54,PTR_DAT_42000a58,uVar2,PTR_DAT_42000a54,
               PTR_s_uart_driver_delete_42000b9c,0x707);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


