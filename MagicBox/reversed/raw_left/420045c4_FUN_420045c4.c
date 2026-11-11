// 420045c4  FUN_420045c4  FUN_420045c4  size=64

void FUN_420045c4(char *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 != (char *)0x0) {
    (*(code *)PTR_FUN_42000558)();
    if ((*param_1 == '*') && (param_1[1] == '\0')) {
      FUN_420045b8(param_2);
      FUN_420046c8();
      FUN_42004864();
    }
    else {
      iVar1 = FUN_42004640(param_1,param_2);
      if (iVar1 != 0) {
        FUN_4200473c(param_1,param_2);
      }
    }
    (*(code *)PTR_FUN_4200055c)();
  }
  return;
}


