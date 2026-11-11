// strings: *pvItem2 < *pvItem1 | xIsSplit == ( ( BaseType_t ) 0 ) | ringbuf.c | prvReceiveGenericFromISR

undefined4
FUN_4037a6ec(int param_1,uint *param_2,uint *param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_40 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  uStack_30 = param_6;
  uStack_2c = param_5;
  FUN_4037bbe8(param_1 + 0x68,0xffffffff);
  iVar1 = FUN_4037ac88(param_1);
  if (iVar1 == 1) {
    local_40[0] = 0;
    if ((*(uint *)(param_1 + 8) & 2) == 0) {
      uVar2 = (**(code **)(param_1 + 0x14))(param_1,local_40,0,param_4);
      *param_2 = uVar2;
    }
    else {
      uVar2 = (**(code **)(param_1 + 0x14))(param_1,0,uStack_30,param_4);
      *param_2 = uVar2;
    }
    uVar3 = 1;
    if ((*(uint *)(param_1 + 8) & 1) != 0) {
      if (local_40[0] == 1) {
        uVar2 = (**(code **)(param_1 + 0x14))(param_1,local_40,0,uStack_2c);
        *param_3 = uVar2;
        if (*param_2 <= uVar2) {
          FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x395,
                       PTR_s_prvReceiveGenericFromISR_40374b5c,PTR_s__pvItem2_<_*pvItem1_40374b50);
        }
        if (local_40[0] == 0) goto LAB_4037a77e;
        FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x396,
                     PTR_s_prvReceiveGenericFromISR_40374b5c,
                     PTR_s_xIsSplit________BaseType_t___0___40374b58);
      }
      *param_3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
LAB_4037a77e:
  FUN_4037bd38(param_1 + 0x68);
  return uVar3;
}