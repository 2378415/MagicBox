// 420127f0  spi_flash_init_lock  FUN_420127f0  size=38
// strings: s_flash_op_mutex != NULL

void FUN_420127f0(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_42000b5c)(4);
  *DAT_42000ee8 = iVar1;
  if (iVar1 == 0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_cache_utils_c_3c034168_0x1b_42000ef4,0x5f,PTR_s_spi_flash_init_lock_42000ef0,
               PTR_s_s_flash_op_mutex____NULL_42000eec);
  }
  return;
}


