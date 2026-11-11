undefined4 FUN_4200b604(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 3) {
    uVar1 = 1;
    if (*(int *)(param_1 * 4 + DAT_42000a40) == 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}