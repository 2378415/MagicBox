// 403795b4  FUN_403795b4  FUN_403795b4  size=92

void FUN_403795b4(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  memw();
  uVar2 = *DAT_403749d0 >> 10 & 3;
  if (((uVar2 != 1) && (uVar2 != 2)) && (uVar2 != 0)) {
    uVar2 = 3;
  }
  iVar3 = *param_1;
  if (iVar3 == 0) {
    FUN_403794f4(param_1[3],param_1[2]);
    if ((uVar2 == 1) && (*DAT_40374968 == 0)) {
      FUN_40378ca4();
    }
  }
  else if (iVar3 == 1) {
    if (uVar2 != 1) {
      FUN_40378cc4();
      uVar1 = FUN_403791f8();
      func_0x40378cf0(uVar1,param_1[1]);
    }
    FUN_40379374(param_1[3]);
  }
  else if (iVar3 == 2) {
    FUN_40378cdc();
  }
  return;
}


