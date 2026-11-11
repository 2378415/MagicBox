undefined4 * FUN_42016ea8(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar1 = DAT_42001130;
  puVar2 = DAT_42001128;
  if (*DAT_4200112c != '\0') {
    puVar2 = (undefined4 *)FUN_420062a0(*DAT_42001130);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)(*(code *)PTR_FUN_420006e0)(8);
      puVar3 = puVar2;
      if (puVar2 != (undefined4 *)0x0) goto LAB_42016ed7;
      do {
        puVar3 = (undefined4 *)FUN_42016f38();
LAB_42016ed7:
        iVar4 = FUN_420062bc(*puVar1,puVar3);
      } while (iVar4 != 0);
      *puVar2 = 0;
      puVar2[1] = 0;
    }
  }
  return puVar2;
}