void buttons_set(int param_1,undefined1 param_2)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x210) != 0)) {
    memw();
    memw();
    *DAT_42000e8c = param_2;
    memw();
  }
  return;
}