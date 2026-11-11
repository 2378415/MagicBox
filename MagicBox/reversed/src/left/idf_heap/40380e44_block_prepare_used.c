// strings: 0 == (align & (align - 1)) && 'must align to a p | block_size(block) >= *size | prev && 'prev_free field can not be null' | tlsf_control_functions.h | remove_free_block | next && 'next_free field can not be null' | size && 'size must be non-zero' | block_is_free(block) && 'block must be free' | block_trim_free | block_to_ptr(remaining) == align_ptr(block_to_pt | block_size(block) == remain_size + size + block_ | block_split | block_size(remaining) >= block_size_min && 'bloc | !block_is_last(block) | tlsf_block_functions.h | block_next

int FUN_40380e44(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint extraout_a3;
  int *piVar3;
  int extraout_a3_00;
  int extraout_a3_01;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined *puVar12;
  uint uVar13;
  int iVar14;
  undefined *puVar15;
  uint uVar16;
  uint uVar17;
  int *in_t0;
  ulonglong uVar18;
  undefined8 uVar19;
  
  if (param_2 == 0) {
    return 0;
  }
  uVar2 = param_2 + 3U & 0xfffffffc;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  piVar6 = (int *)param_1[4];
  if ((uint)(1 << 0x20 - (0x20 - ((uint)piVar6 >> 8 & 0x1f))) <= uVar2) {
    return 0;
  }
  uVar2 = (uint)(uVar2 < 0xc) * 0xc + (uVar2 >= 0xc) * uVar2;
  uVar9 = (uint)piVar6 >> 0x17 & 0xff;
  uVar18 = CONCAT44(uVar2,(uint)piVar6 >> 0x17) & 0xffffffff000000ff;
  if (uVar9 <= uVar2) {
    uVar16 = (uint)piVar6 >> 0x14 & 7;
    puVar12 = (undefined *)(1 << 0x20 - (0x20 - (-uVar16 - (LZCOUNT(uVar2) + -0x1f) & 0x1f)));
    if (((uint)(puVar12 + -1) & (uint)puVar12) != 0) {
      puVar12 = PTR_s_align_up_40375238;
      param_1 = in_t0;
      uVar18 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0xf3,
                            PTR_s_align_up_40375238,PTR_s_0_____align____align___1_______m_40375234)
      ;
      piVar6 = param_1;
      in_t0 = param_1;
    }
    uVar9 = (uint)uVar18;
    uVar2 = (uint)(puVar12 + (int)(uVar18 >> 0x20) + -1) & -(int)puVar12;
    if (uVar9 <= uVar2) {
      if (uVar2 == 0) {
        iVar1 = -1;
        iVar10 = 0;
      }
      else {
        iVar10 = -(LZCOUNT(uVar2) + -0x20);
        iVar1 = -(LZCOUNT(uVar2) + -0x1f);
      }
      uVar9 = uVar2 >> (iVar1 - uVar16 & 0x1f) ^ 1 << 0x20 - (0x20 - (uVar16 & 0x1f));
      puVar12 = (undefined *)(iVar10 - ((uint)piVar6 >> 5 & 7));
      goto LAB_40380ef0;
    }
  }
  uVar9 = (int)uVar2 / ((int)uVar9 / (int)((uint)piVar6 >> 0xe & 0x3f));
  puVar12 = (undefined *)0x0;
