// strings: divider > 0

void FUN_40379894(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *in_t0;
  undefined1 auStack_30 [12];
  int iStack_24;
  
  FUN_40379604(auStack_30);
  (*DAT_40374aa0)(param_1);
  puVar1 = DAT_40374a70;
  uVar2 = 0xfffffc00;
  memw();
  memw();
  *DAT_40374a70 = *DAT_40374a70 & 0xfffffc00;
  if (param_2 == 0) {
    puVar1 = in_t0;
    uVar2 = FUN_40381ce4(PTR_s__IDF_components_hal_esp32s3_incl_40374a14,0x1e4,
                         PTR_s_clk_ll_cpu_set_divider_40374aa8,PTR_s_divider_>_0_40374aa4);
  }
  memw();
  memw();
  *puVar1 = param_2 - 1U & 0x3ff | *puVar1 & uVar2;
  memw();
  memw();
  *puVar1 = *puVar1 & DAT_40374a90;
  *DAT_40374a94 = param_1 * DAT_403746f8;
  if (iStack_24 == 0xf0) {
    FUN_40376b50(0x6d,1,4,4,0,*PTR_DAT_40374a98);
    FUN_40376b50(0x6d,1,6,4,0,*PTR_DAT_40374a9c);
    (*DAT_40374444)(0x28);
  }
  memw();
  memw();
  *DAT_40374a88 = *DAT_40374a88 & DAT_40374a8c | DAT_40374aac;
  return;
}