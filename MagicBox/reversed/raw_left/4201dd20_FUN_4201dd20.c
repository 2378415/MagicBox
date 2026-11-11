// 4201dd20  FUN_4201dd20  FUN_4201dd20  size=45

int FUN_4201dd20(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) == -1) {
    iVar1 = DAT_42001a9c;
  }
  else {
    iVar1 = 0;
    if ((*(int *)(param_1 + 0xc) != -4) && (*(uint *)(param_1 + 0x38) < 0x7d)) {
      iVar1 = (-(*(uint *)(param_1 + 0x38) - 0x7d) & 0xffff) << 5;
    }
  }
  return iVar1;
}


