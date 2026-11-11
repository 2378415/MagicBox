// strings: partition != NULL

int FUN_420120b8(int *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined4 local_30;
  undefined4 auStack_2c [11];
  
  if (param_1 == (int *)0x0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_partition_target_c_3c033eac_0x1f_42000e48,0x1d,
               PTR_s_esp_partition_read_42000e60,PTR_s_partition____NULL_42000e40);
  }
  if ((uint)param_1[4] < param_2) {
    iVar1 = 0x102;
  }
  else if (param_1[4] - param_2 < param_4) {
    iVar1 = 0x104;
  }
  else if (*(char *)((int)param_1 + 0x29) == '\0') {
    iVar1 = (*(code *)PTR_FUN_42000e50)(*param_1,param_3,param_1[3] + param_2,param_4);
  }
  else if (*param_1 == *DAT_420009fc) {
    iVar1 = FUN_42012044(param_1,param_2,param_4,0,&local_30,auStack_2c);
    if (iVar1 == 0) {
      (*DAT_420002fc)(param_3,local_30,param_4);
      FUN_420120ac(auStack_2c[0]);
    }
  }
  else {
    iVar1 = 0x106;
  }
  return iVar1;
}