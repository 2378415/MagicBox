// strings: xSemaphore | xQueueGetMutexHolder

int FUN_4037b678(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x2c2,PTR_s_xQueueGetMutexHolder_40374d1c,
                 PTR_s_xSemaphore_40374d18);
  }
  FUN_4037bf44(param_1 + 0x13,0xffffffff);
  iVar1 = 0;
  if (*param_1 == 0) {
    iVar1 = param_1[2];
  }
  FUN_4037c094(param_1 + 0x13);
  return iVar1;
}