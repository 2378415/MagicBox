// 40382dcc  FUN_40382dcc  FUN_40382dcc  size=26

int FUN_40382dcc(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint local_30 [12];
  
  iVar1 = FUN_40382d04(param_1,local_30);
  if (iVar1 == 0) {
    *param_2 = (local_30[0] >> 6 & 1) << 2;
  }
  return iVar1;
}


