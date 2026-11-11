// 42012e30  FUN_42012e30  FUN_42012e30  size=42

undefined4 FUN_42012e30(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_30 [48];
  
  if (*DAT_42000f78 == 0) {
    uVar1 = 0x103;
  }
  else {
    if (param_1 == 0) {
      param_1 = (*(code *)PTR_FUN_42000344)();
    }
    uVar1 = FUN_42012c9c(1,param_1,auStack_30);
  }
  return uVar1;
}


