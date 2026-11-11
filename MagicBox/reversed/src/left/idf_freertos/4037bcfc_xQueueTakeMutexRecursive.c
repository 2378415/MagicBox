// strings: pxMutex

undefined4 FUN_4037bcfc(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x335,PTR_s_xQueueTakeMutexRecursive_40374d64,
                 PTR_s_pxMutex_40374d3c);
  }
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = FUN_4037e0c0();
  if ((iVar1 == iVar2) || (iVar1 = FUN_4037bbf4(param_1,param_2), iVar1 != 0)) {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    return 1;
  }
  return 0;
}