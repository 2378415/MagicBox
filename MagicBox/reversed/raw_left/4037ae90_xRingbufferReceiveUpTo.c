// 4037ae90  xRingbufferReceiveUpTo  FUN_4037ae90  size=83
// strings: pxRingbuffer && pxItemSize | ringbuf.c | xRingbufferReceiveUpTo | pxRingbuffer->uxRingbufferFlags & ( ( UBaseType_

undefined4 FUN_4037ae90(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_30 [12];
  
  if ((param_1 == 0) || (iVar1 = param_1, param_2 == 0)) {
    iVar1 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x494,
                         PTR_s_xRingbufferReceiveUpTo_40374c4c,
                         PTR_s_pxRingbuffer____pxItemSize_40374c40);
  }
  if ((*(uint *)(param_1 + 8) & 2) == 0) {
    iVar1 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x495,
                         PTR_s_xRingbufferReceiveUpTo_40374c4c,
                         PTR_s_pxRingbuffer_>uxRingbufferFlags___40374c50);
  }
  if ((param_4 == 0) || (iVar1 = FUN_4037ab38(iVar1,auStack_30,0), iVar1 != 1)) {
    return 0;
  }
  return auStack_30[0];
}


