void FUN_4037e95c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 < 1) {
    FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
    if (param_1 == 0) {
      param_1 = FUN_4037d934();
    }
    *(undefined4 *)((param_2 + 0x14) * 4 + param_1 + 4) = param_3;
    *(undefined4 *)((param_2 + 0x15) * 4 + param_1 + 4) = param_4;
    FUN_4037bd38(PTR_DAT_40374e54);
  }
  return;
}