// 420167dc  FUN_420167dc  FUN_420167dc  size=64

int FUN_420167dc(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar1 = DAT_420010a4;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc);
    if ((*(int *)(iVar2 + 0xc) != -0x10) || (iVar1 = FUN_420157b4(iVar2), iVar1 == 0)) {
      FUN_42025060(param_1 + 0xc,*(undefined4 *)(param_1 + 0xc));
      FUN_4202503c(param_1,iVar2);
      FUN_4201579c(iVar2,*(undefined4 *)(param_1 + 0x24));
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
      iVar1 = 0;
    }
  }
  return iVar1;
}


