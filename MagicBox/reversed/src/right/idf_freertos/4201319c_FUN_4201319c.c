undefined4 FUN_4201319c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x103;
  }
  else {
    (*DAT_42000050)(param_1);
    (*DAT_420000d4)(param_1);
    (*DAT_42000058)(param_1);
    uVar1 = 0;
  }
  return uVar1;
}