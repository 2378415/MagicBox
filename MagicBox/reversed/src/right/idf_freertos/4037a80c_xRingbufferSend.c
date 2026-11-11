// strings: pxRingbuffer | pvItem != ((void *)0) || xItemSize == 0 | ringbuf.c | xRingbufferSend

undefined4 FUN_4037a80c(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x411,PTR_s_xRingbufferSend_40374b78,
                 PTR_s_pxRingbuffer_40374b74);
  }
  if (param_2 == 0 && param_3 != 0) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x412,PTR_s_xRingbufferSend_40374b78,
                 PTR_s_pvItem______void___0_____xItemSi_40374b7c);
  }
  if (*(uint *)(param_1 + 4) < param_3) {
    uVar1 = 0;
  }
  else if (((*(uint *)(param_1 + 8) & 2) == 0) || (param_3 != 0)) {
    uVar1 = FUN_4037a520(param_1,param_2,0,param_3,param_4);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}