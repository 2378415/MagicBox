// strings: pxQueue | !( ( pvItemToQueue == ((void *)0) ) && ( pxQueue | queue.c | xQueueGenericSendFromISR | !( ( xCopyPosition == ( ( BaseType_t ) 2 ) ) && 

undefined4 FUN_4037b588(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x49c,PTR_s_xQueueGenericSendFromISR_40374c9c,
                 PTR_s_pxQueue_40374c3c);
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x49d,PTR_s_xQueueGenericSendFromISR_40374c9c,
                 PTR_s______pvItemToQueue______void___0_40374c7c);
  }
  if ((param_4 == 2) && (*(int *)(param_1 + 0x3c) != 1)) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x49e,PTR_s_xQueueGenericSendFromISR_40374c9c,
                 PTR_s______xCopyPosition________BaseTy_40374c80);
  }
  FUN_4037bbe8(param_1 + 0x4c,0xffffffff);
  memw();
  if ((*(uint *)(param_1 + 0x38) < *(uint *)(param_1 + 0x3c)) || (param_4 == 2)) {
    memw();
    iVar2 = *(int *)(param_1 + 0x38);
    FUN_4037afa0(param_1,param_2,param_4);
    if (*(int *)(param_1 + 0x48) == 0) {
      memw();
      if (*(int *)(param_1 + 0x24) == 0) {
        uVar1 = 1;
      }
      else {
        iVar2 = FUN_4037d664(param_1 + 0x24);
        if (iVar2 == 0) {
          uVar1 = 1;
        }
        else if (param_3 == (undefined4 *)0x0) {
          uVar1 = 1;
        }
        else {
          uVar1 = 1;
          *param_3 = 1;
        }
      }
    }
    else if (param_4 == 2 && iVar2 != 0) {
      uVar1 = 1;
    }
    else {
      iVar2 = FUN_4037b054(param_1);
      if (iVar2 == 0) {
        uVar1 = 1;
      }
      else if (param_3 == (undefined4 *)0x0) {
        uVar1 = 1;
      }
      else {
        uVar1 = 1;
        *param_3 = 1;
      }
    }
  }
  else {
    uVar1 = 0;
  }
  FUN_4037bd38(param_1 + 0x4c);
  return uVar1;
}