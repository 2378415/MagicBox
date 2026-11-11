// strings: 0 == (align & (align - 1)) && 'must align to a p | sl_map && 'internal error - second level bitmap  | block_size(block) >= *size | prev && 'prev_free field can not be null' | tlsf_control_functions.h | remove_free_block | next && 'next_free field can not be null' | block | size && 'size must be non-zero' | block_prepare_used | block_is_free(block) && 'block must be free' | block_trim_free | block_split | block_size(block) == remain_size + size + block_ | block_size(remaining) >= block_size_min && 'bloc | tlsf_block_functions.h | block_next | !block_is_last(block)

int FUN_40380d74(undefined *param_1,int param_2)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined *puVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  undefined *puVar12;
  undefined *in_t0;
  undefined8 uVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  
  if (param_2 == 0) {
    iVar5 = 0;
  }
  else {
    uVar1 = param_2 + 3U & 0xfffffffc;
    if (param_1 == (undefined *)0x0) {
      iVar5 = 0;
    }
    else if (uVar1 < (uint)(1 << 0x20 - (0x20 - (*(uint *)(param_1 + 0x10) >> 8 & 0x1f)))) {
      puVar2 = (undefined *)((uint)(uVar1 < 0xc) * 0xc + (uVar1 >= 0xc) * uVar1);
      puVar3 = (undefined *)(*(uint *)(param_1 + 0x10) >> 0x17 & 0xff);
      puVar8 = puVar3;
      if (puVar3 <= puVar2) {
        uVar1 = 1 << 0x20 - (0x20 - (-(*(uint *)(param_1 + 0x10) >> 0x14 & 7) -
                                     (LZCOUNT(puVar2) + -0x1f) & 0x1f));
        if ((uVar1 & uVar1 - 1) != 0) {
          puVar8 = PTR_s_align_up_40375184;
          param_1 = in_t0;
          uVar1 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0xf3,
                               PTR_s_align_up_40375184,
                               PTR_s_0_____align____align___1_______m_40375180);
          puVar3 = param_1;
          in_t0 = param_1;
        }
        puVar2 = (undefined *)((uint)(puVar2 + (uVar1 - 1)) & -uVar1);
      }
      if (puVar2 < puVar8) {
        uVar1 = (int)puVar2 / ((int)puVar3 / (int)(*(uint *)(param_1 + 0x10) >> 0xe & 0x3f));
        iVar5 = 0;
      }
      else {
        if (puVar2 == (undefined *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = -(LZCOUNT(puVar2) + -0x20);
        }
        uVar1 = *(uint *)(param_1 + 0x10) >> 0x14;
        uVar1 = (uint)puVar2 >> ((iVar5 + -1) - (uVar1 & 7) & 0x1f) ^
                1 << 0x20 - (0x20 - (uVar1 & 7));
        iVar5 = iVar5 - (*(uint *)(param_1 + 0x10) >> 5 & 7);
      }
      if (iVar5 < (int)(*(uint *)(param_1 + 0x10) & 0x1f)) {
        uVar10 = *(uint *)(iVar5 * 4 + *(int *)(param_1 + 0x1c));
        uVar1 = -1 << 0x20 - (0x20 - (uVar1 & 0x1f));
        uVar13 = CONCAT44(uVar10 & uVar1,iVar5);
        if ((uVar10 & uVar1) == 0) {
          uVar1 = -1 << 0x20 - (0x20 - (iVar5 + 1U & 0x1f));
          uVar10 = *(uint *)(param_1 + 0x18) & uVar1;
          if ((*(uint *)(param_1 + 0x18) & uVar1) == 0) {
            return 0;
          }
          iVar5 = LZCOUNT(-uVar10 & uVar10) + -0x1f;
          iVar7 = *(int *)(iVar5 * -4 + *(int *)(param_1 + 0x1c));
          uVar13 = CONCAT44(iVar7,-iVar5);
          if (iVar7 == 0) {
            param_1 = in_t0;
            uVar13 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x167,
                                  PTR_s_search_suitable_block_4037518c,
                                  PTR_s_sl_map_____internal_error___seco_40375188);
            in_t0 = param_1;
          }
        }
        uVar1 = (uint)((ulonglong)uVar13 >> 0x20);
        iVar5 = -(LZCOUNT(-uVar1 & uVar1) + -0x1f);
        uVar14 = CONCAT44(iVar5,(int)uVar13);
        iVar7 = *(int *)((iVar5 + (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * (int)uVar13) * 4 +
                        *(int *)(param_1 + 0x20));
        iVar5 = iVar7;
        if (iVar7 != 0) {
          if ((undefined *)(*(uint *)(iVar7 + 4) & 0xfffffffc) < puVar2) {
            param_1 = in_t0;
            uVar14 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x26a,
                                  PTR_s_block_locate_free_40375194,
                                  PTR_s_block_size_block__>___size_40375190);
            in_t0 = param_1;
          }
          puVar8 = *(undefined **)(iVar7 + 8);
          puVar3 = *(undefined **)(iVar7 + 0xc);
          if (*(undefined **)(iVar7 + 0xc) == (undefined *)0x0) {
            puVar8 = PTR_s_remove_free_block_40375154;
            param_1 = in_t0;
            uVar14 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x174,
                                  PTR_s_remove_free_block_40375154,
                                  PTR_s_prev_____prev_free_field_can_not_40375150);
            puVar3 = param_1;
            in_t0 = param_1;
          }
          if (puVar8 == (undefined *)0x0) {
            puVar8 = PTR_s_remove_free_block_40375154;
            param_1 = in_t0;
            uVar14 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x175,
                                  PTR_s_remove_free_block_40375154,
                                  PTR_s_next_____next_free_field_can_not_40375158);
            puVar3 = param_1;
            in_t0 = param_1;
          }
          uVar10 = (uint)((ulonglong)uVar14 >> 0x20);
          uVar1 = (uint)uVar14;
          *(undefined **)(puVar8 + 0xc) = puVar3;
          *(undefined **)(puVar3 + 8) = puVar8;
          piVar4 = (int *)((uVar10 + uVar1 * (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)) * 4 +
                          *(int *)(param_1 + 0x20));
          if (((iVar7 == *piVar4) && (*piVar4 = (int)puVar8, puVar8 == param_1)) &&
             (puVar9 = (uint *)(uVar1 * 4 + *(int *)(param_1 + 0x1c)), uVar11 = *puVar9,
             *puVar9 = 1 << 0x20 - (0x20 - (uVar10 & 0x1f)) & uVar11 ^ uVar11,
             *(int *)(uVar1 * 4 + *(int *)(param_1 + 0x1c)) == 0)) {
            *(uint *)(param_1 + 0x18) =
                 1 << 0x20 - (0x20 - (uVar1 & 0x1f)) & *(uint *)(param_1 + 0x18) ^
                 *(uint *)(param_1 + 0x18);
          }
          if (puVar2 == (undefined *)0x0) {
            param_1 = in_t0;
            FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x276,
                         PTR_s_block_prepare_used_4037519c,
                         PTR_s_size_____size_must_be_non_zero__40375198);
            in_t0 = param_1;
          }
          puVar3 = *(undefined **)(iVar7 + 4);
          if (((uint)*(undefined **)(iVar7 + 4) & 1) == 0) {
            param_1 = in_t0;
            FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x224,
                         PTR_s_block_trim_free_403751a4,
                         PTR_s_block_is_free_block______block_m_403751a0);
            puVar3 = param_1;
            in_t0 = param_1;
          }
          if (puVar2 + 0x10 <= (undefined *)((uint)puVar3 & 0xfffffffc)) {
            puVar12 = (undefined *)(iVar7 + 8);
            puVar8 = puVar12 + (int)(puVar2 + -4);
            uVar15 = CONCAT44(puVar3,(undefined *)((uint)puVar3 & 0xfffffffc) + (-4 - (int)puVar2))
                     & 0xfffffffcffffffff;
            puVar3 = puVar8 + 8;
            if (puVar3 != (undefined *)((uint)(puVar8 + 0xb) & 0xfffffffc)) {
              puVar3 = PTR_s_block_split_403751ac;
              puVar12 = PTR_s_block_to_ptr_remaining_____align_403751a8;
              param_1 = in_t0;
              uVar15 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1c4);
              puVar8 = param_1;
              in_t0 = param_1;
            }
            uVar1 = (uint)uVar15;
            if ((undefined *)(uVar15 >> 0x20) != puVar2 + uVar1 + 4) {
              puVar3 = PTR_s_block_split_403751ac;
              puVar12 = PTR_s_block_size_block_____remain_size_403751b0;
              param_1 = in_t0;
              uVar1 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1c7);
              puVar8 = param_1;
              in_t0 = param_1;
            }
            *(uint *)(puVar8 + 4) = uVar1 | *(uint *)(puVar8 + 4) & 3;
            if ((uVar1 & 0xfffffffc) < 0xc) {
              puVar3 = PTR_s_block_split_403751ac;
              puVar12 = PTR_s_block_size_remaining__>__block_s_403751b4;
              param_1 = in_t0;
              FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1c9);
              puVar8 = param_1;
              in_t0 = param_1;
            }
            *(uint *)(iVar7 + 4) = *(uint *)(iVar7 + 4) & 3 | (uint)puVar2;
            puVar6 = (undefined4 *)(puVar3 + ((*(uint *)(puVar8 + 4) & 0xfffffffc) - 4));
            if (*(uint *)(puVar8 + 4) < 4) {
              puVar12 = PTR_s__block_is_last_block__40375134;
              param_1 = in_t0;
              puVar6 = (undefined4 *)
                       FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                                    PTR_s_block_next_40375138);
              puVar8 = param_1;
              in_t0 = param_1;
            }
            *puVar6 = puVar8;
            puVar6[1] = puVar6[1] | 2;
            *(uint *)(puVar8 + 4) = *(uint *)(puVar8 + 4) | 1;
            piVar4 = (int *)(puVar12 + ((*(uint *)(iVar7 + 4) & 0xfffffffc) - 4));
            if (*(uint *)(iVar7 + 4) < 4) {
              piVar4 = (int *)PTR_s__block_is_last_block__40375134;
              param_1 = in_t0;
              FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                           PTR_s_block_next_40375138);
              puVar8 = param_1;
              in_t0 = param_1;
            }
            *piVar4 = iVar7;
            uVar1 = *(uint *)(puVar8 + 4);
            *(uint *)(puVar8 + 4) = uVar1 | 2;
            uVar1 = uVar1 & 0xfffffffc;
            uVar10 = *(uint *)(param_1 + 0x10) >> 0x17 & 0xff;
            if (uVar1 < uVar10) {
              uVar1 = (int)uVar1 / (int)(uVar10 / (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f));
              puVar3 = (undefined *)0x0;
            }
            else {
              if (uVar1 == 0) {
                iVar5 = 0;
              }
              else {
                iVar5 = -(LZCOUNT(uVar1) + -0x20);
              }
              uVar10 = *(uint *)(param_1 + 0x10) >> 0x14;
              uVar1 = uVar1 >> ((iVar5 + -1) - (uVar10 & 7) & 0x1f) ^
                      1 << 0x20 - (0x20 - (uVar10 & 7));
              puVar3 = (undefined *)(iVar5 - (*(uint *)(param_1 + 0x10) >> 5 & 7));
            }
            iVar5 = *(int *)(((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * (int)puVar3 + uVar1) * 4 +
                            *(int *)(param_1 + 0x20));
            uVar13 = CONCAT44(iVar5,uVar1);
            if (iVar5 == 0) {
              puVar3 = PTR_s_insert_free_block_40375174;
              param_1 = in_t0;
              uVar13 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,400,
                                    PTR_s_insert_free_block_40375174,
                                    PTR_s_current_____free_list_cannot_hav_40375170);
              puVar8 = param_1;
              in_t0 = param_1;
            }
            if (puVar8 == (undefined *)0x0) {
              puVar3 = PTR_s_insert_free_block_40375174;
              param_1 = in_t0;
              uVar13 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x191,
                                    PTR_s_insert_free_block_40375174,
                                    PTR_s_block_____cannot_insert_a_null_e_40375178);
              puVar8 = param_1;
              in_t0 = param_1;
            }
            iVar5 = (int)((ulonglong)uVar13 >> 0x20);
            *(int *)(puVar8 + 8) = iVar5;
            *(undefined **)(puVar8 + 0xc) = param_1;
            *(undefined **)(iVar5 + 0xc) = puVar8;
            *(undefined **)
             (((uint)uVar13 + (int)puVar3 * (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)) * 4 +
             *(int *)(param_1 + 0x20)) = puVar8;
            *(uint *)(param_1 + 0x18) =
                 *(uint *)(param_1 + 0x18) | 1 << 0x20 - (0x20 - ((uint)puVar3 & 0x1f));
            puVar9 = (uint *)((int)puVar3 * 4 + *(int *)(param_1 + 0x1c));
            *puVar9 = *puVar9 | 1 << 0x20 - (0x20 - ((uint)uVar13 & 0x1f));
          }
          iVar5 = iVar7 + 8;
          puVar3 = (undefined *)(((*(uint *)(iVar7 + 4) & 0xfffffffc) - 4) + iVar5);
          if (*(uint *)(iVar7 + 4) < 4) {
            puVar3 = in_t0;
            iVar5 = FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                                 PTR_s_block_next_40375138,PTR_s__block_is_last_block__40375134);
          }
          *(uint *)(puVar3 + 4) = *(uint *)(puVar3 + 4) & 0xfffffffd;
          *(uint *)(iVar7 + 4) = *(uint *)(iVar7 + 4) & 0xfffffffe;
        }
      }
      else {
        iVar5 = 0;
      }
    }
    else {
      iVar5 = 0;
    }
  }
  return iVar5;
}