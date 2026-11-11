void FUN_4202ddac(int param_1,char param_2)

{
  *(char *)(DAT_42001e00 + param_1) = param_2 + '\x01';
  (*(code *)PTR_FUN_420004c8)();
  (*(code *)PTR_FUN_420004e0)(PTR_DAT_42001dfc);
  return;
}