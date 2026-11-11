// 420190ac  s_reserve_irom_region  FUN_420190ac  size=412
// strings: esp_mmu_map.c | s_reserve_irom_region | (mmu_ll_vaddr_to_laddr((uint32_t)&_instruction_r | s_reserve_drom_region | (mmu_ll_vaddr_to_laddr((uint32_t)&_rodata_reserv | esp_mmu_map_init | available_region_idx == region_num

void FUN_420190ac(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  int iVar12;
  undefined *in_t0;
  undefined8 uVar13;
  uint local_50;
  undefined *puStack_4c;
  undefined4 uStack_48;
  undefined *puStack_44;
  undefined *puStack_40;
  undefined *puStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  puVar8 = *(undefined **)(PTR_DAT_4200170c + 8);
  puStack_4c = *(undefined **)PTR_DAT_4200170c;
  uStack_48 = *(undefined4 *)(PTR_DAT_4200170c + 4);
  uVar13 = *(undefined8 *)PTR_DAT_4200170c;
  uVar6 = *(uint *)(PTR_DAT_4200170c + 0xc);
  iVar12 = *(int *)(PTR_DAT_4200170c + 0x14);
  uStack_34 = *(undefined4 *)(PTR_DAT_4200170c + 0x10);
  uStack_30 = 0;
  uStack_2c = 0;
  puVar10 = (undefined *)0x0;
  local_50 = uVar6;
  puStack_44 = puVar8;
  puStack_40 = puStack_4c;
  puStack_3c = puVar8;
  iStack_38 = iVar12;
  if (((uint)puVar8 & 0xffff) != 0) {
    puVar10 = PTR_s_esp_mmu_map_init_42001714;
    uVar13 = (*(code *)PTR_FUN_420000a8)
                       (PTR_s_esp_mmu_map_c_3c039e2c_0x18_42001718,0xcd,
                        PTR_s_esp_mmu_map_init_42001714,
                        PTR_s_hw_mem_regions_i__region_size___C_42001710);
    puVar8 = in_t0;
    in_t0 = puVar8;
  }
  puVar11 = (undefined *)(DAT_4200171c - (int)PTR_PTR_42001720);
  puVar7 = PTR_PTR_42001720;
  if (puVar11 != (undefined *)((DAT_4200171c & 0x1ffffff) - ((uint)PTR_PTR_42001720 & 0x1ffffff))) {
    puVar10 = PTR_s_s_reserve_irom_region_42001728;
    puVar11 = PTR_s__mmu_ll_vaddr_to_laddr__uint32_t_42001724;
    puVar8 = in_t0;
    uVar13 = (*(code *)PTR_FUN_420000a8)(PTR_s_esp_mmu_map_c_3c039e2c_0x18_42001718,0x8c);
    in_t0 = puVar8;
  }
  iVar2 = DAT_42000d18;
  puVar7 = (undefined *)((uint)(puVar11 + DAT_42000d18 + ((uint)puVar7 & 0xffff)) & 0xffff0000);
  uVar5 = DAT_4200172c;
  if (puVar11 != (undefined *)0x0) {
    param_2 = 1;
    if ((-(DAT_42001730 + -1) & 0xffU) != 0) goto LAB_42019167;
  }
  if (DAT_42001734 != 0) {
    param_2 = 8;
    if ((-(DAT_42001738 + -1) & 0xffU) != 0) goto LAB_42019167;
  }
  do {
    puVar7 = in_t0;
    uVar13 = FUN_42019094();
    puVar8 = puVar7;
    in_t0 = puVar7;
LAB_42019167:
    puVar11 = (undefined *)((ulonglong)uVar13 >> 0x20);
    if ((uVar6 & param_2) != 0) {
      if (puVar7 < puVar8) {
        puStack_3c = puVar8 + -(int)puVar7;
        puStack_40 = puVar7 + (int)uVar13;
      }
      else {
        puStack_3c = puVar10;
        puStack_40 = puVar11;
      }
    }
    uVar13 = CONCAT44(puVar11,DAT_4200173c - (int)PTR_DAT_42001740);
    puVar11 = PTR_DAT_42001740;
    if (DAT_4200173c - (int)PTR_DAT_42001740 !=
        (DAT_4200173c & 0x1ffffff) - ((uint)PTR_DAT_42001740 & 0x1ffffff)) {
      puVar10 = PTR_s_s_reserve_drom_region_42001748;
      puVar11 = PTR_s__mmu_ll_vaddr_to_laddr__uint32_t_42001744;
      puVar8 = in_t0;
      uVar13 = (*(code *)PTR_FUN_420000a8)(PTR_s_esp_mmu_map_c_3c039e2c_0x18_42001718,0xa8);
      in_t0 = puVar8;
    }
    puVar3 = DAT_4200174c;
    puVar7 = (undefined *)((ulonglong)uVar13 >> 0x20);
    uVar1 = ((uint)puVar11 & 0xffff) + (int)uVar13 + iVar2 >> 0x10;
    puVar11 = (undefined *)(uVar1 * 0x10000);
    if ((uVar5 != 0) && (uVar5 = 1, (-(DAT_42001730 + -1) & 0xffU) != 0)) goto LAB_420191f1;
  } while ((DAT_42001734 == 0) || ((-(DAT_42001738 + -1) & 0xffU) == 0));
  uVar5 = 8;
LAB_420191f1:
  if ((uVar6 & uVar5) != 0) {
    puVar9 = puVar10;
    if (puVar11 < puVar8) {
      puVar7 = puVar11 + (int)puStack_40;
      puVar9 = puStack_3c + uVar1 * -0x10000;
    }
    puStack_40 = puVar7;
    puStack_3c = puVar9;
  }
  *DAT_4200174c = (undefined *)(uint)(iVar12 != -1);
  if (iStack_38 != -1) {
    (*DAT_42000064)(DAT_42001750,&local_50,0x28);
    uVar4 = DAT_42001754;
    puVar10 = (undefined *)0x1;
    puVar3[9] = 0;
    puVar3[10] = uVar4;
  }
  if (puVar10 != (undefined *)(uint)(iVar12 != -1)) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_esp_mmu_map_c_3c039e2c_0x18_42001718,0xff,PTR_s_esp_mmu_map_init_42001714,
               PTR_s_available_region_idx____region_n_42001758);
  }
  return;
}


