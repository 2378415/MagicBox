// strings: slowclk_cycles

undefined4 FUN_40379fe8(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int in_t0;
  undefined8 uVar9;
  
  if (param_2 == 0) {
    FUN_40381ce4(PTR_s_rtc_time_c_3c033f88_0x2d_40374b10,0x93,PTR_s_rtc_clk_cal_40374b0c,
                 PTR_s_slowclk_cycles_40374b08);
  }
  uVar2 = FUN_40379564();
  uVar3 = FUN_40379d38(param_1,param_2);
  uVar8 = uVar2 * param_2;
  uVar2 = (uint)((ulonglong)uVar2 * (ulonglong)param_2 >> 0x20);
  if (param_1 == 2) {
    uVar7 = uVar2 * DAT_403746f8 + (int)((ulonglong)uVar8 * (ulonglong)DAT_403746f8 >> 0x20);
    iVar1 = (int)(CONCAT44(uVar7,uVar8 * DAT_403746f8) >> 0xf);
    uVar7 = uVar7 >> 0xf;
    uVar9 = (*DAT_40374500)(iVar1,uVar7,2000,0);
    iVar6 = (int)((ulonglong)uVar9 >> 0x20);
    iVar4 = (int)uVar9;
    if ((uVar7 - iVar6 != in_t0) || (uVar3 < (uint)(iVar1 - iVar4))) {
      return 0;
    }
    if ((uVar7 + iVar6 + iVar4 == 0) && ((uint)(iVar1 + iVar4) < uVar3)) {
      return 0;
    }
  }
  iVar1 = (int)(CONCAT44(uVar2,uVar8) >> 1);
  uVar7 = (uVar3 >> 0xd) - 1;
  if (uVar3 * 0x80000 != 0) {
    uVar7 = uVar3 >> 0xd;
  }
  uVar5 = (*DAT_40374500)(uVar3 * 0x80000 + -1 + iVar1,uVar7 + (uVar2 >> 1) + iVar1,uVar8,uVar2);
  return uVar5;
}