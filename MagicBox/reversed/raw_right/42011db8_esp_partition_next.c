// 42011db8  esp_partition_next  FUN_42011db8  size=138
// strings: esp_partition_next | <k7@

int * FUN_42011db8(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_partition_c_3c033e54_0x1f_42000e34,0x142,PTR_s_esp_partition_next_42000e30,
               PTR_DAT_42000e2c);
  }
  if (param_1[3] == 0) {
    FUN_42011da8(param_1);
    param_1 = (int *)0x0;
  }
  else {
    (*(code *)PTR_FUN_42000700)(DAT_42000e28);
    while ((iVar2 = param_1[3], iVar2 != 0 &&
           ((((*param_1 != 0xff && (*param_1 != *(int *)(iVar2 + 4))) ||
             ((param_1[1] != 0xff && (param_1[1] != *(int *)(iVar2 + 8))))) ||
            ((param_1[2] != 0 && (iVar1 = (*DAT_420007e8)(param_1[2],iVar2 + 0x18), iVar1 != 0))))))
          ) {
      param_1[3] = *(int *)(iVar2 + 0x30);
    }
    (*(code *)PTR_FUN_42000704)(DAT_42000e28);
    iVar2 = param_1[3];
    if (iVar2 == 0) {
      FUN_42011da8(param_1);
      param_1 = (int *)0x0;
    }
    else {
      param_1[4] = iVar2;
      param_1[3] = *(int *)(iVar2 + 0x30);
    }
  }
  return param_1;
}


