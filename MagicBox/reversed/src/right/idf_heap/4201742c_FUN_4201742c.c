// strings: Hl7@

undefined4 FUN_4201742c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_2 + 0x10) != 0) {
    if ((param_1 != 0) && (*(int *)(param_1 + 0x28) == 0)) {
      FUN_42017694(param_1);
    }
    if (*(ushort *)(param_2 + 0xc) != 0) {
      if (((*(uint *)(param_2 + 100) & 1) == 0) && ((*(ushort *)(param_2 + 0xc) & 0x200) == 0)) {
        (*(code *)PTR_FUN_42001154)(*(undefined4 *)(param_2 + 0x58));
      }
      uVar1 = FUN_420172f8(param_1,param_2);
      if ((*(uint *)(param_2 + 100) & 1) != 0) {
        return uVar1;
      }
      if ((*(ushort *)(param_2 + 0xc) & 0x200) == 0) {
        (*(code *)PTR_FUN_42001158)(*(undefined4 *)(param_2 + 0x58));
        return uVar1;
      }
      return uVar1;
    }
  }
  return 0;
}