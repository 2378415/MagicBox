// strings: out_write_protected!=NULL

int FUN_403833c8(int param_1,int param_2)

{
  int iVar1;
  uint local_30 [12];
  
  iVar1 = param_1;
  if (param_2 == 0) {
    iVar1 = FUN_40381d9c(PTR_s_spi_flash_chip_mxic_opi_c_3fc95f04_0x1b_40375298,0x9e,
                         PTR_s_spi_flash_chip_mxic_opi_get_writ_403752ac,
                         PTR_s_out_write_protected__NULL_403752a8);
  }
  iVar1 = (**(code **)(*(int *)(param_1 + 4) + 100))(iVar1,1,local_30);
  if (iVar1 == 0) {
    *(bool *)param_2 = (local_30[0] & 2) == 0;
  }
  return iVar1;
}