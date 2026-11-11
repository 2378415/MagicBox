// strings: blk >= 0 && blk < EFUSE_BLK_MAX | num_reg <= (range_read_addr_blocks[blk].end - ra | esp_efuse_utility.c | esp_efuse_utility_read_reg

undefined4 FUN_420026dc(uint param_1,uint param_2)

{
  int iVar1;
  int in_t0;
  
  if (10 < param_1) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_esp_efuse_utility_c_3c03036c_0x1b_420000c8,0x117,
               PTR_s_esp_efuse_utility_read_reg_420000d8,
               PTR_s_blk_>__0____blk_<_EFUSE_BLK_MAX_420000c0);
  }
  iVar1 = *(int *)(PTR_DAT_420000cc + param_1 * 8);
  if ((uint)(*(int *)((int)(PTR_DAT_420000cc + param_1 * 8) + 4) - iVar1) >> 2 < param_2) {
    iVar1 = in_t0;
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_esp_efuse_utility_c_3c03036c_0x1b_420000c8,0x118,
               PTR_s_esp_efuse_utility_read_reg_420000d8,
               PTR_s_num_reg_<__(range_read_addr_bloc_420000d0);
  }
  memw();
  return *(undefined4 *)(param_2 * 4 + iVar1);
}