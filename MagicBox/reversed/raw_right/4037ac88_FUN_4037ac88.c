// 4037ac88  FUN_4037ac88  FUN_4037ac88  size=71

undefined4 FUN_4037ac88(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 8);
  if (((uVar2 & 2) == 0) || (*(int *)(param_1 + 0x28) == *(int *)(param_1 + 0x2c))) {
    if (*(int *)(param_1 + 0x38) < 1) {
      uVar1 = 0;
    }
    else if ((*(int *)(param_1 + 0x28) == *(int *)(param_1 + 0x24)) && ((uVar2 & 4) == 0)) {
      uVar1 = 0;
    }
    else if ((uVar2 & 3) == 0) {
      if ((*(uint *)(*(int *)(param_1 + 0x28) + 4) & 8) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


