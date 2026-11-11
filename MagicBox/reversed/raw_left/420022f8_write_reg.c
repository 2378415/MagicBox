// 420022f8  write_reg  FUN_420022f8  size=93
// strings: blk >= 0 && blk < EFUSE_BLK_MAX | num_reg <= (range_read_addr_blocks[blk].end - ra | esp_efuse_utility.c | write_reg

void FUN_420022f8(uint param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  
  if (10 < param_1) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_esp_efuse_utility_c_3c03036c_0x1b_420000c8,0x127,PTR_s_write_reg_420000c4,
               PTR_s_blk_>__0____blk_<_EFUSE_BLK_MAX_420000c0);
  }
  iVar2 = param_1 << 3;
  if ((uint)(*(int *)((int)(PTR_DAT_420000cc + param_1 * 8) + 4) -
            *(int *)(PTR_DAT_420000cc + param_1 * 8)) >> 2 < param_2) {
    iVar2 = (*(code *)PTR_FUN_420000a8)
                      (PTR_s_esp_efuse_utility_c_3c03036c_0x1b_420000c8,0x128,
                       PTR_s_write_reg_420000c4,PTR_s_num_reg_<__(range_read_addr_bloc_420000d0);
  }
  puVar1 = (uint *)(param_2 * 4 + *(int *)(PTR_DAT_420000d4 + iVar2));
  memw();
  memw();
  *puVar1 = *puVar1 | param_3;
  return;
}


