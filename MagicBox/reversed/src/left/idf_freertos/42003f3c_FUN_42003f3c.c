undefined4 FUN_42003f3c(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x102;
  if (param_1 < 2) {
    if ((*(int *)(param_1 * 4 + DAT_4200045c) == 0) ||
       (iVar2 = (*(code *)PTR_FUN_420004b4)(), iVar2 != 2)) {
      uVar1 = 0x103;
    }
    else {
      FUN_42003e0c(param_1,param_2,param_3,2);
      uVar1 = 0;
    }
  }
  return uVar1;
}