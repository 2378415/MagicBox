// strings: rtc_clk_xtal_freq_get() == SOC_XTAL_FREQ_40M

void FUN_42002dc4(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 in_CCOUNT;
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [12];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  iVar1 = (*(code *)PTR_FUN_420001d8)();
  if (iVar1 != 0x28) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_clk_c_3c030c1c_0x2d_420001d0,0x4f,PTR_s_esp_clk_init_3c03c487_1_420001cc,
               PTR_s_rtc_clk_xtal_freq_get______SOC_X_420001c8);
  }
  uVar2 = (*(code *)PTR_FUN_420001dc)();
  (*(code *)PTR_FUN_420001e0)(1,uVar2);
  (*(code *)PTR_FUN_420001e4)(1);
  uStack_2c = DAT_42000170;
  uStack_30 = 0;
  uVar3 = (*(code *)PTR_FUN_420001e8)();
  (*DAT_42000174)(&uStack_30);
  (*DAT_420001ec)(&uStack_30);
  uVar2 = (*DAT_420001f0)(uVar3 * 0x640,(int)((ulonglong)uVar3 * 0x640 >> 0x20),1000,0);
  (*DAT_420001f4)(&uStack_30,0,uVar2,4);
  (*DAT_4200017c)(&uStack_30);
  FUN_42002ce4(0);
  iVar1 = (*(code *)PTR_FUN_420001e8)();
  (*DAT_42000174)(&uStack_30);
  (*DAT_420001ec)(&uStack_30);
  (*DAT_420001f4)(&uStack_30,0,iVar1 * 9,4);
  (*DAT_4200017c)(&uStack_30);
  (*(code *)PTR_FUN_420001f8)(auStack_40);
  iVar1 = (*(code *)PTR_FUN_420001fc)(0xf0,auStack_50);
  if (iVar1 == 0) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_clk_c_3c030c1c_0x2d_420001d0,0x7d,PTR_s_esp_clk_init_3c03c487_1_420001cc,
               PTR_DAT_420001d4);
  }
  (*DAT_42000200)(0);
  (*(code *)PTR_FUN_42000204)(auStack_50);
  uVar3 = rsr(in_CCOUNT);
  uVar2 = (*DAT_420001f0)(uVar3 * 0xf0,(int)((ulonglong)uVar3 * 0xf0 >> 0x20),uStack_34,0);
  wsr(in_CCOUNT,uVar2);
  return;
}