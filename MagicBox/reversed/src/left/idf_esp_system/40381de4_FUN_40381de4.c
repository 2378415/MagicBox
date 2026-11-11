int FUN_40381de4(uint param_1,uint param_2)

{
  int iVar1;
  
  FUN_4037ed44();
  if ((int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20) == 0) {
    iVar1 = FUN_40376334(param_1 * param_2);
    if (iVar1 != 0) {
      (*DAT_403752c4)(iVar1,param_1 * param_2);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}