// 42018f14  esp_partition_mmap  FUN_42018f14  size=92
// strings: partition != NULL

int FUN_42018f14(int *param_1,uint param_2,uint param_3,undefined4 param_4,int *param_5,
                undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *in_t0;
  
  piVar3 = param_1;
  if (param_1 == (int *)0x0) {
    piVar3 = in_t0;
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_partition_target_c_3c039d00_0x1f_420016d8,0x9e,
               PTR_s_esp_partition_mmap_420016ec,PTR_s_partition____NULL_420016d0,param_6);
  }
  iVar1 = 0x102;
  if (((param_2 <= (uint)param_1[4]) && (iVar1 = 0x104, param_3 <= param_1[4] - param_2)) &&
     (iVar1 = 0x106, *piVar3 == *DAT_42000cbc)) {
    uVar2 = param_2 + piVar3[3] & 0xffff;
    iVar1 = FUN_42019854(param_2 + piVar3[3] & 0xffff0000,param_3 + uVar2,param_4,param_5);
    if (iVar1 == 0) {
      *param_5 = *param_5 + uVar2;
    }
  }
  return iVar1;
}


