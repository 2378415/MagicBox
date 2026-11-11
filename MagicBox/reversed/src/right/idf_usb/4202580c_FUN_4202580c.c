void FUN_4202580c(int param_1,char param_2)

{
  *(char *)(DAT_42001364 + param_1) = param_2 + '\x01';
  (*(code *)PTR_FUN_42000870)();
  return;
}