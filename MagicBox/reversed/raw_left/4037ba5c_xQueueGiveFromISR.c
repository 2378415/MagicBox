// 4037ba5c  xQueueGiveFromISR  FUN_4037ba5c  size=157
// strings: pxQueue | pxQueue->uxItemSize == 0 | queue.c | xQueueGiveFromISR | !( ( pxQueue->pcHead == ((void *)0) ) && ( pxQue

undefined4 FUN_4037ba5c(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x54e,PTR_s_xQueueGiveFromISR_40374d48,
                 PTR_s_pxQueue_40374cf0);
  }
  if (param_1[0x10] != 0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x552,PTR_s_xQueueGiveFromISR_40374d48,
                 PTR_s_pxQueue_>uxItemSize____0_40374d4c);
  }
  if ((*param_1 == 0) && (param_1[2] != 0)) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x557,PTR_s_xQueueGiveFromISR_40374d48,
                 PTR_s______pxQueue_>pcHead______void___40374d50);
  }
  FUN_4037bf44(param_1 + 0x13,0xffffffff);
  memw();
  uVar1 = 0;
  if ((uint)param_1[0xf] <= (uint)param_1[0xe]) goto LAB_4037baf1;
  memw();
  param_1[0xe] = param_1[0xe] + 1;
  if (param_1[0x12] == 0) {
    memw();
    if (param_1[9] != 0) {
      iVar2 = FUN_4037dde4(param_1 + 9);
      goto joined_r0x4037bae7;
    }
  }
  else {
    iVar2 = FUN_4037b440(param_1);
joined_r0x4037bae7:
    if ((param_2 != (undefined4 *)0x0) && (iVar2 != 0)) {
      *param_2 = 1;
    }
  }
  uVar1 = 1;
LAB_4037baf1:
  FUN_4037c094(param_1 + 0x13);
  return uVar1;
}


