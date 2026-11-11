// 403785f8  spi_flash_os_check_yield  FUN_403785f8  size=48
// strings: chip_status == 0

undefined4 FUN_403785f8(undefined4 param_1,int param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 != 0) {
    param_1 = FUN_40381d9c(PTR_s_spi_flash_os_func_app_c_3c034368_0x1b_403748c0,0xae,
                           PTR_s_spi_flash_os_check_yield_403748bc,PTR_s_chip_status____0_403748b8);
  }
  iVar1 = FUN_403785c8(param_1);
  if (iVar1 != 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x107;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = (uint)(iVar1 != 0);
  }
  return uVar2;
}


