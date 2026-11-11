// 40376760  FUN_40376760  FUN_40376760  size=39

int FUN_40376760(uint param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20) == 0) {
    iVar1 = FUN_40376608(param_1 * param_2,param_3);
    if (iVar1 != 0) {
      (*DAT_403744c4)(iVar1,0,param_1 * param_2);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


