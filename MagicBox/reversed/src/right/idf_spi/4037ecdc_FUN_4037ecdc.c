int FUN_4037ecdc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_30;
  undefined4 auStack_2c [11];
  
  local_30 = 0;
  auStack_2c[0] = 0;
  iVar1 = FUN_4037ec6c(param_1,param_2,&local_30,auStack_2c);
  if (iVar1 != 0) {
    (*DAT_40375018)(param_1,param_2);
  }
  return iVar1;
}