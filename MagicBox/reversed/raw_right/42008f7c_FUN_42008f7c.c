// 42008f7c  FUN_42008f7c  FUN_42008f7c  size=53

undefined4 FUN_42008f7c(uint param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 < 3) {
    if (*(int *)(param_1 * 4 + DAT_42000844) == 0) {
      uVar1 = 0xffffffff;
    }
    else if (param_2 == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = FUN_420086c8(param_1,param_2,param_3,0);
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


