// strings: slowclk_cycles | W2D'

undefined4 FUN_40379a48(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  
  if (param_2 == 0) {
    FUN_40381d9c(PTR_s_rtc_time_c_3c0317f4_0x2d_40374a54,0x93,PTR_s_rtc_clk_cal_40374a50,
                 PTR_s_slowclk_cycles_40374a4c);
  }
  uVar1 = FUN_403791f8();
  uVar2 = FUN_40379820(param_1,param_2);
  if (param_1 == 2) {
    uVar3 = (int)((ulonglong)uVar1 * (ulonglong)param_2 >> 0x20) * DAT_403746b8 +
            (int)((ulonglong)(uVar1 * param_2) * (ulonglong)DAT_403746b8 >> 0x20);
    uVar7 = uVar3 * 0x20000 | uVar1 * param_2 * DAT_403746b8 >> 0xf;
    uVar3 = uVar3 >> 0xf;
    uVar10 = (*DAT_403744c8)(uVar7,uVar3,2000,0);
    iVar5 = (int)((ulonglong)uVar10 >> 0x20);
    uVar4 = (uint)uVar10;
    iVar8 = uVar3 - iVar5;
    if (uVar7 < uVar4) {
      iVar8 = iVar8 + -1;
    }
    if ((iVar8 != 0) || (uVar2 < uVar7 - uVar4)) {
      return 0;
    }
    iVar5 = uVar3 + iVar5;
    if (uVar7 + uVar4 < uVar4) {
      iVar5 = iVar5 + 1;
    }
    if ((iVar5 == 0) && (uVar7 + uVar4 < uVar2)) {
      return 0;
    }
  }
  uVar3 = (uint)((ulonglong)uVar1 * (ulonglong)param_2 >> 0x20);
  uVar1 = uVar3 << 0x1f | uVar1 * param_2 >> 1;
  iVar5 = (uVar2 >> 0xd) + (uVar3 >> 1);
  uVar2 = uVar2 * 0x80000 + uVar1;
  if (uVar2 < uVar1) {
    iVar5 = iVar5 + 1;
  }
  iVar9 = uVar2 - 1;
  iVar8 = iVar5 + -1;
  if (iVar9 != -1) {
    iVar8 = iVar5;
  }
  uVar6 = (*DAT_403744c8)(iVar9,iVar8);
  return uVar6;
}