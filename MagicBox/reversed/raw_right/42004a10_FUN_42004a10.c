// 42004a10  FUN_42004a10  FUN_42004a10  size=80
// strings: &B!!

int FUN_42004a10(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0x102;
  }
  else {
    iVar1 = DAT_420005b4;
    if (param_1 < 3) {
      if (param_1 != 0) {
        memw();
        *(bool *)param_2 = *DAT_420005d0 == 1;
        iVar1 = 0;
      }
    }
    else if ((param_1 == 4) && (iVar1 = FUN_42004798(param_3), iVar1 == 0)) {
      FUN_420040f8(param_3,param_2);
      iVar1 = FUN_42005ab0();
    }
  }
  return iVar1;
}


