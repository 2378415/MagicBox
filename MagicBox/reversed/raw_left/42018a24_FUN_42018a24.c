// 42018a24  FUN_42018a24  FUN_42018a24  size=27

int FUN_42018a24(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 < 0x31) {
    iVar1 = (*(int *)(PTR_DAT_42000710 + param_1 * 4) >> 0x1f) + 1;
  }
  return iVar1;
}


