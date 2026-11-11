// 4200ca78  FUN_4200ca78  FUN_4200ca78  size=57

undefined4 FUN_4200ca78(uint param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  
  if ((param_1 < 0x10) && ((*DAT_42000c74 >> (param_1 * 2 & 0x1f) & 3) != 0)) {
    if (param_3 < 3) {
      return 0;
    }
    puVar1 = (undefined4 *)FUN_42020b54();
    *puVar1 = 0x16;
  }
  else {
    puVar1 = (undefined4 *)FUN_42020b54();
    *puVar1 = 9;
  }
  return 0xffffffff;
}


