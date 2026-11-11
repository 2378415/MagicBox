// 4200cd18  esp_core_dump_get_user_ram_info  FUN_4200cd18  size=49
// strings: start != ((void *)0)

int FUN_4200cd18(uint param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_core_dump_common_c_3c036354_0x21_42000c9c,0x131,
               PTR_s_esp_core_dump_get_user_ram_info_42000c98,PTR_s_start______void___0__42000c94);
  }
  if (param_1 < 4) {
    iVar2 = *(int *)(PTR_DAT_42000ca0 + param_1 * 8);
    iVar1 = *(int *)((int)(PTR_DAT_42000ca0 + param_1 * 8) + 4);
    *param_2 = iVar2;
    iVar1 = iVar1 - iVar2;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


