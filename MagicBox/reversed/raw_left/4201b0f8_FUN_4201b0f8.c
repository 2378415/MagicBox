// 4201b0f8  FUN_4201b0f8  FUN_4201b0f8  size=79

int FUN_4201b0f8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_30 [48];
  
  iVar1 = FUN_4202d7d4();
  if (iVar1 == 0) {
    FUN_4201cb08(auStack_30);
    uVar2 = FUN_4201c7b0();
    iVar1 = FUN_4201c81c(uVar2,param_1);
    if ((iVar1 == 0) || (iVar1 = FUN_4201b060(param_1), iVar1 == 0)) {
      iVar3 = FUN_42018d80(1,2,param_1);
      iVar1 = 0x105;
      if (iVar3 != 0) {
        iVar1 = FUN_42018ec0(iVar3,0,*(undefined4 *)(iVar3 + 0x10));
      }
    }
    FUN_4201cb18(auStack_30);
  }
  return iVar1;
}


