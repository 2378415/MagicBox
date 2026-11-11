// strings: pxRingbuffer && ppucRingbufferStorage && ppxStat | xResult == ( ( BaseType_t ) 1 ) | ringbuf.c | vRingbufferDeleteWithCaps | xRingbufferGetStaticBuffer

void FUN_4037b09c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x55a,
                 PTR_s_xRingbufferGetStaticBuffer_40374c70,
                 PTR_s_pxRingbuffer____ppucRingbufferSt_40374c6c);
  }
  if ((*(uint *)(param_1 + 8) & 8) == 0) {
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x590,
                 PTR_s_vRingbufferDeleteWithCaps_40374c78,
                 PTR_s_xResult________BaseType_t___1___40374c74);
  }
  uVar1 = *(undefined4 *)(param_1 + 0x30);
  FUN_4037645c(param_1);
  FUN_4037645c(uVar1);
  return;
}