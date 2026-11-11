// strings: hw_mem_regions[i].region_size % CONFIG_MMU_PAGE_ | esp_mmu_map_init | available_region_idx == region_num

void FUN_4201233c(void)

{
  bool bVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  
  (*DAT_42000240)(&local_50,0,0x28);
  for (iVar6 = 0; iVar6 == 0; iVar6 = iVar6 + 1) {
    uStack_4c = *(undefined4 *)PTR_DAT_42000eb0;
    uStack_48 = *(undefined4 *)(PTR_DAT_42000eb0 + 4);
    uStack_44 = *(uint *)(PTR_DAT_42000eb0 + 8);
    local_50 = *(undefined4 *)(PTR_DAT_42000eb0 + 0xc);
    iStack_38 = *(int *)(PTR_DAT_42000eb0 + 0x14);
    uStack_34 = *(undefined4 *)(PTR_DAT_42000eb0 + 0x10);
    iVar6 = 0;
    uStack_40 = uStack_4c;
    uStack_3c = uStack_44;
    if ((uStack_44 & 0xffff) != 0) {
      iVar6 = (*(code *)PTR_FUN_42000044)
                        (PTR_s_esp_mmu_map_c_3c034030_0x18_42000e9c,0xcd,
                         PTR_s_esp_mmu_map_init_42000eb8,
                         PTR_s_hw_mem_regions_i__region_size___C_42000eb4);
    }
  }
  FUN_4201223c(&local_50,1);
  FUN_420122bc(&local_50,1);
  uVar3 = 0;
  bVar1 = false;
  while (!bVar1) {
    if (iStack_38 != -1) {
      uVar3 = uVar3 + 1;
    }
    bVar1 = true;
  }
  *DAT_42000ebc = uVar3;
  uVar4 = 0;
  bVar1 = false;
  while (!bVar1) {
    if (iStack_38 != -1) {
      (*DAT_420002fc)(DAT_42000ebc + uVar4 * 10 + 1,&local_50,0x28);
      uVar4 = uVar4 + 1;
    }
    bVar1 = true;
  }
  for (uVar5 = 0; puVar2 = DAT_42000ebc, uVar5 < uVar4; uVar5 = uVar5 + 1) {
    DAT_42000ebc[uVar5 * 10 + 9] = 0;
    puVar2[uVar5 * 10 + 10] = (uint)(puVar2 + uVar5 * 10 + 9);
  }
  if (uVar3 != uVar4) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_esp_mmu_map_c_3c034030_0x18_42000e9c,0xff,PTR_s_esp_mmu_map_init_42000eb8,
               PTR_s_available_region_idx____region_n_42000ec0);
  }
  return;
}