undefined4 FUN_4201c7e4(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  do {
    if (iVar3 == 0) {
      return DAT_42001a44;
    }
    iVar2 = *(int *)(iVar3 + 8);
    bVar1 = param_2 != iVar3;
    iVar3 = iVar2;
  } while (bVar1);
  iVar3 = *(int *)(param_2 + 4);
  if (iVar3 == 0) {
    *(int *)(param_1 + 4) = iVar2;
  }
  else {
    *(int *)(iVar3 + 8) = iVar2;
  }
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = iVar3;
  }
  else {
    *(int *)(iVar2 + 4) = iVar3;
  }
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
  return 0;
}