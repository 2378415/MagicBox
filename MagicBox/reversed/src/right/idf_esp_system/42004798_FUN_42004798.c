undefined4 FUN_42004798(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (*(uint *)(PTR_DAT_420005a8 + 0xc) <= uVar1) {
      return DAT_420005a4;
    }
    if (*(int *)(PTR_DAT_420005a8 + (uVar1 + 4) * 4) == param_1) break;
    uVar1 = uVar1 + 1;
  }
  return 0;
}