// 420040bc  FUN_420040bc  FUN_420040bc  size=56

undefined4 FUN_420040bc(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    memw();
    memw();
    *DAT_42000550 = *DAT_42000550 & 0xfffffffe;
    uVar1 = 0;
  }
  else if (param_1 == 1) {
    memw();
    memw();
    *DAT_42000554 = *DAT_42000554 & 0xfffffffe;
    uVar1 = 0;
  }
  else {
    uVar1 = 7;
  }
  return uVar1;
}


