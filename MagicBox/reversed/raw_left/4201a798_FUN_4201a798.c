// 4201a798  FUN_4201a798  FUN_4201a798  size=64
// strings: clk_hal

int FUN_4201a798(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  memw();
  uVar1 = *DAT_42001968;
  if ((((uVar1 & 0xffff) != uVar1 >> 0x10) || (0xfffffffd < uVar1 - 1)) ||
     (uVar1 = uVar1 >> 1 & 0x7fff, iVar3 = uVar1 * 2, uVar1 == 0)) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (2,PTR_s_clk_hal_4200196c,PTR_DAT_42001970,uVar2,PTR_s_clk_hal_4200196c);
    iVar3 = 0x28;
  }
  return iVar3;
}


