// strings: period

undefined8 FUN_40379b10(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  if (param_3 == 0) {
    FUN_40381d9c(PTR_s_rtc_time_c_3c0317f4_0x2d_40374a54,0xa3,PTR_s_rtc_time_us_to_slowclk_40374a5c,
                 PTR_s_period_40374a58);
  }
  if (DAT_403745dc < param_2) {
    uVar3 = (*DAT_403744c8)(param_1,param_2,param_3,0);
    lVar4 = (*DAT_4037475c)(param_1,param_2,param_3,0);
    uVar5 = (*DAT_403744c8)((int)(lVar4 << 0x13),(int)((ulonglong)(lVar4 << 0x13) >> 0x20),param_3,0
                           );
    iVar2 = ((uint)uVar3 >> 0xd | (int)((ulonglong)uVar3 >> 0x20) << 0x13) +
            (int)((ulonglong)uVar5 >> 0x20);
    uVar1 = (uint)uVar3 * 0x80000 + (uint)uVar5;
    uVar3 = CONCAT44(iVar2,uVar1);
    if (uVar1 < (uint)uVar5) {
      uVar3 = CONCAT44(iVar2 + 1,uVar1);
    }
  }
  else {
    uVar3 = (*DAT_403744c8)(param_1 << 0x13,param_1 >> 0xd | param_2 << 0x13,param_3,0);
  }
  return uVar3;
}