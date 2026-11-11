// strings: *pvItem2 < *pvItem1 | xIsSplit == ( ( BaseType_t ) 0 ) | ringbuf.c | prvReceiveGeneric

undefined4
FUN_4037a5f8(int param_1,uint *param_2,uint *param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,int param_7)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined1 in_PRID;
  undefined1 auStack_50 [8];
  int aiStack_48 [2];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint *puStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  
  bVar1 = false;
  bVar2 = false;
  uStack_40 = 0;
  uStack_3c = param_4;
  puStack_38 = param_3;
  uStack_34 = param_6;
  uStack_30 = param_5;
  do {
    if (bVar2) {
      return uStack_40;
    }
    FUN_4037bbe8(param_1 + 0x68,0xffffffff);
    iVar3 = FUN_4037ac88(param_1);
    if (iVar3 == 1) {
      aiStack_48[0] = 0;
      if ((*(uint *)(param_1 + 8) & 2) == 0) {
        uVar4 = (**(code **)(param_1 + 0x14))(param_1,aiStack_48,0,uStack_3c);
        *param_2 = uVar4;
      }
      else {
        uVar4 = (**(code **)(param_1 + 0x14))(param_1,0,uStack_34,uStack_3c);
        *param_2 = uVar4;
      }
      if ((*(uint *)(param_1 + 8) & 1) != 0) {
        if (aiStack_48[0] == 1) {
          uVar4 = (**(code **)(param_1 + 0x14))(param_1,aiStack_48,0,uStack_30);
          *puStack_38 = uVar4;
          if (*param_2 <= uVar4) {
            FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x359,
                         PTR_s_prvReceiveGeneric_40374b54,PTR_s__pvItem2_<_*pvItem1_40374b50);
          }
          if (aiStack_48[0] == 0) goto LAB_4037a69c;
          FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x35a,PTR_s_prvReceiveGeneric_40374b54
                       ,PTR_s_xIsSplit________BaseType_t___0___40374b58);
        }
        *puStack_38 = 0;
      }
LAB_4037a69c:
      bVar2 = true;
      uStack_40 = 1;
    }
    else if (param_7 == 0) {
      bVar2 = true;
    }
    else {
      if (!bVar1) {
        FUN_4037d860(auStack_50);
        bVar1 = true;
      }
      iVar3 = FUN_4037d87c(auStack_50,&param_7);
      if (iVar3 == 0) {
        FUN_4037d564(param_1 + 0x50,param_7);
        uVar4 = rsr(in_PRID);
        FUN_403787f4(uVar4 >> 0xd & 1);
      }
      else {
        bVar2 = true;
      }
    }
    FUN_4037bd38(param_1 + 0x68);
  } while( true );
}