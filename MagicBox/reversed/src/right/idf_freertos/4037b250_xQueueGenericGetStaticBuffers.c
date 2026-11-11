// strings: pxQueue | ppxStaticQueue | queue.c | xQueueGenericGetStaticBuffers

undefined4 FUN_4037b250(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x1db,
                 PTR_s_xQueueGenericGetStaticBuffers_40374c58,PTR_s_pxQueue_40374c3c);
  }
  if (param_3 == (int *)0x0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x1dc,
                 PTR_s_xQueueGenericGetStaticBuffers_40374c58,PTR_s_ppxStaticQueue_40374c5c);
  }
  if (*(char *)(param_1 + 0x11) == '\x01') {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *param_1;
    }
    *param_3 = (int)param_1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}