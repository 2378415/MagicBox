// strings: period < (1 << 26)

void FUN_40380688(int *param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  code *pcVar4;
  uint *puVar5;
  
  puVar2 = (uint *)*param_1;
  memw();
  uVar3 = 1 << 0x20 - (0x20 - (-(param_2 + -0x18) & 0x1fU));
  pcVar4 = (code *)param_1[2];
  memw();
  *puVar2 = uVar3 & *puVar2 ^ *puVar2;
  uVar1 = (*pcVar4)(param_3,0);
  if (DAT_403749bc < uVar1) {
    uVar1 = FUN_40381ce4(PTR_s__IDF_components_hal_esp32s3_incl_403751cc,0x95,
                         PTR_s_systimer_ll_set_alarm_period_403751c8,
                         PTR_s_period_<_(1_<<_26)_403751c4);
  }
  memw();
  puVar5 = (uint *)*param_1;
  memw();
  puVar2[param_2 + 0xd] = (uint)(CONCAT44(puVar2[param_2 + 0xd] >> 0x1a,uVar1 << 6) >> 6);
  memw();
  puVar5[param_2 + 0x14] = 1;
  memw();
  memw();
  *puVar5 = uVar3 | *puVar5;
  return;
}