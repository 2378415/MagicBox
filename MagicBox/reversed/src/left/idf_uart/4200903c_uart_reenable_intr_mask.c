// strings: uart_reenable_intr_mask

char FUN_4200903c(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined *puVar6;
  uint uVar7;
  int iVar8;
  
  iVar2 = DAT_42000a40;
  piVar5 = (int *)(param_1 * 4 + DAT_42000a40);
  iVar8 = *piVar5;
  cVar3 = *(char *)(iVar8 + 0x1c);
  if ((cVar3 == '\0') ||
     (iVar8 = (*(code *)PTR_FUN_42000a5c)
                        (*(undefined4 *)(iVar8 + 0x60),*(undefined4 *)(iVar8 + 0x20),
                         *(undefined1 *)(iVar8 + 0x24),0), puVar1 = PTR_DAT_42000a3c, iVar8 != 1)) {
    cVar3 = '\0';
  }
  else {
    puVar6 = PTR_DAT_42000a3c + (param_1 & 0xffff) * 0x18 + 0xc;
    (*(code *)PTR_FUN_420004dc)(puVar6,0xffffffff);
    iVar8 = *piVar5;
    *(undefined1 *)(iVar8 + 0x1c) = 0;
    *(uint *)(iVar8 + 0x14) = *(int *)(iVar8 + 0x14) + (uint)*(byte *)(iVar8 + 0x24);
    (*(code *)PTR_FUN_420004e0)(puVar6);
    uVar7 = *(uint *)*piVar5;
    if (uVar7 < 3) {
      puVar6 = puVar1 + uVar7 * 0x18 + 0xc;
      (*(code *)PTR_FUN_420004dc)(puVar6,0xffffffff);
      iVar8 = *(int *)(puVar1 + uVar7 * 0x18 + 8);
      uVar7 = *(uint *)(*(int *)(uVar7 * 4 + iVar2) + 0x28) & 0x101;
      memw();
      *(uint *)(iVar8 + 0x10) = uVar7;
      memw();
      memw();
      *(uint *)(iVar8 + 0xc) = uVar7 | *(uint *)(iVar8 + 0xc);
      (*(code *)PTR_FUN_420004e0)(puVar6);
    }
    else {
      uVar4 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (1,PTR_DAT_42000a54,PTR_DAT_42000a58,uVar4,PTR_DAT_42000a54,
                 PTR_s_uart_reenable_intr_mask_42000a50,0x1d2);
    }
  }
  return cVar3;
}