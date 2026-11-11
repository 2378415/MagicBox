// strings: pxRingbuffer | pvItem != ((void *)0) || xItemSize == 0 | ringbuf.c | xRingbufferSend

undefined4 FUN_4037acf8(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint in_t0;
  
  if (param_1 == 0) {
    param_1 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x411,
                           PTR_s_xRingbufferSend_40374c34,PTR_s_pxRingbuffer_40374c30);
  }
  uVar2 = (uint)(param_3 == 0);
  if ((param_2 == 0) && (uVar2 == 0)) {
    uVar2 = in_t0;
    param_1 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x412,
                           PTR_s_xRingbufferSend_40374c34,
                           PTR_s_pvItem______void___0_____xItemSi_40374c38);
  }
  uVar1 = 0;
  if ((param_3 <= *(uint *)(param_1 + 4)) &&
     (((*(uint *)(param_1 + 8) & 2) == 0 || (uVar1 = 1, uVar2 == 0)))) {
    uVar1 = FUN_4037a964(param_1,param_2,0,param_3,param_4);
  }
  return uVar1;
}