// strings: pxQueueSetContainer | pxQueueSetContainer->uxMessagesWaiting < pxQueue | queue.c | prvNotifyQueueSetContainer

void FUN_4037b054(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_30 [12];
  
  iVar3 = *(int *)(param_1 + 0x48);
  local_30[0] = param_1;
  if (iVar3 == 0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,DAT_40374c2c,
                 PTR_s_prvNotifyQueueSetContainer_40374c28,PTR_s_pxQueueSetContainer_40374c24);
  }
  memw();
  if (*(uint *)(iVar3 + 0x3c) <= *(uint *)(iVar3 + 0x38)) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,DAT_40374c38,
                 PTR_s_prvNotifyQueueSetContainer_40374c28,
                 PTR_s_pxQueueSetContainer_>uxMessagesW_40374c34);
  }
  iVar2 = iVar3 + 0x4c;
  iVar1 = FUN_4037bbc4();
  if (iVar1 == 0) {
    FUN_4037bbe8(iVar2,0xffffffff);
  }
  else {
    FUN_4037bbe8(iVar2,0xffffffff);
  }
  memw();
  if (*(uint *)(iVar3 + 0x38) < *(uint *)(iVar3 + 0x3c)) {
    FUN_4037afa0(iVar3,local_30,0);
    memw();
    if (*(int *)(iVar3 + 0x24) != 0) {
      FUN_4037d664(iVar3 + 0x24);
    }
  }
  iVar3 = FUN_4037bbc4();
  if (iVar3 == 0) {
    FUN_4037bd38(iVar2);
  }
  else {
    FUN_4037bd38(iVar2);
  }
  return;
}