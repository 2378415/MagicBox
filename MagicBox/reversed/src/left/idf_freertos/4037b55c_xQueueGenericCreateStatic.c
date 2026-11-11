// strings: pxStaticQueue | xSize == sizeof( Queue_t ) | pxNewQueue | queue.c | xQueueGenericCreateStatic

/* (1 unreachable decompiler blocks omitted) */

int * FUN_4037b55c(int param_1,int param_2,int *param_3,int *param_4)

{
  if (param_4 == (int *)0x0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x19f,PTR_s_xQueueGenericCreateStatic_40374d00
                 ,PTR_s_pxStaticQueue_40374cfc);
  }
  if (((param_1 == 0) || ((param_3 != (int *)0x0 && (param_2 == 0 && param_3 != (int *)0x0)))) ||
     ((param_3 == (int *)0x0 && (param_2 != 0)))) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x1c8,PTR_s_xQueueGenericCreateStatic_40374d00
                 ,PTR_s_pxNewQueue_40374d08);
  }
  else {
    memw();
    memw();
  }
  if (param_2 == 0) {
    param_3 = param_4;
  }
  *(undefined1 *)(param_4 + 0x11) = 1;
  param_4[0xf] = param_1;
  memw();
  *param_4 = (int)param_3;
  param_4[0x10] = param_2;
  FUN_4037b4b8(param_4,1);
  param_4[0x12] = 0;
  return param_4;
}