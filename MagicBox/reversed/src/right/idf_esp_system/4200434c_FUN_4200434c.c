undefined4 FUN_4200434c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    memw();
    *(bool *)param_2 = *DAT_42000578 == 1;
    uVar1 = 0;
  }
  else if (param_1 == 1) {
    memw();
    *(bool *)param_2 = *DAT_4200057c == 1;
    uVar1 = 0;
  }
  else {
    uVar1 = 7;
  }
  return uVar1;
}