// strings: phys_offs != SPI_FLASH_CACHE2PHYS_FAIL | it != NULL | esp_ota_get_running_partition

void FUN_4201e508(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_42019924(PTR_FUN_42001ae8);
  if (uVar1 == 0xffffffff) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_esp_ota_ops_c_3c03c2f4_0x1c_42001af4,0x22a,
               PTR_s_esp_ota_get_running_partition_3c03f81b_1_42001af0,
               PTR_s_phys_offs____SPI_FLASH_CACHE2PHY_42001aec);
  }
  iVar2 = FUN_42018d30(0,0xff);
  if (iVar2 == 0) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_esp_ota_ops_c_3c03c2f4_0x1c_42001af4,0x22f,
               PTR_s_esp_ota_get_running_partition_3c03f81b_1_42001af0,PTR_s_it____NULL_42001af8);
  }
  do {
    iVar3 = FUN_42018db0(iVar2);
    if ((*(uint *)(iVar3 + 0xc) <= uVar1) &&
       (uVar1 < *(uint *)(iVar3 + 0xc) + *(int *)(iVar3 + 0x10))) goto LAB_4201e56f;
    iVar2 = FUN_42018ca8(iVar2);
  } while (iVar2 != 0);
  (*(code *)PTR_FUN_42000330)();
LAB_4201e56f:
  FUN_42018da0();
  *DAT_42001afc = iVar3;
  return;
}