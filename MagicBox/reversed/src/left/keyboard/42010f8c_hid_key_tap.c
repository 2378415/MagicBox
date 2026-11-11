void hid_key_tap(undefined4 param_1,undefined2 param_2,uint param_3,uint param_4)

{
  hid_key_down(param_1,param_2);
  if ((int)param_3 < 1) {
    if ((int)param_4 < 1) goto LAB_42010fcf;
    param_3 = (*(code *)PTR_FUN_42000e24)();
    param_3 = param_3 % param_4;
  }
  (*(code *)PTR_FUN_42000098)((uint)((ulonglong)(param_3 * 1000) * (ulonglong)DAT_420002d0 >> 0x26))
  ;
LAB_42010fcf:
  hid_key_up(param_1,param_2);
  return;
}