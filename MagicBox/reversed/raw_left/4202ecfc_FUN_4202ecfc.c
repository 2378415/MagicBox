// 4202ecfc  FUN_4202ecfc  FUN_4202ecfc  size=87

uint FUN_4202ecfc(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_2 == 0) || (param_1 == 0 || param_2 == 0)) {
    param_2 = 0;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x10);
    if (param_2 < (uVar2 >> 0x17 & 0xff)) {
      uVar1 = param_2 + 3 & 0xfffffffc;
      param_2 = 0;
      if (uVar1 < (uint)(1 << 0x20 - (0x20 - (uVar2 >> 8 & 0x1f)))) {
        param_2 = (uint)(uVar1 < 0xc) * 0xc + (uVar1 >= 0xc) * uVar1;
      }
    }
    else {
      param_2 = -((int)(DAT_420014c0 >> (LZCOUNT(param_2) & 0x1fU)) / (int)(uVar2 >> 0xe & 0x3f)) &
                param_2;
    }
  }
  return param_2;
}


