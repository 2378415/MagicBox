// 42016cd8  FUN_42016cd8  FUN_42016cd8  size=126
// strings: phys_offs != SPI_FLASH_CACHE2PHYS_FAIL | it != NULL | esp_ota_get_running_partition

void FUN_42016cd8(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (*DAT_42001104 == 0) {
    uVar1 = FUN_42012914(PTR_FUN_42001108);
    if (uVar1 == 0xffffffff) {
      (*(code *)PTR_FUN_42000044)
                (PTR_s_esp_ota_ops_c_3c036818_0x1c_42001114,0x22a,
                 PTR_s_esp_ota_get_running_partition_3c0390f3_1_42001110,
                 PTR_s_phys_offs____SPI_FLASH_CACHE2PHY_4200110c);
    }
    iVar2 = FUN_42011e44(0,0xff);
    if (iVar2 != 0) goto LAB_42016d4d;
    (*(code *)PTR_FUN_42000044)
              (PTR_s_esp_ota_ops_c_3c036818_0x1c_42001114,0x22f,
               PTR_s_esp_ota_get_running_partition_3c0390f3_1_42001110,PTR_s_it____NULL_42001118);
    do {
      iVar3 = FUN_42011e80(iVar2);
      if ((*(uint *)(iVar3 + 0xc) <= uVar1) &&
         (uVar1 < *(uint *)(iVar3 + 0xc) + *(int *)(iVar3 + 0x10))) {
        FUN_42011da8(iVar2);
        *DAT_42001104 = iVar3;
        return;
      }
      iVar2 = FUN_42011db8(iVar2);
LAB_42016d4d:
    } while (iVar2 != 0);
    (*(code *)PTR_FUN_4200006c)();
  }
  return;
}


