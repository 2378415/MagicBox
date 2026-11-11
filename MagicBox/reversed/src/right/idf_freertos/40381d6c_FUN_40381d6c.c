void FUN_40381d6c(undefined1 *param_1)

{
  uint unaff_retaddr;
  
  *param_1 = 0x30;
  param_1[1] = 0x78;
  (*DAT_403751dc)((unaff_retaddr & 0x3fffffff | DAT_403751e0 & 0xc0000000) - 3,param_1 + 2,0x10);
  return;
}