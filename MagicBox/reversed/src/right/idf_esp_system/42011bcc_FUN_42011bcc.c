int FUN_42011bcc(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_42000a00)();
  if ((((iVar1 != 0) && (param_2 != 0 && param_2 != 2)) && (param_2 != 3)) &&
     ((param_2 != 1 || param_3 != 0 && (param_2 != 1 || param_3 != 4)))) {
    iVar1 = param_1;
  }
  return iVar1;
}