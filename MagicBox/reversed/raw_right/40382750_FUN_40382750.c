// 40382750  FUN_40382750  FUN_40382750  size=56

int FUN_40382750(undefined4 param_1,uint *param_2)

{
  int iVar1;
  byte local_30 [4];
  uint auStack_2c [11];
  
  iVar1 = FUN_403826ec(param_1,0x35,8,auStack_2c);
  if ((iVar1 == 0) && (iVar1 = FUN_403826ec(param_1,5,8,local_30), iVar1 == 0)) {
    *param_2 = (uint)local_30[0] | (auStack_2c[0] & 0xff) << 8;
  }
  return iVar1;
}


