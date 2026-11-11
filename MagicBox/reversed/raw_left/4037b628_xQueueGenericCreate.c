// 4037b628  xQueueGenericCreate  FUN_4037b628  size=78
// strings: pxNewQueue | queue.c | xQueueGenericCreate

void FUN_4037b628(uint param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  
  if (((param_1 == 0) || ((int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20) != 0)) ||
     (0xffffffab < param_1 * param_2)) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x23d,PTR_s_xQueueGenericCreate_40374d14,
                 PTR_s_pxNewQueue_40374d08);
    return;
  }
  piVar1 = (int *)FUN_4037c428(param_1 * param_2 + 0x54);
  if (piVar1 == (int *)0x0) {
    return;
  }
  piVar2 = piVar1 + 0x15;
  if (param_2 == 0) {
    piVar2 = piVar1;
  }
  *(char *)(piVar1 + 0x11) = (char)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20);
  *piVar1 = (int)piVar2;
  piVar1[0xf] = param_1;
  piVar1[0x10] = param_2;
  FUN_4037b4b8(piVar1,1);
  piVar1[0x12] = 0;
  return;
}


