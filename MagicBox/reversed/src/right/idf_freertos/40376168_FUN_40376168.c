// strings: esp_ptr_in_diram_dram((void *)dstart) || esp_ptr | esp_ptr_in_diram_dram((void *)dend) || esp_ptr_i | (dstart & 3) == 0 | heap_caps_base.c | dram_alloc_to_iram_addr | (dend & 3) == 0

uint * FUN_40376168(uint *param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = param_1;
  if (((-(DAT_40374670 + -1) & 0xffU) == 0) && ((-(DAT_403745dc - 1) & 0xff) == 0)) {
    puVar1 = (uint *)FUN_40381d9c(PTR_s_heap_caps_base_c_3c0314cc_0x16_4037467c,0x29,
                                  PTR_s_dram_alloc_to_iram_addr_40374678,
                                  PTR_s_esp_ptr_in_diram_dram__void___ds_40374674);
  }
  if (((-(DAT_40374670 + -1) & 0xffU) == 0) && ((-(DAT_403745dc - 1) & 0xff) == 0)) {
    puVar1 = (uint *)FUN_40381d9c(PTR_s_heap_caps_base_c_3c0314cc_0x16_4037467c,0x2a,
                                  PTR_s_dram_alloc_to_iram_addr_40374678,
                                  PTR_s_esp_ptr_in_diram_dram__void___de_40374688);
  }
  if (((uint)puVar1 & 3) != 0) {
    puVar1 = (uint *)FUN_40381d9c(PTR_s_heap_caps_base_c_3c0314cc_0x16_4037467c,0x2b,
                                  PTR_s_dram_alloc_to_iram_addr_40374678,
                                  PTR_s__dstart___3_____0_4037468c);
  }
  if (((int)param_1 + param_2 & 3U) != 0) {
    puVar1 = (uint *)FUN_40381d9c(PTR_s_heap_caps_base_c_3c0314cc_0x16_4037467c,0x2c,
                                  PTR_s_dram_alloc_to_iram_addr_40374678,
                                  PTR_s__dend___3_____0_40374690);
  }
  if (DAT_403745dc < (uint)((int)puVar1 + DAT_403745d8)) {
    param_1 = (uint *)((int)param_1 + DAT_40374694);
  }
  *param_1 = (uint)puVar1;
  return param_1 + 1;
}