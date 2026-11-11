// strings: io <= ESP_MSPI_IO_D7

uint FUN_42019948(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (10 < param_1) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_flash_ops_c_3c03a47c_0x1b_420017e4,0xf5,PTR_s_esp_mspi_get_io_420017e0,
               PTR_s_io_<__ESP_MSPI_IO_D7_420017dc);
  }
  if (param_1 == 5) {
    uVar1 = (*DAT_420017ec)();
    uVar2 = 0x1c;
    if (uVar1 != 0x3f) {
      uVar2 = uVar1 & 0x3f;
    }
  }
  else {
    if (param_1 < 5) {
      uVar2 = (*DAT_420017f0)();
      if (uVar2 != 0) {
        return uVar2 >> (param_1 * 6 & 0x1f) & 0x3f;
      }
    }
    else {
      uVar2 = FUN_4201a51c();
      if (uVar2 != 0) {
        return uVar2 >> (param_1 * 6 - 0x24 & 0x1f) & 0x3f;
      }
    }
    uVar2 = (uint)(byte)PTR_DAT_420017e8[param_1];
  }
  return uVar2;
}