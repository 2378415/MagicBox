int FUN_4200c920(int param_1)

{
  int iVar1;
  
  FUN_4200da44();
  iVar1 = 0;
  while( true ) {
    if (7 < iVar1) {
      FUN_4200da70();
      return -1;
    }
    if (*(char *)(DAT_42000af8 + iVar1 * 0x18 + (uint)*(byte *)(param_1 + 0xc) * 0xc4 + 0xd) == '\0'
       ) break;
    iVar1 = iVar1 + 1;
  }
  *(undefined1 *)(DAT_42000af8 + iVar1 * 0x18 + (uint)*(byte *)(param_1 + 0xc) * 0xc4 + 0xd) = 1;
  FUN_4200da70();
  return iVar1;
}