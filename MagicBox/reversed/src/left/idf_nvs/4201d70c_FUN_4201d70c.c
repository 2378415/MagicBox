int FUN_4201d70c(undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6)

{
  int iVar1;
  undefined1 auStack_50 [32];
  undefined4 auStack_30 [12];
  
  auStack_30[0] = 0;
  iVar1 = FUN_4201d244(param_1,param_2,param_3,param_4,auStack_30,auStack_50,param_5,param_6);
  if (iVar1 == 0) {
    iVar1 = FUN_4201d0e8(param_1,auStack_30[0]);
  }
  return iVar1;
}