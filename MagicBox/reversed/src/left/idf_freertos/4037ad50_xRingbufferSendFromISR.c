// strings: pxRingbuffer | pvItem != ((void *)0) || xItemSize == 0 | ringbuf.c | xRingbufferSendFromISR

undefined4 FUN_4037ad50(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint in_t0;
  int local_30 [12];
  
  local_30[0] = param_1;
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x427,PTR_s_xRingbufferSendFromISR_40374c3c,
                 PTR_s_pxRingbuffer_40374c30);
  }
  uVar3 = (uint)(param_3 == 0);
  if ((param_2 == 0) && (uVar3 == 0)) {
    uVar3 = in_t0;
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x428,PTR_s_xRingbufferSendFromISR_40374c3c,
                 PTR_s_pvItem______void___0_____xItemSi_40374c38);
  }
  if (*(uint *)(param_1 + 4) < param_3) {
LAB_4037ad87:
    uVar1 = 0;
  }
  else {
    if (((*(uint *)(param_1 + 8) & 2) == 0) || (uVar3 == 0)) {
      FUN_4037bf44(param_1 + 0x68,0xffffffff);
      iVar2 = (**(code **)(local_30[0] + 0xc))(param_1,param_3);
      if (iVar2 != 1) {
        FUN_4037c094(local_30[0] + 0x68);
        goto LAB_4037ad87;
      }
      (**(code **)(local_30[0] + 0x10))(param_1,param_2,param_3);
      if (*(int *)(local_30[0] + 100) == 0) {
        memw();
        if (*(int *)(local_30[0] + 0x50) == 0) {
          FUN_4037c094(local_30[0] + 0x68);
        }
        else {
          iVar2 = FUN_4037dde4(local_30[0] + 0x50);
          if ((iVar2 == 1) && (param_4 != (undefined4 *)0x0)) {
            *param_4 = 1;
          }
          FUN_4037c094(local_30[0] + 0x68);
        }
      }
      else {
        FUN_4037c094(local_30[0] + 0x68);
        FUN_4037b988(*(undefined4 *)(local_30[0] + 100),local_30,param_4,0);
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}