// strings: xBufferSize > 0 | xBufferType < RINGBUF_TYPE_MAX | ringbuf.c | xRingbufferCreateStatic | pucRingbufferStorage != ((void *)0) && pxStaticR | ( ( ( UBaseType_t ) ( xBufferSize ) & (0x03) ) =

void FUN_4037ac84(int param_1,uint param_2,int param_3,int param_4)

{
  ulonglong uVar1;
  
  uVar1 = CONCAT44(param_2,param_1);
  if (param_1 == 0) {
    uVar1 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x3ca,
                         PTR_s_xRingbufferCreateStatic_40374c20,PTR_s_xBufferSize_>_0_40374c1c);
  }
  if (2 < param_2) {
    uVar1 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x3cb,
                         PTR_s_xRingbufferCreateStatic_40374c20,
                         PTR_s_xBufferType_<_RINGBUF_TYPE_MAX_40374c24);
  }
  if ((param_3 == 0) || (param_4 == 0)) {
    uVar1 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x3cc,
                         PTR_s_xRingbufferCreateStatic_40374c20,
                         PTR_s_pucRingbufferStorage______void___40374c28);
  }
  if ((param_2 != 2) && ((uVar1 & 3) != 0)) {
    uVar1 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x3cf,
                         PTR_s_xRingbufferCreateStatic_40374c20,
                         PTR_s_______UBaseType_t_____xBufferSiz_40374c2c);
  }
  FUN_4037a764((int)uVar1,(int)(uVar1 >> 0x20),param_4);
  *(uint *)(param_4 + 8) = *(uint *)(param_4 + 8) | 8;
  return;
}