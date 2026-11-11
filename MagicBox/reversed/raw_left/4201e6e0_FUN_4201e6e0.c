// 4201e6e0  FUN_4201e6e0  FUN_4201e6e0  size=66

undefined4 * FUN_4201e6e0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar1 = DAT_42001b14;
  puVar2 = DAT_42001b0c;
  if (*DAT_42001b10 != '\0') {
    puVar2 = (undefined4 *)FUN_42007ee8(*DAT_42001b14);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)(*(code *)PTR_FUN_4200056c)(8);
      puVar3 = puVar2;
      if (puVar2 != (undefined4 *)0x0) goto LAB_4201e70f;
      do {
        puVar3 = (undefined4 *)FUN_4201e770();
LAB_4201e70f:
        iVar4 = FUN_42007f14(*puVar1,puVar3);
      } while (iVar4 != 0);
      *puVar2 = 0;
      puVar2[1] = 0;
    }
  }
  return puVar2;
}


