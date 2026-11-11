// 42011fd8  esp_partition_erase_range  FUN_42011fd8  size=98
// strings: partition != NULL

undefined4 FUN_42011fd8(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_partition_target_c_3c033eac_0x1f_42000e48,0x7e,
               PTR_s_esp_partition_erase_range_42000e58,PTR_s_partition____NULL_42000e40);
  }
  if (*(char *)((int)param_1 + 0x2a) == '\0') {
    if ((uint)param_1[4] < param_2) {
      uVar1 = 0x102;
    }
    else if (param_1[4] - param_2 < param_3) {
      uVar1 = 0x104;
    }
    else if ((param_3 & 0xfff) == 0) {
      if ((param_2 & 0xfff) == 0) {
        uVar1 = (*(code *)PTR_FUN_42000a18)(*param_1,param_1[3] + param_2,param_3);
      }
      else {
        uVar1 = 0x102;
      }
    }
    else {
      uVar1 = 0x104;
    }
  }
  else {
    uVar1 = 0x10d;
  }
  return uVar1;
}


