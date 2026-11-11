// 40381e44  FUN_40381e44  FUN_40381e44  size=35

int FUN_40381e44(undefined4 param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  if ((int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20) == 0) {
    iVar1 = FUN_40376334(param_2 * param_3);
    if (iVar1 != 0) {
      (*DAT_403752c4)(iVar1,param_2 * param_3);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


