// strings: partition != NULL

int FUN_42012044(int *param_1,uint param_2,uint param_3,undefined4 param_4,int *param_5,
                undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == (int *)0x0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_partition_target_c_3c033eac_0x1f_42000e48,0x9e,
               PTR_s_esp_partition_mmap_42000e5c,PTR_s_partition____NULL_42000e40,param_6);
  }
  if ((uint)param_1[4] < param_2) {
    iVar1 = 0x102;
  }
  else if (param_1[4] - param_2 < param_3) {
    iVar1 = 0x104;
  }
  else if (*param_1 == *DAT_420009fc) {
    uVar2 = param_1[3] + param_2 & 0xffff;
    iVar1 = FUN_4201283c(param_1[3] + param_2 & 0xffff0000,param_3 + uVar2,param_4,param_5);
    if (iVar1 == 0) {
      *param_5 = *param_5 + uVar2;
    }
  }
  else {
    iVar1 = 0x106;
  }
  return iVar1;
}