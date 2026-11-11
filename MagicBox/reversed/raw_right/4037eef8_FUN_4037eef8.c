// 4037eef8  FUN_4037eef8  FUN_4037eef8  size=86

uint FUN_4037eef8(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_4 & 2) == 0) {
    uVar1 = 0;
  }
  else if (DAT_403745e8 < (uint)(param_2 + DAT_40374ce0)) {
    uVar1 = 0;
  }
  else if (DAT_403745e8 < (uint)(param_2 + param_3 + DAT_4037500c)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  if ((param_4 & 1) != 0) {
    if (DAT_403745e8 < (uint)(param_2 + DAT_40375010)) {
      uVar2 = 0;
    }
    else if (DAT_403745e8 < (uint)(param_2 + param_3 + DAT_40375014)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    uVar1 = uVar1 | uVar2;
  }
  return uVar1;
}


