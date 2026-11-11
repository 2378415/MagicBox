// 403809b8  FUN_403809b8  FUN_403809b8  size=97

int FUN_403809b8(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_2 == 0) || (param_1 == (int *)0x0 || param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
    if (iVar1 != 0) {
      FUN_4037bf20();
      FUN_4037bf44(iVar1,0xffffffff);
    }
    iVar1 = FUN_40380e44(param_1[4],param_2);
    if (iVar1 != 0) {
      iVar2 = FUN_40380aa8();
      param_1[1] = param_1[1] - iVar2;
      iVar2 = FUN_40380aa0();
      uVar3 = param_1[1] - iVar2;
      param_1[1] = uVar3;
      if (uVar3 < (uint)param_1[2]) {
        param_1[2] = uVar3;
      }
    }
    iVar2 = *param_1;
    if (iVar2 != 0) {
      FUN_4037bf20();
      FUN_4037c094(iVar2);
    }
  }
  return iVar1;
}


