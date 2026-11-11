// strings: pxQueue | xQueueGenericReset | xReturn != ( ( ( BaseType_t ) 0 ) ) | queue.c

undefined4 FUN_4037b0ec(int *param_1,int param_2)

{
  int *in_a7;
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  if (param_1 == (int *)0x0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x14d,PTR_s_xQueueGenericReset_40374c40,
                 PTR_s_pxQueue_40374c3c);
  }
  if (param_2 == 1) {
    param_1[0x13] = DAT_40374b44;
    param_1[0x14] = 0;
LAB_4037b118:
    if ((param_1[0xf] != 0) &&
       ((int)((ulonglong)(uint)param_1[0xf] * (ulonglong)(uint)param_1[0x10] >> 0x20) == 0)) {
      in_a7 = param_1 + 0x13;
      FUN_4037bbe8(in_a7,0xffffffff);
      iVar1 = *param_1;
      param_1[2] = iVar1 + param_1[0xf] * param_1[0x10];
      memw();
      param_1[0xe] = 0;
      param_1[1] = iVar1;
      param_1[3] = iVar1 + param_1[0x10] * (param_1[0xf] + -1);
      if (param_2 == 0) {
        memw();
        if ((param_1[4] != 0) && (iVar1 = FUN_4037d664(param_1 + 4), iVar1 != 0)) {
          uVar2 = rsr(in_PRID);
          FUN_403787f4(uVar2 >> 0xd & 1);
        }
      }
      else {
        FUN_4037c8b8(param_1 + 4);
        FUN_4037c8b8(param_1 + 9);
      }
      goto LAB_4037b194;
    }
  }
  else if (param_1 != (int *)0x0) goto LAB_4037b118;
  FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x18b,PTR_s_xQueueGenericReset_40374c40,
               PTR_s_xReturn__________BaseType_t___0___40374c44);
LAB_4037b194:
  FUN_4037bd38(in_a7);
  return 1;
}