// strings: partition != NULL

undefined4 FUN_42018ec0(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *in_t0;
  
  puVar2 = param_1;
  if (param_1 == (undefined4 *)0x0) {
    puVar2 = in_t0;
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_partition_target_c_3c039d00_0x1f_420016d8,0x7e,
               PTR_s_esp_partition_erase_range_420016e8,PTR_s_partition____NULL_420016d0);
  }
  uVar1 = 0x10d;
  if (*(char *)((int)param_1 + 0x2a) == '\0') {
    uVar1 = 0x102;
    if ((((param_2 <= (uint)puVar2[4]) && (uVar1 = 0x104, param_3 <= puVar2[4] - param_2)) &&
        ((param_3 & 0xfff) == 0)) && (uVar1 = 0x102, (param_2 & 0xfff) == 0)) {
      uVar1 = (*(code *)PTR_FUN_42000cdc)(*puVar2,param_2 + puVar2[3],param_3);
    }
  }
  return uVar1;
}