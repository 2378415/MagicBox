// strings: !block_is_last(block) | tlsf_realloc | !block_is_free(block) && 'block already marked a | block_next | tlsf_control_functions.h | remove_free_block | prev && 'prev_free field can not be null' | next && 'next_free field can not be null' | !block_is_last(prev) && 'previous block can't be | block_absorb | tlsf_block_functions.h | block_trim_used | !block_is_free(block) && 'block must be used' | block_split | block_size(block) == remain_size + size + block_ | block_size(remaining) >= block_size_min && 'bloc

int FUN_40381794(undefined *param_1,int param_2,undefined *param_3)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  int iVar8;
  uint *puVar9;
  undefined *puVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *in_t0;
  undefined8 uVar13;
  
  if (param_2 == 0 || param_3 != (undefined *)0x0) {
    if (param_2 == 0) {
      iVar1 = FUN_40380d74(param_1,param_3);
    }
    else {
      puVar6 = *(undefined4 **)(param_2 + -4);
      puVar4 = (undefined *)((uint)puVar6 & 0xfffffffc);
      puVar7 = puVar4 + param_2 + -4;
      uVar13 = CONCAT44(param_2 + -8,puVar7);
      if (puVar6 < (undefined4 *)0x4) {
        puVar7 = PTR_s_block_next_40375138;
        puVar6 = in_t0;
        uVar13 = FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                              PTR_s_block_next_40375138,PTR_s__block_is_last_block__40375134);
        in_t0 = puVar6;
      }
      uVar11 = *(uint *)((int)uVar13 + 4);
      puVar5 = (undefined4 *)(uVar11 & 0xfffffffc);
      puVar10 = (undefined *)((int)puVar5 + (int)puVar4) + 4;
      if (param_3 == (undefined *)0x0) {
        iVar1 = 0;
      }
      else {
        uVar2 = (uint)(param_3 + 3) & 0xfffffffc;
        if (param_1 == (undefined *)0x0) {
          iVar1 = 0;
        }
        else if (uVar2 < (uint)(1 << 0x20 - (0x20 - (*(uint *)(param_1 + 0x10) >> 8 & 0x1f)))) {
          puVar3 = (undefined *)((uint)(uVar2 < 0xc) * 0xc + (uVar2 >= 0xc) * uVar2);
          if (((uint)puVar6 & 1) != 0) {
            puVar7 = PTR_s_tlsf_realloc_403751c4;
            puVar10 = PTR_s__block_is_free_block______block_a_40375128;
            puVar5 = in_t0;
            uVar13 = FUN_40381d9c(PTR_s_tlsf_c_3c030cd8_0x1b_40375130,0x2a8);
            in_t0 = puVar5;
          }
          if ((puVar4 < puVar3) && (((uVar11 & 1) == 0 || (puVar10 < puVar3)))) {
            iVar1 = FUN_40380d74(param_1,param_3);
            if (iVar1 != 0) {
              (*DAT_403744d4)(iVar1,param_2,
                              (uint)(param_3 < puVar4) * (int)param_3 +
                              (uint)(param_3 >= puVar4) * (int)puVar4);
              FUN_40380984(param_1,param_2);
            }
          }
          else {
            if (puVar4 < puVar3) {
              if ((int)uVar13 == 0) {
                puVar7 = PTR_s_block_merge_next_4037516c;
                puVar5 = in_t0;
                uVar13 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x215,
                                      PTR_s_block_merge_next_4037516c,
                                      PTR_s_next_____next_physical_block_can_40375168);
                in_t0 = puVar5;
              }
              if ((uVar11 & 1) != 0) {
                puVar6 = (undefined4 *)(*(uint *)(param_1 + 0x10) >> 0x17 & 0xff);
                if (puVar5 < puVar6) {
                  puVar5 = (undefined4 *)
                           ((int)puVar5 /
                           (int)((uint)puVar6 / (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)));
                  puVar4 = (undefined *)0x0;
                }
                else {
                  if (puVar5 == (undefined4 *)0x0) {
                    iVar1 = 0;
                  }
                  else {
                    iVar1 = -(LZCOUNT(puVar5) + -0x20);
                  }
                  uVar11 = *(uint *)(param_1 + 0x10) >> 0x14;
                  puVar5 = (undefined4 *)
                           ((uint)puVar5 >> ((iVar1 + -1) - (uVar11 & 7) & 0x1f) ^
                           1 << 0x20 - (0x20 - (uVar11 & 7)));
                  puVar4 = (undefined *)(iVar1 - (*(uint *)(param_1 + 0x10) >> 5 & 7));
                }
                puVar6 = *(undefined4 **)((int)uVar13 + 0xc);
                puVar10 = *(undefined **)((int)uVar13 + 8);
                if (puVar6 == (undefined4 *)0x0) {
                  puVar7 = PTR_s_remove_free_block_40375154;
                  puVar4 = PTR_s_prev_____prev_free_field_can_not_40375150;
                  puVar5 = in_t0;
                  uVar13 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x174)
                  ;
                  puVar6 = puVar5;
                  in_t0 = puVar5;
                }
                if (puVar10 == (undefined *)0x0) {
                  puVar7 = PTR_s_remove_free_block_40375154;
                  puVar4 = PTR_s_next_____next_free_field_can_not_40375158;
                  puVar5 = in_t0;
                  uVar13 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x175)
                  ;
                  puVar6 = puVar5;
                  in_t0 = puVar5;
                }
                *(undefined4 **)(puVar10 + 0xc) = puVar6;
                puVar6[2] = puVar10;
                puVar6 = (undefined4 *)
                         ((int)((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * (int)puVar4 +
                               (int)puVar5) * 4 + *(int *)(param_1 + 0x20));
                if (((puVar7 == (undefined *)*puVar6) && (*puVar6 = puVar10, puVar10 == param_1)) &&
                   (puVar9 = (uint *)((int)puVar4 * 4 + *(int *)(param_1 + 0x1c)), uVar11 = *puVar9,
                   *puVar9 = 1 << 0x20 - (0x20 - ((uint)puVar5 & 0x1f)) & uVar11 ^ uVar11,
                   *(int *)((int)puVar4 * 4 + *(int *)(param_1 + 0x1c)) == 0)) {
                  *(uint *)(param_1 + 0x18) =
                       1 << 0x20 - (0x20 - ((uint)puVar4 & 0x1f)) & *(uint *)(param_1 + 0x18) ^
                       *(uint *)(param_1 + 0x18);
                }
                puVar6 = *(undefined4 **)(param_2 + -4);
                if (puVar6 < (undefined4 *)0x4) {
                  puVar6 = in_t0;
                  uVar13 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1f5,
                                        PTR_s_block_absorb_40375160,
                                        PTR_s__block_is_last_prev______previou_4037515c);
                  in_t0 = puVar6;
                }
                puVar7 = (undefined *)((int)puVar6 + (*(uint *)((int)uVar13 + 4) & 0xfffffffc) + 4);
                *(undefined **)(param_2 + -4) = puVar7;
                puVar6 = (undefined4 *)(param_2 + (((uint)puVar7 & 0xfffffffc) - 4));
                if (puVar7 < (undefined *)0x4) {
                  puVar6 = in_t0;
                  uVar13 = FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                                        PTR_s_block_next_40375138,
                                        PTR_s__block_is_last_block__40375134);
                  in_t0 = puVar6;
                }
                *puVar6 = (int)((ulonglong)uVar13 >> 0x20);
                if (DAT_40375164 != (code *)0x0) {
                  (*DAT_40375164)((int)uVar13,0x10,1);
                }
              }
              puVar6 = (undefined4 *)(param_2 + ((*(uint *)(param_2 + -4) & 0xfffffffc) - 4));
              if (*(uint *)(param_2 + -4) < 4) {
                puVar6 = in_t0;
                FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                             PTR_s_block_next_40375138,PTR_s__block_is_last_block__40375134);
                in_t0 = puVar6;
              }
              puVar6[1] = puVar6[1] & 0xfffffffd;
              *(uint *)(param_2 + -4) = *(uint *)(param_2 + -4) & 0xfffffffe;
            }
            puVar6 = *(undefined4 **)(param_2 + -4);
            if (((uint)puVar6 & 1) != 0) {
              puVar6 = in_t0;
              FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x231,
                           PTR_s_block_trim_used_403751cc,
                           PTR_s__block_is_free_block______block_m_403751c8);
              in_t0 = puVar6;
            }
            puVar7 = (undefined *)((uint)puVar6 & 0xfffffffc);
            iVar1 = param_2;
            if (puVar3 + 0x10 <= puVar7) {
              puVar4 = puVar3 + param_2 + -4;
              puVar5 = (undefined4 *)(puVar7 + (-4 - (int)puVar3));
              puVar6 = (undefined4 *)(puVar4 + 8);
              if ((undefined4 *)(puVar4 + 8) != (undefined4 *)((uint)(puVar4 + 0xb) & 0xfffffffc)) {
                puVar5 = in_t0;
                puVar7 = (undefined *)
                         FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1c4,
                                      PTR_s_block_split_403751ac,
                                      PTR_s_block_to_ptr_remaining_____align_403751a8);
                puVar6 = puVar5;
                in_t0 = puVar5;
              }
              if (puVar7 != puVar3 + (int)puVar5 + 4) {
                puVar5 = in_t0;
                FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1c7,
                             PTR_s_block_split_403751ac,
                             PTR_s_block_size_block_____remain_size_403751b0);
                puVar6 = puVar5;
                in_t0 = puVar5;
              }
              *(uint *)(puVar4 + 4) = (uint)puVar5 | *(uint *)(puVar4 + 4) & 3;
              if (((uint)puVar5 & 0xfffffffc) < 0xc) {
                puVar6 = in_t0;
                FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1c9,
                             PTR_s_block_split_403751ac,
                             PTR_s_block_size_remaining__>__block_s_403751b4);
                in_t0 = puVar6;
              }
              *(uint *)(param_2 + -4) = (uint)puVar3 | *(uint *)(param_2 + -4) & 3;
              puVar5 = (undefined4 *)((int)puVar6 + ((*(uint *)(puVar4 + 4) & 0xfffffffc) - 4));
              if (*(uint *)(puVar4 + 4) < 4) {
                puVar5 = in_t0;
                FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                             PTR_s_block_next_40375138,PTR_s__block_is_last_block__40375134);
                puVar6 = puVar5;
                in_t0 = puVar5;
              }
              *puVar5 = puVar4;
              puVar5[1] = puVar5[1] | 2;
              uVar11 = *(uint *)(puVar4 + 4);
              *(uint *)(puVar4 + 4) = uVar11 | 1;
              uVar2 = uVar11 & 0xfffffffd | 1;
              *(uint *)(puVar4 + 4) = uVar2;
              puVar10 = (undefined *)((int)puVar6 + ((uVar11 & 0xfffffffc) - 4));
              puVar7 = puVar10;
              if (uVar2 < 4) {
                puVar7 = PTR_s_block_next_40375138;
                puVar6 = in_t0;
                puVar10 = (undefined *)
                          FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                                       PTR_s_block_next_40375138,
                                       PTR_s__block_is_last_block__40375134);
                in_t0 = puVar6;
              }
              if (puVar10 == (undefined *)0x0) {
                puVar7 = PTR_s_block_merge_next_4037516c;
                puVar6 = in_t0;
                puVar10 = (undefined *)
                          FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x215,
                                       PTR_s_block_merge_next_4037516c,
                                       PTR_s_next_____next_physical_block_can_40375168);
                in_t0 = puVar6;
              }
              if ((*(uint *)(puVar10 + 4) & 1) != 0) {
                uVar2 = *(uint *)(puVar10 + 4) & 0xfffffffc;
                uVar11 = *(uint *)(param_1 + 0x10) >> 0x17 & 0xff;
                if (uVar2 < uVar11) {
                  uVar2 = (int)uVar2 / (int)(uVar11 / (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f));
                  uVar11 = 0;
                }
                else {
                  if (uVar2 == 0) {
                    iVar8 = 0;
                  }
                  else {
                    iVar8 = -(LZCOUNT(uVar2) + -0x20);
                  }
                  uVar11 = *(uint *)(param_1 + 0x10) >> 0x14;
                  uVar2 = uVar2 >> ((iVar8 + -1) - (uVar11 & 7) & 0x1f) ^
                          1 << 0x20 - (0x20 - (uVar11 & 7));
                  uVar11 = iVar8 - (*(uint *)(param_1 + 0x10) >> 5 & 7);
                }
                uVar13 = CONCAT44(uVar2,puVar10);
                puVar5 = *(undefined4 **)(puVar10 + 0xc);
                puVar10 = *(undefined **)(puVar10 + 8);
                if (puVar5 == (undefined4 *)0x0) {
                  puVar7 = PTR_s_remove_free_block_40375154;
                  puVar10 = PTR_s_prev_____prev_free_field_can_not_40375150;
                  puVar5 = in_t0;
                  uVar13 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x174)
                  ;
                  puVar6 = puVar5;
                  in_t0 = puVar5;
                }
                if (puVar10 == (undefined *)0x0) {
                  puVar7 = PTR_s_remove_free_block_40375154;
                  puVar10 = PTR_s_next_____next_free_field_can_not_40375158;
                  puVar5 = in_t0;
                  uVar13 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x175)
                  ;
                  puVar6 = puVar5;
                  in_t0 = puVar5;
                }
                uVar2 = (uint)((ulonglong)uVar13 >> 0x20);
                iVar8 = (int)uVar13;
                *(undefined4 **)(puVar10 + 0xc) = puVar5;
                puVar5[2] = puVar10;
                puVar5 = (undefined4 *)
                         (((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * uVar11 + uVar2) * 4 +
                         *(int *)(param_1 + 0x20));
                if (((puVar7 == (undefined *)*puVar5) && (*puVar5 = puVar10, puVar10 == param_1)) &&
                   (puVar9 = (uint *)(*(int *)(param_1 + 0x1c) + uVar11 * 4), uVar12 = *puVar9,
                   *puVar9 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f)) & uVar12 ^ uVar12,
                   *(int *)(*(int *)(param_1 + 0x1c) + uVar11 * 4) == 0)) {
                  *(uint *)(param_1 + 0x18) =
                       1 << 0x20 - (0x20 - (uVar11 & 0x1f)) & *(uint *)(param_1 + 0x18) ^
                       *(uint *)(param_1 + 0x18);
                }
                puVar5 = *(undefined4 **)(puVar4 + 4);
                if (puVar5 < (undefined4 *)0x4) {
                  puVar5 = in_t0;
                  iVar8 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x1f5,
                                       PTR_s_block_absorb_40375160,
                                       PTR_s__block_is_last_prev______previou_4037515c);
                  puVar6 = puVar5;
                  in_t0 = puVar5;
                }
                puVar7 = (undefined *)((int)puVar5 + (*(uint *)(iVar8 + 4) & 0xfffffffc) + 4);
                *(undefined **)(puVar4 + 4) = puVar7;
                puVar6 = (undefined4 *)((int)puVar6 + (((uint)puVar7 & 0xfffffffc) - 4));
                if (puVar7 < (undefined *)0x4) {
                  puVar6 = in_t0;
                  iVar8 = FUN_40381d9c(PTR_s_tlsf_block_functions_h_3c030d80_0x1b_4037513c,0xa1,
                                       PTR_s_block_next_40375138,
                                       PTR_s__block_is_last_block__40375134);
                  in_t0 = puVar6;
                }
                *puVar6 = puVar4;
                if (DAT_40375164 != (code *)0x0) {
                  (*DAT_40375164)(iVar8,0x10,1);
                }
              }
              uVar11 = *(uint *)(puVar4 + 4) & 0xfffffffc;
              uVar2 = *(uint *)(param_1 + 0x10) >> 0x17 & 0xff;
              if (uVar11 < uVar2) {
                puVar6 = (undefined4 *)
                         ((int)uVar11 / (int)(uVar2 / (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)));
                uVar11 = 0;
              }
              else {
                if (uVar11 == 0) {
                  iVar8 = 0;
                }
                else {
                  iVar8 = -(LZCOUNT(uVar11) + -0x20);
                }
                uVar2 = *(uint *)(param_1 + 0x10) >> 0x14;
                puVar6 = (undefined4 *)
                         (uVar11 >> ((iVar8 + -1) - (uVar2 & 7) & 0x1f) ^
                         1 << 0x20 - (0x20 - (uVar2 & 7)));
                uVar11 = iVar8 - (*(uint *)(param_1 + 0x10) >> 5 & 7);
              }
              puVar5 = *(undefined4 **)
                        ((int)((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * uVar11 + (int)puVar6) * 4
                        + *(int *)(param_1 + 0x20));
              if (puVar5 == (undefined4 *)0x0) {
                puVar6 = in_t0;
                uVar11 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,400,
                                      PTR_s_insert_free_block_40375174,
                                      PTR_s_current_____free_list_cannot_hav_40375170);
                puVar5 = puVar6;
                in_t0 = puVar6;
              }
              if (puVar4 == (undefined *)0x0) {
                puVar6 = in_t0;
                uVar11 = FUN_40381d9c(PTR_s_tlsf_control_functions_h_3c030e58_0x1b_40375148,0x191,
                                      PTR_s_insert_free_block_40375174,
                                      PTR_s_block_____cannot_insert_a_null_e_40375178);
                puVar5 = puVar6;
              }
              *(undefined4 **)(puVar4 + 8) = puVar5;
              *(undefined **)(puVar4 + 0xc) = param_1;
              puVar5[3] = puVar4;
              *(undefined **)
               ((int)((int)puVar6 + uVar11 * (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)) * 4 +
               *(int *)(param_1 + 0x20)) = puVar4;
              *(uint *)(param_1 + 0x18) =
                   *(uint *)(param_1 + 0x18) | 1 << 0x20 - (0x20 - (uVar11 & 0x1f));
              puVar9 = (uint *)(uVar11 * 4 + *(int *)(param_1 + 0x1c));
              *puVar9 = *puVar9 | 1 << 0x20 - (0x20 - ((uint)puVar6 & 0x1f));
            }
          }
        }
        else {
          iVar1 = 0;
        }
      }
    }
  }
  else {
    FUN_40380984(param_1,param_2);
    iVar1 = 0;
  }
  return iVar1;
}