// strings: !block_is_free(block) && 'block already marked a | !block_is_last(block) | tlsf_block_functions.h | block_next | prev && 'prev physical block can't be null' | block_is_free(prev) && 'prev block is not free t | tlsf_control_functions.h | block_merge_prev | prev && 'prev_free field can not be null' | remove_free_block | next && 'next_free field can not be null' | block | !block_is_last(prev) && 'previous block can't be | block_absorb | `v 2 | next && 'next physical block can't be null' | block_merge_next

void FUN_40380984(undefined *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  undefined *puVar12;
  undefined *puVar13;
  int *in_t0;
  undefined8 uVar14;
  
  if (param_2 != 0) {
    iVar1 = param_2 + -8;
    piVar6 = *(int **)(param_2 + -4);
    if (((uint)piVar6 & 1) != 0) {
      piVar6 = in_t0;
      FUN_40381d9c(PTR_s_tlsf_c_3c030cd8_0x1b_40375130,0x275,PTR_s_tlsf_free_4037512c,
                   PTR_s__block_is_free_block______block_a_40375128);
      in_t0 = piVar6;
    }
    piVar2 = (int *)((((uint)piVar6 & 0xfffffffc) - 4) + param_2);
    if (piVar6 < (int *)0x4) {
      piVar2 = in_t0;
      FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                   PTR_s_block_next_40375138,PTR_s__block_is_last_block__40375134);
      in_t0 = piVar2;
    }
    *piVar2 = iVar1;
    piVar2[1] = piVar2[1] | 2;
    uVar7 = *(uint *)(param_2 + -4);
    *(uint *)(param_2 + -4) = uVar7 | 1;
    if ((uVar7 & 2) != 0) {
      iVar9 = *(int *)(param_2 + -8);
      if (iVar9 == 0) {
        FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x208,
                     PTR_s_block_merge_prev_40375144,PTR_s_prev_____prev_physical_block_can_40375140
                    );
      }
      piVar6 = *(int **)(iVar9 + 4);
      if (((uint)piVar6 & 1) == 0) {
        piVar6 = in_t0;
        FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x209,
                     PTR_s_block_merge_prev_40375144,PTR_s_block_is_free_prev______prev_blo_4037514c
                    );
        in_t0 = piVar6;
      }
      uVar7 = (uint)piVar6 & 0xfffffffc;
      uVar5 = *(uint *)(param_1 + 0x10) >> 0x17 & 0xff;
      if (uVar7 < uVar5) {
        uVar7 = (int)uVar7 / (int)(uVar5 / (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f));
        iVar11 = 0;
      }
      else {
        if (uVar7 == 0) {
          iVar11 = 0;
        }
        else {
          iVar11 = -(LZCOUNT(uVar7) + -0x20);
        }
        uVar5 = *(uint *)(param_1 + 0x10) >> 0x14;
        uVar7 = uVar7 >> ((iVar11 + -1) - (uVar5 & 7) & 0x1f) ^ 1 << 0x20 - (0x20 - (uVar5 & 7));
        iVar11 = iVar11 - (*(uint *)(param_1 + 0x10) >> 5 & 7);
      }
      uVar14 = CONCAT44(iVar11,uVar7);
      piVar6 = *(int **)(iVar9 + 0xc);
      puVar12 = *(undefined **)(iVar9 + 8);
      if (piVar6 == (int *)0x0) {
        puVar12 = PTR_s_remove_free_block_40375154;
        piVar6 = in_t0;
        uVar14 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x174,
                              PTR_s_remove_free_block_40375154,
                              PTR_s_prev_____prev_free_field_can_not_40375150);
        in_t0 = piVar6;
      }
      if (puVar12 == (undefined *)0x0) {
        puVar12 = PTR_s_remove_free_block_40375154;
        piVar6 = in_t0;
        uVar14 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x175,
                              PTR_s_remove_free_block_40375154,
                              PTR_s_next_____next_free_field_can_not_40375158);
        in_t0 = piVar6;
      }
      uVar7 = (uint)((ulonglong)uVar14 >> 0x20);
      *(int **)(puVar12 + 0xc) = piVar6;
      piVar6[2] = (int)puVar12;
      piVar6 = (int *)(((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * uVar7 + (uint)uVar14) * 4 +
                      *(int *)(param_1 + 0x20));
      if (((iVar9 == *piVar6) && (*piVar6 = (int)puVar12, puVar12 == param_1)) &&
         (puVar10 = (uint *)(uVar7 * 4 + *(int *)(param_1 + 0x1c)), uVar5 = *puVar10,
         *puVar10 = 1 << 0x20 - (0x20 - ((uint)uVar14 & 0x1f)) & uVar5 ^ uVar5,
         *(int *)(uVar7 * 4 + *(int *)(param_1 + 0x1c)) == 0)) {
        *(uint *)(param_1 + 0x18) =
             1 << 0x20 - (0x20 - (uVar7 & 0x1f)) & *(uint *)(param_1 + 0x18) ^
             *(uint *)(param_1 + 0x18);
      }
      piVar6 = *(int **)(iVar9 + 4);
      if (piVar6 < (int *)0x4) {
        piVar6 = in_t0;
        FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1f5,
                     PTR_s_block_absorb_40375160,PTR_s__block_is_last_prev______previou_4037515c);
        in_t0 = piVar6;
      }
      uVar7 = (int)piVar6 + (*(uint *)(param_2 + -4) & 0xfffffffc) + 4;
      *(uint *)(iVar9 + 4) = uVar7;
      piVar6 = (int *)((uVar7 & 0xfffffffc) + iVar9 + 4);
      if (uVar7 < 4) {
        piVar6 = in_t0;
        FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                     PTR_s_block_next_40375138,PTR_s__block_is_last_block__40375134);
        in_t0 = piVar6;
      }
      *piVar6 = iVar9;
      if (DAT_40375164 == (code *)0x0) {
        iVar1 = iVar9;
      }
      else {
        (*DAT_40375164)(iVar1,0x10,1);
        iVar1 = iVar9;
      }
    }
    uVar7 = iVar1 + 8;
    piVar6 = (int *)(((*(uint *)(iVar1 + 4) & 0xfffffffc) - 4) + uVar7);
    piVar2 = piVar6;
    if (*(uint *)(iVar1 + 4) < 4) {
      piVar6 = in_t0;
      piVar2 = (int *)FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                                   PTR_s_block_next_40375138,PTR_s__block_is_last_block__40375134);
      in_t0 = piVar6;
    }
    if (piVar2 == (int *)0x0) {
      piVar6 = in_t0;
      piVar2 = (int *)FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x215,
                                   PTR_s_block_merge_next_4037516c,
                                   PTR_s_next_____next_physical_block_can_40375168);
      in_t0 = piVar6;
    }
    if ((piVar2[1] & 1U) != 0) {
      uVar8 = piVar2[1] & 0xfffffffc;
      uVar5 = *(uint *)(param_1 + 0x10) >> 0x17 & 0xff;
      if (uVar8 < uVar5) {
        puVar12 = (undefined *)
                  ((int)uVar8 / (int)(uVar5 / (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)));
        iVar9 = 0;
      }
      else {
        if (uVar8 == 0) {
          iVar9 = 0;
        }
        else {
          iVar9 = -(LZCOUNT(uVar8) + -0x20);
        }
        uVar5 = *(uint *)(param_1 + 0x10) >> 0x14;
        puVar12 = (undefined *)
                  (uVar8 >> ((iVar9 + -1) - (uVar5 & 7) & 0x1f) ^ 1 << 0x20 - (0x20 - (uVar5 & 7)));
        iVar9 = iVar9 - (*(uint *)(param_1 + 0x10) >> 5 & 7);
      }
      uVar14 = CONCAT44(iVar9,piVar2);
      piVar3 = (int *)piVar2[3];
      puVar13 = (undefined *)piVar2[2];
      if (piVar3 == (int *)0x0) {
        puVar12 = PTR_s_remove_free_block_40375154;
        puVar13 = PTR_s_prev_____prev_free_field_can_not_40375150;
        piVar3 = in_t0;
        uVar14 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x174);
        piVar6 = piVar3;
        in_t0 = piVar3;
      }
      if (puVar13 == (undefined *)0x0) {
        puVar12 = PTR_s_remove_free_block_40375154;
        puVar13 = PTR_s_next_____next_free_field_can_not_40375158;
        piVar3 = in_t0;
        uVar14 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x175);
        piVar6 = piVar3;
        in_t0 = piVar3;
      }
      uVar5 = (uint)((ulonglong)uVar14 >> 0x20);
      iVar9 = (int)uVar14;
      *(int **)(puVar13 + 0xc) = piVar3;
      piVar3[2] = (int)puVar13;
      puVar4 = (undefined4 *)
               ((int)(puVar12 + (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * uVar5) * 4 +
               *(int *)(param_1 + 0x20));
      if (((piVar6 == (int *)*puVar4) && (*puVar4 = puVar13, puVar13 == param_1)) &&
         (puVar10 = (uint *)(uVar5 * 4 + *(int *)(param_1 + 0x1c)), uVar8 = *puVar10,
         *puVar10 = 1 << 0x20 - (0x20 - ((uint)puVar12 & 0x1f)) & uVar8 ^ uVar8,
         *(int *)(uVar5 * 4 + *(int *)(param_1 + 0x1c)) == 0)) {
        *(uint *)(param_1 + 0x18) =
             1 << 0x20 - (0x20 - (uVar5 & 0x1f)) & *(uint *)(param_1 + 0x18) ^
             *(uint *)(param_1 + 0x18);
      }
      piVar6 = *(int **)(iVar1 + 4);
      if (piVar6 < (int *)0x4) {
        piVar6 = in_t0;
        iVar9 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1f5,
                             PTR_s_block_absorb_40375160,
                             PTR_s__block_is_last_prev______previou_4037515c);
        in_t0 = piVar6;
      }
      uVar5 = (int)piVar6 + (*(uint *)(iVar9 + 4) & 0xfffffffc) + 4;
      *(uint *)(iVar1 + 4) = uVar5;
      piVar6 = (int *)(uVar7 + ((uVar5 & 0xfffffffc) - 4));
      if (uVar5 < 4) {
        piVar6 = in_t0;
        iVar9 = FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                             PTR_s_block_next_40375138,PTR_s__block_is_last_block__40375134);
        in_t0 = piVar6;
      }
      *piVar6 = iVar1;
      if (DAT_40375164 != (code *)0x0) {
        (*DAT_40375164)(iVar9,0x10,1);
      }
    }
    uVar8 = *(uint *)(iVar1 + 4) & 0xfffffffc;
    uVar5 = *(uint *)(param_1 + 0x10) >> 0x17 & 0xff;
    if (uVar8 < uVar5) {
      piVar6 = (int *)((int)uVar8 / (int)(uVar5 / (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)));
      uVar5 = 0;
    }
    else {
      if (uVar8 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = -(LZCOUNT(uVar8) + -0x20);
      }
      uVar5 = *(uint *)(param_1 + 0x10) >> 0x14;
      piVar6 = (int *)(uVar8 >> ((iVar9 + -1) - (uVar5 & 7) & 0x1f) ^
                      1 << 0x20 - (0x20 - (uVar5 & 7)));
      uVar5 = iVar9 - (*(uint *)(param_1 + 0x10) >> 5 & 7);
    }
    piVar2 = *(int **)((int)((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * uVar5 + (int)piVar6) * 4 +
                      *(int *)(param_1 + 0x20));
    if (piVar2 == (int *)0x0) {
      piVar2 = in_t0;
      uVar5 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,400,
                           PTR_s_insert_free_block_40375174,
                           PTR_s_current_____free_list_cannot_hav_40375170);
      piVar6 = piVar2;
      in_t0 = piVar2;
    }
    if (iVar1 == 0) {
      piVar2 = in_t0;
      uVar5 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x191,
                           PTR_s_insert_free_block_40375174,
                           PTR_s_block_____cannot_insert_a_null_e_40375178);
      piVar6 = piVar2;
      in_t0 = piVar2;
    }
    *(int **)(iVar1 + 8) = piVar2;
    *(undefined **)(iVar1 + 0xc) = param_1;
    piVar2[3] = iVar1;
    if (uVar7 != (iVar1 + 0xbU & 0xfffffffc)) {
      piVar6 = in_t0;
      uVar5 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x196,
                           PTR_s_insert_free_block_40375174,
                           PTR_s_block_to_ptr_block_____align_ptr_4037517c);
    }
    *(int *)((int)((int)piVar6 + uVar5 * (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)) * 4 +
            *(int *)(param_1 + 0x20)) = iVar1;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 1 << 0x20 - (0x20 - (uVar5 & 0x1f));
    puVar10 = (uint *)(uVar5 * 4 + *(int *)(param_1 + 0x1c));
    *puVar10 = *puVar10 | 1 << 0x20 - (0x20 - ((uint)piVar6 & 0x1f));
  }
  return;
}