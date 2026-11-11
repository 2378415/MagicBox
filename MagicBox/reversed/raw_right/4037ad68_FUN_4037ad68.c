// 4037ad68  FUN_4037ad68  FUN_4037ad68  size=31

int FUN_4037ad68(int *param_1)

{
  int iVar1;
  
  if ((param_1[2] & 4U) == 0) {
    iVar1 = param_1[0xb] - param_1[8];
    if (iVar1 < 1) {
      iVar1 = iVar1 + *param_1;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


