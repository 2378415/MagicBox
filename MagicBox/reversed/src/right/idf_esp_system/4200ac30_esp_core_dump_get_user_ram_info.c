// strings: start != ((void *)0)

int FUN_4200ac30(uint param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_core_dump_common_c_3c03323c_0x21_420009cc,0x131,
               PTR_s_esp_core_dump_get_user_ram_info_420009c8,PTR_s_start______void___0__420009c4);
  }
  if (param_1 < 4) {
    iVar2 = *(int *)(PTR_DAT_420009d0 + param_1 * 8);
    iVar1 = *(int *)((int)(PTR_DAT_420009d0 + param_1 * 8) + 4) - iVar2;
    *param_2 = iVar2;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}