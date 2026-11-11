void mouse_submit_default(int param_1,undefined2 param_2,undefined2 param_3)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x210) != 0)) {
    memw();
    memw();
    *DAT_42000e00 = 0;
    memw();
    memw();
    memw();
    *DAT_42000dfc = 0;
    memw();
    memw();
    memw();
    *DAT_42000e44 = param_2;
    memw();
    memw();
    memw();
    *DAT_42000e48 = param_3;
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