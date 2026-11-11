// 4201349c  FUN_4201349c  FUN_4201349c  size=57
// strings: false

undefined4 FUN_4201349c(void)

{
  uint uVar1;
  
  memw();
  uVar1 = *DAT_42000694 >> 0x1e;
  if (uVar1 != 1) {
    if (uVar1 == 2) {
      return DAT_42000684;
    }
    if (uVar1 == 0) {
      return DAT_42001010;
    }
    (*(code *)PTR_FUN_42000044)
              (PTR_s__IDF_components_hal_esp32s3_incl_4200101c,0x21a,
               PTR_s_clk_ll_rtc_slow_get_src_3c03855b_1_42001018,PTR_s_false_42001014);
  }
  return DAT_42000160;
}


