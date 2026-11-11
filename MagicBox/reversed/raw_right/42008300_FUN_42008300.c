// 42008300  FUN_42008300  FUN_42008300  size=34

undefined4 FUN_42008300(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 3) {
    FUN_42024ac8(PTR_DAT_42000848 + param_1 * 0x18 + 8,param_2);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


