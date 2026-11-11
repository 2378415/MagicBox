// strings: pxRingbuffer && pxItemSize | ringbuf.c | xRingbufferReceive

undefined4 FUN_4037a950(int param_1,int param_2)

{
  int iVar1;
  undefined4 auStack_30 [12];
  
  if (param_1 == 0 || param_2 == 0) {
    param_1 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x452,
                           PTR_s_xRingbufferReceive_40374b88,
                           PTR_s_pxRingbuffer____pxItemSize_40374b84);
  }
  iVar1 = FUN_4037a5f8(param_1,auStack_30,0);
  if (iVar1 != 1) {
    auStack_30[0] = 0;
  }
  return auStack_30[0];
}