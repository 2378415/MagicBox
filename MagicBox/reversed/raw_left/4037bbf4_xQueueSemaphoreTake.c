// 4037bbf4  xQueueSemaphoreTake  FUN_4037bbf4  size=257
// strings: ( pxQueue ) | pxQueue->uxItemSize == 0 | queue.c | xQueueSemaphoreTake | !( ( xTaskGetSchedulerState() == ( ( BaseType_t 

undefined4 FUN_4037bbf4(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined1 in_PRID;
  undefined1 auStack_40 [16];
  int local_30 [12];
  
  local_30[0] = param_2;
  if (param_1 == (int *)0x0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x6ad,PTR_s_xQueueSemaphoreTake_40374d60,
                 PTR_s___pxQueue___40374d54);
  }
  iVar2 = param_1[0x10];
  if (iVar2 != 0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x6b1,PTR_s_xQueueSemaphoreTake_40374d60,
                 PTR_s_pxQueue_>uxItemSize____0_40374d4c);
  }
  iVar1 = FUN_4037e0e0();
  if ((iVar1 == 0) && (iVar2 = 0, local_30[0] != 0)) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x6b6,PTR_s_xQueueSemaphoreTake_40374d60,
                 PTR_s______xTaskGetSchedulerState______40374d38);
  }
  piVar3 = param_1 + 0x13;
  iVar1 = iVar2;
  while( true ) {
    FUN_4037bf44(piVar3,0xffffffff);
    memw();
    if (param_1[0xe] != 0) {
      memw();
      param_1[0xe] = param_1[0xe] + -1;
      if (*param_1 == 0) {
        iVar2 = FUN_4037e3b0();
        param_1[2] = iVar2;
      }
      memw();
      if ((param_1[4] != 0) && (iVar2 = FUN_4037dde4(param_1 + 4), iVar2 != 0)) {
        uVar4 = rsr(in_PRID);
        FUN_40378e40(uVar4 >> 0xd & 1);
      }
      FUN_4037c094(piVar3);
      return 1;
    }
    if (local_30[0] == 0) break;
    if (iVar1 == 0) {
      FUN_4037dfb8(auStack_40);
    }
    iVar1 = FUN_4037dfd4(auStack_40,local_30);
    if (iVar1 != 0) {
      if (iVar2 != 0) {
        memw();
        iVar2 = 0;
        if (param_1[9] != 0) {
          memw();
          memw();
          iVar2 = -(*(int *)param_1[0xc] + -0x19);
        }
        FUN_4037e2cc(param_1[2],iVar2);
      }
      break;
    }
    if (*param_1 == 0) {
      iVar2 = FUN_4037e114(param_1[2]);
    }
    FUN_4037dce8(param_1 + 9,local_30[0]);
    uVar4 = rsr(in_PRID);
    FUN_40378e40(uVar4 >> 0xd & 1);
    FUN_4037c094(piVar3);
    iVar1 = 1;
  }
  FUN_4037c094(piVar3);
  return 0;
}


