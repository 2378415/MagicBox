// strings: pxRingbuffer

undefined4 FUN_4037ab2c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x4f3,
                 PTR_s_xRingbufferGetCurFreeSize_40374bac,PTR_s_pxRingbuffer_40374b74);
  }
  FUN_4037bbe8(param_1 + 0x68,0xffffffff);
  uVar1 = (**(code **)(param_1 + 0x1c))(param_1);
  FUN_4037bd38(param_1 + 0x68);
  return uVar1;
}