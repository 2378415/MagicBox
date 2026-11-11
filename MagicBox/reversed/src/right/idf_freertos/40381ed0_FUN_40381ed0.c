int FUN_40381ed0(undefined4 param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  if ((int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20) == 0) {
    iVar1 = FUN_40376030(param_2 * param_3);
    if (iVar1 != 0) {
      (*DAT_40375204)(iVar1,param_2 * param_3);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}