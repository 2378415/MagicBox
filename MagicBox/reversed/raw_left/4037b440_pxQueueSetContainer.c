// 4037b440  pxQueueSetContainer  FUN_4037b440  size=118
// strings: pxQueueSetContainer | pxQueueSetContainer->uxMessagesWaiting < pxQueue | queue.c | prvNotifyQueueSetContainer

void FUN_4037b440(int param_1)

{
  int iVar1;
  int local_30 [12];
  
  iVar1 = *(int *)(param_1 + 0x48);
  local_30[0] = param_1;
  if (iVar1 == 0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,DAT_40374ce0,
                 PTR_s_prvNotifyQueueSetContainer_40374cdc,PTR_s_pxQueueSetContainer_40374cd8);
  }
  memw();
  if (*(uint *)(iVar1 + 0x3c) <= *(uint *)(iVar1 + 0x38)) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,DAT_40374cec,
                 PTR_s_prvNotifyQueueSetContainer_40374cdc,
                 PTR_s_pxQueueSetContainer_>uxMessagesW_40374ce8);
  }
  FUN_4037bf20();
  FUN_4037bf44(iVar1 + 0x4c,0xffffffff);
  memw();
  if (*(uint *)(iVar1 + 0x38) < *(uint *)(iVar1 + 0x3c)) {
    FUN_4037b3b8(iVar1,local_30,0);
    memw();
    if (*(int *)(iVar1 + 0x24) != 0) {
      FUN_4037dde4(iVar1 + 0x24);
    }
  }
  FUN_4037bf20();
  FUN_4037c094(iVar1 + 0x4c);
  return;
}


