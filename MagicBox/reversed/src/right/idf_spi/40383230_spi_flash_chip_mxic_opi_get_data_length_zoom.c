// strings: (io_mode == SPI_FLASH_OPI_STR) || (io_mode == SP

void FUN_40383230(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (1 < param_1 - 0x10U) {
    FUN_40381d9c(PTR_s_spi_flash_chip_mxic_opi_c_3fc95f04_0x1b_40375298,0x5d,
                 PTR_s_spi_flash_chip_mxic_opi_get_data_40375294,
                 PTR_s__io_mode____SPI_FLASH_OPI_STR____40375290);
  }
  if (param_1 == 0x10) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  *param_2 = uVar1;
  return;
}