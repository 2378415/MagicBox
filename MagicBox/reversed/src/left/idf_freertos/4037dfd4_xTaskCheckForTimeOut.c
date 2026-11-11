// strings: pxTimeOut | pxTicksToWait | tasks.c | xTaskCheckForTimeOut

undefined4 FUN_4037dfd4(undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined1 in_PRID;
  
  if (param_1 == (undefined4 *)0x0) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374fcc,
                 PTR_s_xTaskCheckForTimeOut_40374fc8,PTR_s_pxTimeOut_40374fc4);
  }
  if (param_2 == (uint *)0x0) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374fd4,
                 PTR_s_xTaskCheckForTimeOut_40374fc8,PTR_s_pxTicksToWait_40374fd0);
  }
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  memw();
  uVar2 = rsr(in_PRID);
  piVar3 = (int *)((uVar2 >> 0xd & 1) * 4 + DAT_40374e18);
  memw();
  if (*(char *)(*piVar3 + 0x152) == '\0') {
    uVar2 = *param_2;
    if (uVar2 != 0xffffffff) {
      memw();
      if (uVar2 <= (uint)(*DAT_40374edc - param_1[1])) {
        *param_2 = 0;
        goto LAB_4037e061;
      }
      memw();
      uVar1 = *DAT_40374f74;
      memw();
      iVar4 = *DAT_40374edc;
      *param_2 = (uVar2 - *DAT_40374edc) + param_1[1];
      *param_1 = uVar1;
      param_1[1] = iVar4;
    }
    uVar1 = 0;
  }
  else {
    memw();
    *(undefined1 *)(*piVar3 + 0x152) = 0;
LAB_4037e061:
    uVar1 = 1;
  }
  FUN_4037c094(PTR_DAT_40374ef4);
  return uVar1;
}