// 420015d4  FUN_420015d4  FUN_420015d4  size=50

undefined4 FUN_420015d4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while( true ) {
    if (4 < iVar1) {
      return 0x101;
    }
    iVar2 = *(int *)(iVar1 * 4 + DAT_42000028);
    if (iVar2 == param_1) break;
    if (iVar2 == 0) {
      *(int *)(iVar1 * 4 + DAT_42000028) = param_1;
      return 0;
    }
    iVar1 = iVar1 + 1;
  }
  return 0x103;
}


