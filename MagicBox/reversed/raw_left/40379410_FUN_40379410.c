// 40379410  FUN_40379410  FUN_40379410  size=193
// strings: false | clk_ll_rtc_slow_get_src

void FUN_40379410(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_40374a48;
  memw();
  if ((int)*DAT_40374a48 < 0) {
    if (*DAT_40374a48 >> 0x1e != 2) {
      FUN_40381ce4(PTR_s__IDF_components_hal_esp32s3_incl_40374a14,0x21a,
                   PTR_s_clk_ll_rtc_slow_get_src_40374a10,PTR_s_false_40374a0c);
      goto LAB_40379433;
    }
    if (param_1 == 2) goto LAB_40379499;
    (*(code *)PTR_FUN_40374a54)(0);
LAB_40379455:
    if (param_1 != 0) {
      if (param_1 != 1) {
                    /* WARNING: Subroutine does not return */
        FUN_40381c60();
      }
      memw();
      memw();
      *puVar1 = *puVar1 & 0x3fffffff | DAT_4037460c;
      memw();
      memw();
      *puVar1 = *puVar1 | 0x100;
      goto LAB_403794c7;
    }
    memw();
    memw();
    *puVar1 = *puVar1 & 0x3fffffff;
  }
  else {
LAB_40379433:
    if (param_1 != 2) goto LAB_40379455;
    (*(code *)PTR_FUN_40374a54)(0,1);
LAB_40379499:
    memw();
    memw();
    *puVar1 = *puVar1 & 0x3fffffff | DAT_40374550;
  }
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffffeff;
LAB_403794c7:
  (*DAT_40374444)(300);
  return;
}


