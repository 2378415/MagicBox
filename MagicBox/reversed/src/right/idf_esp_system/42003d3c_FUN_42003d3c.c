void FUN_42003d3c(undefined4 *param_1)

{
  undefined2 uVar1;
  
  (*DAT_42000240)(param_1,0,0xc);
  *param_1 = 9;
  uVar1 = (*(code *)PTR_FUN_42000524)();
  *(undefined2 *)(param_1 + 2) = uVar1;
  *(undefined1 *)((int)param_1 + 10) = 2;
  param_1[1] = 0x12;
  return;
}