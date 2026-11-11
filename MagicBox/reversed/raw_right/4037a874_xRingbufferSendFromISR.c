// 4037a874  xRingbufferSendFromISR  FUN_4037a874  size=213
// strings: pxRingbuffer | pvItem != ((void *)0) || xItemSize == 0 | ringbuf.c | xRingbufferSendFromISR

undefined4 FUN_4037a874(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int local_30 [12];
  
  local_30[0] = param_1;
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x427,PTR_s_xRingbufferSendFromISR_40374b80,
                 PTR_s_pxRingbuffer_40374b74);
  }
  if (param_2 == 0 && param_3 != 0) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x428,PTR_s_xRingbufferSendFromISR_40374b80,
                 PTR_s_pvItem______void___0_____xItemSi_40374b7c);
  }
  if (*(uint *)(param_1 + 4) < param_3) {
    uVar3 = 0;
  }
  else if (((*(uint *)(param_1 + 8) & 2) == 0) || (param_3 != 0)) {
    FUN_4037bbe8(param_1 + 0x68,0xffffffff);
    iVar2 = (**(code **)(local_30[0] + 0xc))(param_1,param_3);
    if (iVar2 == 1) {
      (**(code **)(local_30[0] + 0x10))(param_1,param_2,param_3);
      uVar3 = 1;
      if (*(int *)(local_30[0] + 100) == 0) {
        memw();
        if (*(int *)(local_30[0] + 0x50) == 0) {
          bVar1 = false;
        }
        else {
          iVar2 = FUN_4037d664(local_30[0] + 0x50);
          if (iVar2 == 1) {
            uVar3 = 1;
            if (param_4 == (undefined4 *)0x0) {
              bVar1 = false;
            }
            else {
              *param_4 = 1;
              bVar1 = false;
            }
          }
          else {
            bVar1 = false;
          }
        }
      }
      else {
        bVar1 = true;
      }
    }
    else {
      uVar3 = 0;
      bVar1 = false;
    }
    FUN_4037bd38(local_30[0] + 0x68);
    if (bVar1) {
      FUN_4037b588(*(undefined4 *)(local_30[0] + 100),local_30,param_4,0);
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


