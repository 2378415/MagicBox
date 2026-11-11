// 4037f30c  spi_flash_encrypt_ll_plaintext_save  FUN_4037f30c  size=76
// strings: plaintext_offs + size <= SOC_FLASH_ENCRYPTED_XTS

void FUN_4037f30c(uint param_1,undefined4 param_2,uint param_3)

{
  undefined4 extraout_a3;
  uint uVar1;
  uint in_t0;
  
  memw();
  *DAT_4037515c = param_3 >> 5;
  uVar1 = param_1 & 0x3f;
  memw();
  *DAT_40375160 = param_1;
  if (0x40 < param_3 + uVar1) {
    uVar1 = in_t0;
    FUN_40381ce4(PTR_s__IDF_components_hal_esp32s3_incl_4037516c,0x5a,
                 PTR_s_spi_flash_encrypt_ll_plaintext_s_40375168,
                 PTR_s_plaintext_offs___size_<__SOC_FLA_40375164);
    param_2 = extraout_a3;
  }
  (*DAT_4037450c)(uVar1 + DAT_40375170,param_2);
  memw();
  *DAT_40375174 = 1;
  return;
}


