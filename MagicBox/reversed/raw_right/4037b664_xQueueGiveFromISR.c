// 4037b664  xQueueGiveFromISR  FUN_4037b664  size=184
// strings: pxQueue | pxQueue->uxItemSize == 0 | queue.c | xQueueGiveFromISR | !( ( pxQueue->pcHead == ((void *)0) ) && ( pxQue

undefined4 FUN_4037b664(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (int *)0x0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x54e,PTR_s_xQueueGiveFromISR_40374ca0,
                 PTR_s_pxQueue_40374c3c);
  }
  if (param_1[0x10] != 0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x552,PTR_s_xQueueGiveFromISR_40374ca0,
                 PTR_s_pxQueue_>uxItemSize____0_40374ca4);
  }
  if ((*param_1 == 0) && (param_1[2] != 0)) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x557,PTR_s_xQueueGiveFromISR_40374ca0,
                 PTR_s______pxQueue_>pcHead______void___40374ca8);
  }
  FUN_4037bbe8(param_1 + 0x13,0xffffffff);
  memw();
  if ((uint)param_1[0xe] < (uint)param_1[0xf]) {
    memw();
    param_1[0xe] = param_1[0xe] + 1;
    if (param_1[0x12] == 0) {
      memw();
      if (param_1[9] == 0) {
        uVar2 = 1;
      }
      else {
        iVar1 = FUN_4037d664(param_1 + 9);
        if (iVar1 == 0) {
          uVar2 = 1;
        }
        else if (param_2 == (undefined4 *)0x0) {
          uVar2 = 1;
        }
        else {
          uVar2 = 1;
          *param_2 = 1;
        }
      }
    }
    else {
      iVar1 = FUN_4037b054(param_1);
      if (iVar1 == 0) {
        uVar2 = 1;
      }
      else if (param_2 == (undefined4 *)0x0) {
        uVar2 = 1;
      }
      else {
        uVar2 = 1;
        *param_2 = 1;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  FUN_4037bd38(param_1 + 0x13);
  return uVar2;
}


