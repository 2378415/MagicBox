undefined4 FUN_42012914(int param_1)

{
  int iVar1;
  undefined4 local_30;
  undefined4 auStack_2c [11];
  
  if (param_1 == 0) {
    local_30 = 0xffffffff;
  }
  else {
    local_30 = 0;
    auStack_2c[0] = 0;
    iVar1 = FUN_42012794(param_1,&local_30,auStack_2c);
    if (iVar1 != 0) {
      local_30 = 0xffffffff;
    }
  }
  return local_30;
}