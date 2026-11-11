// 42017484  FUN_42017484  FUN_42017484  size=38

undefined4 FUN_42017484(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = FUN_42025144(PTR_DAT_420006c4,PTR_FUN_42001168,PTR_DAT_420006d0);
  }
  else {
    uVar1 = (*(code *)PTR_FUN_420006f0)();
    uVar1 = FUN_4201742c(uVar1,param_1);
  }
  return uVar1;
}


