// 42015130  FUN_42015130  FUN_42015130  size=32

undefined4 FUN_42015130(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  if ((param_4 & 0xf) == 0) {
    uVar1 = FUN_42011ec0(*(undefined4 *)(param_1 + 0xc),param_2,param_3,param_4);
  }
  else {
    uVar1 = 0x102;
  }
  return uVar1;
}


