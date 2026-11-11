// strings: (hint & (~RST_REASON_MASK)) == 0

void FUN_40375a70(uint param_1)

{
  if (DAT_40374540 < param_1) {
    FUN_40381ce4(PTR_s_reset_reason_c_3c030c78_0x2d_4037454c,0x5d,
                 PTR_s_esp_reset_reason_set_hint_40374548,
                 PTR_s__hint_____RST_REASON_MASK______0_40374544);
  }
  memw();
  *DAT_40374554 = param_1 << 0x10 | param_1 | DAT_40374550;
  return;
}