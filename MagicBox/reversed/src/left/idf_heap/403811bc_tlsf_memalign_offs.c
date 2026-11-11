// strings: 0 == (align & (align - 1)) && 'must align to a p | tlsf_control_functions.h | align_up | sl_map && 'internal error - second level bitmap  | block_size(block) >= *size | prev && 'prev_free field can not be null' | remove_free_block | next && 'next_free field can not be null' | block | gap >= gap_minimum && 'gap size too small' | tlsf.c | tlsf_memalign_offs | block_to_ptr(remaining) == align_ptr(block_to_pt | block_split | block_size(block) == remain_size + size + block_ | block_size(remaining) >= block_size_min && 'bloc

undefined4 * FUN_403811bc(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  undefined *puVar12;
  uint uVar13;
  int iVar14;
  undefined *puVar15;
  undefined4 *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  undefined4 *in_t0;
  undefined8 uVar21;
  undefined8 uVar22;
  
  puVar1 = param_2 + 4;
  puVar3 = (undefined *)0x0;
  if (((param_3 == 0) || (puVar3 = (undefined *)(param_3 + 3U & 0xfffffffc), param_1 == 0)) ||
     (uVar13 = *(uint *)(param_1 + 0x10),
     (undefined *)(1 << 0x20 - (0x20 - (uVar13 >> 8 & 0x1f))) <= puVar3)) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (((int)param_2 - 1U & (uint)param_2) == 0) {
      return (undefined4 *)0x0;
    }
  }
  else {
    puVar3 = (undefined *)
             ((uint)(puVar3 < (undefined *)0xc) * 0xc +
             (uint)(puVar3 >= (undefined *)0xc) * (int)puVar3);
    if (puVar3 + (int)puVar1 == (undefined *)0x0) {
      if (param_2 < (undefined4 *)0x5) goto LAB_40381219;
      return (undefined4 *)0x0;
    }
    if (((uint)param_2 & (int)param_2 - 1U) == 0) {
      uVar19 = -(int)param_2 & (uint)(puVar3 + (int)puVar1 + ((int)param_2 - 1U));
      if ((uint)(1 << 0x20 - (0x20 - (uVar13 >> 8 & 0x1f))) <= uVar19) goto LAB_40381213;
      puVar15 = puVar3;
      if (param_2 < (undefined4 *)0x5) goto LAB_40381229;
      puVar15 = (undefined *)((uint)(uVar19 < 0xc) * 0xc + (uVar19 >= 0xc) * uVar19);
      goto LAB_40381229;
    }
  }
  do {
    uVar21 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0xf3,
                          PTR_s_align_up_40375238,PTR_s_0_____align____align___1_______m_40375234);
    uVar13 = (uint)((ulonglong)uVar21 >> 0x20);
    param_1 = (int)uVar21;
LAB_40381213:
    if ((undefined4 *)0x4 < param_2) {
      return (undefined4 *)0x0;
    }
LAB_40381219:
    puVar15 = puVar3;
