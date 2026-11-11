// 403832f8  FUN_403832f8  FUN_403832f8  size=98
// strings: (io_mode == SPI_FLASH_OPI_STR) || (io_mode == SP

int FUN_403832f8(undefined4 *param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  byte bVar2;
  int in_t0;
  int3 local_40;
  undefined1 uStack_3d;
  uint *puStack_34;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  uint auStack_24 [9];
  
  iVar1 = param_1[4];
  auStack_24[0] = 0;
  if (1 < iVar1 - 0x10U) {
    iVar1 = in_t0;
    FUN_40381ce4(PTR_s_spi_flash_chip_mxic_opi_c_3fc96230_0x1b_40375380,0x5d,
                 PTR_s_spi_flash_chip_mxic_opi_get_data_4037537c,
                 PTR_s__io_mode____SPI_FLASH_OPI_STR____40375378);
  }
  uStack_2a = 8;
  bVar2 = 2;
  if (iVar1 == 0x10) {
    uStack_2a = 4;
    bVar2 = 1;
  }
  _local_40 = CONCAT13(0x20,(uint3)bVar2 << 0x10);
  puStack_34 = auStack_24;
  uStack_2c = 0xfa05;
  iVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,&local_40);
  if (iVar1 == 0) {
    *param_3 = auStack_24[0] & 0xff;
  }
  return iVar1;
}


