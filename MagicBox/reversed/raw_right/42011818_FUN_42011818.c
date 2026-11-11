// 42011818  FUN_42011818  FUN_42011818  size=104

undefined4 FUN_42011818(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((int)param_1 < 0) {
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
      if ((param_2 & 1) == 0) {
        FUN_42010bec(param_1);
      }
      else {
        FUN_42010c4c(param_1);
      }
      if ((param_2 & 2) == 0) {
        FUN_42010cac(param_1);
        uVar1 = 0;
      }
      else {
        FUN_42010d0c(param_1);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


