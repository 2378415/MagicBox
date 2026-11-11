int FUN_420049ac(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_420005b4;
  if (param_1 < 3) {
    if (param_1 != 0) {
      memw();
      *DAT_420005d0 = 1;
      iVar1 = 0;
    }
  }
  else if ((param_1 == 4) && (iVar1 = FUN_42004798(param_2), iVar1 == 0)) {
    if (param_2 == 0) {
      memw();
      *DAT_42000558 = 1;
      uVar2 = 0;
    }
    else if (param_2 == 1) {
      memw();
      *DAT_4200055c = 1;
      uVar2 = 0;
    }
    else {
      uVar2 = 7;
    }
    iVar1 = FUN_42005ab0(uVar2);
  }
  return iVar1;
}