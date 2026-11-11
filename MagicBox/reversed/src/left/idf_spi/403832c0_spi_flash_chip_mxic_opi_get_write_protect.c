// strings: out_write_protected!=NULL

int FUN_403832c0(int param_1,byte *param_2)

{
  int iVar1;
  uint local_30 [12];
  
  iVar1 = param_1;
  if (param_2 == (byte *)0x0) {
    iVar1 = FUN_40381ce4(PTR_s_spi_flash_chip_mxic_opi_c_3fc96230_0x1b_40375380,0x9e,
                         PTR_s_spi_flash_chip_mxic_opi_get_writ_40375394,
                         PTR_s_out_write_protected__NULL_40375390);
  }
  iVar1 = (**(code **)(*(int *)(param_1 + 4) + 100))(iVar1,1,local_30);
  if (iVar1 == 0) {
    *param_2 = (byte)(local_30[0] >> 1) & 1 ^ 1;
  }
  return iVar1;
}