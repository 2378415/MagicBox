undefined4 FUN_4201feb4(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = FUN_4202d98c(PTR_DAT_420008a0,PTR_FUN_42001c44,PTR_DAT_420008ac);
  }
  else {
    uVar1 = (*(code *)PTR_FUN_420008c8)();
    uVar1 = FUN_4201fe5c(uVar1,param_1);
  }
  return uVar1;
}