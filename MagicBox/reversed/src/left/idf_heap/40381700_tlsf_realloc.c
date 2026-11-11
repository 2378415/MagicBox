// strings: !block_is_last(block) | tlsf_block_functions.h | block_next | !block_is_free(block) && 'block already marked a | tlsf_realloc | tlsf_control_functions.h | remove_free_block | prev && 'prev_free field can not be null' | next && 'next_free field can not be null' | ree_block | block_absorb | !block_is_last(prev) && 'previous block can't be | block_to_ptr(remaining) == align_ptr(block_to_pt | block_size(block) == remain_size + size + block_ | block_split | block_size(remaining) >= block_size_min && 'bloc

int FUN_40381700(uint param_1,int param_2,uint param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint extraout_a3;
  int extraout_a3_00;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined *puVar12;
  undefined *puVar13;
  int iVar14;
  uint in_t0;
  ulonglong uVar15;
  undefined8 uVar16;
  
  if (param_2 == 0) {
LAB_40381718:
    iVar2 = FUN_40380e44(param_1,param_3);
    return iVar2;
  }
  if (param_3 == 0) {
    FUN_40380ac0(param_1,param_2);
  }
  else {
    if (param_2 == 0) goto LAB_40381718;
    uVar5 = param_2 - 8;
    uVar6 = *(uint *)(param_2 + -4);
    uVar3 = param_1;
    if (3 < uVar6) goto LAB_4038173f;
LAB_40381730:
    uVar6 = in_t0;
    FUN_40381ce4(PTR_s_tlsf_block_functions_h_3c0331e0_0x1b_403751f4,0xa1,PTR_s_block_next_403751f0,
                 PTR_s__block_is_last_block__403751ec);
    in_t0 = uVar6;
LAB_4038173f:
    if (param_3 != 0) {
      uVar11 = 0xfffffffc;
      uVar8 = param_3 + 3 & 0xfffffffc;
      if ((uVar3 != 0) &&
         (puVar12 = *(undefined **)(uVar3 + 0x10),
         uVar8 < (uint)(1 << 0x20 - (0x20 - ((uint)puVar12 >> 8 & 0x1f))))) {
        uVar3 = (uint)(uVar8 < 0xc) * 0xc + (uVar8 >= 0xc) * uVar8;
        if ((uVar6 & 1) != 0) {
          puVar12 = PTR_s_tlsf_realloc_40375278;
          uVar6 = in_t0;
          FUN_40381ce4(PTR_s_tlsf_c_3c033380_0x1b_403751e8,0x2a8,PTR_s_tlsf_realloc_40375278,
                       PTR_s__block_is_free_block______block_a_403751e0);
          uVar11 = extraout_a3;
          in_t0 = uVar6;
        }
        uVar4 = uVar6 & uVar11;
        uVar8 = param_2 - 4;
        if (uVar3 <= uVar4) goto LAB_403818d8;
        iVar2 = uVar4 + uVar8;
        uVar11 = *(uint *)(iVar2 + 4) & uVar11;
        uVar15 = CONCAT44(uVar11,iVar2);
        if ((uVar4 + 4 + uVar11 < uVar3) || ((*(uint *)(iVar2 + 4) & 1) == 0)) {
          iVar2 = FUN_40380e44(param_1,param_3);
          if (iVar2 == 0) {
            return 0;
          }
          (*DAT_4037450c)(iVar2,param_2,(param_3 < uVar4) * param_3 + (param_3 >= uVar4) * uVar4);
          FUN_40380ac0(param_1,param_2);
          return iVar2;
        }
        uVar4 = (uint)puVar12 >> 0x17 & 0xff;
        if (uVar11 < uVar4) {
          puVar13 = (undefined *)((int)uVar11 / (int)(uVar4 / ((uint)puVar12 >> 0xe & 0x3f)));
          uVar11 = 0;
        }
        else {
          if (uVar11 == 0) {
            iVar14 = -1;
            iVar10 = 0;
          }
          else {
            iVar10 = -(LZCOUNT(uVar11) + -0x20);
            iVar14 = -(LZCOUNT(uVar11) + -0x1f);
          }
          puVar13 = (undefined *)
                    (uVar11 >> (iVar14 - ((uint)puVar12 >> 0x14 & 7) & 0x1f) ^
                    1 << 0x20 - (0x20 - ((uint)puVar12 >> 0x14 & 7)));
          uVar11 = iVar10 - ((uint)puVar12 >> 5 & 7);
        }
        puVar12 = *(undefined **)(iVar2 + 0xc);
        uVar9 = *(uint *)(iVar2 + 8);
        if (puVar12 != (undefined *)0x0) goto LAB_40381817;
LAB_40381805:
        uVar6 = in_t0;
        puVar12 = PTR_s_remove_free_block_4037520c;
        puVar13 = PTR_s_prev_____prev_free_field_can_not_40375208;
        uVar15 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x174);
        uVar8 = uVar6;
        in_t0 = uVar6;
LAB_40381817:
        if (uVar9 == 0) goto LAB_40381819;
LAB_40381828:
        uVar4 = (uint)uVar15;
        *(undefined **)(uVar9 + 0xc) = puVar12;
        *(uint *)(puVar12 + 8) = uVar9;
        puVar7 = (uint *)((int)(puVar13 + (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * uVar11) * 4 +
                         *(int *)(param_1 + 0x20));
        if ((uVar4 == *puVar7) && (*puVar7 = uVar9, uVar9 == param_1)) {
          puVar7 = (uint *)(uVar11 * 4 + *(int *)(param_1 + 0x1c));
          uVar6 = *puVar7;
          uVar6 = 1 << 0x20 - (0x20 - ((uint)puVar13 & 0x1f)) & uVar6 ^ uVar6;
          *puVar7 = uVar6;
          if (uVar6 == 0) {
            *(uint *)(param_1 + 0x18) =
                 1 << 0x20 - (0x20 - (uVar11 & 0x1f)) & *(uint *)(param_1 + 0x18) ^
                 *(uint *)(param_1 + 0x18);
          }
          uVar6 = *(uint *)(uVar5 + 4);
          if (uVar6 < 4) goto LAB_40381874;
          goto LAB_40381883;
        }
        do {
          uVar6 = uVar6 + (int)(uVar15 >> 0x20) + 4;
          *(uint *)(uVar5 + 4) = uVar6;
          pcVar1 = DAT_4037521c;
          puVar7 = (uint *)((uVar6 & 0xfffffffc) + uVar8);
          if (uVar6 < 4) goto LAB_40381730;
          *puVar7 = uVar5;
          if (pcVar1 != (code *)0x0) {
            (*DAT_4037521c)((int)uVar15,0x10,1);
            puVar7 = (uint *)((*(uint *)(uVar5 + 4) & 0xfffffffc) + uVar8);
            if (*(uint *)(uVar5 + 4) < 4) goto LAB_40381730;
          }
          puVar7[1] = puVar7[1] & 0xfffffffd;
          uVar4 = *(uint *)(uVar5 + 4);
          *(uint *)(uVar5 + 4) = uVar4 & 0xfffffffe;
          uVar4 = uVar4 & 0xfffffffc;
LAB_403818d8:
          if (uVar4 < uVar3 + 0x10) {
            return param_2;
          }
          param_3 = uVar3 + uVar8;
          uVar9 = 0xfffffffc;
          uVar16 = CONCAT44(param_3 + 8,uVar4 - (uVar3 + 4));
          if (param_3 + 8 != (param_3 + 0xb & 0xfffffffc)) {
            uVar9 = in_t0;
            uVar16 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x1c4,
                                  PTR_s_block_split_40375260,
                                  PTR_s_block_to_ptr_remaining_____align_4037525c);
            in_t0 = uVar9;
          }
          if (uVar3 + 4 + (int)uVar16 != uVar4) {
            uVar9 = in_t0;
            uVar16 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x1c7,
                                  PTR_s_block_split_40375260,
                                  PTR_s_block_size_block_____remain_size_40375264);
            in_t0 = uVar9;
          }
          iVar2 = (int)((ulonglong)uVar16 >> 0x20);
          uVar6 = *(uint *)(param_3 + 4) & 3 | (uint)uVar16;
          *(uint *)(param_3 + 4) = uVar6;
          if ((uVar6 & uVar9) < 0xc) {
            uVar9 = in_t0;
            FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x1c9,
                         PTR_s_block_split_40375260,PTR_s_block_size_remaining__>__block_s_40375268)
            ;
            iVar2 = extraout_a3_00;
            in_t0 = uVar9;
          }
          *(uint *)(uVar5 + 4) = *(uint *)(uVar5 + 4) & 3 | uVar3;
          puVar7 = (uint *)((*(uint *)(param_3 + 4) & uVar9) + iVar2);
          if (*(uint *)(param_3 + 4) < 4) goto LAB_40381730;
          *puVar7 = *puVar7 | 2;
          uVar11 = *(uint *)(param_3 + 4);
          puVar7[-1] = param_3;
          uVar6 = uVar11 & 0xfffffffd | 1;
          uVar11 = uVar11 & uVar9;
          *(uint *)(param_3 + 4) = uVar6;
          iVar10 = iVar2 + uVar11 + -4;
          uVar16 = CONCAT44(iVar2,iVar10);
          if (uVar6 < 4) goto LAB_40381730;
          if (iVar10 == 0) {
            uVar6 = in_t0;
            uVar16 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x215,
                                  PTR_s_block_merge_next_40375224,
                                  PTR_s_next_____next_physical_block_can_40375220);
            uVar9 = uVar6;
            in_t0 = uVar6;
          }
          uVar8 = (uint)uVar16;
          if ((*(uint *)(uVar8 + 4) & 1) == 0) {
LAB_40381a79:
            uVar6 = *(uint *)(param_1 + 0x10);
            puVar12 = *(undefined **)(param_1 + 0x20);
            uVar3 = uVar6 >> 0x17 & 0xff;
            if (uVar3 <= uVar11) {
              iVar10 = -1;
              iVar2 = 0;
              if (uVar11 != 0) {
LAB_40381a9d:
                iVar2 = -(LZCOUNT(uVar11) + -0x20);
                iVar10 = -(LZCOUNT(uVar11) + -0x1f);
              }
              uVar5 = iVar2 - (uVar6 >> 5 & 7);
              uVar3 = uVar11 >> (iVar10 - (uVar6 >> 0x14 & 7) & 0x1f) ^
                      1 << 0x20 - (0x20 - (uVar6 >> 0x14 & 7));
              uVar11 = (uVar6 >> 0xe & 0x3f) * uVar5 + uVar3;
              goto LAB_40381ad3;
            }
LAB_40381a83:
            uVar11 = (int)uVar11 / (int)(uVar3 / (uVar6 >> 0xe & 0x3f));
            uVar5 = 0;
            uVar3 = uVar11;
LAB_40381ad3:
            uVar6 = *(uint *)(puVar12 + uVar11 * 4);
            if (uVar6 == 0) {
              puVar12 = PTR_s_current_____free_list_cannot_hav_40375228;
              uVar6 = in_t0;
              uVar5 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,400,
                                   PTR_s_insert_free_block_4037522c);
              uVar3 = uVar6;
            }
            *(uint *)(param_3 + 8) = uVar6;
            *(uint *)(param_3 + 0xc) = param_1;
            *(uint *)(uVar6 + 0xc) = param_3;
            uVar6 = *(uint *)(param_1 + 0x18);
            iVar2 = *(int *)(param_1 + 0x1c);
            *(uint *)(puVar12 + ((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * uVar5 + uVar3) * 4) =
                 param_3;
            *(uint *)(param_1 + 0x18) = uVar6 | 1 << 0x20 - (0x20 - (uVar5 & 0x1f));
            puVar7 = (uint *)(uVar5 * 4 + iVar2);
            *puVar7 = *puVar7 | 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
            return param_2;
          }
          uVar11 = *(uint *)(param_1 + 0x10);
          uVar9 = *(uint *)(uVar8 + 4) & uVar9;
          uVar5 = uVar11 >> 0x17 & 0xff;
          if (uVar9 < uVar5) {
            uVar4 = (int)uVar9 / (int)(uVar5 / (uVar11 >> 0xe & 0x3f));
            uVar11 = 0;
          }
          else {
            if (uVar9 == 0) {
              iVar2 = -1;
              iVar10 = 0;
            }
            else {
              iVar10 = -(LZCOUNT(uVar9) + -0x20);
              iVar2 = -(LZCOUNT(uVar9) + -0x1f);
            }
            uVar4 = uVar9 >> (iVar2 - (uVar11 >> 0x14 & 7) & 0x1f) ^
                    1 << 0x20 - (0x20 - (uVar11 >> 0x14 & 7));
            uVar11 = iVar10 - (uVar11 >> 5 & 7);
          }
          iVar2 = *(int *)(uVar8 + 0xc);
          uVar5 = *(uint *)(uVar8 + 8);
          if (iVar2 == 0) goto LAB_40381805;
          if (uVar5 == 0) goto LAB_40381819;
          *(int *)(uVar5 + 0xc) = iVar2;
          *(uint *)(iVar2 + 8) = uVar5;
          puVar12 = *(undefined **)(param_1 + 0x20);
          if ((uVar8 != *(uint *)(puVar12 +
                                 ((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * uVar11 + uVar4) * 4))
             || (*(uint *)(puVar12 +
                          ((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * uVar11 + uVar4) * 4) = uVar5,
                uVar5 != param_1)) {
LAB_40381a4d:
            uVar6 = uVar6 + uVar9 + 4;
            uVar5 = 0xfffffffc;
            uVar11 = uVar6 & 0xfffffffc;
            *(uint *)(param_3 + 4) = uVar6;
            pcVar1 = DAT_4037521c;
            if (3 < uVar6) {
              *(uint *)((int)((ulonglong)uVar16 >> 0x20) + -4 + uVar11) = param_3;
              if (pcVar1 != (code *)0x0) {
                (*DAT_4037521c)(uVar8,0x10,1);
                uVar11 = *(uint *)(param_3 + 4) & 0xfffffffc;
                goto LAB_40381a79;
              }
              uVar6 = *(uint *)(param_1 + 0x10);
              uVar3 = uVar6 >> 0x17 & 0xff;
              if (uVar3 <= uVar11) goto LAB_40381a9d;
              goto LAB_40381a83;
            }
            goto LAB_40381730;
          }
          puVar7 = (uint *)(uVar11 * 4 + *(int *)(param_1 + 0x1c));
          uVar5 = *puVar7;
          uVar6 = 1 << 0x20 - (0x20 - (uVar4 & 0x1f)) & uVar5 ^ uVar5;
          *puVar7 = uVar6;
          if (uVar6 == 0) {
            *(uint *)(param_1 + 0x18) =
                 1 << 0x20 - (0x20 - (uVar11 & 0x1f)) & *(uint *)(param_1 + 0x18) ^
                 *(uint *)(param_1 + 0x18);
          }
          uVar6 = *(uint *)(param_3 + 4);
          if (3 < uVar6) {
            uVar9 = *(uint *)(uVar8 + 4) & 0xfffffffc;
            goto LAB_40381a4d;
          }
LAB_40381874:
          uVar6 = in_t0;
          uVar4 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x1f5,
                               PTR_s_block_absorb_40375218,
                               PTR_s__block_is_last_prev______previou_40375214);
          uVar8 = uVar6;
          in_t0 = uVar6;
LAB_40381883:
          uVar15 = CONCAT44(*(undefined4 *)(uVar4 + 4),uVar4) & 0xfffffffcffffffff;
        } while( true );
      }
    }
  }
  return 0;
LAB_40381819:
  uVar6 = in_t0;
  puVar12 = PTR_s_remove_free_block_4037520c;
  puVar13 = PTR_s_next_____next_free_field_can_not_40375210;
  uVar15 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x175);
  uVar8 = uVar6;
  in_t0 = uVar6;
  goto LAB_40381828;
}