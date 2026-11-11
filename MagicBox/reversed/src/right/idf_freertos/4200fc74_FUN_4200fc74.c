void FUN_4200fc74(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + 4;
  iVar1 = FUN_42010364();
  if (iVar1 == 0) {
    *(undefined2 *)(param_2 + 2) = 1;
    *(undefined1 *)(param_2 + 4) = 0xff;
  }
  else if (*(short *)(param_1 + 10) == 0) {
    FUN_4200f8e0(iVar2,param_2);
  }
  else if (*(char *)(param_1 + 4) < '\0') {
    FUN_4200fc00(iVar2,param_2);
  }
  else {
    FUN_4200f90c(iVar2,param_1,param_2);
  }
  return;
}