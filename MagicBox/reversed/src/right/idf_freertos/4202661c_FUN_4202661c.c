// strings: tlsf.c | control_construct | ALIGN_SIZE == control->small_block_size / contro

undefined * FUN_4202661c(undefined *param_1,uint param_2)

{
  uint extraout_a3;
  int extraout_a3_00;
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  undefined *puVar7;
  uint uVar8;
  
  if (param_2 < 0x24) {
    param_1 = (undefined *)0x0;
  }
  else {
    *(uint *)(param_1 + 0x10) =
         *(uint *)(param_1 + 0x10) & DAT_420014d4 | (-(LZCOUNT(param_2) + -0x20) & 0x3fU) << 8;
    if (DAT_42000874 < param_2) {
      if (DAT_420003b4 < param_2) {
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & DAT_420014d8 | DAT_420014dc;
      }
      else {
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & DAT_420014d8 | DAT_42001038;
      }
    }
    else {
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & DAT_420014d8 | DAT_420008e4;
    }
    uVar4 = *(uint *)(param_1 + 0x10) >> 0x14;
    uVar8 = (uVar4 & 7) + 2;
    uVar5 = uVar8 & 7;
    uVar2 = *(uint *)(param_1 + 0x10) & 0xffffff1f | uVar5 << 5;
    *(uint *)(param_1 + 0x10) = uVar2;
    puVar7 = (undefined *)(1 << 0x20 - (0x20 - (uVar4 & 7)) & 0x3f);
    uVar2 = uVar2 & DAT_420014e0;
    *(uint *)(param_1 + 0x10) = uVar2 | (int)puVar7 << 0xe;
    uVar5 = ((-(LZCOUNT(param_2) + -0x20) & 0x3fU) - uVar5 & 0xff) + 1 & 0x1f;
    uVar2 = uVar2 & 0xffffffe0 | (int)puVar7 << 0xe | uVar5;
    *(uint *)(param_1 + 0x10) = uVar2;
    uVar4 = 1 << 0x20 - (0x20 - (uVar8 & 7));
    *(uint *)(param_1 + 0x10) = uVar2 & DAT_420014e4 | (uVar4 & 0xff) << 0x17;
    iVar1 = (uVar5 * (int)puVar7 + uVar5 + 9) * 4;
    *(int *)(param_1 + 0x14) = iVar1;
    if (param_2 < iVar1 + 0xcU) {
      param_1 = (undefined *)0x0;
    }
    else {
      *(undefined **)(param_1 + 8) = param_1;
      *(undefined **)(param_1 + 0xc) = param_1;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(uint *)(param_1 + 0x1c) = (uint)(param_1 + 0x27) & 0xfffffffc;
      *(uint *)(param_1 + 0x20) = uVar5 * 4 + ((uint)(param_1 + 0x27) & 0xfffffffc);
      puVar6 = param_1;
      if ((undefined *)0x20 < puVar7) {
        puVar6 = PTR_s_control_construct_420014ec;
        puVar7 = PTR_s_sizeof_unsigned_int____CHAR_BIT_>_420014e8;
        (*(code *)PTR_FUN_42000044)(PTR_s_tlsf_c_3c030cd8_0x1b_420014f0,0x4a);
        uVar4 = extraout_a3;
      }
      if ((int)(uVar4 & 0xff) / (int)puVar7 == 4) {
        iVar1 = 0;
        goto LAB_42026776;
      }
      puVar6 = PTR_s_control_construct_420014ec;
      (*(code *)PTR_FUN_42000044)
                (PTR_s_tlsf_c_3c030cd8_0x1b_420014f0,0x4e,PTR_s_control_construct_420014ec,
                 PTR_s_ALIGN_SIZE____control_>small_blo_420014f4);
      iVar1 = extraout_a3_00;
      do {
        *(undefined4 *)(iVar1 * 4 + *(int *)(param_1 + 0x1c)) = 0;
        for (iVar3 = 0; uVar4 = *(uint *)(param_1 + 0x10) >> 0xe & 0x3f, iVar3 < (int)uVar4;
            iVar3 = iVar3 + 1) {
          *(undefined **)((uVar4 * iVar1 + iVar3) * 4 + *(int *)(param_1 + 0x20)) = puVar6;
        }
        iVar1 = iVar1 + 1;
LAB_42026776:
      } while (iVar1 < (int)(*(uint *)(param_1 + 0x10) & 0x1f));
    }
  }
  return param_1;
}