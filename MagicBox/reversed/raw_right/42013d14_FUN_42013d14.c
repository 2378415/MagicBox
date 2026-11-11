// 42013d14  FUN_42013d14  FUN_42013d14  size=73

int FUN_42013d14(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [48];
  
  iVar1 = FUN_42024e5c();
  if (iVar1 == 0) {
    FUN_420154e8(auStack_30);
    uVar2 = FUN_4201523c();
    iVar1 = FUN_42015278(uVar2,param_1);
    if ((iVar1 == 0) || (iVar1 = FUN_42013cd8(param_1), iVar1 == 0)) {
      iVar1 = FUN_42011e9c(1,2,param_1);
      if (iVar1 == 0) {
        iVar1 = 0x105;
      }
      else {
        iVar1 = FUN_42011fd8(iVar1,0,*(undefined4 *)(iVar1 + 0x10));
      }
    }
    FUN_420154f8(auStack_30);
  }
  return iVar1;
}


