// strings: pxRingbuffer | pvItem != ((void *)0) | ringbuf.c | vRingbufferReturnItem

void FUN_4037aa2c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x4ba,PTR_s_vRingbufferReturnItem_40374b98,
                 PTR_s_pxRingbuffer_40374b74);
  }
  if (param_2 == 0) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x4bb,PTR_s_vRingbufferReturnItem_40374b98,
                 PTR_s_pvItem______void___0__40374b9c);
  }
  FUN_4037bbe8(param_1 + 0x68,0xffffffff);
  (**(code **)(param_1 + 0x18))(param_1,param_2);
  memw();
  if ((*(int *)(param_1 + 0x3c) != 0) && (iVar1 = FUN_4037d664(param_1 + 0x3c), iVar1 == 1)) {
    uVar2 = rsr(in_PRID);
    FUN_403787f4(uVar2 >> 0xd & 1);
  }
  FUN_4037bd38(param_1 + 0x68);
  return;
}