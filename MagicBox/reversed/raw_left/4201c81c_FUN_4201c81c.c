// 4201c81c  FUN_4201c81c  FUN_4201c81c  size=36

int FUN_4201c81c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x10);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    uVar2 = (**(code **)(**(int **)(iVar1 + 8) + 8))();
    iVar3 = (*DAT_42000568)(uVar2,param_2);
    if (iVar3 == 0) break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  return iVar1;
}


