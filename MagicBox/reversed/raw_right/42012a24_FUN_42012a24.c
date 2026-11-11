// 42012a24  FUN_42012a24  FUN_42012a24  size=40

undefined4 FUN_42012a24(char param_1)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    uVar1 = FUN_42012b6c(*DAT_420009fc);
  }
  else {
    uVar1 = (*(code *)PTR_FUN_42000f28)(*DAT_420009fc);
  }
  return uVar1;
}


