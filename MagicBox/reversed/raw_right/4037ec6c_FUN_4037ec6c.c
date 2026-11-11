// 4037ec6c  FUN_4037ec6c  FUN_4037ec6c  size=110

uint FUN_4037ec6c(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 == (undefined4 *)0x0 || param_4 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    if (DAT_403745e8 < (uint)(param_1 + DAT_40374ce0)) {
      uVar1 = 0;
    }
    else if (DAT_403745e8 < (uint)(param_1 + param_2 + DAT_4037500c)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    if (DAT_403745e8 < (uint)(param_1 + DAT_40375010)) {
      uVar2 = 0;
    }
    else if (DAT_403745e8 < (uint)(param_1 + param_2 + DAT_40375014)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    uVar1 = uVar1 | uVar2;
    if (uVar1 != 0) {
      *param_3 = 1;
      *param_4 = 0;
    }
  }
  return uVar1;
}


