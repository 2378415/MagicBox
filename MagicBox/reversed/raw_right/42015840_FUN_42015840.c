// 42015840  FUN_42015840  FUN_42015840  size=48

int FUN_42015840(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) == -1) {
    iVar1 = DAT_420010e4;
  }
  else if (*(int *)(param_1 + 0xc) == -4) {
    iVar1 = 0;
  }
  else if (*(uint *)(param_1 + 0x38) < 0x7d) {
    iVar1 = (*(uint *)(param_1 + 0x38) - 0x7d) * -0x20;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


