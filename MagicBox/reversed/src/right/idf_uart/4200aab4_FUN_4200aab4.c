undefined4 FUN_4200aab4(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((param_1 < 0x10) && ((*DAT_420009ac & 1 << ((char)param_1 * '\x02' & 0x1fU)) != 0)) {
    uVar2 = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 9;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}