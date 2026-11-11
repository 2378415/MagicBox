// 4037aa88  vRingbufferReturnItemFromISR  FUN_4037aa88  size=96
// strings: pxRingbuffer | pvItem != ((void *)0) | ringbuf.c | vRingbufferReturnItemFromISR

void FUN_4037aa88(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x4cc,
                 PTR_s_vRingbufferReturnItemFromISR_40374ba0,PTR_s_pxRingbuffer_40374b74);
  }
  if (param_2 == 0) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x4cd,
                 PTR_s_vRingbufferReturnItemFromISR_40374ba0,PTR_s_pvItem______void___0__40374b9c);
  }
  FUN_4037bbe8(param_1 + 0x68,0xffffffff);
  (**(code **)(param_1 + 0x18))(param_1,param_2);
  memw();
  if (((*(int *)(param_1 + 0x3c) != 0) && (iVar1 = FUN_4037d664(param_1 + 0x3c), iVar1 == 1)) &&
     (param_3 != (undefined4 *)0x0)) {
    *param_3 = 1;
  }
  FUN_4037bd38(param_1 + 0x68);
  return;
}


