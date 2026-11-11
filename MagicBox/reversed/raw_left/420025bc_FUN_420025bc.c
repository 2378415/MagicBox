// 420025bc  FUN_420025bc  FUN_420025bc  size=131
// strings: blk >= 0 && blk < EFUSE_BLK_MAX | num_reg <= (range_read_addr_blocks[blk].end - ra | esp_efuse_utility.c | esp_efuse_utility_read_reg | efuse

uint FUN_420025bc(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int in_t0;
  
  uVar1 = param_1;
  if (10 < param_1) {
    uVar1 = (*(code *)PTR_FUN_420000a8)
                      (PTR_s_esp_efuse_utility_c_3c03036c_0x1b_420000c8,0x117,
                       PTR_s_esp_efuse_utility_read_reg_420000d8,
                       PTR_s_blk_>__0____blk_<_EFUSE_BLK_MAX_420000c0);
  }
  iVar5 = *(int *)(PTR_DAT_420000cc + param_1 * 8);
  if ((uint)(*(int *)((int)(PTR_DAT_420000cc + param_1 * 8) + 4) - iVar5) >> 2 < param_2) {
    iVar5 = in_t0;
    uVar1 = (*(code *)PTR_FUN_420000a8)
                      (PTR_s_esp_efuse_utility_c_3c03036c_0x1b_420000c8,0x118,
                       PTR_s_esp_efuse_utility_read_reg_420000d8,
                       PTR_s_num_reg_<__(range_read_addr_bloc_420000d0);
  }
  memw();
  uVar4 = *(uint *)(param_2 * 4 + iVar5);
  uVar2 = param_3 & uVar4;
  if ((param_3 & uVar4) == 0) {
    FUN_420022f8(uVar1,param_2,param_3);
  }
  else {
    if (*(int *)PTR_DAT_42000028 != 0) {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*DAT_42000060)(PTR_DAT_42000104,uVar3,PTR_s_efuse_420000e8,uVar2);
    }
    uVar2 = DAT_42000100;
  }
  return uVar2;
}


