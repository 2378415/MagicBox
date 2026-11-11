// 42013b94  FUN_42013b94  FUN_42013b94  size=100

int FUN_42013b94(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,uint *param_5)

{
  int iVar1;
  undefined1 auStack_30 [4];
  int *piStack_2c;
  uint auStack_28 [10];
  
  FUN_420154e8(auStack_30);
  iVar1 = FUN_42013b60(param_1,&piStack_2c);
  if ((iVar1 == 0) &&
     (iVar1 = (**(code **)(*piStack_2c + 0x18))(piStack_2c,param_2,param_3,auStack_28), iVar1 == 0))
  {
    if (param_5 == (uint *)0x0) {
      iVar1 = DAT_42001094;
    }
    else if (param_4 == 0) {
      *param_5 = auStack_28[0];
    }
    else if (*param_5 < auStack_28[0]) {
      *param_5 = auStack_28[0];
      iVar1 = DAT_42001094;
    }
    else {
      *param_5 = auStack_28[0];
      iVar1 = (**(code **)(*piStack_2c + 0x34))(piStack_2c,param_2,param_3,param_4);
    }
  }
  FUN_420154f8(auStack_30);
  return iVar1;
}


