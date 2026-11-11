// strings: !block_is_free(block) && 'block already marked a | !block_is_last(block) | tlsf_block_functions.h | block_next | prev && 'prev physical block can't be null' | block_is_free(prev) && 'prev block is not free t | tlsf_control_functions.h | block_merge_prev | remove_free_block | prev && 'prev_free field can not be null' | next && 'next_free field can not be null' | block | block_absorb | !block_is_last(prev) && 'previous block can't be | `v V | next && 'next physical block can't be null' | block_merge_next

void FUN_40380ac0(undefined *param_1,int *param_2,undefined4 param_3,undefined4 param_4,int *param_5
                 )

{
  code *pcVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined *puVar11;
  int iVar12;
  undefined *puVar13;
  int *piVar14;
  undefined4 *in_t0;
  undefined8 uVar15;
  ulonglong uVar16;
  
  if (param_2 == (int *)0x0) {
    return;
  }
  piVar3 = param_2 + -2;
  puVar7 = (undefined4 *)param_2[-1];
  piVar2 = piVar3;
  if (((uint)puVar7 & 1) != 0) {
    puVar7 = in_t0;
    piVar2 = (int *)FUN_40381ce4(PTR_s_tlsf_c_3c033380_0x1b_403751e8,0x275,PTR_s_tlsf_free_403751e4,
                                 PTR_s__block_is_free_block______block_a_403751e0);
    in_t0 = puVar7;
  }
  puVar13 = (undefined *)0xfffffffc;
  piVar14 = param_2 + -1;
  puVar4 = (undefined4 *)((int)piVar14 + ((uint)puVar7 & 0xfffffffc));
  if ((undefined4 *)0x3 < puVar7) goto LAB_40380afb;
LAB_40380aec:
  do {
    puVar4 = in_t0;
    puVar13 = PTR_s_block_next_403751f0;
    piVar2 = (int *)FUN_40381ce4(PTR_s_tlsf_block_functions_h_3c0331e0_0x1b_403751f4,0xa1,
                                 PTR_s_block_next_403751f0,PTR_s__block_is_last_block__403751ec);
    in_t0 = puVar4;
LAB_40380afb:
    puVar4[1] = puVar4[1] | 2;
    uVar10 = piVar2[1];
    *puVar4 = piVar2;
    uVar5 = uVar10 | 1;
    piVar2[1] = uVar5;
    if ((uVar10 & 2) != 0) {
      param_5 = (int *)*piVar2;
      if (param_5 == (int *)0x0) {
        puVar13 = PTR_s_block_merge_prev_403751fc;
        piVar2 = (int *)FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x208,
                                     PTR_s_block_merge_prev_403751fc,
                                     PTR_s_prev_____prev_physical_block_can_403751f8);
      }
      uVar15 = CONCAT44(param_5[1],piVar2);
      if ((param_5[1] & 1U) == 0) {
        puVar13 = PTR_s_block_merge_prev_403751fc;
        uVar15 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x209,
                              PTR_s_block_merge_prev_403751fc,
                              PTR_s_block_is_free_prev______prev_blo_40375204);
      }
      uVar5 = *(uint *)(param_1 + 0x10);
      uVar10 = (uint)((ulonglong)uVar15 >> 0x20) & (uint)puVar13;
      uVar8 = uVar5 >> 0x17 & 0xff;
      if (uVar10 < uVar8) {
        puVar7 = (undefined4 *)((int)uVar10 / (int)(uVar8 / (uVar5 >> 0xe & 0x3f)));
        puVar13 = (undefined *)0x0;
      }
      else {
        if (uVar10 == 0) {
          iVar12 = -1;
          iVar9 = 0;
        }
        else {
          iVar9 = -(LZCOUNT(uVar10) + -0x20);
          iVar12 = -(LZCOUNT(uVar10) + -0x1f);
        }
        puVar7 = (undefined4 *)
                 (uVar10 >> (iVar12 - (uVar5 >> 0x14 & 7) & 0x1f) ^
                 1 << 0x20 - (0x20 - (uVar5 >> 0x14 & 7)));
        puVar13 = (undefined *)(iVar9 - (uVar5 >> 5 & 7));
      }
      puVar4 = (undefined4 *)param_5[3];
      puVar11 = (undefined *)param_5[2];
      if (puVar4 != (undefined4 *)0x0) goto LAB_40380ba3;
      goto LAB_40380b91;
    }
    while( true ) {
      puVar7 = (undefined4 *)((uVar5 & 0xfffffffc) + (int)piVar14);
      if (uVar5 < 4) break;
      do {
        if (puVar7 == (undefined4 *)0x0) {
          puVar7 = (undefined4 *)PTR_s_next_____next_physical_block_can_40375220;
          FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x215,
                       PTR_s_block_merge_next_40375224);
        }
        if ((puVar7[1] & 1) == 0) {
          puVar13 = *(undefined **)(param_1 + 0x20);
          piVar14 = (int *)(piVar3[1] & 0xfffffffc);
LAB_40380e22:
          uVar5 = *(uint *)(param_1 + 0x10);
          piVar2 = (int *)(uVar5 >> 0x17 & 0xff);
          if (piVar2 <= piVar14) {
LAB_40380d7a:
            iVar12 = -(LZCOUNT(piVar14) + -0x20);
            iVar9 = -(LZCOUNT(piVar14) + -0x1f);
LAB_40380d89:
            iVar12 = iVar12 - (uVar5 >> 5 & 7);
            uVar10 = (uint)piVar14 >> (iVar9 - (uVar5 >> 0x14 & 7) & 0x1f) ^
                     1 << 0x20 - (0x20 - (uVar5 >> 0x14 & 7));
            uVar5 = (uVar5 >> 0xe & 0x3f) * iVar12 + uVar10;
            goto LAB_40380dae;
          }
LAB_40380d64:
          uVar5 = (int)piVar14 / (int)((uint)piVar2 / (uVar5 >> 0xe & 0x3f));
          iVar12 = 0;
          uVar10 = uVar5;
LAB_40380dae:
          uVar16 = CONCAT44(iVar12,uVar10);
          puVar7 = *(undefined4 **)(puVar13 + uVar5 * 4);
          if (puVar7 == (undefined4 *)0x0) {
            puVar13 = PTR_s_insert_free_block_4037522c;
            puVar7 = in_t0;
            uVar16 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,400,
                                  PTR_s_insert_free_block_4037522c,
                                  PTR_s_current_____free_list_cannot_hav_40375228);
          }
          piVar3[2] = (int)puVar7;
          piVar3[3] = (int)param_1;
          puVar7[3] = piVar3;
          if (param_2 != (int *)((int)param_2 + 3U & 0xfffffffc)) {
            puVar13 = PTR_s_insert_free_block_4037522c;
            uVar16 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x196,
                                  PTR_s_insert_free_block_4037522c,
                                  PTR_s_block_to_ptr_block_____align_ptr_40375230);
          }
          iVar9 = (int)(uVar16 >> 0x20);
          uVar5 = *(uint *)(param_1 + 0x18);
          iVar12 = *(int *)(param_1 + 0x1c);
          *(int **)(puVar13 + ((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * iVar9 + (int)uVar16) * 4)
               = piVar3;
          *(uint *)(param_1 + 0x18) =
               uVar5 | 1 << 0x20 - (0x20 - (int)((uVar16 & 0x1f0000001f) >> 0x20));
          puVar6 = (uint *)(iVar9 * 4 + iVar12);
          *puVar6 = *puVar6 | 1 << 0x20 - (0x20 - (int)(uVar16 & 0x1f0000001f));
          return;
        }
        uVar5 = *(uint *)(param_1 + 0x10);
        uVar10 = uVar5 >> 0x17 & 0xff;
        uVar8 = puVar7[1] & 0xfffffffc;
        if (uVar8 < uVar10) {
          uVar10 = (int)uVar8 / (int)(uVar10 / (uVar5 >> 0xe & 0x3f));
          piVar14 = (int *)0x0;
        }
        else {
          if (uVar8 == 0) {
            iVar12 = -1;
            iVar9 = 0;
          }
          else {
            iVar9 = -(LZCOUNT(uVar8) + -0x20);
            iVar12 = -(LZCOUNT(uVar8) + -0x1f);
          }
          uVar10 = uVar8 >> (iVar12 - (uVar5 >> 0x14 & 7) & 0x1f) ^
                   1 << 0x20 - (0x20 - (uVar5 >> 0x14 & 7));
          piVar14 = (int *)(iVar9 - (uVar5 >> 5 & 7));
        }
        iVar9 = puVar7[3];
        puVar11 = (undefined *)puVar7[2];
        if (iVar9 == 0) {
LAB_40380b91:
          puVar4 = in_t0;
          puVar11 = PTR_s_remove_free_block_4037520c;
          puVar13 = PTR_s_prev_____prev_free_field_can_not_40375208;
          uVar15 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x174);
          puVar7 = puVar4;
          in_t0 = puVar4;
