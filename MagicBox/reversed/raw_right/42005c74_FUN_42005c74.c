// 42005c74  FUN_42005c74  FUN_42005c74  size=89

undefined4 FUN_42005c74(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    uVar1 = DAT_42000160;
  }
  else if (param_1 == 2) {
    (*(code *)PTR_FUN_42000090)(2,100);
    uVar1 = (*(code *)PTR_FUN_4200068c)();
    *(undefined4 *)(DAT_42000688 + 4) = uVar1;
  }
  else if (param_1 == 0) {
    if (*(int *)(DAT_42000688 + 4) == 0) {
      (*(code *)PTR_FUN_42000090)(2,100);
      uVar1 = (*(code *)PTR_FUN_4200068c)();
      *(undefined4 *)(DAT_42000688 + 4) = uVar1;
    }
    uVar1 = *(undefined4 *)(DAT_42000688 + 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


