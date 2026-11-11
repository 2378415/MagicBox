// 42024640  FUN_42024640  FUN_42024640  size=37

void FUN_42024640(int param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (param_2 < 0) {
      return;
    }
    if (*(byte *)(param_1 + param_2) == param_3) {
      iVar1 = iVar1 + 1;
    }
    else {
      iVar1 = 0;
    }
    if (param_4 <= iVar1) break;
    param_2 = param_2 + -1;
  }
  return;
}


