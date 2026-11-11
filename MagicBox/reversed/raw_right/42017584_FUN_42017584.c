// 42017584  FUN_42017584  FUN_42017584  size=28
// strings: Hl7@

undefined4 FUN_42017584(undefined4 param_1,int param_2)

{
  if (((*(uint *)(param_2 + 100) & 1) == 0) && ((*(ushort *)(param_2 + 0xc) & 0x200) == 0)) {
    (*(code *)PTR_FUN_42001158)(*(undefined4 *)(param_2 + 0x58));
  }
  return 0;
}


