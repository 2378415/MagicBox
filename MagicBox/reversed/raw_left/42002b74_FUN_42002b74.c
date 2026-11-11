// 42002b74  FUN_42002b74  FUN_42002b74  size=48

undefined4 FUN_42002b74(int param_1)

{
  undefined4 uVar1;
  
  if (*DAT_42000154 == param_1) {
    uVar1 = 0x103;
  }
  else if (*DAT_42000154 == 0) {
    *DAT_42000154 = param_1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x101;
  }
  return uVar1;
}


