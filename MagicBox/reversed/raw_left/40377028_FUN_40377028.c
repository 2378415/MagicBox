// 40377028  FUN_40377028  FUN_40377028  size=86
// strings: alarm_id < sizeof(timestamp_id) / sizeof(timesta

void FUN_40377028(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (1 < param_3) {
    FUN_40381ce4(PTR_s_esp_timer_impl_systimer_c_3c03591c_0x1f_403747b4,0x4f,
                 PTR_s_esp_timer_impl_set_alarm_id_403747b0,
                 PTR_s_alarm_id_<_sizeof(timestamp_id)___403747ac);
  }
  FUN_4037bf20();
  FUN_4037bf44(PTR_DAT_403747b8,0xffffffff);
  puVar1 = PTR_DAT_403747bc;
  puVar2 = (undefined4 *)(PTR_DAT_403747bc + param_3 * 8);
  *puVar2 = param_1;
  puVar2[1] = param_2;
  uVar3 = *(uint *)(puVar1 + 4);
  uVar5 = *(uint *)(puVar1 + 0xc);
  uVar4 = *(uint *)(puVar1 + 8);
  if ((uVar3 < uVar5) || ((uVar5 == uVar3 && (*(uint *)puVar1 < uVar4)))) {
    uVar4 = *(uint *)puVar1;
    uVar5 = uVar3;
  }
  FUN_403807a8(DAT_403747a4,2,uVar4,uVar5);
  FUN_4037bf20();
  FUN_4037c094(PTR_DAT_403747b8);
  return;
}


