// 420267b0  FUN_420267b0  FUN_420267b0  size=88
// strings: !block_is_last(block)

void FUN_420267b0(int param_1,code *param_2,undefined4 param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 == (code *)0x0) {
    param_2 = (code *)PTR_FUN_42001504;
  }
  param_1 = param_1 + -4;
  iVar3 = 1;
  while (((param_1 != 0 && (uVar2 = *(uint *)(param_1 + 4), 3 < uVar2)) && (iVar3 != 0))) {
    iVar3 = (*param_2)(param_1 + 8,uVar2 & 0xfffffffc,uVar2 & 1 ^ 1,param_3);
    if ((iVar3 != 0) &&
       (puVar1 = (uint *)(param_1 + 4), param_1 = ((*puVar1 & 0xfffffffc) - 4) + param_1 + 8,
       *puVar1 < 4)) {
      iVar3 = (*(code *)PTR_FUN_42000044)
                        (PTR_s_tlsf_block_functions_h_3c030d80_0x1b_42001510,0xa1,
                         PTR_s_block_next_4200150c,PTR_s__block_is_last_block__42001508);
    }
  }
  return;
}


