// 40378c38  spi_flash_os_check_yield  FUN_40378c38  size=69
// strings: chip_status == 0

undefined4 FUN_40378c38(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 != 0) {
    FUN_40381ce4(PTR_s_spi_flash_os_func_app_c_3c03a8c0_0x1b_4037496c,0xae,
                 PTR_s_spi_flash_os_check_yield_40374968,PTR_s_chip_status____0_40374964);
  }
  iVar1 = FUN_40376fcc();
  if ((uint)(iVar1 - *(int *)(param_1 + 0xc)) < 1000) {
    if (DAT_40374970 < (uint)(iVar1 - *(int *)(param_1 + 8))) {
      param_2 = 1;
      uVar2 = 0;
      goto LAB_40378c78;
    }
  }
  else {
    *(int *)(param_1 + 8) = iVar1;
  }
  uVar2 = 0x107;
LAB_40378c78:
  if (param_3 != (int *)0x0) {
    *param_3 = param_2;
  }
  return uVar2;
}


