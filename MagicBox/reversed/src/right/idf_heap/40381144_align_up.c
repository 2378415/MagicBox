// strings: 0 == (align & (align - 1)) && 'must align to a p | tlsf_control_functions.h | align_up | k_next | epare_reserved_regions | s_prepare_reserved_regions | cate_free | e_reserved_regions | block | block_size(block) >= *size | prev && 'prev_free field can not be null' | remove_free_block | next && 'next_free field can not be null' | insert_free_block | n_ptr | align_ptr

undefined4 * FUN_40381144(undefined *param_1,uint param_2,int param_3,int param_4)

{
  int unaff_retaddr;
  undefined4 *puVar1;
  int extraout_a3;
  int extraout_a3_00;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined *puVar14;
  undefined4 *in_t0;
  ulonglong uVar15;
  undefined8 uVar16;
  
  puVar3 = (undefined4 *)0x0;
  if (param_3 != 0) {
    uVar2 = param_3 + 3U & 0xfffffffc;
    if (param_1 == (undefined *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else if (uVar2 < (uint)(1 << 0x20 - (0x20 - (*(uint *)(param_1 + 0x10) >> 8 & 0x1f)))) {
      puVar3 = (undefined4 *)((uint)(uVar2 < 0xc) * 0xc + (uVar2 >= 0xc) * uVar2);
    }
    else {
      puVar3 = (undefined4 *)0x0;
    }
  }
  puVar6 = (undefined4 *)(param_4 + 3U & 0xfffffffc);
  puVar7 = puVar6 + 4;
  if (((undefined4 *)(param_2 + (int)puVar3 + (int)puVar7) != puVar6) &&
     ((param_2 & param_2 - 1) != 0)) {
    param_1 = PTR_s_align_up_40375184;
    puVar7 = (undefined4 *)PTR_s_0_____align____align___1_______m_40375180;
    puVar6 = in_t0;
    FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0xf3);
    in_t0 = puVar6;
  }
  uVar2 = (uint)(puVar3 != (undefined4 *)0x0);
  if (puVar3 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar8 = (undefined4 *)(*(uint *)(param_1 + 0x10) >> 0x17 & 0xff);
    puVar5 = puVar3;
    puVar1 = puVar8;
    if (puVar8 <= puVar3) {
      uVar11 = 1 << 0x20 - (0x20 - (-(*(uint *)(param_1 + 0x10) >> 0x14 & 7) -
                                    (LZCOUNT(puVar3) + -0x1f) & 0x1f));
      uVar15 = CONCAT44(uVar11,*(uint *)(param_1 + 0x10) >> 0x17) & 0xffffffff000000ff;
      if ((uVar11 & uVar11 - 1) != 0) {
        param_1 = PTR_s_align_up_40375184;
        puVar7 = (undefined4 *)PTR_s_0_____align____align___1_______m_40375180;
        puVar5 = in_t0;
        uVar15 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0xf3);
        puVar6 = puVar5;
        in_t0 = puVar5;
      }
      iVar12 = (int)(uVar15 >> 0x20);
      puVar1 = (undefined4 *)uVar15;
      puVar5 = (undefined4 *)((int)puVar5 + iVar12 + -1 & -iVar12);
    }
    if (puVar5 < puVar8) {
      uVar11 = (int)puVar5 / ((int)puVar1 / (int)(*(uint *)(param_1 + 0x10) >> 0xe & 0x3f));
      iVar12 = 0;
    }
    else {
      puVar5 = *(undefined4 **)(unaff_retaddr + 4);
      uVar11 = *(uint *)(param_1 + 0x10) >> 0x14;
      uVar11 = (uint)puVar5 >> ((-(LZCOUNT(puVar5) + -0x20) + -1) - (uVar11 & 7) & 0x1f) ^
               1 << 0x20 - (0x20 - (uVar11 & 7));
      iVar12 = -(LZCOUNT(puVar5) + -0x20) - (*(uint *)(param_1 + 0x10) >> 5 & 7);
    }
    if ((int)(*(uint *)(param_1 + 0x10) & 0x1f) <= iVar12) {
      return (undefined4 *)0x0;
    }
    uVar4 = *(uint *)(iVar12 * 4 + *(int *)(param_1 + 0x1c));
    uVar9 = -1 << 0x20 - (0x20 - (uVar11 & 0x1f));
    uVar11 = uVar4 & uVar9;
    if ((uVar4 & uVar9) == 0) {
      uVar4 = -1 << 0x20 - (0x20 - (iVar12 + 1U & 0x1f));
      uVar11 = *(uint *)(param_1 + 0x18) & uVar4;
      if ((*(uint *)(param_1 + 0x18) & uVar4) == 0) {
        return (undefined4 *)0x0;
      }
      iVar13 = LZCOUNT(-uVar11 & uVar11) + -0x1f;
      iVar12 = -iVar13;
      uVar11 = *(uint *)(iVar13 * -4 + *(int *)(param_1 + 0x1c));
      if (uVar11 == 0) {
        param_1 = PTR_s_search_suitable_block_4037518c;
        puVar7 = (undefined4 *)PTR_s_sl_map_____internal_error___seco_40375188;
        puVar5 = in_t0;
        FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x167);
        puVar6 = puVar5;
        iVar12 = extraout_a3;
        in_t0 = puVar5;
      }
    }
    uVar11 = -(LZCOUNT(-uVar11 & uVar11) + -0x1f);
    puVar1 = *(undefined4 **)
              ((uVar11 + (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * iVar12) * 4 +
              *(int *)(param_1 + 0x20));
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if ((undefined4 *)(puVar1[1] & 0xfffffffc) < puVar5) {
      param_1 = PTR_s_block_locate_free_40375194;
      puVar7 = (undefined4 *)PTR_s_block_size_block__>___size_40375190;
      puVar6 = in_t0;
      FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x26a);
      iVar12 = extraout_a3_00;
      in_t0 = puVar6;
    }
    puVar5 = (undefined4 *)puVar1[3];
    uVar16 = CONCAT44(iVar12,puVar1[2]);
    if (puVar5 == (undefined4 *)0x0) {
      param_1 = PTR_s_remove_free_block_40375154;
      puVar7 = (undefined4 *)PTR_s_prev_____prev_free_field_can_not_40375150;
      puVar5 = in_t0;
      uVar16 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x174);
      puVar6 = puVar5;
      in_t0 = puVar5;
    }
    if ((int)uVar16 == 0) {
      param_1 = PTR_s_remove_free_block_40375154;
      puVar7 = (undefined4 *)PTR_s_next_____next_free_field_can_not_40375158;
      puVar5 = in_t0;
      uVar16 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x175);
      puVar6 = puVar5;
      in_t0 = puVar5;
    }
    uVar4 = (uint)((ulonglong)uVar16 >> 0x20);
    puVar14 = (undefined *)uVar16;
    *(undefined4 **)(puVar14 + 0xc) = puVar5;
    puVar5[2] = puVar14;
    puVar8 = (undefined4 *)
             ((uVar11 + uVar4 * (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)) * 4 +
             *(int *)(param_1 + 0x20));
    puVar5 = (undefined4 *)*puVar8;
    if ((puVar1 == puVar5) && (*puVar8 = puVar14, puVar14 == param_1)) {
      puVar10 = (uint *)(uVar4 * 4 + *(int *)(param_1 + 0x1c));
      puVar5 = (undefined4 *)*puVar10;
      *puVar10 = 1 << 0x20 - (0x20 - (uVar11 & 0x1f)) & (uint)puVar5 ^ (uint)puVar5;
      if (*(int *)(uVar4 * 4 + *(int *)(param_1 + 0x1c)) == 0) {
        *(uint *)(param_1 + 0x18) =
             1 << 0x20 - (0x20 - (uVar4 & 0x1f)) & *(uint *)(param_1 + 0x18) ^
             *(uint *)(param_1 + 0x18);
      }
    }
    uVar16 = CONCAT44(-param_2,puVar1 + 2);
    uVar11 = (int)(puVar1 + 2) + (param_2 - 1) & -param_2;
    if ((param_2 & param_2 - 1) != 0) {
      param_1 = PTR_s_align_ptr_403751b8;
      puVar7 = (undefined4 *)PTR_s_0_____align____align___1_______m_40375180;
      puVar6 = in_t0;
      uVar16 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x101);
      in_t0 = puVar6;
    }
    iVar12 = (int)uVar16;
    puVar8 = (undefined4 *)(uVar11 - iVar12);
    if ((((uint)(puVar8 != (undefined4 *)0x0) & (uint)puVar5) != 0) ||
       ((puVar8 == (undefined4 *)0x0 && puVar6 != (undefined4 *)0x0 && (4 < param_2)))) {
      uVar4 = (int)puVar7 - (int)puVar8;
      puVar8 = (undefined4 *)
               (((uint)((ulonglong)uVar16 >> 0x20) &
                ((param_2 < uVar4) * uVar4 + (param_2 >= uVar4) * param_2 + uVar11 + param_2) - 1) -
               iVar12);
    }
    if (puVar8 != (undefined4 *)0x0) {
      if (puVar8 < puVar7) {
        param_1 = PTR_s_tlsf_memalign_offs_403751c0;
        puVar8 = in_t0;
        iVar12 = FUN_40381d9c(PTR_s_tlsf_c_3c030cd8_0x1b_40375130,0x25b,
                              PTR_s_tlsf_memalign_offs_403751c0,
                              PTR_s_gap_>__gap_minimum_____gap_size_t_403751bc);
        puVar6 = puVar8;
        in_t0 = puVar8;
      }
      puVar14 = (undefined *)(puVar1[1] & 0xfffffffc);
      uVar15 = CONCAT44(puVar1[1],iVar12) & 0xfffffffcffffffff;
      if (puVar14 < (undefined *)((int)puVar8 + (0x10 - (int)puVar6))) goto LAB_40381593;
      uVar11 = (int)puVar8 + (-4 - (int)puVar6);
      puVar8 = (undefined4 *)((int)puVar8 + iVar12 + (-8 - (int)puVar6));
      puVar7 = puVar8 + 2;
      puVar6 = (undefined4 *)(puVar14 + (-4 - uVar11));
      if (puVar7 != (undefined4 *)((int)puVar8 + 0xbU & 0xfffffffc)) {
        param_1 = PTR_s_block_split_403751ac;
        puVar7 = (undefined4 *)PTR_s_block_to_ptr_remaining_____align_403751a8;
        puVar8 = in_t0;
        uVar15 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1c4);
        puVar6 = puVar8;
        in_t0 = puVar8;
      }
      iVar12 = (int)uVar15;
      if ((int)(uVar15 >> 0x20) != (int)puVar6 + uVar11 + 4) {
        param_1 = PTR_s_block_split_403751ac;
        puVar7 = (undefined4 *)PTR_s_block_size_block_____remain_size_403751b0;
        puVar8 = in_t0;
        iVar12 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1c7);
        puVar6 = puVar8;
        in_t0 = puVar8;
      }
      puVar8[1] = (uint)puVar6 | puVar8[1] & 3;
      if (((uint)puVar6 & 0xfffffffc) < 0xc) {
        param_1 = PTR_s_block_split_403751ac;
        puVar7 = (undefined4 *)PTR_s_block_size_remaining__>__block_s_403751b4;
        puVar8 = in_t0;
        iVar12 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1c9);
        in_t0 = puVar8;
      }
      puVar1[1] = uVar11 | puVar1[1] & 3;
      puVar7 = (undefined4 *)((int)puVar7 + ((puVar8[1] & 0xfffffffc) - 4));
      if ((uint)puVar8[1] < 4) {
        param_1 = PTR_s_block_next_40375138;
        puVar7 = (undefined4 *)PTR_s__block_is_last_block__40375134;
        puVar8 = in_t0;
        iVar12 = FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1);
        in_t0 = puVar8;
      }
      *puVar7 = puVar8;
      puVar7[1] = puVar7[1] | 2;
      uVar11 = puVar8[1];
      puVar8[1] = uVar11 | 1;
      puVar8[1] = uVar11 | 3;
      puVar6 = (undefined4 *)(iVar12 + ((puVar1[1] & 0xfffffffc) - 4));
      if ((uint)puVar1[1] < 4) {
        param_1 = PTR_s_block_next_40375138;
        puVar8 = in_t0;
        iVar12 = FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                              PTR_s_block_next_40375138,PTR_s__block_is_last_block__40375134);
        puVar6 = puVar8;
        in_t0 = puVar8;
      }
      *puVar6 = puVar1;
      uVar11 = puVar1[1] & 0xfffffffc;
      uVar4 = *(uint *)(param_1 + 0x10) >> 0x17 & 0xff;
      if (uVar11 < uVar4) {
        puVar6 = (undefined4 *)
                 ((int)uVar11 / (int)(uVar4 / (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)));
        puVar14 = (undefined *)0x0;
      }
      else {
        if (uVar11 == 0) {
          iVar13 = 0;
        }
        else {
          iVar13 = -(LZCOUNT(uVar11) + -0x20);
        }
        uVar4 = *(uint *)(param_1 + 0x10) >> 0x14;
        puVar6 = (undefined4 *)
                 (uVar11 >> ((iVar13 + -1) - (uVar4 & 7) & 0x1f) ^ 1 << 0x20 - (0x20 - (uVar4 & 7)))
        ;
        puVar14 = (undefined *)(iVar13 - (*(uint *)(param_1 + 0x10) >> 5 & 7));
      }
      iVar13 = *(int *)((int)((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * (int)puVar14 + (int)puVar6
                             ) * 4 + *(int *)(param_1 + 0x20));
      uVar16 = CONCAT44(iVar13,iVar12);
      if (iVar13 == 0) {
        param_1 = PTR_s_insert_free_block_40375174;
        puVar14 = PTR_s_current_____free_list_cannot_hav_40375170;
        puVar8 = in_t0;
        uVar16 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,400);
        puVar6 = puVar8;
        in_t0 = puVar8;
      }
      iVar12 = (int)((ulonglong)uVar16 >> 0x20);
      puVar1[2] = iVar12;
      puVar1[3] = param_1;
      *(undefined4 **)(iVar12 + 0xc) = puVar1;
      if ((uint)uVar16 != ((uint)uVar16 + 3 & 0xfffffffc)) {
        param_1 = PTR_s_insert_free_block_40375174;
        puVar14 = PTR_s_block_to_ptr_block_____align_ptr_4037517c;
        puVar8 = in_t0;
        FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x196);
        puVar6 = puVar8;
        in_t0 = puVar8;
      }
      *(undefined4 **)
       ((int)((int)puVar6 + (int)puVar14 * (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)) * 4 +
       *(int *)(param_1 + 0x20)) = puVar1;
      *(uint *)(param_1 + 0x18) =
           *(uint *)(param_1 + 0x18) | 1 << 0x20 - (0x20 - ((uint)puVar14 & 0x1f));
      puVar10 = (uint *)((int)puVar14 * 4 + *(int *)(param_1 + 0x1c));
      *puVar10 = *puVar10 | 1 << 0x20 - (0x20 - ((uint)puVar6 & 0x1f));
      puVar1 = puVar8;
    }
  }
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_40381593:
  if (uVar2 == 0) {
    param_1 = PTR_s_block_prepare_used_4037519c;
    puVar1 = in_t0;
    FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x276,
                 PTR_s_block_prepare_used_4037519c,PTR_s_size_____size_must_be_non_zero__40375198);
    in_t0 = puVar1;
  }
  puVar6 = (undefined4 *)puVar1[1];
  if (((uint)puVar1[1] & 1) == 0) {
    param_1 = PTR_s_block_trim_free_403751a4;
    puVar1 = in_t0;
    FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x224,
                 PTR_s_block_trim_free_403751a4,PTR_s_block_is_free_block______block_m_403751a0);
    puVar6 = puVar1;
    in_t0 = puVar1;
  }
  if (puVar3 + 4 <= (undefined4 *)((uint)puVar6 & 0xfffffffc)) {
    puVar5 = puVar1 + 2;
    puVar7 = (undefined4 *)((int)puVar5 + (int)(puVar3 + -1));
    uVar15 = CONCAT44(puVar6,(int)((uint)puVar6 & 0xfffffffc) + (-4 - (int)puVar3)) &
             0xfffffffcffffffff;
    puVar6 = puVar7 + 2;
    if (puVar6 != (undefined4 *)((uint)((int)puVar7 + 0xb) & 0xfffffffc)) {
      param_1 = PTR_s_block_split_403751ac;
      puVar6 = (undefined4 *)PTR_s_block_to_ptr_remaining_____align_403751a8;
      puVar1 = in_t0;
      uVar15 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1c4);
      puVar7 = puVar1;
      in_t0 = puVar1;
    }
    uVar2 = (uint)uVar15;
    if ((int)(uVar15 >> 0x20) != (int)puVar3 + uVar2 + 4) {
      param_1 = PTR_s_block_split_403751ac;
      puVar6 = (undefined4 *)PTR_s_block_size_block_____remain_size_403751b0;
      puVar1 = in_t0;
      uVar2 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1c7);
      puVar7 = puVar1;
      in_t0 = puVar1;
    }
    puVar7[1] = uVar2 | puVar7[1] & 3;
    if ((uVar2 & 0xfffffffc) < 0xc) {
      param_1 = PTR_s_block_split_403751ac;
      puVar6 = (undefined4 *)PTR_s_block_size_remaining__>__block_s_403751b4;
      puVar1 = in_t0;
      FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1c9);
      puVar7 = puVar1;
      in_t0 = puVar1;
    }
    puVar1[1] = (uint)puVar3 | puVar1[1] & 3;
    puVar6 = (undefined4 *)((int)puVar6 + ((puVar7[1] & 0xfffffffc) - 4));
    if ((uint)puVar7[1] < 4) {
      param_1 = PTR_s_block_next_40375138;
      puVar1 = in_t0;
      puVar6 = (undefined4 *)
               FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                            PTR_s_block_next_40375138,PTR_s__block_is_last_block__40375134);
      puVar7 = puVar1;
      in_t0 = puVar1;
    }
    *puVar6 = puVar7;
    puVar6[1] = puVar6[1] | 2;
    puVar7[1] = puVar7[1] | 1;
    puVar5 = (undefined4 *)((int)puVar5 + ((puVar1[1] & 0xfffffffc) - 4));
    if ((uint)puVar1[1] < 4) {
      param_1 = PTR_s_block_next_40375138;
      puVar1 = in_t0;
      FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                   PTR_s_block_next_40375138,PTR_s__block_is_last_block__40375134);
      puVar7 = puVar1;
      in_t0 = puVar1;
    }
    *puVar5 = puVar1;
    uVar11 = puVar7[1];
    puVar7[1] = uVar11 | 2;
    uVar11 = uVar11 & 0xfffffffc;
    uVar2 = *(uint *)(param_1 + 0x10) >> 0x17 & 0xff;
    if (uVar11 < uVar2) {
      uVar11 = (int)uVar11 / (int)(uVar2 / (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f));
      puVar14 = (undefined *)0x0;
    }
    else {
      if (uVar11 == 0) {
        iVar12 = 0;
      }
      else {
        iVar12 = -(LZCOUNT(uVar11) + -0x20);
      }
      uVar2 = *(uint *)(param_1 + 0x10) >> 0x14;
      uVar11 = uVar11 >> ((iVar12 + -1) - (uVar2 & 7) & 0x1f) ^ 1 << 0x20 - (0x20 - (uVar2 & 7));
      puVar14 = (undefined *)(iVar12 - (*(uint *)(param_1 + 0x10) >> 5 & 7));
    }
    iVar12 = *(int *)(((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * (int)puVar14 + uVar11) * 4 +
                     *(int *)(param_1 + 0x20));
    uVar16 = CONCAT44(uVar11,iVar12);
    if (iVar12 == 0) {
      param_1 = PTR_s_insert_free_block_40375174;
      puVar14 = PTR_s_current_____free_list_cannot_hav_40375170;
      puVar1 = in_t0;
      uVar16 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,400);
      puVar7 = puVar1;
      in_t0 = puVar1;
    }
    if (puVar7 == (undefined4 *)0x0) {
      param_1 = PTR_s_insert_free_block_40375174;
      puVar14 = PTR_s_block_____cannot_insert_a_null_e_40375178;
      puVar1 = in_t0;
      uVar16 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x191);
      puVar7 = puVar1;
      in_t0 = puVar1;
    }
    uVar2 = (uint)((ulonglong)uVar16 >> 0x20);
    puVar7[2] = (int)uVar16;
    puVar7[3] = param_1;
    *(undefined4 **)((int)uVar16 + 0xc) = puVar7;
    *(undefined4 **)
     ((uVar2 + (int)puVar14 * (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)) * 4 +
     *(int *)(param_1 + 0x20)) = puVar7;
    *(uint *)(param_1 + 0x18) =
         *(uint *)(param_1 + 0x18) | 1 << 0x20 - (0x20 - ((uint)puVar14 & 0x1f));
    puVar10 = (uint *)((int)puVar14 * 4 + *(int *)(param_1 + 0x1c));
    *puVar10 = *puVar10 | 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  puVar6 = puVar1 + 2;
  puVar3 = (undefined4 *)(((puVar1[1] & 0xfffffffc) - 4) + (int)puVar6);
  if ((uint)puVar1[1] < 4) {
    puVar1 = in_t0;
    FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,PTR_s_block_next_40375138,
                 PTR_s__block_is_last_block__40375134);
    puVar3 = puVar1;
  }
  puVar3[1] = puVar3[1] & 0xfffffffd;
  puVar1[1] = puVar1[1] & 0xfffffffe;
  return puVar6;
}