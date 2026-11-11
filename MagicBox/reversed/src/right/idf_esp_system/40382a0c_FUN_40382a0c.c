int FUN_40382a0c(undefined4 param_1,uint *param_2)

{
  int iVar1;
  int local_30 [12];
  
  iVar1 = FUN_403829f4(param_1,local_30);
  if (iVar1 == 0) {
    *param_2 = local_30[0] * 2 & 4;
  }
  return iVar1;
}