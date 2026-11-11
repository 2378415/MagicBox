// 40379604  FUN_40379604  FUN_40379604  size=174
// strings: rtc_clk

void FUN_40379604(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  memw();
  uVar4 = *DAT_40374a70 >> 10 & 3;
  if (uVar4 == 1) {
    memw();
    memw();
    uVar1 = *DAT_40374a74;
    uVar3 = *DAT_40374a74 & 3;
    if (uVar3 == 1) {
      if ((uVar1 & 4) == 0) {
        uVar5 = 0xa0;
        uVar3 = 2;
        uVar1 = 0x140;
      }
      else {
        uVar5 = 0xa0;
        uVar3 = 3;
        uVar1 = 0x1e0;
      }
    }
    else if (uVar3 == 2) {
      if ((uVar1 & 4) == 0) goto LAB_4037966d;
      uVar5 = 0xf0;
      uVar1 = 0x1e0;
      uVar3 = 2;
    }
    else {
      if (uVar3 != 0) {
LAB_4037966d:
        if (*(int *)PTR_DAT_40374414 == 0) {
          return;
        }
        uVar2 = FUN_40381bb0();
        (*DAT_40374438)(PTR_DAT_40374a78,uVar2,PTR_s_rtc_clk_40374a68);
        return;
      }
      uVar3 = 4;
      if ((uVar1 & 4) == 0) {
        uVar5 = 0x50;
        uVar1 = 0x140;
      }
      else {
        uVar5 = 0x50;
        uVar3 = 6;
        uVar1 = 0x1e0;
      }
    }
  }
  else if (uVar4 == 2) {
    uVar5 = 0x14;
    uVar3 = 1;
    uVar1 = 0x14;
  }
  else {
    if (uVar4 != 0) goto LAB_4037966d;
    memw();
    uVar3 = *DAT_40374a70;
    uVar1 = FUN_40379564();
    uVar3 = (uVar3 & 0x3ff) + 1;
    uVar5 = uVar1 / uVar3;
  }
  *param_1 = uVar4;
  param_1[1] = uVar1;
  param_1[2] = uVar3;
  param_1[3] = uVar5;
  return;
}


