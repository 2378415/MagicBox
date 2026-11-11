// 403801e4  FUN_403801e4  FUN_403801e4  size=54

undefined4 FUN_403801e4(int *param_1,char param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)param_1[1];
  memw();
  if (param_2 == '\0') {
    memw();
    *puVar1 = *puVar1 | DAT_4037460c;
  }
  else {
    memw();
    *puVar1 = *puVar1 | DAT_40374a60;
  }
  (**(code **)(*param_1 + 0x40))();
  return 0;
}


