uint FUN_42026808(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 == 0 || param_1 == 0) {
    uVar1 = 0;
  }
  else if (param_2 < (*(uint *)(param_1 + 0x10) >> 0x17 & 0xff)) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = param_2 + 3 & 0xfffffffc;
      if (param_1 == 0) {
        uVar1 = 0;
      }
      else if (uVar1 < (uint)(1 << 0x20 - (0x20 - (*(uint *)(param_1 + 0x10) >> 8 & 0x1f)))) {
        uVar1 = (uint)(uVar1 < 0xc) * 0xc + (uVar1 >= 0xc) * uVar1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = -((int)(DAT_42000afc >> (LZCOUNT(param_2) & 0x1fU)) /
             (int)(*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)) & param_2;
  }
  return uVar1;
}