// strings: pxRingbuffer && pxItemSize | ringbuf.c | xRingbufferReceiveUpTo | pxRingbuffer->uxRingbufferFlags & ( ( UBaseType_

undefined4 FUN_4037a9d0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_30 [12];
  
  iVar1 = param_1;
  if (param_1 == 0 || param_2 == 0) {
    iVar1 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x494,
                         PTR_s_xRingbufferReceiveUpTo_40374b90,
                         PTR_s_pxRingbuffer____pxItemSize_40374b84);
  }
  if ((*(uint *)(param_1 + 8) & 2) == 0) {
    iVar1 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x495,
                         PTR_s_xRingbufferReceiveUpTo_40374b90,
                         PTR_s_pxRingbuffer_>uxRingbufferFlags___40374b94);
  }
  if (param_4 == 0) {
    auStack_30[0] = 0;
  }
  else {
    iVar1 = FUN_4037a5f8(iVar1,auStack_30,0);
    if (iVar1 != 1) {
      auStack_30[0] = 0;
    }
  }
  return auStack_30[0];
}