LAB_40381229:
    puVar6 = (undefined *)(uVar13 >> 0x17 & 0xff);
    if (puVar15 < puVar6) goto LAB_4038125c;
    uVar18 = uVar13 >> 0x14 & 7;
    uVar11 = 1 << 0x20 - (0x20 - (-uVar18 - (LZCOUNT(puVar15) + -0x1f) & 0x1f));
    uVar19 = uVar11 - 1 & uVar11;
  } while ((uVar11 - 1 & uVar11) != 0);
  puVar15 = (undefined *)((uint)(puVar15 + (uVar11 - 1)) & -uVar11);
  if (puVar15 < puVar6) {
LAB_4038125c:
    uVar11 = (int)puVar15 / (int)((uint)puVar6 / (uVar13 >> 0xe & 0x3f));
    puVar6 = (undefined *)0x0;
  }
  else {
    iVar20 = -1;
    if (puVar15 != (undefined *)0x0) {
      uVar19 = -(LZCOUNT(puVar15) + -0x20);
      iVar20 = -(LZCOUNT(puVar15) + -0x1f);
    }
    uVar11 = (uint)puVar15 >> (iVar20 - uVar18 & 0x1f) ^ 1 << 0x20 - (0x20 - (uVar13 >> 0x14 & 7));
    puVar6 = (undefined *)(uVar19 - (uVar13 >> 5 & 7));
  }
  if ((int)(uVar13 & 0x1f) <= (int)puVar6) {
    return (undefined4 *)0x0;
  }
  iVar20 = *(int *)(param_1 + 0x1c);
  uVar19 = *(uint *)((int)puVar6 * 4 + iVar20);
  uVar11 = -1 << 0x20 - (0x20 - (uVar11 & 0x1f));
  uVar18 = uVar11 & uVar19;
  uVar21 = CONCAT44(uVar13,param_1);
  if ((uVar11 & uVar19) == 0) {
    uVar19 = -1 << 0x20 - (0x20 - ((uint)(puVar6 + 1) & 0x1f));
    puVar1 = (undefined4 *)(uVar19 & *(uint *)(param_1 + 0x18));
    if ((uVar19 & *(uint *)(param_1 + 0x18)) == 0) {
      return puVar1;
    }
    puVar6 = (undefined *)-(LZCOUNT(-(int)puVar1 & (uint)puVar1) + -0x1f);
    uVar18 = *(uint *)(((uint)puVar6 & 0xffff) * 4 + iVar20);
    uVar21 = CONCAT44(uVar13,param_1);
    if (uVar18 == 0) {
      puVar15 = PTR_s_search_suitable_block_40375240;
      puVar6 = PTR_s_sl_map_____internal_error___seco_4037523c;
      uVar21 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x167);
    }
  }
  uVar13 = *(uint *)((int)uVar21 + 0x20);
  iVar14 = -(LZCOUNT(-uVar18 & uVar18) + -0x1f);
  uVar22 = CONCAT44(iVar14,(int)uVar21);
  puVar1 = *(undefined4 **)
            ((((uint)((ulonglong)uVar21 >> 0x2e) & 0x3f) * (int)puVar6 + iVar14) * 4 + uVar13);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if ((undefined *)(puVar1[1] & 0xfffffffc) < puVar15) {
    puVar6 = PTR_s_block_size_block__>___size_40375244;
    puVar1 = in_t0;
    uVar22 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x26a,
                          PTR_s_block_locate_free_40375248);
    in_t0 = puVar1;
  }
  puVar7 = (undefined4 *)puVar1[3];
  puVar15 = (undefined *)puVar1[2];
  if (puVar7 == (undefined4 *)0x0) {
    puVar15 = PTR_s_remove_free_block_4037520c;
    puVar6 = PTR_s_prev_____prev_free_field_can_not_40375208;
    puVar7 = in_t0;
    uVar22 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x174);
    puVar1 = puVar7;
    in_t0 = puVar7;
  }
  if (puVar15 == (undefined *)0x0) {
    puVar15 = PTR_s_remove_free_block_4037520c;
    puVar6 = PTR_s_next_____next_free_field_can_not_40375210;
    puVar7 = in_t0;
    uVar22 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x175);
    puVar1 = puVar7;
    in_t0 = puVar7;
  }
  uVar19 = (uint)((ulonglong)uVar22 >> 0x20);
  puVar12 = (undefined *)uVar22;
  *(undefined4 **)(puVar15 + 0xc) = puVar7;
  puVar7[2] = puVar15;
  puVar7 = (undefined4 *)
           (((*(uint *)(puVar12 + 0x10) >> 0xe & 0x3f) * (int)puVar6 + uVar19) * 4 + uVar13);
  if (((puVar1 == (undefined4 *)*puVar7) && (*puVar7 = puVar15, puVar15 == puVar12)) &&
     (puVar9 = (uint *)((int)puVar6 * 4 + iVar20), uVar11 = *puVar9,
     uVar11 = 1 << 0x20 - (0x20 - (uVar19 & 0x1f)) & uVar11 ^ uVar11, *puVar9 = uVar11, uVar11 == 0)
     ) {
    *(uint *)(puVar12 + 0x18) =
         1 << 0x20 - (0x20 - ((uint)puVar6 & 0x1f)) & *(uint *)(puVar12 + 0x18) ^
         *(uint *)(puVar12 + 0x18);
  }
  puVar7 = puVar1 + 2;
  puVar5 = (undefined4 *)((int)param_2 + -1);
  uVar21 = CONCAT44((int)puVar7 + (int)puVar5 & -(int)param_2,puVar12);
  if (((uint)param_2 & (uint)puVar5) != 0) {
    puVar7 = (undefined4 *)PTR_s_0_____align____align___1_______m_40375234;
    puVar1 = in_t0;
    uVar21 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x101,
                          PTR_s_align_ptr_4037526c);
    in_t0 = puVar1;
  }
  puVar2 = (undefined4 *)((ulonglong)uVar21 >> 0x20);
  iVar14 = (int)uVar21;
  uVar19 = param_4 + 3U & 0xfffffffc;
  puVar16 = (undefined4 *)(uVar19 + 0x10);
  puVar8 = (undefined4 *)((int)puVar2 - (int)puVar7);
  if ((puVar7 == puVar2) || (puVar16 <= puVar8)) {
    if (puVar8 != (undefined4 *)0x0) goto LAB_403813f4;
    if (uVar19 == 0) goto LAB_403813ec;
    if ((undefined4 *)0x4 < param_2) goto LAB_403813dc;
  }
  else {
LAB_403813dc:
    puVar8 = (undefined4 *)((int)puVar16 - (int)puVar8);
    puVar8 = (undefined4 *)
             (((int)puVar2 + (int)puVar5 +
               (uint)(puVar8 < param_2) * (int)param_2 + (uint)(puVar8 >= param_2) * (int)puVar8 &
              -(int)param_2) - (int)puVar7);
LAB_403813ec:
    if (puVar8 != (undefined4 *)0x0) {
LAB_403813f4:
      if (puVar8 < puVar16) {
        puVar7 = (undefined4 *)PTR_s_gap_>__gap_minimum_____gap_size_t_40375270;
        puVar8 = in_t0;
        iVar14 = FUN_40381ce4(PTR_s_tlsf_c_3c033380_0x1b_403751e8,0x25b,
                              PTR_s_tlsf_memalign_offs_40375274);
        puVar1 = puVar8;
        in_t0 = puVar8;
      }
      puVar15 = (undefined *)puVar1[1];
      puVar2 = (undefined4 *)((int)puVar8 - uVar19);
      uVar21 = CONCAT44(0xfffffffc,iVar14);
      param_2 = (undefined4 *)((uint)puVar15 & 0xfffffffc);
      puVar5 = puVar2 + 4;
      if (puVar5 <= param_2) {
        puVar5 = (undefined4 *)((int)(puVar7 + -2) + (int)puVar2);
        puVar16 = puVar5 + 2;
        param_2 = (undefined4 *)((int)param_2 + (uVar19 - (int)puVar8));
        if (puVar16 == (undefined4 *)((uint)((int)puVar5 + 0xb) & 0xfffffffc)) goto LAB_4038144e;
        goto LAB_40381430;
      }
      goto LAB_40381577;
    }
  }
  puVar15 = (undefined *)puVar1[1];
