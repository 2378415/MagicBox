// 420136ac  FUN_420136ac  FUN_420136ac  size=34

void FUN_420136ac(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x48) = *(uint *)(*param_1 + 0x48) & DAT_42001040 | (param_2 & 0x3ff) << 10;
  return;
}


