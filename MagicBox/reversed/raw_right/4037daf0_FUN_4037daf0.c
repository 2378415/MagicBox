// 4037daf0  FUN_4037daf0  FUN_4037daf0  size=28

undefined4 FUN_4037daf0(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 2) {
    if (param_1 == 0) {
      param_1 = FUN_4037d934();
    }
    uVar1 = *(undefined4 *)((param_2 + 0x14) * 4 + param_1 + 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


