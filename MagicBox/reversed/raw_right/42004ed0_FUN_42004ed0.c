// 42004ed0  FUN_42004ed0  FUN_42004ed0  size=179

int FUN_42004ed0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_42004798(param_2);
  if (iVar1 == 0) {
    if (param_1 == 2) {
      if (param_2 == 0) {
        memw();
        *DAT_42000594 = 1;
        uVar2 = 0;
      }
      else if (param_2 == 1) {
        memw();
        *DAT_42000598 = 1;
        uVar2 = 0;
      }
      else {
        uVar2 = 7;
      }
      iVar1 = FUN_42005ab0(uVar2);
    }
    else if (param_1 == 4) {
      if (param_2 == 0) {
        memw();
        *DAT_42000578 = 1;
        uVar2 = 0;
      }
      else if (param_2 == 1) {
        memw();
        *DAT_4200057c = 1;
        uVar2 = 0;
      }
      else {
        uVar2 = 7;
      }
      iVar1 = FUN_42005ab0(uVar2);
    }
    else if (param_1 == 1) {
      if (param_2 == 0) {
        memw();
        *DAT_42000548 = 1;
        uVar2 = 0;
      }
      else if (param_2 == 1) {
        memw();
        *DAT_4200054c = 1;
        uVar2 = 0;
      }
      else {
        uVar2 = 7;
      }
      iVar1 = FUN_42005ab0(uVar2);
    }
    else {
      iVar1 = DAT_420005b4;
    }
  }
  return iVar1;
}


