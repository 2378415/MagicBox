// strings: ( pxQueue ) | pxQueue->uxItemSize == 0 | queue.c | xQueueSemaphoreTake | `V r | !( ( xTaskGetSchedulerState() == ( ( BaseType_t 

undefined4 FUN_4037b80c(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  undefined1 in_PRID;
  undefined1 auStack_40 [16];
  int local_30 [12];
  
  local_30[0] = param_2;
  if (param_1 == (int *)0x0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x6ad,PTR_s_xQueueSemaphoreTake_40374cb8,
                 PTR_s___pxQueue___40374cac);
  }
  if (param_1[0x10] != 0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x6b1,PTR_s_xQueueSemaphoreTake_40374cb8,
                 PTR_s_pxQueue_>uxItemSize____0_40374ca4);
  }
  iVar2 = FUN_4037db0c();
  if (iVar2 == 0) {
    if (local_30[0] == 0) {
      iVar2 = 0;
      bVar1 = false;
      goto LAB_4037b864;
    }
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x6b6,PTR_s_xQueueSemaphoreTake_40374cb8,
                 PTR_s______xTaskGetSchedulerState______40374c84);
  }
  iVar2 = 0;
  bVar1 = false;
LAB_4037b864:
  while( true ) {
    piVar5 = param_1 + 0x13;
    FUN_4037bbe8(piVar5,0xffffffff);
    memw();
    if (param_1[0xe] != 0) {
      memw();
      param_1[0xe] = param_1[0xe] + -1;
      if (*param_1 == 0) {
        iVar2 = FUN_4037e154();
        param_1[2] = iVar2;
      }
      memw();
      if ((param_1[4] != 0) && (iVar2 = FUN_4037d664(param_1 + 4), iVar2 != 0)) {
        uVar6 = rsr(in_PRID);
        FUN_403787f4(uVar6 >> 0xd & 1);
      }
      FUN_4037bd38(piVar5);
      return 1;
    }
    if (local_30[0] == 0) break;
    if (!bVar1) {
      FUN_4037d860(auStack_40);
      bVar1 = true;
    }
    iVar3 = FUN_4037d87c(auStack_40,local_30);
    if (iVar3 != 0) {
      if (iVar2 != 0) {
        uVar4 = FUN_4037c898(param_1);
        FUN_4037e05c(param_1[2],uVar4);
      }
      FUN_4037bd38(piVar5);
      return 0;
    }
    if (*param_1 == 0) {
      iVar2 = FUN_4037de64(param_1[2]);
    }
    FUN_4037d564(param_1 + 9,local_30[0]);
    uVar6 = rsr(in_PRID);
    FUN_403787f4(uVar6 >> 0xd & 1);
    FUN_4037bd38(piVar5);
  }
  FUN_4037bd38(piVar5);
  return 0;
}