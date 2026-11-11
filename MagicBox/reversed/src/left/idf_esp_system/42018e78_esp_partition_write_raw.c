// strings: partition != NULL

undefined4 FUN_42018e78(undefined4 *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *in_t0;
  
  puVar2 = param_1;
  if (param_1 == (undefined4 *)0x0) {
    puVar2 = in_t0;
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_partition_target_c_3c039d00_0x1f_420016d8,0x6c,
               PTR_s_esp_partition_write_raw_420016e4,PTR_s_partition____NULL_420016d0);
  }
  uVar1 = 0x10d;
  if (*(char *)((int)param_1 + 0x2a) == '\0') {
    uVar1 = 0x102;
    if ((param_2 <= (uint)puVar2[4]) && (uVar1 = 0x104, param_4 <= puVar2[4] - param_2)) {
      uVar1 = (*(code *)PTR_FUN_42000ccc)(*puVar2,param_3,param_2 + puVar2[3],param_4);
    }
  }
  return uVar1;
}