// 4037b39c  xQueueGenericSend  FUN_4037b39c  size=313
// strings: pxQueue | !( ( pvItemToQueue == ((void *)0) ) && ( pxQueue | queue.c | xQueueGenericSend | !( ( xCopyPosition == ( ( BaseType_t ) 2 ) ) &&  | !( ( xTaskGetSchedulerState() == ( ( BaseType_t 

undefined4 FUN_4037b39c(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 in_PRID;
  undefined1 auStack_40 [16];
  int local_30 [12];
  
  local_30[0] = param_3;
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x3a8,PTR_s_xQueueGenericSend_40374c78,
                 PTR_s_pxQueue_40374c3c);
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x3a9,PTR_s_xQueueGenericSend_40374c78,
                 PTR_s______pvItemToQueue______void___0_40374c7c);
  }
  if ((param_4 == 2) && (*(int *)(param_1 + 0x3c) != 1)) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x3aa,PTR_s_xQueueGenericSend_40374c78,
                 PTR_s______xCopyPosition________BaseTy_40374c80);
  }
  iVar2 = FUN_4037db0c();
  if (iVar2 == 0) {
    bVar1 = false;
    if (local_30[0] == 0) goto LAB_4037b404;
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x3ad,PTR_s_xQueueGenericSend_40374c78,
                 PTR_s______xTaskGetSchedulerState______40374c84);
  }
  bVar1 = false;
LAB_4037b404:
  while( true ) {
    iVar2 = param_1 + 0x4c;
    FUN_4037bbe8(iVar2,0xffffffff);
    memw();
    if ((*(uint *)(param_1 + 0x38) < *(uint *)(param_1 + 0x3c)) || (param_4 == 2)) {
      memw();
      iVar4 = *(int *)(param_1 + 0x38);
      iVar3 = FUN_4037afa0(param_1,param_2,param_4);
      if (*(int *)(param_1 + 0x48) == 0) {
        memw();
        if (*(int *)(param_1 + 0x24) == 0) {
          if (iVar3 != 0) {
            uVar5 = rsr(in_PRID);
            FUN_403787f4(uVar5 >> 0xd & 1);
          }
        }
        else {
          iVar3 = FUN_4037d664(param_1 + 0x24);
          if (iVar3 != 0) {
            uVar5 = rsr(in_PRID);
            FUN_403787f4(uVar5 >> 0xd & 1);
          }
        }
      }
      else if ((param_4 != 2 || iVar4 == 0) && (iVar3 = FUN_4037b054(param_1), iVar3 != 0)) {
        uVar5 = rsr(in_PRID);
        FUN_403787f4(uVar5 >> 0xd & 1);
      }
      FUN_4037bd38(iVar2);
      return 1;
    }
    if (local_30[0] == 0) {
      FUN_4037bd38(iVar2);
      return 0;
    }
    if (!bVar1) {
      FUN_4037d860(auStack_40);
      bVar1 = true;
    }
    iVar3 = FUN_4037d87c(auStack_40,local_30);
    if (iVar3 != 0) break;
    FUN_4037d564(param_1 + 0x10,local_30[0]);
    uVar5 = rsr(in_PRID);
    FUN_403787f4(uVar5 >> 0xd & 1);
    FUN_4037bd38(iVar2);
  }
  FUN_4037bd38(iVar2);
  return 0;
}


