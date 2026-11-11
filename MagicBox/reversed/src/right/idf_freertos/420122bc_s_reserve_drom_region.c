// strings: (mmu_ll_vaddr_to_laddr((uint32_t)&_rodata_reserv

void FUN_420122bc(uint *param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  undefined8 uVar6;
  
  iVar5 = DAT_42000ea0 - (int)PTR_DAT_42000ea4;
  puVar4 = PTR_DAT_42000ea4;
  if ((DAT_42000ea0 & DAT_4200021c) - ((uint)PTR_DAT_42000ea4 & DAT_4200021c) != iVar5) {
    uVar6 = (*(code *)PTR_FUN_42000044)
                      (PTR_s_esp_mmu_map_c_3c034030_0x18_42000e9c,0xa8,
                       PTR_s_s_reserve_drom_region_42000eac,
                       PTR_s__mmu_ll_vaddr_to_laddr__uint32_t_42000ea8);
    iVar5 = (int)((ulonglong)uVar6 >> 0x20);
    puVar4 = (undefined *)uVar6;
  }
  uVar3 = ((uint)puVar4 & 0xffff) + iVar5 + DAT_42000a78 & 0xffff0000;
  uVar2 = FUN_420121f0(puVar4,uVar3);
  bVar1 = false;
  while (!bVar1) {
    if ((*param_1 & uVar2) != 0) {
      if (uVar3 < param_1[3]) {
        param_1[4] = param_1[4] + uVar3;
        param_1[5] = param_1[5] - uVar3;
      }
      else {
        param_1[4] = param_1[2];
        param_1[5] = 0;
        uVar3 = uVar3 - param_1[3];
      }
    }
    bVar1 = true;
  }
  return;
}