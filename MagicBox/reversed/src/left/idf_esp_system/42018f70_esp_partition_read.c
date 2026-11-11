// strings: partition != NULL

int FUN_42018f70(int *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 auStack_2c [11];
  
  piVar1 = param_1;
  if (param_1 == (int *)0x0) {
    piVar1 = (int *)(*(code *)PTR_FUN_420000a8)
                              (PTR_s_partition_target_c_3c039d00_0x1f_420016d8,0x1d,
                               PTR_s_esp_partition_read_420016f0,PTR_s_partition____NULL_420016d0);
  }
  iVar2 = 0x102;
  if ((param_2 <= (uint)param_1[4]) && (iVar2 = 0x104, param_4 <= param_1[4] - param_2)) {
    if (*(char *)((int)piVar1 + 0x29) == '\0') {
      iVar2 = (*(code *)PTR_FUN_420016e0)(*piVar1,param_3,param_2 + piVar1[3],param_4);
    }
    else {
      iVar2 = 0x106;
      if ((*piVar1 == *DAT_42000cbc) &&
         (iVar2 = FUN_42018f14(piVar1,param_2,param_4,0,auStack_2c,&local_30), iVar2 == 0)) {
        (*DAT_42000064)(param_3,auStack_2c[0],param_4);
        FUN_420198dc(local_30);
      }
    }
  }
  return iVar2;
}