// 4037b914  xQueueTakeMutexRecursive  FUN_4037b914  size=65
// strings: pxMutex

int FUN_4037b914(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x335,PTR_s_xQueueTakeMutexRecursive_40374cbc,
                 PTR_s_pxMutex_40374c94);
  }
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = FUN_4037d934();
  if (iVar1 == iVar2) {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    iVar1 = 1;
  }
  else {
    iVar1 = FUN_4037b80c(param_1,param_2);
    if (iVar1 != 0) {
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    }
  }
  return iVar1;
}


