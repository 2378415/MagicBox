// strings: pxRingbuffer

void FUN_4037aae8(int param_1)

{
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x4e0,PTR_s_vRingbufferDelete_40374ba4,
                 PTR_s_pxRingbuffer_40374b74);
  }
  if ((*(uint *)(param_1 + 8) & 8) == 0) {
    FUN_40381e98(*(undefined4 *)(param_1 + 0x30));
    FUN_40381e98(param_1);
  }
  return;
}