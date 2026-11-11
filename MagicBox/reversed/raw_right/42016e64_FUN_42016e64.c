// 42016e64  FUN_42016e64  FUN_42016e64  size=36

void FUN_42016e64(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x10);
      FUN_420171f0(iVar2 + 0x30);
      iVar2 = iVar1;
    }
    (*(code *)PTR_FUN_420004c0)(param_1);
  }
  return;
}


