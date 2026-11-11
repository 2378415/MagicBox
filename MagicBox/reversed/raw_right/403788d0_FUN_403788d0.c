// 403788d0  FUN_403788d0  FUN_403788d0  size=26

int FUN_403788d0(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  
  if (((*(int *)(param_1 + 8) != 0) &&
      (pcVar2 = *(code **)(*(int *)(param_1 + 8) + 4), pcVar2 != (code *)0x0)) &&
     (iVar1 = (*pcVar2)(*(undefined4 *)(param_1 + 0xc)), param_2 == 0)) {
    param_2 = iVar1;
  }
  return param_2;
}


