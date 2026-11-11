// 4202d4a8  FUN_4202d4a8  FUN_4202d4a8  size=50

void FUN_4202d4a8(int param_1,uint param_2,char param_3)

{
  int iVar1;
  int unaff_a10;
  
  if ((param_1 != 0) && ((param_2 & 0xffff) < 0x100)) {
    iVar1 = 1;
    if (*(int *)(param_1 + 0x214) != 0) {
      iVar1 = unaff_a10;
    }
    if ((iVar1 == 0) && ((param_3 == '\0' || (param_3 == '\x01')))) {
      *(char *)(*(int *)(param_1 + 0x214) + (param_2 & 0xffff) + 0x163) = param_3;
    }
  }
  return;
}


