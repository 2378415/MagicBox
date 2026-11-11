// 4037b330  FUN_4037b330  FUN_4037b330  size=75
// strings: %s failed: esp_err_t 0x%x |  (%s) |  at 0x%08x | file: '%s' line %d

void FUN_4037b330(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7)

{
  undefined4 uVar1;
  int iVar2;
  
  (*DAT_40374438)(PTR_s__s_failed__esp_err_t_0x_x_40374cc0,param_1,param_2);
  uVar1 = (*(code *)PTR_FUN_40374514)(param_2);
  (*DAT_40374438)(PTR_s___s__40374cc4,uVar1);
  (*DAT_40374438)(PTR_s_at_0x_08x_40374cc8,param_7 + -3);
  iVar2 = FUN_403780cc();
  if (iVar2 != 0) {
    (*DAT_40374438)(PTR_s_file____s__line__d_func___s_expr_40374ccc,param_3,param_4,param_5,param_6)
    ;
  }
  return;
}


