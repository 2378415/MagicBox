// 40380580  systimer_ll_set_alarm_period  FUN_40380580  size=130
// strings: period < (1 << 26)

void FUN_40380580(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  memw();
  uVar3 = *(uint *)*param_1;
  uVar2 = 1 << 0x20 - (0x20 - (-(param_2 + -0x18) & 0x1fU));
  memw();
  *(uint *)*param_1 = uVar2 & uVar3 ^ uVar3;
  iVar1 = *param_1;
  uVar3 = (*(code *)param_1[2])(param_3,0);
  if (DAT_40375108 < uVar3) {
    uVar3 = FUN_40381d9c(PTR_s__IDF_components_hal_esp32s3_incl_40375114,0x95,
                         PTR_s_systimer_ll_set_alarm_period_40375110,
                         PTR_s_period_<_(1_<<_26)_4037510c);
  }
  iVar1 = (param_2 + 0xc) * 4 + iVar1;
  memw();
  memw();
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xfc000000 | uVar3 & 0x3ffffff;
  memw();
  *(undefined4 *)((param_2 + 0x14) * 4 + *param_1) = 1;
  memw();
  memw();
  *(uint *)*param_1 = *(uint *)*param_1 | uVar2;
  return;
}


