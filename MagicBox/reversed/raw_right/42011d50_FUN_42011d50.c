// 42011d50  FUN_42011d50  FUN_42011d50  size=52
// strings: <k7@

undefined4 FUN_42011d50(void)

{
  undefined4 uVar1;
  
  if (*DAT_42000e10 == 0) {
    (*(code *)PTR_FUN_42000700)(DAT_42000e28);
    if (*DAT_42000e10 == 0) {
      uVar1 = FUN_42011c14();
    }
    else {
      uVar1 = 0;
    }
    (*(code *)PTR_FUN_42000704)(DAT_42000e28);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


