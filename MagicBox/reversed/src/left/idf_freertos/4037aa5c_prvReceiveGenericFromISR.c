// strings: *pvItem2 < *pvItem1 | xIsSplit == ( ( BaseType_t ) 0 ) | ringbuf.c | prvReceiveGenericFromISR

int FUN_4037aa5c(int param_1,uint *param_2,uint *param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_40 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  uStack_30 = param_6;
  uStack_2c = param_5;
  FUN_4037bf44(param_1 + 0x68,0xffffffff);
  iVar1 = FUN_4037b0d4(param_1);
  if (iVar1 == 1) {
    local_40[0] = 0;
    if ((*(uint *)(param_1 + 8) & 2) == 0) {
      uVar2 = (**(code **)(param_1 + 0x14))(param_1,local_40,*(uint *)(param_1 + 8) & 2,param_4);
    }
    else {
      uVar2 = (**(code **)(param_1 + 0x14))(param_1,0,uStack_30);
    }
    uVar3 = *(uint *)(param_1 + 8);
    *param_2 = uVar2;
    if ((uVar3 & 1) != 0) {
      if (local_40[0] == 1) {
        uVar2 = (**(code **)(param_1 + 0x14))(param_1,local_40,0,uStack_2c);
        *param_3 = uVar2;
        if (*param_2 <= uVar2) {
          FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x395,
                       PTR_s_prvReceiveGenericFromISR_40374c04,PTR_s__pvItem2_<_*pvItem1_40374c00);
        }
        if (local_40[0] == 0) goto LAB_4037aaea;
        FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x396,
                     PTR_s_prvReceiveGenericFromISR_40374c04,
                     PTR_s_xIsSplit________BaseType_t___0___40374c08);
      }
      *param_3 = 0;
    }
  }
LAB_4037aaea:
  FUN_4037c094(param_1 + 0x68);
  return iVar1;
}