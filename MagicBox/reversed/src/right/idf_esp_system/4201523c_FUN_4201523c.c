int FUN_4201523c(void)

{
  undefined4 *puVar1;
  
  if (*DAT_420010d0 == 0) {
    puVar1 = (undefined4 *)(*(code *)PTR_FUN_420006e0)(0x28);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = PTR_PTR_420010cc;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      puVar1[7] = 0;
      puVar1[8] = 0;
      puVar1[9] = 0;
    }
    *DAT_420010d0 = (int)puVar1;
  }
  return *DAT_420010d0;
}