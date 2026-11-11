// 4037a08c  rtc_time_us_to_slowclk  FUN_4037a08c  size=129
// strings: period

undefined8 FUN_4037a08c(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  if (param_3 == 0) {
    FUN_40381ce4(PTR_s_rtc_time_c_3c033f88_0x2d_40374b10,0xa3,PTR_s_rtc_time_us_to_slowclk_40374b18,
                 PTR_s_period_40374b14);
  }
  if (DAT_40374608 < param_2) {
    uVar3 = (*DAT_4037479c)(param_1,param_2,param_3,0);
    uVar2 = (*DAT_40374500)((int)uVar3 << 0x13,(int)(uVar3 >> 0xd),param_3,0);
    uVar3 = (*DAT_40374500)(param_1,param_2,param_3,0);
    iVar1 = (int)uVar3 * 0x80000;
    uVar2 = CONCAT44((int)((ulonglong)uVar2 >> 0x20) + (int)(uVar3 >> 0xd) + iVar1,
                     (int)uVar2 + iVar1);
  }
  else {
    uVar2 = (*DAT_40374500)(param_1 << 0x13,(int)(CONCAT44(param_2,param_1) >> 0xd));
  }
  return uVar2;
}


