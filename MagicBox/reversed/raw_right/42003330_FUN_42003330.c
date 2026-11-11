// 42003330  FUN_42003330  FUN_42003330  size=36

void FUN_42003330(uint param_1,uint param_2)

{
  uint *puVar1;
  
  for (puVar1 = (uint *)*DAT_42000478;
      (puVar1 != (uint *)0x0 &&
      (((*puVar1 >> 0x10 & 1) != param_2 || ((*puVar1 >> 0x11 & 0x1f) != param_1))));
      puVar1 = (uint *)puVar1[2]) {
  }
  return;
}


