undefined4 FUN_40380060(int *param_1,char param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)param_1[1];
  if (param_2 == '\0') {
    memw();
    memw();
    *puVar1 = *puVar1 | DAT_403745e0;
  }
  else {
    memw();
    memw();
    *puVar1 = *puVar1 | DAT_403749c8;
  }
  (**(code **)(*param_1 + 0x40))();
  return 0;
}