// strings: x'e= | pxMutex

undefined4 FUN_4037b548(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x2fd,PTR_s_xQueueGiveMutexRecursive_40374c98,
                 PTR_s_pxMutex_40374c94);
  }
  iVar3 = *(int *)(param_1 + 8);
  iVar1 = FUN_4037d934();
  if (iVar3 == iVar1) {
    iVar1 = *(int *)(param_1 + 0xc) + -1;
    *(int *)(param_1 + 0xc) = iVar1;
    if (iVar1 == 0) {
      FUN_4037b39c(param_1,0,0);
      uVar2 = 1;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}