// strings: catch_ml | catch_unknown | catch_ms1 | catch_mm

undefined * FUN_4200efb0(uint param_1)

{
  undefined *puVar1;
  
  if (param_1 == 3) {
    puVar1 = PTR_s_catch_mm_42000dd8;
  }
  else if (param_1 < 4) {
    puVar1 = PTR_s_catch_ml_42000dd0;
    if ((param_1 != 1) && (puVar1 = PTR_s_catch_mr_42000dd4, param_1 != 2)) {
      puVar1 = PTR_s_catch_unknown_42000de4;
    }
  }
  else {
    puVar1 = PTR_s_catch_ms1_42000ddc;
    if ((param_1 != 4) && (puVar1 = PTR_s_catch_ms2_42000de0, param_1 != 5)) {
      puVar1 = PTR_s_catch_unknown_42000de4;
    }
  }
  return puVar1;
}