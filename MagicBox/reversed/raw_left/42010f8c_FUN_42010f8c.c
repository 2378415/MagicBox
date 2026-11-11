// 42010f8c  FUN_42010f8c  FUN_42010f8c  size=79

void FUN_42010f8c(undefined4 param_1,undefined2 param_2,uint param_3,uint param_4)

{
  FUN_42010e70(param_1,param_2);
  if ((int)param_3 < 1) {
    if ((int)param_4 < 1) goto LAB_42010fcf;
    param_3 = (*(code *)PTR_FUN_42000e24)();
    param_3 = param_3 % param_4;
  }
  (*(code *)PTR_FUN_42000098)((uint)((ulonglong)(param_3 * 1000) * (ulonglong)DAT_420002d0 >> 0x26))
  ;
LAB_42010fcf:
  FUN_42010f00(param_1,param_2);
  return;
}


