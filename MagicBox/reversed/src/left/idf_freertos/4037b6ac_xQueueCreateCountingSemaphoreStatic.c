// strings: pxStaticQueue | xSize == sizeof( Queue_t ) | xHandle | queue.c | xQueueCreateCountingSemaphoreStatic

/* (1 unreachable decompiler blocks omitted) */

void FUN_4037b6ac(int param_1,undefined4 param_2,int param_3)

{
  char unaff_a8;
  int in_t0;
  
  if ((param_1 == 0) || (unaff_a8 == '\x01')) {
    param_1 = in_t0;
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x372,
                 PTR_s_xQueueCreateCountingSemaphoreSta_40374d24,PTR_s_xHandle_40374d20);
  }
  else {
    if (param_3 == 0) {
      param_1 = in_t0;
      FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x19f,
                   PTR_s_xQueueGenericCreateStatic_40374d00,PTR_s_pxStaticQueue_40374cfc);
    }
    memw();
    memw();
  }
  *(undefined1 *)(param_3 + 0x44) = 1;
  *(int *)param_3 = param_3;
  memw();
  *(int *)(param_3 + 0x3c) = param_1;
  *(undefined4 *)(param_3 + 0x40) = 0;
  FUN_4037b4b8(param_3,1);
  *(undefined4 *)(param_3 + 0x48) = 0;
  memw();
  *(undefined4 *)(param_3 + 0x38) = param_2;
  return;
}