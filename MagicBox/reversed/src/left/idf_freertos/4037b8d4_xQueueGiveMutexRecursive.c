// strings: h'%} | pxMutex

undefined4 FUN_4037b8d4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x2fd,PTR_s_xQueueGiveMutexRecursive_40374d40,
                 PTR_s_pxMutex_40374d3c);
  }
  iVar3 = *(int *)(param_1 + 8);
  iVar1 = FUN_4037e0c0();
  uVar2 = 0;
  if (iVar3 == iVar1) {
    iVar1 = *(int *)(param_1 + 0xc) + -1;
    *(int *)(param_1 + 0xc) = iVar1;
    if (iVar1 == 0) {
      FUN_4037b768(param_1,0,0,0);
    }
    uVar2 = 1;
  }
  return uVar2;
}