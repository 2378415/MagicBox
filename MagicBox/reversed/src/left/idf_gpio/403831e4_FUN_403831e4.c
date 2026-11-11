// strings: (io_mode == SPI_FLASH_OPI_STR) || (io_mode == SP

undefined4 FUN_403831e4(undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  int in_t0;
  int3 local_50;
  undefined1 uStack_4d;
  uint *puStack_44;
  undefined2 uStack_3c;
  undefined1 uStack_3a;
  uint uStack_30;
  undefined4 uStack_2c;
  
  iVar2 = param_1[4];
  uStack_30 = 0;
  uStack_2c = 0;
  if (1 < iVar2 - 0x10U) {
    iVar2 = in_t0;
    FUN_40381ce4(PTR_s_spi_flash_chip_mxic_opi_c_3fc96230_0x1b_40375380,0x5d,
                 PTR_s_spi_flash_chip_mxic_opi_get_data_4037537c,
                 PTR_s__io_mode____SPI_FLASH_OPI_STR____40375378);
  }
  uStack_3a = 8;
  bVar3 = 6;
  if (iVar2 == 0x10) {
    uStack_3a = 4;
    bVar3 = 3;
  }
  _local_50 = CONCAT13(0x20,(uint3)bVar3 << 0x10);
  puStack_44 = &uStack_30;
  uStack_3c = (undefined2)DAT_4037538c;
  (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,&local_50);
  if (param_1[4] == 0x11) {
    uStack_30 = ((uint)(CONCAT44(uStack_2c,uStack_30) >> 8) >> 8 & 0xff) << 8 |
                ((uint)(CONCAT44(uStack_2c,uStack_30) >> 0x10) >> 0x10 & 0xff) << 0x10 |
                uStack_30 & 0xff;
    uStack_2c = 0;
  }
  uVar1 = (undefined4)(CONCAT44(uStack_30 >> 0x10,uStack_30) >> 8);
  if ((uStack_30 == 0xffffff00) || (uStack_30 == 0 || uStack_30 == 0xffffff00)) {
    if (*(int *)PTR_DAT_40374414 != 0) {
      uVar1 = FUN_40381bb0();
      (*DAT_40374438)(PTR_DAT_40375388,uVar1,PTR_s_mxic__opi__40375384);
    }
    uVar1 = 0x108;
  }
  else {
    *param_2 = (uint)(CONCAT44(uStack_30,(int)(CONCAT44(uVar1,uVar1) >> 8)) >> 8) >> 8;
    uVar1 = 0;
  }
  return uVar1;
}