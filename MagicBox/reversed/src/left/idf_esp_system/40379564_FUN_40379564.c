// strings: rtc_clk

int FUN_40379564(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  memw();
  uVar1 = *DAT_40374a64;
  if ((((uVar1 & 0xffff) != uVar1 >> 0x10) || (0xfffffffd < uVar1 - 1)) ||
     (uVar1 = uVar1 >> 1 & 0x7fff, iVar3 = uVar1 * 2, uVar1 == 0)) {
    if (1 < *(uint *)PTR_DAT_40374414) {
      uVar2 = FUN_40381bb0();
      (*DAT_40374438)(PTR_DAT_40374a6c,uVar2,PTR_s_rtc_clk_40374a68);
    }
    iVar3 = 0x28;
  }
  return iVar3;
}