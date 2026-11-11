// strings: pxRingbuffer | vRingbufferGetInfo

void FUN_4037afe8(int param_1,int *param_2,int *param_3,int *param_4,int *param_5,
                 undefined4 *param_6)

{
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x534,PTR_s_vRingbufferGetInfo_40374c68,
                 PTR_s_pxRingbuffer_40374c30);
  }
  FUN_4037bf44(param_1 + 0x68,0xffffffff);
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
  FUN_4037c094(param_1 + 0x68);
  return;
}