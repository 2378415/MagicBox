uint FUN_420247d8(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  bVar1 = *param_1;
  while( true ) {
    bVar2 = *param_1;
    uVar3 = (uint)bVar2;
    if (uVar3 < 0x7f) {
      *param_1 = bVar2 + 1;
    }
    else {
      *param_1 = 2;
    }
    uVar4 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
    if ((*(uint *)(param_1 + (uint)(bVar2 >> 5) * 4 + 4) & uVar4) == 0) break;
    if (bVar1 == uVar3) {
      return 0xffffffff;
    }
  }
  *(uint *)(param_1 + (uint)(bVar2 >> 5) * 4 + 4) =
       *(uint *)(param_1 + (uint)(bVar2 >> 5) * 4 + 4) | uVar4;
  return uVar3;
}