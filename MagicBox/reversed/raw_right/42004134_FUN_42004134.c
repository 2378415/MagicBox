// 42004134  FUN_42004134  FUN_42004134  size=114

undefined4 FUN_42004134(uint param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  if (DAT_42000234 < param_2 + DAT_42000230) {
    uVar1 = 2;
  }
  else if ((param_2 & 3) == 0) {
    if (param_1 < 2) {
      if (param_3 == 1) {
        uVar4 = 0x7ff;
      }
      else {
        if (param_3 != 0x10) {
          return 6;
        }
        uVar4 = DAT_42000560;
      }
      if (param_1 == 0) {
        puVar3 = DAT_42000564;
      }
      else {
        puVar3 = DAT_42000568;
      }
      memw();
      memw();
      *puVar3 = uVar4 & *puVar3 ^ *puVar3;
      memw();
      uVar2 = param_2 >> 2 & 0x7ff;
      memw();
      *puVar3 = uVar2 & *puVar3 ^ *puVar3 | uVar2 & uVar4;
      uVar1 = 0;
    }
    else {
      uVar1 = 7;
    }
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}


