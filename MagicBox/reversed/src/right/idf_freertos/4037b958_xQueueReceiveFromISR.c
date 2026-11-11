// strings: pxQueue | !( ( pvBuffer == ((void *)0) ) && ( pxQueue->uxI | queue.c | xQueueReceiveFromISR

undefined4 FUN_4037b958(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,DAT_40374cc4,
                 PTR_s_xQueueReceiveFromISR_40374cc0,PTR_s_pxQueue_40374c3c);
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,DAT_40374ccc,
                 PTR_s_xQueueReceiveFromISR_40374cc0,PTR_s______pvBuffer______void___0______40374cc8
                );
  }
  FUN_4037bbe8(param_1 + 0x4c,0xffffffff);
  memw();
  iVar2 = *(int *)(param_1 + 0x38);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    FUN_4037b030(param_1,param_2);
    memw();
    *(int *)(param_1 + 0x38) = iVar2 + -1;
    memw();
    if (*(int *)(param_1 + 0x10) == 0) {
      uVar1 = 1;
    }
    else {
      iVar2 = FUN_4037d664(param_1 + 0x10);
      if (iVar2 == 0) {
        uVar1 = 1;
      }
      else if (param_3 == (undefined4 *)0x0) {
        uVar1 = 1;
      }
      else {
        uVar1 = 1;
        *param_3 = 1;
      }
    }
  }
  FUN_4037bd38(param_1 + 0x4c);
  return uVar1;
}