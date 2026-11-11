// 4202481c  FUN_4202481c  FUN_4202481c  size=73

undefined4 FUN_4202481c(byte *param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if ((param_2 - 1 & 0xff) < 0x7e) {
    uVar3 = param_2 >> 5;
    uVar4 = *(uint *)(param_1 + uVar3 * 4 + 4);
    uVar2 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
    uVar5 = uVar4 | uVar2;
    *(uint *)(param_1 + uVar3 * 4 + 4) = uVar5;
    if (uVar5 == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      *(uint *)(param_1 + uVar3 * 4 + 4) = uVar2 & uVar4 ^ uVar4;
      if (param_2 < *param_1) {
        *param_1 = (byte)param_2;
        uVar1 = 0;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


