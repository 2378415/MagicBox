// 4037ae58  xRingbufferReceiveFromISR  FUN_4037ae58  size=55
// strings: pxRingbuffer && pxItemSize | ringbuf.c | xRingbufferReceiveFromISR

undefined4 FUN_4037ae58(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_30 [12];
  
  if ((param_1 == 0) || (param_2 == 0)) {
    param_1 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x462,
                           PTR_s_xRingbufferReceiveFromISR_40374c48,
                           PTR_s_pxRingbuffer____pxItemSize_40374c40);
  }
  iVar1 = FUN_4037aa5c(param_1,local_30,0);
  if (iVar1 != 1) {
    local_30[0] = 0;
  }
  return local_30[0];
}


