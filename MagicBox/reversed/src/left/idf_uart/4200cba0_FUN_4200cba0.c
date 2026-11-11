undefined4 FUN_4200cba0(uint param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((0xf < param_1) || (uVar1 = 0, (*DAT_42000c74 & 1 << ((char)param_1 * '\x02' & 0x1fU)) == 0))
  {
    puVar2 = (undefined4 *)FUN_42020b54();
    *puVar2 = 9;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}