// 4037f0d0  spi_flash_encrypt_ll_plaintext_save  FUN_4037f0d0  size=46
// strings: plaintext_offs + size <= SOC_FLASH_ENCRYPTED_XTS

void FUN_4037f0d0(uint param_1,undefined4 param_2,int param_3)

{
  undefined4 extraout_a3;
  
  if (0x40 < (param_1 & 0x3f) + param_3) {
    FUN_40381d9c(PTR_s__IDF_components_hal_esp32s3_incl_403750a0,0x5a,
                 PTR_s_spi_flash_encrypt_ll_plaintext_s_4037509c,
                 PTR_s_plaintext_offs___size_<__SOC_FLA_40375098);
    param_2 = extraout_a3;
  }
  (*DAT_403744d4)((param_1 & 0x3f) + DAT_403750a4,param_2);
  return;
}


