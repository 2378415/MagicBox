// 4037aaf4  prvReturnItemByteBuf  FUN_4037aaf4  size=67
// strings: (uint8_t *)pucItem >= pxRingbuffer->pucHead | (uint8_t *)pucItem < pxRingbuffer->pucTail | ringbuf.c | prvReturnItemByteBuf

void FUN_4037aaf4(int param_1,uint param_2)

{
  if (param_2 < *(uint *)(param_1 + 0x30)) {
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x299,PTR_s_prvReturnItemByteBuf_40374c10,
                 PTR_s__uint8_t___pucItem_>__pxRingbuff_40374c0c);
  }
  if (*(uint *)(param_1 + 0x34) <= param_2) {
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x29a,PTR_s_prvReturnItemByteBuf_40374c10,
                 PTR_s__uint8_t___pucItem_<_pxRingbuffe_40374c14);
  }
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x28);
  if ((*(uint *)(param_1 + 8) & 4) != 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffb;
  }
  return;
}


