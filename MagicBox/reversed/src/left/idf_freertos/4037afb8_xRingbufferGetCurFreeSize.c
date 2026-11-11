// strings: pxRingbuffer

undefined4 FUN_4037afb8(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x4f3,
                 PTR_s_xRingbufferGetCurFreeSize_40374c64,PTR_s_pxRingbuffer_40374c30);
  }
  FUN_4037bf44(param_1 + 0x68,0xffffffff);
  uVar1 = (**(code **)(param_1 + 0x1c))(param_1);
  FUN_4037c094(param_1 + 0x68);
  return uVar1;
}