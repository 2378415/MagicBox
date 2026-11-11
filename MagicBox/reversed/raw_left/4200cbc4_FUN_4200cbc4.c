// 4200cbc4  FUN_4200cbc4  FUN_4200cbc4  size=42

undefined4 FUN_4200cbc4(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  if ((0xf < param_1) || ((*DAT_42000c74 >> (param_1 * 2 & 0x1f) & 2) == 0)) {
    puVar1 = (undefined4 *)FUN_42020b54();
    *puVar1 = 9;
    param_3 = 0xffffffff;
  }
  return param_3;
}


