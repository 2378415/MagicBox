// 4037abc0  xRingbufferGetStaticBuffer  FUN_4037abc0  size=58
// strings: pxRingbuffer && ppucRingbufferStorage && ppxStat | ringbuf.c | xRingbufferGetStaticBuffer

bool FUN_4037abc0(int param_1,undefined4 *param_2,int *param_3)

{
  bool bVar1;
  
  if ((param_1 == 0 || param_2 == (undefined4 *)0x0) || (param_3 == (int *)0x0)) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x55a,
                 PTR_s_xRingbufferGetStaticBuffer_40374bb8,
                 PTR_s_pxRingbuffer____ppucRingbufferSt_40374bb4);
  }
  bVar1 = (*(uint *)(param_1 + 8) & 8) != 0;
  if (bVar1) {
    *param_2 = *(undefined4 *)(param_1 + 0x30);
    *param_3 = param_1;
  }
  return bVar1;
}


