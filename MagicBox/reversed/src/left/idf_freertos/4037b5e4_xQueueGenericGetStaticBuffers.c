// strings: pxQueue | ppxStaticQueue | queue.c | xQueueGenericGetStaticBuffers

undefined4 FUN_4037b5e4(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *in_t0;
  
  puVar2 = param_1;
  if (param_1 == (undefined4 *)0x0) {
    puVar2 = in_t0;
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x1db,
                 PTR_s_xQueueGenericGetStaticBuffers_40374d0c,PTR_s_pxQueue_40374cf0);
    in_t0 = puVar2;
  }
  if (param_3 == (int *)0x0) {
    puVar2 = in_t0;
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x1dc,
                 PTR_s_xQueueGenericGetStaticBuffers_40374d0c,PTR_s_ppxStaticQueue_40374d10);
  }
  uVar1 = 0;
  if (*(char *)(param_1 + 0x11) == '\x01') {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *puVar2;
    }
    *param_3 = (int)puVar2;
    uVar1 = 1;
  }
  return uVar1;
}