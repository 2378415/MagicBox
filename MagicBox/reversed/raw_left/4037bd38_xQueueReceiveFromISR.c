// 4037bd38  xQueueReceiveFromISR  FUN_4037bd38  size=138
// strings: pxQueue | !( ( pvBuffer == ((void *)0) ) && ( pxQueue->uxI | queue.c | xQueueReceiveFromISR

undefined4 FUN_4037bd38(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,DAT_40374d6c,
                 PTR_s_xQueueReceiveFromISR_40374d68,PTR_s_pxQueue_40374cf0);
  }
  if ((param_2 == 0) && (param_1[0x10] != 0)) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,DAT_40374d74,
                 PTR_s_xQueueReceiveFromISR_40374d68,PTR_s______pvBuffer______void___0______40374d70
                );
  }
  FUN_4037bf44(param_1 + 0x13,0xffffffff);
  memw();
  iVar2 = param_1[0xe];
  uVar1 = 0;
  if (iVar2 != 0) {
    if (param_1[0x10] != 0) {
      uVar3 = param_1[3] + param_1[0x10];
      param_1[3] = uVar3;
      if ((uint)param_1[2] <= uVar3) {
        param_1[3] = *param_1;
      }
      (*DAT_4037450c)(param_2);
    }
    memw();
    param_1[0xe] = iVar2 + -1;
    memw();
    if (((param_1[4] != 0) && (iVar2 = FUN_4037dde4(param_1 + 4), param_3 != (undefined4 *)0x0)) &&
       (iVar2 != 0)) {
      *param_3 = 1;
    }
    uVar1 = 1;
  }
  FUN_4037c094(param_1 + 0x13);
  return uVar1;
}


