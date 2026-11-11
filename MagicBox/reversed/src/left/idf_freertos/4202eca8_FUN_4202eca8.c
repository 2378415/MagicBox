// strings: !block_is_last(block)

void FUN_4202eca8(uint *param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  
  pcVar2 = (code *)PTR_FUN_42001f88;
  if (param_2 != (code *)0x0) {
    pcVar2 = param_2;
  }
  while ((param_1 != (uint *)0x4 && (uVar3 = *param_1, 3 < uVar3))) {
    iVar1 = (*pcVar2)(param_1 + 1,uVar3 & 0xfffffffc,(uVar3 ^ 0xffffffff) & 1,param_3);
    if (iVar1 == 0) {
      return;
    }
    uVar3 = *param_1;
    param_1 = (uint *)((int)(param_1 + 1) + (uVar3 & 0xfffffffc));
    if (uVar3 < 4) {
      (*(code *)PTR_FUN_420000a8)
                (PTR_s_tlsf_block_functions_h_3c0331e0_0x1b_42001f94,0xa1,PTR_s_block_next_42001f90,
                 PTR_s__block_is_last_block__42001f8c);
    }
  }
  return;
}