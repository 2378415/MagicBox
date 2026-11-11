// 4038335c  FUN_4038335c  FUN_4038335c  size=128
// strings: (io_mode == SPI_FLASH_OPI_STR) || (io_mode == SP

int FUN_4038335c(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  byte bVar3;
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
  bVar3 = 2;
  if (iVar1 == 0x10) {
    uStack_2a = 4;
    bVar3 = 1;
  }
  _local_40 = CONCAT13(0x20,(uint3)bVar3 << 0x10);
  puStack_34 = auStack_24;
  uStack_2c = (undefined2)DAT_40375398;
  iVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,&local_40);
  if (iVar1 == 0) {
    iVar2 = 0x10;
    if (((auStack_24[0] & 0xff) != 1) && (iVar2 = 0x11, (auStack_24[0] & 0xff) != 2)) {
      iVar2 = 0;
    }
    *param_2 = iVar2;
    if (param_1[4] != iVar2) {
      iVar2 = 0;
    }
    *param_2 = iVar2;
  }
  return iVar1;
}