LAB_40380ef0:
  if ((int)((uint)piVar6 & 0x1f) <= (int)puVar12) {
    return 0;
  }
  puVar15 = (undefined *)param_1[7];
  uVar9 = -1 << 0x20 - (0x20 - (uVar9 & 0x1f));
  uVar16 = uVar9 & *(uint *)(puVar15 + (int)puVar12 * 4);
  if ((uVar9 & *(uint *)(puVar15 + (int)puVar12 * 4)) == 0) {
    uVar16 = -1 << 0x20 - (0x20 - ((uint)(puVar12 + 1) & 0x1f));
    uVar9 = uVar16 & param_1[6];
    if ((uVar16 & param_1[6]) == 0) {
      return 0;
    }
    puVar12 = (undefined *)-(LZCOUNT(-uVar9 & uVar9) + -0x1f);
    uVar16 = *(uint *)(puVar15 + ((uint)puVar12 & 0xffff) * 4);
    if (uVar16 == 0) {
      puVar12 = PTR_s_search_suitable_block_40375240;
      puVar15 = PTR_s_sl_map_____internal_error___seco_4037523c;
      param_1 = in_t0;
      FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x167);
      piVar6 = param_1;
      uVar2 = extraout_a3;
      in_t0 = param_1;
    }
  }
  uVar17 = param_1[8];
  iVar10 = -(LZCOUNT(-uVar16 & uVar16) + -0x1f);
  uVar19 = CONCAT44(uVar2,iVar10);
  uVar9 = *(uint *)((((uint)piVar6 >> 0xe & 0x3f) * (int)puVar12 + iVar10) * 4 + uVar17);
  if (uVar9 == 0) {
    return 0;
  }
  if ((*(uint *)(uVar9 + 4) & 0xfffffffc) < uVar2) {
    puVar12 = PTR_s_block_locate_free_40375248;
    puVar15 = PTR_s_block_size_block__>___size_40375244;
    param_1 = in_t0;
    uVar19 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x26a);
    in_t0 = param_1;
  }
  piVar3 = *(int **)(uVar9 + 8);
  piVar6 = *(int **)(uVar9 + 0xc);
  if (*(int **)(uVar9 + 0xc) == (int *)0x0) {
    puVar12 = PTR_s_remove_free_block_4037520c;
    puVar15 = PTR_s_prev_____prev_free_field_can_not_40375208;
    param_1 = in_t0;
    uVar19 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x174);
    piVar6 = param_1;
    in_t0 = param_1;
  }
  if (piVar3 == (int *)0x0) {
    puVar12 = PTR_s_remove_free_block_4037520c;
    puVar15 = PTR_s_next_____next_free_field_can_not_40375210;
    param_1 = in_t0;
    uVar19 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x175);
    piVar6 = param_1;
    in_t0 = param_1;
  }
  iVar10 = (int)((ulonglong)uVar19 >> 0x20);
  piVar3[3] = (int)piVar6;
  piVar6[2] = (int)piVar3;
  puVar7 = (uint *)((((uint)param_1[4] >> 0xe & 0x3f) * (int)puVar12 + (uint)uVar19) * 4 + uVar17);
  if (((uVar9 == *puVar7) && (*puVar7 = (uint)piVar3, piVar3 == param_1)) &&
     (uVar2 = *(uint *)(puVar15 + (int)puVar12 * 4),
     uVar2 = 1 << 0x20 - (0x20 - ((uint)uVar19 & 0x1f)) & uVar2 ^ uVar2,
     *(uint *)(puVar15 + (int)puVar12 * 4) = uVar2, uVar2 == 0)) {
    param_1[6] = 1 << 0x20 - (0x20 - ((uint)puVar12 & 0x1f)) & param_1[6] ^ param_1[6];
  }
  if (iVar10 == 0) {
    puVar15 = PTR_s_size_____size_must_be_non_zero__4037524c;
    param_1 = in_t0;
    FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x276,
                 PTR_s_block_prepare_used_40375250);
    iVar10 = extraout_a3_00;
    in_t0 = param_1;
  }
  piVar6 = *(int **)(uVar9 + 4);
  if (((uint)*(int **)(uVar9 + 4) & 1) == 0) {
    puVar15 = PTR_s_block_is_free_block______block_m_40375254;
    param_1 = in_t0;
    FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x224,
                 PTR_s_block_trim_free_40375258);
    piVar6 = param_1;
    iVar10 = extraout_a3_01;
    in_t0 = param_1;
  }
  uVar16 = 0xfffffffc;
  puVar12 = (undefined *)((uint)piVar6 & 0xfffffffc);
  iVar1 = uVar9 + 8;
  uVar2 = uVar9;
  if (puVar12 < (undefined *)(iVar10 + 0x10)) goto LAB_40381190;
  iVar4 = iVar10 + -4 + iVar1;
  uVar19 = CONCAT44(iVar10,iVar4);
  uVar16 = (int)puVar12 - (iVar10 + 4);
  if (iVar4 + 8U != (iVar4 + 0xbU & 0xfffffffc)) {
    puVar12 = PTR_s_block_split_40375260;
    puVar15 = PTR_s_block_to_ptr_remaining_____align_4037525c;
    param_1 = in_t0;
    uVar19 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x1c4);
    in_t0 = param_1;
  }
  if (puVar12 != (undefined *)((int)((ulonglong)uVar19 >> 0x20) + 4 + uVar16)) {
    puVar15 = PTR_s_block_size_block_____remain_size_40375264;
    param_1 = in_t0;
    uVar19 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x1c7,
                          PTR_s_block_split_40375260);
    in_t0 = param_1;
  }
  *(uint *)((int)uVar19 + 4) = *(uint *)((int)uVar19 + 4) & 3 | uVar16;
  if ((uVar16 & 0xfffffffc) < 0xc) {
    puVar15 = PTR_s_block_size_remaining__>__block_s_40375268;
    param_1 = in_t0;
    uVar19 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x1c9,
                          PTR_s_block_split_40375260);
    in_t0 = param_1;
  }
  iVar10 = (int)uVar19;
  uVar16 = 0xfffffffc;
  *(uint *)(uVar2 + 4) = *(uint *)(uVar2 + 4) & 3 | (uint)((ulonglong)uVar19 >> 0x20);
  piVar6 = (int *)(((*(uint *)(iVar10 + 4) & 0xfffffffc) + iVar4 + 8U) - 4);
  if (3 < *(uint *)(iVar10 + 4)) goto LAB_403810b7;
  do {
    do {
      param_1 = in_t0;
      puVar15 = PTR_s__block_is_last_block__403751ec;
      iVar10 = FUN_40381ce4(PTR_s_tlsf_block_functions_h_3c0331e0_0x1b_403751f4,0xa1,
                            PTR_s_block_next_403751f0);
      piVar6 = param_1;
      in_t0 = param_1;
LAB_403810b7:
      piVar6[1] = piVar6[1] | 2;
      uVar11 = *(uint *)(iVar10 + 4);
      *piVar6 = iVar10;
      *(uint *)(iVar10 + 4) = uVar11 | 1;
    } while (*(uint *)(uVar2 + 4) < 4);
    *(uint *)((*(uint *)(uVar2 + 4) & uVar16) + iVar1 + -4) = uVar2;
    *(uint *)(iVar10 + 4) = uVar11 | 3;
    uVar8 = param_1[4];
    uVar11 = uVar11 & uVar16;
    uVar13 = uVar8 >> 0x17 & 0xff;
    uVar5 = uVar8 >> 0xe & 0x3f;
    if (uVar11 < uVar13) {
      uVar11 = (int)uVar11 / (int)(uVar13 / uVar5);
      puVar12 = (undefined *)0x0;
      uVar8 = uVar11;
    }
    else {
      if (uVar11 == 0) {
        iVar4 = -1;
        iVar14 = 0;
      }
      else {
        iVar14 = -(LZCOUNT(uVar11) + -0x20);
        iVar4 = -(LZCOUNT(uVar11) + -0x1f);
      }
      puVar12 = (undefined *)(iVar14 - (uVar8 >> 5 & 7));
      uVar16 = iVar4 - (uVar8 >> 0x14 & 7);
      uVar8 = uVar11 >> (uVar16 & 0x1f) ^ 1 << 0x20 - (0x20 - (uVar8 >> 0x14 & 7));
      uVar11 = (int)puVar12 * uVar5 + uVar8;
    }
    uVar19 = CONCAT44(uVar8,iVar10);
    piVar6 = *(int **)(uVar11 * 4 + uVar17);
    if (piVar6 == (int *)0x0) {
      puVar12 = PTR_s_insert_free_block_4037522c;
      puVar15 = PTR_s_current_____free_list_cannot_hav_40375228;
      param_1 = in_t0;
      uVar19 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,400);
      piVar6 = param_1;
      in_t0 = param_1;
    }
    uVar5 = (uint)((ulonglong)uVar19 >> 0x20);
    iVar10 = (int)uVar19;
    *(int **)(iVar10 + 0xc) = param_1;
    *(int **)(iVar10 + 8) = piVar6;
    piVar6[3] = iVar10;
    uVar11 = param_1[6];
    piVar6 = (int *)((((uint)param_1[4] >> 0xe & 0x3f) * (int)puVar12 + uVar5) * 4 + uVar17);
    uVar17 = 1 << 0x20 - (0x20 - ((uint)puVar12 & 0x1f));
    *piVar6 = iVar10;
    param_1[6] = uVar11 | uVar17;
    *(uint *)(puVar15 + (int)puVar12 * 4) =
         *(uint *)(puVar15 + (int)puVar12 * 4) | 1 << 0x20 - (0x20 - (uVar5 & 0x1f));
    piVar6 = *(int **)(uVar2 + 4);
    puVar12 = (undefined *)((uint)piVar6 & 0xfffffffc);
LAB_40381190:
  } while (piVar6 < (int *)0x4);
  *(uint *)(puVar12 + uVar9 + 8) = *(uint *)(puVar12 + uVar9 + 8) & 0xfffffffd;
  *(uint *)(uVar2 + 4) = *(uint *)(uVar2 + 4) & 0xfffffffe;
  return iVar1;
}