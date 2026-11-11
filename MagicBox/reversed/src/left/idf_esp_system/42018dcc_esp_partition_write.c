// strings: partition != NULL

undefined4 FUN_42018dcc(int *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *in_t0;
  
  piVar2 = param_1;
  if (param_1 == (int *)0x0) {
    piVar2 = in_t0;
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_partition_target_c_3c039d00_0x1f_420016d8,0x42,
               PTR_s_esp_partition_write_420016d4,PTR_s_partition____NULL_420016d0);
  }
  uVar1 = 0x10d;
  if (*(char *)((int)param_1 + 0x2a) == '\0') {
    uVar1 = 0x102;
    if ((param_2 <= (uint)piVar2[4]) && (uVar1 = 0x104, param_4 <= piVar2[4] - param_2)) {
      iVar3 = *piVar2;
      if (*(char *)((int)piVar2 + 0x29) == '\0') {
        uVar1 = (*(code *)PTR_FUN_42000ccc)(iVar3,param_3,param_2 + piVar2[3],param_4);
      }
      else {
        uVar1 = 0x106;
        if (iVar3 == *DAT_42000cbc) {
          uVar1 = (*(code *)PTR_FUN_42000cc8)(iVar3,param_2 + piVar2[3],param_3,param_4);
        }
      }
    }
  }
  return uVar1;
}