void FUN_40376fe8(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_403747a8;
  memw();
  memw();
  *(uint *)(*DAT_403747a4 + 0x6c) = *(uint *)(*DAT_403747a4 + 0x6c) | 4;
  (*(code *)*puVar1)(param_1);
  return;
}