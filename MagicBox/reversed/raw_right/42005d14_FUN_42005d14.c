// 42005d14  FUN_42005d14  FUN_42005d14  size=22

int FUN_42005d14(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    iVar1 = DAT_42000690;
  }
  else {
    iVar1 = FUN_42005c18(param_1);
    iVar1 = iVar1 << 8;
  }
  return iVar1;
}


