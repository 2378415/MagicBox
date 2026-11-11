// 4200aa60  FUN_4200aa60  FUN_4200aa60  size=43

undefined4 FUN_4200aa60(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  if ((0xf < param_1) || ((*DAT_420009ac >> (param_1 * 2 & 0x1f) & 2) == 0)) {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 9;
    param_3 = 0xffffffff;
  }
  return param_3;
}


