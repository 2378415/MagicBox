undefined4 FUN_4200aadc(uint param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((param_1 < 0x10) && ((*DAT_420009ac >> (param_1 * 2 & 0x1f) & 3) != 0)) {
    if (param_3 < 3) {
      uVar2 = 0;
    }
    else {
      puVar1 = (undefined4 *)FUN_420180e4();
      *puVar1 = 0x16;
      uVar2 = 0xffffffff;
    }
  }
  else {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 9;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}