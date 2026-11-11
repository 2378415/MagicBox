// 40378fe4  FUN_40378fe4  FUN_40378fe4  size=20

bool FUN_40378fe4(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int in_SCOMPARE1;
  
  wsr((char)in_SCOMPARE1,param_2);
  iVar1 = *param_1;
  if (iVar1 == in_SCOMPARE1) {
    *param_1 = param_3;
  }
  return param_2 == iVar1;
}


