undefined4 FUN_42007458(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 * 4 + DAT_42000844);
  iVar1 = *(int *)(iVar3 + 0x30);
  while (*(int *)(iVar3 + 0x2c) != iVar1) {
    iVar4 = iVar1 * 4;
    piVar2 = (int *)(iVar1 * 4 + *(int *)(iVar3 + 0x38));
    *piVar2 = *piVar2 - param_2;
    iVar1 = iVar1 + 1;
    if (*(int *)(iVar3 + 0x34) <= iVar1) {
      iVar1 = 0;
    }
    if (*(int *)(*(int *)(iVar3 + 0x38) + iVar4) < 0) {
      *(int *)(iVar3 + 0x30) = iVar1;
    }
  }
  return 0;
}