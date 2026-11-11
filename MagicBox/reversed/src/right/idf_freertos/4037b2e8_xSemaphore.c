// strings: xSemaphore | xQueueGetMutexHolder

int FUN_4037b2e8(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x2c2,PTR_s_xQueueGetMutexHolder_40374c68,
                 PTR_s_xSemaphore_40374c64);
  }
  FUN_4037bbe8(param_1 + 0x13,0xffffffff);
  if (*param_1 == 0) {
    iVar1 = param_1[2];
  }
  else {
    iVar1 = 0;
  }
  FUN_4037bd38(param_1 + 0x13);
  return iVar1;
}