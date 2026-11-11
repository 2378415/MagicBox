// 4037bdf8  vQueueDelete  FUN_4037bdf8  size=36
// strings: pxQueue

void FUN_4037bdf8(int param_1)

{
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,DAT_40374d84,PTR_s_vQueueDelete_40374d80,
                 PTR_s_pxQueue_40374cf0);
  }
  if (*(char *)(param_1 + 0x44) == '\0') {
    FUN_4037c43c(param_1);
  }
  return;
}


