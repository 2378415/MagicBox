// strings: out_write_protect!=NULL

int FUN_40382774(int param_1,byte *param_2)

{
  int iVar1;
  uint local_30 [12];
  
  iVar1 = param_1;
  if (param_2 == (byte *)0x0) {
    iVar1 = FUN_40381ce4(PTR_s_spi_flash_chip_generic_c_3fc96154_0x1b_40375340,0x14a,
                         PTR_s_spi_flash_chip_generic_get_write_4037533c,
                         PTR_s_out_write_protect__NULL_40375338);
  }
  iVar1 = (**(code **)(*(int *)(param_1 + 4) + 100))(iVar1,1,local_30);
  if (iVar1 == 0) {
    *param_2 = (byte)(local_30[0] >> 1) & 1 ^ 1;
  }
  return iVar1;
}