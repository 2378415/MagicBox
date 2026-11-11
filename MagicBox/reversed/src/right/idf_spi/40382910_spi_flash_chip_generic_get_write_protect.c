// strings: out_write_protect!=NULL

int FUN_40382910(int param_1,int param_2)

{
  int iVar1;
  uint local_30 [12];
  
  iVar1 = param_1;
  if (param_2 == 0) {
    iVar1 = FUN_40381d9c(PTR_s_spi_flash_chip_generic_c_3fc95e8c_0x1b_40375264,0x14a,
                         PTR_s_spi_flash_chip_generic_get_write_40375260,
                         PTR_s_out_write_protect__NULL_4037525c);
  }
  iVar1 = (**(code **)(*(int *)(param_1 + 4) + 100))(iVar1,1,local_30);
  if (iVar1 == 0) {
    *(bool *)param_2 = (local_30[0] & 2) == 0;
  }
  return iVar1;
}