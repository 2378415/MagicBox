// 42011a24  FUN_42011a24  FUN_42011a24  size=139

undefined4 FUN_42011a24(uint param_1,uint param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if ((int)param_1 < 0) {
    uVar2 = 0x102;
  }
  else {
    uVar3 = DAT_42000504 << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000508 >> (param_1 & 0x1f);
    if ((param_1 & 0x20) != 0) {
      uVar3 = DAT_4200050c >> (param_1 & 0x1f);
    }
    if ((uVar3 & 1) == 0) {
      uVar2 = 0x102;
    }
    else {
      if (((param_1 & 0xff) - 0x13 & 0xff) < 2) {
        memw();
        memw();
        *DAT_42000df4 = *DAT_42000df4 & DAT_4200016c;
      }
      puVar1 = (uint *)(((param_1 & 0xff) + DAT_42000de8) * 4);
      memw();
      memw();
      *puVar1 = *puVar1 & DAT_4200052c | (param_2 & 7) << 0xc;
      uVar2 = 0;
    }
  }
  return uVar2;
}