LAB_40380ba3:
          if (puVar11 == (undefined *)0x0) goto LAB_40380ba5;
LAB_40380bb4:
          uVar5 = (uint)((ulonglong)uVar15 >> 0x20);
          *(undefined4 **)(puVar11 + 0xc) = puVar4;
          puVar4[2] = puVar11;
          puVar4 = (undefined4 *)
                   ((int)((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * (int)puVar13 + (int)puVar7) *
                    4 + *(int *)(param_1 + 0x20));
          piVar14 = (int *)*puVar4;
          if ((param_5 == piVar14) && (*puVar4 = puVar11, puVar11 == param_1)) {
            puVar6 = (uint *)((int)puVar13 * 4 + *(int *)(param_1 + 0x1c));
            piVar14 = (int *)*puVar6;
            uVar5 = 1 << 0x20 - (0x20 - ((uint)puVar7 & 0x1f)) & (uint)piVar14 ^ (uint)piVar14;
            *puVar6 = uVar5;
            if (uVar5 == 0) {
              uVar5 = param_5[1];
              *(uint *)(param_1 + 0x18) =
                   1 << 0x20 - (0x20 - ((uint)puVar13 & 0x1f)) & *(uint *)(param_1 + 0x18) ^
                   *(uint *)(param_1 + 0x18);
            }
            else {
              uVar5 = param_5[1];
            }
          }
          uVar15 = CONCAT44(uVar5,(int)uVar15);
          if (uVar5 < 4) goto LAB_40380c08;
        }
        else {
          if (puVar11 == (undefined *)0x0) {
LAB_40380ba5:
            puVar4 = in_t0;
            puVar11 = PTR_s_remove_free_block_4037520c;
            puVar13 = PTR_s_next_____next_free_field_can_not_40375210;
            uVar15 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x175);
            puVar7 = puVar4;
            in_t0 = puVar4;
            goto LAB_40380bb4;
          }
          *(int *)(puVar11 + 0xc) = iVar9;
          *(undefined **)(iVar9 + 8) = puVar11;
          puVar13 = *(undefined **)(param_1 + 0x20);
          if ((*(undefined4 **)
                (puVar13 + ((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * (int)piVar14 + uVar10) * 4)
               != puVar7) ||
             (*(undefined **)
               (puVar13 + ((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * (int)piVar14 + uVar10) * 4) =
                   puVar11, puVar11 != param_1)) {
            uVar5 = piVar3[1];
LAB_40380d2b:
            uVar5 = uVar5 + uVar8 + 4;
            param_5 = (int *)0xfffffffc;
            piVar14 = (int *)(uVar5 & 0xfffffffc);
            piVar3[1] = uVar5;
            pcVar1 = DAT_4037521c;
            if (3 < uVar5) {
              *(int **)((int)(param_2 + -1) + (int)piVar14) = piVar3;
              if (pcVar1 == (code *)0x0) goto LAB_40380e22;
              (*DAT_4037521c)(puVar7,0x10,1);
              uVar5 = *(uint *)(param_1 + 0x10);
              piVar14 = (int *)(piVar3[1] & 0xfffffffc);
              piVar2 = (int *)(uVar5 >> 0x17 & 0xff);
              puVar13 = *(undefined **)(param_1 + 0x20);
              if (piVar2 <= piVar14) {
                iVar9 = -1;
                iVar12 = 0;
                if (piVar14 != (int *)0x0) goto LAB_40380d7a;
                goto LAB_40380d89;
              }
              goto LAB_40380d64;
            }
            goto LAB_40380aec;
          }
          puVar6 = (uint *)((int)piVar14 * 4 + *(int *)(param_1 + 0x1c));
          uVar5 = *puVar6;
          uVar5 = 1 << 0x20 - (0x20 - (uVar10 & 0x1f)) & uVar5 ^ uVar5;
          *puVar6 = uVar5;
          if (uVar5 == 0) {
            *(uint *)(param_1 + 0x18) =
                 1 << 0x20 - (0x20 - ((uint)piVar14 & 0x1f)) & *(uint *)(param_1 + 0x18) ^
                 *(uint *)(param_1 + 0x18);
          }
          uVar5 = piVar3[1];
          if (3 < uVar5) {
            uVar8 = puVar7[1] & 0xfffffffc;
            goto LAB_40380d2b;
          }
LAB_40380c08:
          uVar15 = FUN_40381ce4(PTR_s_tlsf_control_functions_h_3c0332b8_0x1b_40375200,0x1f5,
                                PTR_s_block_absorb_40375218,
                                PTR_s__block_is_last_prev______previou_40375214);
        }
        uVar5 = (*(uint *)((int)uVar15 + 4) & 0xfffffffc) + 4 + (int)((ulonglong)uVar15 >> 0x20);
        param_5[1] = uVar5;
        pcVar1 = DAT_4037521c;
        param_2 = param_5 + 2;
        puVar7 = (undefined4 *)((int)param_5 + (uVar5 & 0xfffffffc) + 4);
        if (uVar5 < 4) goto LAB_40380aec;
        *puVar7 = param_5;
        piVar3 = param_5;
      } while (pcVar1 == (code *)0x0);
      (*DAT_4037521c)((int)uVar15,0x10,1);
      uVar5 = param_5[1];
      piVar14 = param_5 + 1;
    }
  } while( true );
}