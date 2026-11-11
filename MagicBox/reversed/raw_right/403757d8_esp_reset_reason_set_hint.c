// 403757d8  esp_reset_reason_set_hint  FUN_403757d8  size=48
// strings: (hint & (~RST_REASON_MASK)) == 0

void FUN_403757d8(uint param_1)

{
  if (DAT_403744fc < param_1) {
    FUN_40381d9c(PTR_s_reset_reason_c_3c0301ec_0x2d_40374508,0x5d,
                 PTR_s_esp_reset_reason_set_hint_40374504,
                 PTR_s__hint_____RST_REASON_MASK______0_40374500);
  }
  memw();
  *DAT_40374510 = param_1 << 0x10 | param_1 | DAT_4037450c;
  return;
}


