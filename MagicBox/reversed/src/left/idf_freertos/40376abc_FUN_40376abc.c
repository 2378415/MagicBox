void FUN_40376abc(int param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_4037473c;
  if (*(int *)PTR_DAT_40374738 == param_1) {
    memw();
    *(undefined4 *)(DAT_40374518 + 0x40) = *(undefined4 *)PTR_DAT_4037473c;
    *(undefined4 *)puVar1 = 0;
  }
  return;
}