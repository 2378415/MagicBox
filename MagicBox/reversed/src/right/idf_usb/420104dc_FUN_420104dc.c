undefined4 FUN_420104dc(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1 == 0xffffffff) {
    uVar1 = 0;
  }
  else if ((int)param_1 < 0) {
    uVar1 = 0x102;
  }
  else {
    uVar2 = DAT_42000504 << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000508 >> (param_1 & 0x1f);
    if ((param_1 & 0x20) != 0) {
      uVar2 = DAT_4200050c >> (param_1 & 0x1f);
    }
    if ((uVar2 & 1) == 0) {
      uVar1 = 0x102;
    }
    else {
      (*DAT_42000db0)(param_1);
      (*DAT_420008d0)(param_1,param_2,0);
      (*DAT_42000db4)(param_1);
      uVar1 = 0;
    }
  }
  return uVar1;
}