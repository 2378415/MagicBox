undefined4 FUN_42011b5c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x31) {
    if (*(int *)(PTR_DAT_42000518 + param_1 * 4) < 0) {
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