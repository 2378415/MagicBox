// strings: pxRingbuffer | vRingbufferGetInfo

void FUN_4037ab5c(int param_1,int *param_2,int *param_3,int *param_4,int *param_5,
                 undefined4 *param_6)

{
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x534,PTR_s_vRingbufferGetInfo_40374bb0,
                 PTR_s_pxRingbuffer_40374b74);
  }
  FUN_4037bbe8(param_1 + 0x68,0xffffffff);
  if (param_2 != (int *)0x0) {
    *param_2 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x30);
  }
  if (param_3 != (int *)0x0) {
    *param_3 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x30);
  }
  if (param_4 != (int *)0x0) {
    *param_4 = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x30);
  }
  if (param_5 != (int *)0x0) {
    *param_5 = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x30);
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = *(undefined4 *)(param_1 + 0x38);
  }
  FUN_4037bd38(param_1 + 0x68);
  return;
}