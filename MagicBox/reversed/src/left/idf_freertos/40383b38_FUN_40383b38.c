void FUN_40383b38(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(PTR_DAT_4037480c + 0x20);
  puVar1 = (undefined4 *)PTR_DAT_4037480c;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 < puVar2);
  return;
}