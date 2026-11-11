void FUN_4201a934(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x24) = *(uint *)(*param_1 + 0x24) & DAT_42001998 | (param_2 & 0x3ff) << 10;
  return;
}