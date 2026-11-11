// 42015394  FUN_42015394  FUN_42015394  size=33

undefined4 FUN_42015394(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  while( true ) {
    if (iVar1 == 0) {
      return DAT_4200108c;
    }
    if (param_2 == iVar1) break;
    iVar1 = *(int *)(iVar1 + 8);
  }
  FUN_42024df0(param_1 + 4);
  return 0;
}


