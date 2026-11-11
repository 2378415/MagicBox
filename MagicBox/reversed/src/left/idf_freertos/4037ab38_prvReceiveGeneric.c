// strings: *pvItem2 < *pvItem1 | xIsSplit == ( ( BaseType_t ) 0 ) | ringbuf.c | prvReceiveGeneric

undefined4
FUN_4037ab38(int param_1,uint *param_2,uint *param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,int param_7)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined1 in_PRID;
  undefined1 auStack_50 [8];
  int aiStack_48 [2];
  uint *puStack_40;
  uint *puStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  undefined4 uStack_30;
  
  iStack_34 = param_1 + 0x50;
  iVar4 = param_1 + 0x68;
  bVar1 = false;
  puStack_40 = param_2;
  puStack_3c = param_3;
  uStack_38 = param_6;
  uStack_30 = param_5;
  do {
    FUN_4037bf44(iVar4,0xffffffff);
    puVar2 = puStack_40;
    uVar6 = *(uint *)(param_1 + 8);
    if ((uVar6 & 2) == 0) {
      if (((0 < *(int *)(param_1 + 0x38)) &&
          ((*(int *)(param_1 + 0x28) != *(int *)(param_1 + 0x24) || ((uVar6 & 4) != 0)))) &&
         (((uVar6 & 3) != 0 || ((*(uint *)(*(int *)(param_1 + 0x28) + 4) & 8) != 0)))) {
        aiStack_48[0] = 0;
        uVar6 = (**(code **)(param_1 + 0x14))(param_1,aiStack_48,0,param_4);
        goto LAB_4037abc3;
      }
    }
    else if (((*(int *)(param_1 + 0x28) == *(int *)(param_1 + 0x2c)) &&
             (0 < *(int *)(param_1 + 0x38))) &&
            ((*(int *)(param_1 + 0x24) != *(int *)(param_1 + 0x28) || ((uVar6 & 4) != 0)))) {
      aiStack_48[0] = 0;
      uVar6 = (**(code **)(param_1 + 0x14))(param_1,0,uStack_38,param_4);
LAB_4037abc3:
      uVar5 = *(uint *)(param_1 + 8);
      *puVar2 = uVar6;
      if ((uVar5 & 1) != 0) {
        if (aiStack_48[0] == 1) {
          uVar6 = (**(code **)(param_1 + 0x14))(param_1,aiStack_48,0,uStack_30);
          *puStack_3c = uVar6;
          if (*puVar2 <= uVar6) {
            FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x359,
                         PTR_s_prvReceiveGeneric_40374c18,PTR_s__pvItem2_<_*pvItem1_40374c00);
          }
          if (aiStack_48[0] == 0) goto LAB_4037ac13;
          FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x35a,PTR_s_prvReceiveGeneric_40374c18
                       ,PTR_s_xIsSplit________BaseType_t___0___40374c08);
        }
        *puStack_3c = 0;
      }
LAB_4037ac13:
      FUN_4037c094(iVar4);
      return 1;
    }
    if (param_7 == 0) {
LAB_4037ac38:
      FUN_4037c094(iVar4);
      return 0;
    }
    if (!bVar1) {
      FUN_4037dfb8(auStack_50);
    }
    iVar3 = FUN_4037dfd4(auStack_50,&param_7);
    if (iVar3 != 0) goto LAB_4037ac38;
    FUN_4037dce8(iStack_34,param_7);
    uVar6 = rsr(in_PRID);
    FUN_40378e40(uVar6 >> 0xd & 1);
    FUN_4037c094(iVar4);
    bVar1 = true;
  } while( true );
}