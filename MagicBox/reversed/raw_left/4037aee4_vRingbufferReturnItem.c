// 4037aee4  vRingbufferReturnItem  FUN_4037aee4  size=92
// strings: pxRingbuffer | pvItem != ((void *)0) | ringbuf.c | vRingbufferReturnItem

void FUN_4037aee4(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x4ba,PTR_s_vRingbufferReturnItem_40374c54,
                 PTR_s_pxRingbuffer_40374c30);
  }
  if (param_2 == 0) {
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x4bb,PTR_s_vRingbufferReturnItem_40374c54,
                 PTR_s_pvItem______void___0__40374c58);
  }
  FUN_4037bf44(param_1 + 0x68,0xffffffff);
  (**(code **)(param_1 + 0x18))(param_1,param_2);
  memw();
  if ((*(int *)(param_1 + 0x3c) != 0) && (iVar1 = FUN_4037dde4(param_1 + 0x3c), iVar1 == 1)) {
    uVar2 = rsr(in_PRID);
    FUN_40378e40(uVar2 >> 0xd & 1);
  }
  FUN_4037c094(param_1 + 0x68);
  return;
}


