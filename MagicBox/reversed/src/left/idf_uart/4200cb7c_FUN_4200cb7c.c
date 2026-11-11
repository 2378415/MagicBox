undefined4 FUN_4200cb7c(uint param_1)

{
  undefined4 *puVar1;
  
  if (param_1 < 0x10) {
    puVar1 = (undefined4 *)FUN_42020b54();
    *puVar1 = 0x58;
  }
  else {
    puVar1 = (undefined4 *)FUN_42020b54();
    *puVar1 = 9;
  }
  return 0xffffffff;
}