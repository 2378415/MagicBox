// 42009f6c  FUN_42009f6c  FUN_42009f6c  size=34

undefined4 FUN_42009f6c(uint param_1)

{
  undefined4 uVar1;
  
  if ((int)param_1 < 0) {
    uVar1 = 0;
  }
  else if (param_1 < *DAT_42000980) {
    uVar1 = *(undefined4 *)(param_1 * 4 + DAT_4200097c);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


