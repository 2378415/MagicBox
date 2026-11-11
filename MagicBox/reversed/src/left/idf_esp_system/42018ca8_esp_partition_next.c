// strings: esp_partition_next

int * FUN_42018ca8(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_partition_c_3c039cac_0x1f_420016c4,0x142,PTR_s_esp_partition_next_420016c0,
               PTR_s_it_3c030268_8_420016bc);
  }
  if (param_1[3] != 0) {
    (*(code *)PTR_FUN_420008d8)(DAT_4200168c);
    iVar3 = param_1[3];
    if (iVar3 != 0) {
      iVar2 = *param_1;
      do {
        if (iVar2 != 0xff) {
          while (iVar2 != *(int *)(iVar3 + 4)) {
            iVar3 = *(int *)(iVar3 + 0x30);
            param_1[3] = iVar3;
            if (iVar3 == 0) goto LAB_42018d19;
          }
        }
        if (((param_1[1] == 0xff) || (param_1[1] == *(int *)(iVar3 + 8))) &&
           ((param_1[2] == 0 || (iVar1 = (*DAT_42000568)(param_1[2],iVar3 + 0x18), iVar1 == 0))))
        break;
        iVar3 = *(int *)(iVar3 + 0x30);
        param_1[3] = iVar3;
      } while (iVar3 != 0);
    }
LAB_42018d19:
    (*(code *)PTR_FUN_420008dc)(DAT_4200168c);
    iVar3 = param_1[3];
    if (iVar3 != 0) {
      iVar2 = *(int *)(iVar3 + 0x30);
      param_1[4] = iVar3;
      param_1[3] = iVar2;
      return param_1;
    }
  }
  (*(code *)PTR_FUN_42000570)(param_1);
  return (int *)0x0;
}