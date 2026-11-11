// 42009f0c  FUN_42009f0c  FUN_42009f0c  size=93

int FUN_42009f0c(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0) {
    iVar2 = 0x102;
  }
  else if ((param_3 & 8) == 0) {
    iVar3 = FUN_42009ce8(param_2);
    if (iVar3 == 0) {
      iVar2 = 0x101;
    }
    else {
      uVar1 = (*DAT_420001e4)(param_1);
      iVar2 = FUN_42009de4(param_1,uVar1,iVar3,param_3,param_4,0);
      if (iVar2 != 0) {
        FUN_42009dbc(iVar3);
      }
    }
  }
  else {
    uVar1 = (*DAT_420001e4)(param_1);
    iVar2 = FUN_42009de4(param_1,uVar1,param_2,param_3,param_4,0);
  }
  return iVar2;
}