LAB_40381577:
  do {
    if (((uint)puVar15 & 1) == 0) {
      puVar15 = PTR_s_block_trim_free_40375258;
      puVar1 = in_t0;
      iVar14 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x224,
                            PTR_s_block_trim_free_40375258,
                            PTR_s_block_is_free_block______block_m_40375254);
      in_t0 = puVar1;
    }
    puVar7 = (undefined4 *)((uint)puVar15 & 0xfffffffc);
    puVar2 = puVar1 + 2;
    if (puVar7 < puVar3 + 0x10) {
LAB_403816ad:
      if ((undefined *)0x3 < puVar15) {
        *(uint *)((int)(puVar1 + 1) + (int)puVar7 + 4) =
             *(uint *)((int)(puVar1 + 1) + (int)puVar7 + 4) & 0xfffffffd;
        puVar1[1] = puVar1[1] & 0xfffffffe;
        return puVar2;
      }
      goto LAB_4038148c;
    }
    puVar15 = puVar3 + -4 + (int)puVar2;
    puVar5 = (undefined4 *)((uint)(puVar15 + 0xb) & 0xfffffffc);
    uVar19 = (int)puVar7 - (int)(puVar3 + 4);
    if ((undefined4 *)(puVar15 + 8) == puVar5) {
      puVar5 = (undefined4 *)(puVar3 + uVar19 + 4);
      if (puVar7 != puVar5) goto LAB_4038143f;
      puVar5 = (undefined4 *)0xb;
      *(uint *)(puVar15 + 4) = *(uint *)(puVar15 + 4) & 3 | uVar19;
      if ((uVar19 & 0xfffffffc) < 0xc) goto LAB_40381460;
      puVar1[1] = puVar1[1] & 3 | (uint)puVar3;
      puVar5 = *(undefined4 **)(puVar15 + 4);
      puVar9 = (uint *)(((uint)puVar5 & 0xfffffffc) + (int)(puVar15 + 8));
      if (puVar5 < (undefined4 *)0x4) goto LAB_4038148c;
      *puVar9 = *puVar9 | 2;
      puVar5 = *(undefined4 **)(puVar15 + 4);
      puVar9[-1] = (uint)puVar15;
      *(uint *)(puVar15 + 4) = (uint)puVar5 | 1;
      if ((uint)puVar1[1] < 4) goto LAB_4038148c;
      *(undefined4 **)((int)puVar2 + ((puVar1[1] & 0xfffffffc) - 4)) = puVar1;
      *(uint *)(puVar15 + 4) = (uint)puVar5 | 3;
      uVar18 = *(uint *)(iVar14 + 0x10);
      uVar19 = (uint)puVar5 & 0xfffffffc;
      uVar11 = uVar18 >> 0x17 & 0xff;
      uVar17 = uVar18 >> 0xe & 0x3f;
      if (uVar19 < uVar11) {
        puVar5 = (undefined4 *)((int)uVar19 / (int)(uVar11 / uVar17));
        uVar11 = 0;
        puVar7 = puVar5;
      }
      else {
        if (uVar19 == 0) {
          iVar4 = -1;
          iVar10 = 0;
        }
        else {
          iVar10 = -(LZCOUNT(uVar19) + -0x20);
          iVar4 = -(LZCOUNT(uVar19) + -0x1f);
        }
        puVar3 = (undefined *)(uVar18 >> 0x14 & 7);
        uVar11 = iVar10 - (uVar18 >> 5 & 7);
        puVar5 = (undefined4 *)
                 (uVar19 >> (iVar4 - (int)puVar3 & 0x1fU) ^
                 1 << 0x20 - (0x20 - (uVar18 >> 0x14 & 7)));
        puVar7 = (undefined4 *)(uVar11 * uVar17 + (int)puVar5);
      }
      iVar10 = *(int *)((int)puVar7 * 4 + uVar13);
      if (iVar10 != 0) {
        *(int *)(puVar15 + 8) = iVar10;
        *(int *)(puVar15 + 0xc) = iVar14;
        *(undefined **)(iVar10 + 0xc) = puVar15;
        uVar19 = *(uint *)(iVar14 + 0x18);
        puVar7 = (undefined4 *)
                 ((int)((*(uint *)(iVar14 + 0x10) >> 0xe & 0x3f) * uVar11 + (int)puVar5) * 4 +
                 uVar13);
        uVar13 = 1 << 0x20 - (0x20 - (uVar11 & 0x1f));
        *puVar7 = puVar15;
        *(uint *)(iVar14 + 0x18) = uVar19 | uVar13;
        puVar9 = (uint *)(uVar11 * 4 + iVar20);
        *puVar9 = *puVar9 | 1 << 0x20 - (0x20 - ((uint)puVar5 & 0x1f));
        puVar15 = (undefined *)puVar1[1];
        puVar7 = (undefined4 *)((uint)puVar15 & 0xfffffffc);
        goto LAB_403816ad;
      }
LAB_40381511:
      puVar8 = in_t0;
      puVar15 = PTR_s_insert_free_block_4037522c;
      puVar7 = (undefined4 *)PTR_s_current_____free_list_cannot_hav_40375228;
      uVar21 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,400);
      puVar1 = puVar8;
      in_t0 = puVar8;
    }
    else {
LAB_40381430:
      FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x1c4,
                   PTR_s_block_split_40375260,PTR_s_block_to_ptr_remaining_____align_4037525c);
