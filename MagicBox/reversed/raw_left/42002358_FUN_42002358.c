// 42002358  FUN_42002358  FUN_42002358  size=120
// strings: blk >= 0 && blk < EFUSE_BLK_MAX | num_reg <= (range_read_addr_blocks[blk].end - ra | esp_efuse_utility.c | esp_efuse_utility_read_reg

undefined4
FUN_42002358(uint param_1,uint param_2,uint param_3,uint param_4,int *param_5,int *param_6)

{
  int iVar1;
  int iVar2;
  int in_t0;
  
  if (10 < param_2) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_esp_efuse_utility_c_3c03036c_0x1b_420000c8,0x117,
               PTR_s_esp_efuse_utility_read_reg_420000d8,
               PTR_s_blk_>__0____blk_<_EFUSE_BLK_MAX_420000c0);
  }
  iVar2 = *(int *)(PTR_DAT_420000cc + param_2 * 8);
  if ((uint)(*(int *)((int)(PTR_DAT_420000cc + param_2 * 8) + 4) - iVar2) >> 2 < param_1) {
    iVar2 = in_t0;
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_esp_efuse_utility_c_3c03036c_0x1b_420000c8,0x118,
               PTR_s_esp_efuse_utility_read_reg_420000d8,
               PTR_s_num_reg_<__(range_read_addr_bloc_420000d0);
  }
  memw();
  iVar1 = -1;
  if (param_4 != 0x20) {
    iVar1 = (1 << 0x20 - (0x20 - (param_4 & 0x1f))) + -1;
  }
  iVar2 = (*DAT_420000dc)(iVar1 << 0x20 - (0x20 - (param_3 & 0x1f)) & *(uint *)(param_1 * 4 + iVar2)
                         );
  iVar1 = *param_6;
  *param_5 = *param_5 + iVar2;
  *param_6 = iVar1 + param_4;
  return 0;
}


