// 42005c18  FUN_42005c18  FUN_42005c18  size=89

int FUN_42005c18(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    iVar1 = DAT_42000684;
  }
  else if (param_1 == 2) {
    (*(code *)PTR_FUN_42000090)(1,100);
    iVar1 = (*(code *)PTR_FUN_4200068c)();
    *DAT_42000688 = iVar1;
  }
  else if (param_1 == 0) {
    if (*DAT_42000688 == 0) {
      (*(code *)PTR_FUN_42000090)(1,100);
      iVar1 = (*(code *)PTR_FUN_4200068c)();
      *DAT_42000688 = iVar1;
    }
    iVar1 = *DAT_42000688;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


