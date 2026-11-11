// 42011888  FUN_42011888  FUN_42011888  size=169
// strings: &39'

undefined4 FUN_42011888(uint param_1,uint param_2)

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
    else if (param_2 < 4) {
      if (param_2 == 2) {
        FUN_42010d6c(param_1);
        FUN_42010de0(param_1);
        uVar1 = 0;
      }
      else if (param_2 < 3) {
        if (param_2 == 0) {
          FUN_42010e54(param_1);
          FUN_42010de0(param_1);
          uVar1 = 0;
        }
        else if (param_2 == 1) {
          FUN_42010d6c(param_1);
          FUN_42010ec8(param_1);
          uVar1 = 0;
        }
        else {
          uVar1 = 0x102;
        }
      }
      else if (param_2 == 3) {
        FUN_42010e54(param_1);
        FUN_42010ec8(param_1);
        uVar1 = 0;
      }
      else {
        uVar1 = 0x102;
      }
    }
    else {
      uVar1 = 0x102;
    }
  }
  return uVar1;
}


