uint FUN_420031b8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  for (uVar2 = 0; uVar2 < 5; uVar2 = uVar2 + 1) {
    uVar1 = uVar1 * 0x1f ^ *(uint *)(uVar2 * 4 + DAT_42000464);
  }
  return uVar1;
}