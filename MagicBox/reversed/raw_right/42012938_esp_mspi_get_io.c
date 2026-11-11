// 42012938  esp_mspi_get_io  FUN_42012938  size=124
// strings: io <= ESP_MSPI_IO_D7

uint FUN_42012938(uint param_1)

{
  uint uVar1;
  
  if (10 < param_1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_flash_ops_c_3c0342d8_0x1b_42000f14,0xf5,PTR_s_esp_mspi_get_io_42000f10,
               PTR_s_io_<__ESP_MSPI_IO_D7_42000f0c);
  }
  if (param_1 == 5) {
    uVar1 = (*DAT_42000f1c)();
    if (uVar1 == 0x3f) {
      uVar1 = (uint)(byte)PTR_DAT_42000f18[5];
    }
    else {
      uVar1 = uVar1 & 0x3f;
    }
  }
  else {
    if (param_1 < 5) {
      uVar1 = (*DAT_42000f20)();
    }
    else {
      uVar1 = FUN_42013248();
    }
    if (uVar1 == 0) {
      uVar1 = (uint)(byte)PTR_DAT_42000f18[param_1];
    }
    else if (param_1 < 5) {
      uVar1 = uVar1 >> (param_1 * 6 & 0x1f) & 0x3f;
    }
    else {
      uVar1 = uVar1 >> (param_1 * 6 - 0x24 & 0x1f) & 0x3f;
    }
  }
  return uVar1;
}


