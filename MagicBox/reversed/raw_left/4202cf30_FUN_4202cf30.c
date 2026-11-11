// 4202cf30  FUN_4202cf30  FUN_4202cf30  size=38

bool FUN_4202cf30(uint *param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if (param_1[7] != 0) {
    bVar1 = ((*param_1 | param_1[1] | param_1[2]) & param_2) == param_2;
  }
  return bVar1;
}


