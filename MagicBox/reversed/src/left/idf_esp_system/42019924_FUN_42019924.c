undefined4 FUN_42019924(int param_1)

{
  int iVar1;
  undefined4 local_30;
  undefined4 auStack_2c [11];
  
  if (param_1 != 0) {
    auStack_2c[0] = 0;
    local_30 = 0;
    iVar1 = FUN_42019750(param_1,auStack_2c,&local_30);
    if (iVar1 == 0) {
      return auStack_2c[0];
    }
  }
  return 0xffffffff;
}