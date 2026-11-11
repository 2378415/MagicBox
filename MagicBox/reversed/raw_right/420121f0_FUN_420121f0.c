// 420121f0  FUN_420121f0  FUN_420121f0  size=74

undefined8 FUN_420121f0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((-(DAT_42000e74 + -1) & DAT_42000e70) == 0) {
    if ((-(DAT_42000e7c + -1) & DAT_42000e78) != 0) {
      uVar1 = 8;
      goto LAB_42012238;
    }
    (*(code *)PTR_FUN_42000044)
              (PTR_s__IDF_components_hal_esp32s3_incl_42000e88,0x220,
               PTR_s_cache_ll_l1_get_bus_42000e84,PTR_DAT_42000e80);
  }
  uVar1 = 1;
LAB_42012238:
  return CONCAT44(param_1 + param_2 + -1,uVar1);
}


