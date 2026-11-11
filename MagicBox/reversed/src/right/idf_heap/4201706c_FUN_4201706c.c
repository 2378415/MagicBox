undefined4 FUN_4201706c(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_5 == param_3) &&
     (iVar1 = FUN_42016fc4(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_4 + 4)), iVar1 != 0))
  {
    return 6;
  }
  uVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x20))
                    (*(int **)(param_1 + 8),param_2,param_3,param_4,param_5);
  return uVar2;
}