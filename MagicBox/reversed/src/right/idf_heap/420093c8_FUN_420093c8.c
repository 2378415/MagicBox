undefined4 FUN_420093c8(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 3) {
    if (*(int *)(param_1 * 4 + DAT_42000844) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}