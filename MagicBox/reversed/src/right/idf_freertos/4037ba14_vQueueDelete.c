// strings: pxQueue

void FUN_4037ba14(int param_1)

{
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,DAT_40374cdc,PTR_s_vQueueDelete_40374cd8,
                 PTR_s_pxQueue_40374c3c);
  }
  if (*(char *)(param_1 + 0x44) == '\0') {
    FUN_4037c060(param_1);
  }
  return;
}