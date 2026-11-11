void wheel_submit(int param_1,char param_2)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x210) != 0)) {
    memw();
    memw();
    *DAT_42000e88 = (short)param_2;
    memw();
    memw();
    memw();
    *DAT_42000e4c = 1;
    memw();
    memw();
    memw();
    *DAT_42000e04 = 1;
    memw();
    if (*DAT_42000e08 != 0) {
      (*(code *)PTR_FUN_42000484)(*DAT_42000e08,0,0,2);
    }
  }
  return;
}