// 40378fb8  FUN_40378fb8  FUN_40378fb8  size=30

int FUN_40378fb8(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  
  if (((*(int *)(param_1 + 8) == 0) ||
      (pcVar2 = *(code **)(*(int *)(param_1 + 8) + 4), pcVar2 == (code *)0x0)) ||
     (iVar1 = (*pcVar2)(*(undefined4 *)(param_1 + 0xc)), param_2 != 0)) {
    iVar1 = param_2;
  }
  return iVar1;
}


