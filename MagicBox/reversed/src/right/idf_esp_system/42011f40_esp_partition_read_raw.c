// strings: partition != NULL

undefined4 FUN_42011f40(undefined4 *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_partition_target_c_3c033eac_0x1f_42000e48,0x5e,
               PTR_s_esp_partition_read_raw_42000e4c,PTR_s_partition____NULL_42000e40);
  }
  if ((uint)param_1[4] < param_2) {
    uVar1 = 0x102;
  }
  else if (param_1[4] - param_2 < param_4) {
    uVar1 = 0x104;
  }
  else {
    uVar1 = (*(code *)PTR_FUN_42000e50)(*param_1,param_3,param_1[3] + param_2,param_4);
  }
  return uVar1;
}