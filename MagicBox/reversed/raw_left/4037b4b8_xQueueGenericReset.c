// 4037b4b8  xQueueGenericReset  FUN_4037b4b8  size=161
// strings: pxQueue | xQueueGenericReset | xReturn != ( ( ( BaseType_t ) 0 ) ) | queue.c

undefined4 FUN_4037b4b8(int *param_1,int param_2)

{
  int *in_a7;
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 in_PRID;
  
  if (param_1 == (int *)0x0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x14d,PTR_s_xQueueGenericReset_40374cf4,
                 PTR_s_pxQueue_40374cf0);
  }
  if (param_2 == 1) {
    param_1[0x13] = DAT_40374bf4;
    param_1[0x14] = 0;
  }
  if ((param_1[0xf] == 0) ||
     ((int)((ulonglong)(uint)param_1[0xf] * (ulonglong)(uint)param_1[0x10] >> 0x20) != 0)) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x18b,PTR_s_xQueueGenericReset_40374cf4,
                 PTR_s_xReturn__________BaseType_t___0___40374cf8);
  }
  else {
    in_a7 = param_1 + 0x13;
    FUN_4037bf44(in_a7,0xffffffff);
    iVar2 = *param_1;
    iVar1 = param_1[0x10] * param_1[0xf];
    memw();
    param_1[0xe] = 0;
    param_1[2] = iVar2 + iVar1;
    param_1[1] = iVar2;
    param_1[3] = iVar2 + (iVar1 - param_1[0x10]);
    if (param_2 == 0) {
      memw();
      if ((param_1[4] != 0) && (iVar1 = FUN_4037dde4(param_1 + 4), iVar1 != 0)) {
        uVar3 = rsr(in_PRID);
        FUN_40378e40(uVar3 >> 0xd & 1);
      }
    }
    else {
      FUN_4037cbbc(param_1 + 4);
      FUN_4037cbbc(param_1 + 9);
    }
  }
  FUN_4037c094(in_a7);
  return 1;
}


