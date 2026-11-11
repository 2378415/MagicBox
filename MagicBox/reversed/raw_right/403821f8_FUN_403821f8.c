// 403821f8  FUN_403821f8  FUN_403821f8  size=51

int FUN_403821f8(int param_1,uint param_2,uint param_3,uint *param_4,uint param_5)

{
  uint uVar1;
  
  if ((*(uint *)(param_1 + 0x24) & 1) != 0) {
    if ((param_2 & 1) == 0) {
      if ((param_3 & 1) != 0) {
        param_3 = param_3 + 1;
      }
    }
    else if ((param_3 & 1) == 0) {
      param_2 = param_2 - 1;
      param_3 = param_3 + 2;
    }
    else {
      param_2 = param_2 - 1;
      param_3 = param_3 + 1;
    }
  }
  param_5 = param_5 - param_2 % param_5;
  uVar1 = (param_5 < 0x40) * param_5 + (uint)(param_5 >= 0x40) * 0x40;
  *param_4 = param_2;
  return (param_3 < uVar1) * param_3 + (param_3 >= uVar1) * uVar1;
}


