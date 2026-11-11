// 42013bec  FUN_42013bec  FUN_42013bec  size=105

int FUN_42013bec(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_30;
  char acStack_2c [44];
  
  uVar2 = 0;
  if (param_1 != (char *)0x0) {
    if (*param_1 == '\0') {
      param_1 = (char *)0x0;
    }
    else {
      uVar2 = (*DAT_4200030c)(param_1);
    }
  }
  iVar1 = FUN_42013b20(0xa4,param_1,uVar2,acStack_2c,&local_30);
  if (iVar1 == 0) {
    if (local_30 == 1) {
      if (acStack_2c[0] == '\0') {
        if (*DAT_4200125c != 0) {
          (*(code *)PTR_FUN_42000488)(*DAT_4200125c,0,0,0);
        }
      }
      else {
        iVar1 = -2;
        if (acStack_2c[0] != -1) {
          iVar1 = -3;
        }
      }
    }
    else {
      iVar1 = -3;
    }
  }
  else if (iVar1 != -1) {
    iVar1 = -2;
  }
  return iVar1;
}


