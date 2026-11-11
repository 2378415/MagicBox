// 42026878  FUN_42026878  FUN_42026878  size=404
// strings: tlsf_add_pool: Memory size must be between %u an | current && 'free list cannot have a null entry' | tlsf_control_functions.h | insert_free_block | block && 'cannot insert a null entry into the fr | block_to_ptr(block) == align_ptr(block_to_ptr(bl

uint * FUN_42026878(uint param_1,uint *param_2,int param_3)

{
  int iVar1;
  uint extraout_a3;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *in_t0;
  undefined8 uVar10;
  
  iVar1 = FUN_42026a68();
  uVar2 = param_3 - iVar1 & 0xfffffffc;
  if (((uint)param_2 & 3) == 0) {
    if (0xb < uVar2) {
      if (param_1 == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = 1 << 0x20 - (0x20 - (*(uint *)(param_1 + 0x10) >> 8 & 0x1f));
      }
      if (uVar2 <= uVar8) {
        uVar7 = *param_2;
        uVar8 = uVar2 | uVar7 & 3;
        *param_2 = uVar8;
        *param_2 = uVar8 | 1;
        *param_2 = uVar2 | uVar7 & 1 | 1;
        uVar8 = *(uint *)(param_1 + 0x10) >> 0x17 & 0xff;
        if (uVar2 < uVar8) {
          puVar3 = (uint *)((int)uVar2 / (int)(uVar8 / (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)));
          iVar1 = 0;
        }
        else {
          if (uVar2 == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = -(LZCOUNT(uVar2) + -0x20);
          }
          uVar8 = *(uint *)(param_1 + 0x10) >> 0x14;
          puVar3 = (uint *)(uVar2 >> ((iVar1 + -1) - (uVar8 & 7) & 0x1f) ^
                           1 << 0x20 - (0x20 - (uVar8 & 7)));
          iVar1 = iVar1 - (*(uint *)(param_1 + 0x10) >> 5 & 7);
        }
        iVar5 = *(int *)((int)((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * iVar1 + (int)puVar3) * 4
                        + *(int *)(param_1 + 0x20));
        uVar10 = CONCAT44(iVar1,iVar5);
        puVar6 = param_2 + -1;
        if (iVar5 == 0) {
          puVar3 = in_t0;
          uVar10 = (*(code *)PTR_FUN_42000044)
                             (PTR_s_tlsf_control_functions_h_3c030e58_0x1b_42001524,400,
                              PTR_s_insert_free_block_42001520,
                              PTR_s_current_____free_list_cannot_hav_4200151c);
          puVar6 = puVar3;
          in_t0 = puVar3;
        }
        if (param_2 == (uint *)0x4) {
          puVar3 = in_t0;
          uVar10 = (*(code *)PTR_FUN_42000044)
                             (PTR_s_tlsf_control_functions_h_3c030e58_0x1b_42001524,0x191,
                              PTR_s_insert_free_block_42001520,
                              PTR_s_block_____cannot_insert_a_null_e_42001528);
          puVar6 = puVar3;
          in_t0 = puVar3;
        }
        uVar2 = (uint)((ulonglong)uVar10 >> 0x20);
        puVar6[2] = (uint)uVar10;
        puVar6[3] = param_1;
        *(uint **)((uint)uVar10 + 0xc) = puVar6;
        puVar4 = puVar6 + 2;
        if (puVar4 != (uint *)((uint)((int)puVar6 + 0xb) & 0xfffffffc)) {
          puVar4 = (uint *)PTR_s_insert_free_block_42001520;
          puVar3 = in_t0;
          (*(code *)PTR_FUN_42000044)
                    (PTR_s_tlsf_control_functions_h_3c030e58_0x1b_42001524,0x196,
                     PTR_s_insert_free_block_42001520,
                     PTR_s_block_to_ptr_block_____align_ptr_4200152c);
          puVar6 = puVar3;
          uVar2 = extraout_a3;
          in_t0 = puVar3;
        }
        *(uint **)((int)((int)puVar3 + uVar2 * (*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)) * 4 +
                  *(int *)(param_1 + 0x20)) = puVar6;
        *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
        puVar9 = (uint *)(uVar2 * 4 + *(int *)(param_1 + 0x1c));
        *puVar9 = *puVar9 | 1 << 0x20 - (0x20 - ((uint)puVar3 & 0x1f));
        puVar4 = (uint *)(((puVar6[1] & 0xfffffffc) - 4) + (int)puVar4);
        if (puVar6[1] < 4) {
          puVar4 = in_t0;
          (*(code *)PTR_FUN_42000044)
                    (PTR_s_tlsf_block_functions_h_3c030d80_0x1b_42001510,0xa1,
                     PTR_s_block_next_4200150c,PTR_s__block_is_last_block__42001508);
          puVar6 = puVar4;
        }
        *puVar4 = (uint)puVar6;
        uVar2 = puVar4[1];
        puVar4[1] = uVar2 & 3;
        puVar4[1] = uVar2 & 2;
        puVar4[1] = 2;
        return param_2;
      }
    }
    iVar5 = 0;
    if (param_1 != 0) {
      iVar5 = 1 << 0x20 - (0x20 - (*(uint *)(param_1 + 0x10) >> 8 & 0x1f));
    }
    FUN_42017abc(PTR_s_tlsf_add_pool__Memory_size_must_b_42001518,iVar1 + 0xc,iVar1 + iVar5);
  }
  else {
    FUN_42017abc(PTR_s_tlsf_add_pool__Memory_must_be_al_42001514,4);
  }
  return (uint *)0x0;
}


