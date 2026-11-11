uint FUN_4200a90c(void)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (0xf < uVar1) {
      return 0xffffffff;
    }
    if ((*DAT_420009ac >> (uVar1 * 2 & 0x1f) & 3) == 0) break;
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}