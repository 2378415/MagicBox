// strings: uart_flush_input | uart

undefined4 FUN_4200af94(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int *piVar5;
  int iVar6;
  undefined *puVar7;
  undefined4 uVar8;
  uint uVar9;
  int aiStack_40 [4];
  int iStack_30;
  int iStack_2c;
  
  if (param_1 < 3) {
    iStack_30 = param_1 << 2;
    piVar5 = (int *)(param_1 * 4 + DAT_42000a40);
    iVar6 = *piVar5;
    if (iVar6 != 0) {
      (*(code *)PTR_FUN_42000480)(*(undefined4 *)(iVar6 + 0x68),0xffffffff);
      iVar3 = param_1 * 0x18;
      puVar7 = PTR_DAT_42000a3c + iVar3 + 0xc;
      iStack_2c = param_1 * 2;
      (*(code *)PTR_FUN_420004dc)(puVar7,0xffffffff);
      memw();
      memw();
      *(uint *)(*(int *)(PTR_DAT_42000a3c + iVar3 + 8) + 0xc) =
           *(uint *)(*(int *)(PTR_DAT_42000a3c + iVar3 + 8) + 0xc) & 0xfffffefe;
      (*(code *)PTR_FUN_420004e0)(puVar7);
      while (iVar2 = (*(code *)PTR_FUN_42000b98)(*(undefined4 *)(iVar6 + 0x60),aiStack_40,0),
            iVar2 != 0) {
        (*(code *)PTR_FUN_420004dc)(puVar7,0xffffffff);
        *(int *)(*piVar5 + 0x14) = *(int *)(*piVar5 + 0x14) - aiStack_40[0];
        FUN_4200910c(param_1);
        (*(code *)PTR_FUN_420004e0)(puVar7);
        (*(code *)PTR_FUN_42000b88)(*(undefined4 *)(iVar6 + 0x60),iVar2);
        iVar2 = *piVar5;
        if ((*(char *)(iVar2 + 0x1c) != '\0') &&
           (iVar2 = (*(code *)PTR_FUN_42000a5c)
                              (*(undefined4 *)(iVar2 + 0x60),*(undefined4 *)(iVar2 + 0x20),
                               *(undefined1 *)(iVar2 + 0x24),0), iVar2 == 1)) {
          (*(code *)PTR_FUN_420004dc)(puVar7,0xffffffff);
          iVar2 = *piVar5;
          *(undefined1 *)(iVar2 + 0x1c) = 0;
          *(uint *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + (uint)*(byte *)(iVar2 + 0x24);
          (*(code *)PTR_FUN_420004e0)(puVar7);
        }
      }
      (*(code *)PTR_FUN_420004dc)();
      iVar2 = *(int *)(DAT_42000a40 + iStack_30);
      puVar4 = PTR_DAT_42000a3c + iVar3 + 8;
      if (*(int *)(iVar2 + 0x14) == 0) {
        *(undefined1 *)(iVar2 + 0x1c) = 0;
        (*(code *)PTR_FUN_420004e0)(puVar7);
        FUN_42004478(puVar4);
      }
      else {
        *(undefined4 *)(iVar2 + 0x14) = 0;
        *(undefined1 *)(iVar2 + 0x1c) = 0;
        (*(code *)PTR_FUN_420004e0)(puVar7);
        uVar1 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)(1,PTR_DAT_42000a54,PTR_DAT_42000b94,uVar1,PTR_DAT_42000a54);
        FUN_42004478(puVar4);
      }
      (*(code *)PTR_FUN_420004dc)(puVar7,0xffffffff);
      iVar3 = *(int *)(PTR_DAT_42000a3c + (iStack_2c + param_1) * 8 + 8);
      uVar9 = *(uint *)(*(int *)(DAT_42000a40 + iStack_30) + 0x28) & 0x101;
      memw();
      *(uint *)(iVar3 + 0x10) = uVar9;
      memw();
      memw();
      *(uint *)(iVar3 + 0xc) = uVar9 | *(uint *)(iVar3 + 0xc);
      (*(code *)PTR_FUN_420004e0)(puVar7);
      (*(code *)PTR_FUN_42000488)(*(undefined4 *)(iVar6 + 0x68),0,0);
      return 0;
    }
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar8 = 0x62f;
    puVar7 = PTR_DAT_42000af0;
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar8 = 0x62e;
    puVar7 = PTR_DAT_42000a58;
  }
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_42000a54,puVar7,uVar1,PTR_DAT_42000a54,PTR_s_uart_flush_input_42000b90,uVar8)
  ;
  return 0xffffffff;
}