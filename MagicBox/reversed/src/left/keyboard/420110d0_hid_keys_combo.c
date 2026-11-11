void hid_keys_combo(undefined4 param_1,undefined2 *param_2,int param_3,uint param_4,uint param_5)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (param_3 == 0) {
    if ((int)param_4 < 1) {
      if ((int)param_5 < 1) {
        return;
      }
      param_4 = (*(code *)PTR_FUN_42000e24)();
      param_4 = param_4 % param_5;
    }
    (*(code *)PTR_FUN_42000098)
              ((uint)((ulonglong)(param_4 * 1000) * (ulonglong)DAT_420002d0 >> 0x26));
    return;
  }
  iVar2 = 0;
  puVar1 = param_2;
  do {
    iVar2 = iVar2 + 1;
    hid_key_down(param_1,*puVar1);
    puVar1 = puVar1 + 1;
  } while (param_3 != iVar2);
  if ((int)param_4 < 1) {
    if ((int)param_5 < 1) goto LAB_4201111e;
    param_4 = (*(code *)PTR_FUN_42000e24)();
    param_4 = param_4 % param_5;
  }
  (*(code *)PTR_FUN_42000098)((uint)((ulonglong)(param_4 * 1000) * (ulonglong)DAT_420002d0 >> 0x26))
  ;
LAB_4201111e:
  iVar2 = 0;
  do {
    iVar2 = iVar2 + 1;
    hid_key_up(param_1,*param_2);
    param_2 = param_2 + 1;
  } while (param_3 != iVar2);
  return;
}