undefined4 FUN_42004968(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x102;
  }
  else if (param_1 == 2) {
    uVar1 = FUN_420047cc();
    *param_2 = uVar1;
    uVar1 = 0;
  }
  else if (param_1 == 4) {
    uVar1 = FUN_420047dc();
    *param_2 = uVar1;
    uVar1 = 0;
  }
  else if (param_1 == 1) {
    uVar1 = FUN_420047c4();
    *param_2 = uVar1;
    uVar1 = 0;
  }
  else {
    uVar1 = DAT_420005b4;
  }
  return uVar1;
}