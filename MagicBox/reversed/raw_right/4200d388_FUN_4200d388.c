// 4200d388  FUN_4200d388  FUN_4200d388  size=90

undefined4 FUN_4200d388(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffffe;
  }
  else if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0xfffffffe;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 8) + 0xa64);
    if (iVar2 == 0) {
      uVar1 = 0xfffffffe;
    }
    else {
      uVar1 = FUN_4200da44();
      iVar3 = *(int *)(param_1 + 4);
      FUN_4200c2f8(iVar2,*(undefined1 *)(iVar3 + 8));
      *(undefined4 *)(iVar3 + 0x10) = 0;
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 0x2c) = 0xfffffff3;
      if (*(int *)(param_1 + 0x28) == 0) {
        FUN_4200c978(iVar3);
      }
      else {
        FUN_4200d7d4(*(undefined4 *)(iVar3 + 0xc));
      }
      FUN_4200da70(uVar1);
      uVar1 = 0;
    }
  }
  return uVar1;
}


