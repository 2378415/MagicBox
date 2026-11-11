// 4037b9e0  uxQueueSpacesAvailable  FUN_4037b9e0  size=50
// strings: pxQueue

int FUN_4037b9e0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,DAT_40374cd4,
                 PTR_s_uxQueueSpacesAvailable_40374cd0,PTR_s_pxQueue_40374c3c);
  }
  FUN_4037bbe8(param_1 + 0x4c,0xffffffff);
  iVar1 = *(int *)(param_1 + 0x3c);
  memw();
  iVar2 = *(int *)(param_1 + 0x38);
  FUN_4037bd38(param_1 + 0x4c);
  return iVar1 - iVar2;
}


