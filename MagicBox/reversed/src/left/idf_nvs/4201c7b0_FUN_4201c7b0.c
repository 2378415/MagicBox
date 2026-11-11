void FUN_4201c7b0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = DAT_42001a84;
  if (*DAT_42001a84 == 0) {
    puVar2 = (undefined4 *)(*(code *)PTR_FUN_4200056c)(0x28);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = PTR_PTR_42001a88;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[7] = 0;
      puVar2[8] = 0;
      puVar2[9] = 0;
    }
    *piVar1 = (int)puVar2;
  }
  return;
}