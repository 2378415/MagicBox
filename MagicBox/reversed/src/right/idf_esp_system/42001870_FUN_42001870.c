// strings: rtc_clk_xtal_freq_get() == SOC_XTAL_FREQ_40M

void FUN_42001870(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 in_CCOUNT;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [12];
  undefined4 uStack_3c;
  undefined1 auStack_38 [56];
  
  iVar1 = (*(code *)PTR_FUN_420000c0)();
  if (iVar1 != 0x28) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_clk_c_3c030190_0x2d_420000b4,0x4f,PTR_s_esp_clk_init_3c036893_1_420000b0,
               PTR_s_rtc_clk_xtal_freq_get______SOC_X_420000ac);
  }
  uVar2 = (*(code *)PTR_FUN_420000c4)();
  (*(code *)PTR_FUN_42000094)(1,uVar2);
  (*(code *)PTR_FUN_420000c8)(1);
  local_50 = 0;
  uStack_4c = DAT_4200004c;
  uVar3 = (*(code *)PTR_FUN_420000cc)();
  uVar2 = (*DAT_420000d0)(uVar3 * 0x640,(int)((ulonglong)uVar3 * 0x640 >> 0x20),1000,0);
  (*DAT_42000050)(&local_50);
  (*DAT_420000d4)(&local_50);
  (*DAT_420000d8)(&local_50,0,uVar2,4);
  (*DAT_42000058)(&local_50);
  FUN_420017d8(0);
  uVar3 = (*(code *)PTR_FUN_420000cc)();
  uVar2 = (*DAT_420000d0)(uVar3 * DAT_420000b8,
                          (int)((ulonglong)uVar3 * (ulonglong)DAT_420000b8 >> 0x20),1000,0);
  (*DAT_42000050)(&local_50);
  (*DAT_420000d4)(&local_50);
  (*DAT_420000d8)(&local_50,0,uVar2,4);
  (*DAT_42000058)(&local_50);
  (*(code *)PTR_FUN_420000dc)(auStack_48);
  iVar1 = (*(code *)PTR_FUN_420000e0)(0xa0,auStack_38);
  if (iVar1 == 0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_clk_c_3c030190_0x2d_420000b4,0x7d,PTR_s_esp_clk_init_3c036893_1_420000b0,
               PTR_DAT_420000bc);
  }
  (*DAT_420000e4)(0);
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_420000e8)(auStack_38);
  }
  uVar3 = rsr(in_CCOUNT);
  uVar2 = (*DAT_420000d0)(uVar3 * 0xa0,(int)((ulonglong)uVar3 * 0xa0 >> 0x20),uStack_3c,0);
  wsr(in_CCOUNT,uVar2);
  return;
}