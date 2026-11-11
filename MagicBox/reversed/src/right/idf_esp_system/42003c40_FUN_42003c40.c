void FUN_42003c40(char param_1)

{
  uint uVar1;
  uint uVar2;
  
  for (uVar2 = 0; (int)uVar2 < 0x31; uVar2 = uVar2 + 1) {
    if (-1 < (int)uVar2) {
      uVar1 = DAT_42000504 << 0x20 - (0x20 - ((uVar2 ^ 0xffffffff) & 0x1f)) |
              DAT_42000508 >> (uVar2 & 0x1f);
      if ((uVar2 & 0x20) != 0) {
        uVar1 = DAT_4200050c >> (uVar2 & 0x1f);
      }
      if ((uVar1 & 1) != 0) {
        uVar1 = FUN_42012938(3);
        if (uVar2 == uVar1) {
          FUN_420119b0(uVar2);
        }
        else if (param_1 == '\0') {
          FUN_420119b0(uVar2);
        }
        else {
          FUN_4201193c(uVar2);
        }
      }
    }
  }
  return;
}