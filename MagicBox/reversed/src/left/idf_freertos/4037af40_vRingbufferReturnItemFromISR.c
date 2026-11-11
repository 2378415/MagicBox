// strings: pxRingbuffer | pvItem != ((void *)0) | ringbuf.c | vRingbufferReturnItemFromISR

void FUN_4037af40(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x4cc,
                 PTR_s_vRingbufferReturnItemFromISR_40374c5c,PTR_s_pxRingbuffer_40374c30);
  }
  if (param_2 == 0) {
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x4cd,
                 PTR_s_vRingbufferReturnItemFromISR_40374c5c,PTR_s_pvItem______void___0__40374c58);
  }
  FUN_4037bf44(param_1 + 0x68,0xffffffff);
  (**(code **)(param_1 + 0x18))(param_1,param_2);
  memw();
  if (((*(int *)(param_1 + 0x3c) != 0) &&
      (iVar1 = FUN_4037dde4(param_1 + 0x3c), param_3 != (undefined4 *)0x0)) && (iVar1 == 1)) {
    *param_3 = 1;
  }
  FUN_4037c094(param_1 + 0x68);
  return;
}