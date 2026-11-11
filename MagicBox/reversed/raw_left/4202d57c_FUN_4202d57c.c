// 4202d57c  FUN_4202d57c  FUN_4202d57c  size=70

uint FUN_4202d57c(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = 0;
  if ((param_3 - 1U < 0x20) && ((uint)(param_3 + param_2) <= (uint)(param_4 << 3))) {
    uVar4 = 0;
    do {
      uVar3 = uVar4 + param_2;
      uVar2 = uVar3 + 7;
      if (-1 < (int)uVar3) {
        uVar2 = uVar3;
      }
      uVar1 = uVar1 | ((int)(uint)*(byte *)(param_1 + ((int)uVar2 >> 3)) >> (uVar3 & 7) & 1U) <<
                      0x20 - (0x20 - (uVar4 & 0x1f));
      uVar4 = uVar4 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return uVar1;
}


