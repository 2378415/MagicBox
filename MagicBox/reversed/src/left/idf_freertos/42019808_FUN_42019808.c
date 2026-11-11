// strings: s_flash_op_mutex != NULL

void FUN_42019808(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_42001284)(4);
  *DAT_420017b8 = iVar1;
  if (iVar1 == 0) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_cache_utils_c_3c03a2ac_0x1b_420017c4,0x5f,PTR_s_spi_flash_init_lock_420017c0,
               PTR_s_s_flash_op_mutex____NULL_420017bc);
  }
  return;
}