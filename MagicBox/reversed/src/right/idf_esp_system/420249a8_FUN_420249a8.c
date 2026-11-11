uint FUN_420249a8(int param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while( true ) {
    if (param_2 <= uVar1) {
      return 0xffffffff;
    }
    iVar2 = uVar1 * 0x28 + param_1;
    if ((((~*(uint *)(iVar2 + 0x18) & param_4) == 0) && ((~*(uint *)(iVar2 + 0x1c) & param_5) == 0))
       && (param_3 <= *(uint *)(iVar2 + 0x14))) break;
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}