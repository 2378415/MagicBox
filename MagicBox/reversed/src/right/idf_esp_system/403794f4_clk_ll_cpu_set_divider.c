// strings: divider > 0

void FUN_403794f4(int param_1,int param_2)

{
  uint *puVar1;
  undefined1 auStack_30 [12];
  int iStack_24;
  
  FUN_40379294(auStack_30);
  (*DAT_403749f8)(param_1);
  memw();
  memw();
  *DAT_403749d0 = *DAT_403749d0 & 0xfffffc00;
  if (param_2 == 0) {
    FUN_40381d9c(PTR_s__IDF_components_hal_esp32s3_incl_403749b8,0x1e4,
                 PTR_s_clk_ll_cpu_set_divider_40374a00,PTR_s_divider_>_0_403749fc);
  }
  puVar1 = DAT_403749d0;
  memw();
  memw();
  *DAT_403749d0 = *DAT_403749d0 & 0xfffffc00 | param_2 - 1U & 0x3ff;
  memw();
  memw();
  *puVar1 = *puVar1 & DAT_403749ec;
  FUN_40379368(param_1 * DAT_403746b8);
  if (iStack_24 == 0xf0) {
    FUN_4037690c(0x6d,1,4,4,0,*PTR_DAT_403749f0);
    FUN_4037690c(0x6d,1,6,4,0,*PTR_DAT_403749f4);
    (*DAT_40374434)(0x28);
  }
  memw();
  memw();
  *DAT_403749e4 = *DAT_403749e4 & DAT_403749e8 | DAT_40374a04;
  return;
}