undefined4 FUN_42025750(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = DAT_42000108;
  if (param_1 != 3) {
    if (param_1 < 3) {
      uVar1 = DAT_42000104;
    }
    else if (param_1 < 0x27) {
      if (param_1 < 9) {
        uVar1 = DAT_42000104;
      }
      else {
        uVar2 = 1 << 0x20 - (0x20 - (param_1 - 9 & 0x1f));
        if ((uVar2 & DAT_42001358) == 0) {
          if ((uVar2 >> 0x10 & 0x3f) == 0) {
            if ((uVar2 & 0x20000000) == 0) {
              uVar1 = DAT_42000104;
            }
            else {
              uVar1 = DAT_42001360;
            }
          }
          else {
            uVar1 = DAT_4200135c;
          }
        }
      }
    }
    else {
      uVar1 = DAT_42000104;
    }
  }
  return uVar1;
}