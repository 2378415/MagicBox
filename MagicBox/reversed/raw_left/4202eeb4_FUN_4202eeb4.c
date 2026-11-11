// 4202eeb4  FUN_4202eeb4  FUN_4202eeb4  size=284
// strings: ,878 | ALIGN_SIZE == control->small_block_size / contro

uint FUN_4202eeb4(uint param_1,uint param_2)

{
  int extraout_a3;
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  
  if (param_1 != 0) {
    if ((param_1 & 3) == 0) {
      if (0x23 < param_2) {
        uVar5 = -(LZCOUNT(param_2) + -0x20) & 0xff;
        if (DAT_42000a44 < param_2) {
          if (DAT_42000528 < param_2) {
            uVar4 = 0x20;
            iVar8 = 0x80;
            iVar11 = 5;
            uVar10 = 0x80;
            iVar2 = 0xfa;
            iVar6 = 0x20;
            iVar1 = 7;
          }
          else {
            uVar4 = 0x10;
            iVar8 = 0x40;
            iVar11 = 4;
            uVar10 = 0x40;
            iVar2 = 0xfb;
            iVar6 = 0x10;
            iVar1 = 6;
          }
        }
        else {
          uVar4 = 8;
          iVar8 = 0x20;
          iVar11 = 3;
          uVar10 = 0x20;
          iVar2 = 0xfc;
          iVar6 = 8;
          iVar1 = 5;
        }
        uVar3 = uVar5 + iVar2 & 0xff;
        iVar2 = ((int)(short)uVar3 * (int)(short)uVar4 + uVar3 + 9) * 4;
        *(int *)(param_1 + 0x14) = iVar2;
        *(uint *)(param_1 + 0x10) =
             iVar1 << 5 | uVar3 | uVar5 << 8 | iVar6 << 0xe | iVar11 << 0x14 | iVar8 << 0x17 |
             *(uint *)(param_1 + 0x10) & 0x80000000;
        if (iVar2 + 0xcU <= param_2) {
          puVar9 = (uint *)(param_1 + 0x27 & 0xfffffffc);
          puVar7 = puVar9 + uVar3;
          iVar1 = 0;
          *(uint *)(param_1 + 8) = param_1;
          *(uint *)(param_1 + 0xc) = param_1;
          *(undefined4 *)(param_1 + 0x18) = 0;
          *(uint **)(param_1 + 0x1c) = puVar9;
          *(uint **)(param_1 + 0x20) = puVar7;
          uVar10 = uVar10 / uVar4;
          if (uVar10 == 4) {
            uVar10 = 0;
            if (uVar3 == 0) {
              return param_1;
            }
          }
          else {
            puVar7 = (uint *)PTR_s_control_construct_42001fb8;
            puVar9 = (uint *)PTR_s_ALIGN_SIZE____control_>small_blo_42001fb4;
            (*(code *)PTR_FUN_420000a8)(PTR_s_tlsf_c_3c033380_0x1b_42001fbc,0x4e);
            iVar1 = extraout_a3;
          }
          do {
            *puVar9 = uVar10;
            uVar4 = *(uint *)(param_1 + 0x10);
            iVar2 = 0;
            uVar5 = uVar4 >> 0xe & 0x3f;
            if (uVar5 != 0) {
              do {
                puVar7[(int)(short)iVar1 * (int)(short)uVar5 + iVar2 & 0xffff] = param_1;
                uVar4 = *(uint *)(param_1 + 0x10);
                iVar2 = iVar2 + 1;
                uVar5 = uVar4 >> 0xe & 0x3f;
              } while (iVar2 < (int)uVar5);
            }
            iVar1 = iVar1 + 1;
            puVar9 = puVar9 + 1;
          } while (iVar1 < (int)(uVar4 & 0x1f));
          return param_1;
        }
      }
    }
    else {
      FUN_420204ec(PTR_s_tlsf_create__Memory_must_be_alig_42001fb0,4);
    }
  }
  return 0;
}


