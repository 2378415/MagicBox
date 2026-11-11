// 4202454c  FUN_4202454c  FUN_4202454c  size=44

undefined4 FUN_4202454c(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    uVar1 = 0;
  }
  else {
    uVar3 = 0;
    for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
      uVar3 = uVar3 | *(uint *)(iVar2 * 4 + param_1);
    }
    if ((~uVar3 & param_2) == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