LAB_4038143f:
      puVar1 = in_t0;
      puVar16 = (undefined4 *)PTR_s_block_split_40375260;
      puVar7 = (undefined4 *)PTR_s_block_size_block_____remain_size_40375264;
      uVar21 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x1c7);
      in_t0 = puVar1;
LAB_4038144e:
      uVar19 = puVar5[1] & 3 | (uint)param_2;
      puVar5[1] = uVar19;
      if ((uVar19 & (uint)((ulonglong)uVar21 >> 0x20)) < 0xc) {
LAB_40381460:
        puVar1 = in_t0;
        puVar16 = (undefined4 *)PTR_s_block_split_40375260;
        puVar7 = (undefined4 *)PTR_s_block_size_remaining__>__block_s_40375268;
        uVar21 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x1c9);
        in_t0 = puVar1;
      }
      puVar1[1] = puVar1[1] & 3 | (uint)(puVar2 + -1);
      puVar16 = (undefined4 *)((int)puVar16 + ((puVar5[1] & (uint)((ulonglong)uVar21 >> 0x20)) - 4))
      ;
      if (3 < (uint)puVar5[1]) goto LAB_4038149b;
LAB_4038148c:
      do {
        puVar16 = in_t0;
        puVar7 = (undefined4 *)PTR_s__block_is_last_block__403751ec;
        uVar21 = FUN_40381ce4(PTR_s_tlsf_block_functions_h_3c0331e0_0x1b_403751f4,0xa1,
                              PTR_s_block_next_403751f0);
        puVar1 = puVar16;
        in_t0 = puVar16;
LAB_4038149b:
        puVar16[1] = puVar16[1] | 2;
        uVar19 = puVar5[1];
        *puVar16 = puVar5;
        puVar5[1] = uVar19 | 3;
        uVar19 = puVar1[1] & (uint)((ulonglong)uVar21 >> 0x20);
      } while ((uint)puVar1[1] < 4);
      *(undefined4 **)((int)puVar7 + (uVar19 - 4)) = puVar1;
      uVar11 = *(uint *)((int)uVar21 + 0x10);
      uVar18 = uVar11 >> 0x17 & 0xff;
      uVar17 = uVar11 >> 0xe & 0x3f;
      if (uVar19 < uVar18) {
        uVar19 = (int)uVar19 / (int)(uVar18 / uVar17);
        puVar8 = (undefined4 *)0x0;
        uVar11 = uVar19;
      }
      else {
        puVar8 = (undefined4 *)(-(uVar11 >> 5 & 7) - (LZCOUNT(uVar19) + -0x20));
        param_2 = (undefined4 *)(-(uVar11 >> 0x14 & 7) - (LZCOUNT(uVar19) + -0x1f));
        uVar19 = uVar19 >> ((uint)param_2 & 0x1f) ^ 1 << 0x20 - (0x20 - (uVar11 >> 0x14 & 7));
        uVar11 = (int)puVar8 * uVar17 + uVar19;
      }
      uVar21 = CONCAT44(uVar19,(int)uVar21);
      puVar15 = *(undefined **)(uVar11 * 4 + uVar13);
      if (puVar15 == (undefined *)0x0) goto LAB_40381511;
    }
    puVar1[2] = puVar15;
    puVar1[3] = (int)uVar21;
    *(undefined4 **)(puVar15 + 0xc) = puVar1;
    if (puVar7 != (undefined4 *)((uint)((int)puVar7 + 3) & 0xfffffffc)) {
      puVar8 = in_t0;
      uVar21 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x196,
                            PTR_s_insert_free_block_4037522c,
                            PTR_s_block_to_ptr_block_____align_ptr_40375230);
      puVar1 = puVar8;
      in_t0 = puVar8;
    }
    uVar19 = (uint)((ulonglong)uVar21 >> 0x20);
    iVar14 = (int)uVar21;
    uVar11 = *(uint *)(iVar14 + 0x18);
    *(undefined4 **)(((*(uint *)(iVar14 + 0x10) >> 0xe & 0x3f) * (int)puVar8 + uVar19) * 4 + uVar13)
         = puVar1;
    *(uint *)(iVar14 + 0x18) = uVar11 | 1 << 0x20 - (0x20 - ((uint)puVar8 & 0x1f));
    puVar9 = (uint *)((int)puVar8 * 4 + iVar20);
    *puVar9 = *puVar9 | 1 << 0x20 - (0x20 - (uVar19 & 0x1f));
    puVar15 = (undefined *)puVar5[1];
    puVar1 = puVar5;
  } while( true );
}