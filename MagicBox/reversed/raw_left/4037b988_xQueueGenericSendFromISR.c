// 4037b988  xQueueGenericSendFromISR  FUN_4037b988  size=209
// strings: pxQueue | !( ( pvItemToQueue == ((void *)0) ) && ( pxQueue | queue.c | xQueueGenericSendFromISR | !( ( xCopyPosition == ( ( BaseType_t ) 2 ) ) && 

undefined4 FUN_4037b988(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x49c,PTR_s_xQueueGenericSendFromISR_40374d44,
                 PTR_s_pxQueue_40374cf0);
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x49d,PTR_s_xQueueGenericSendFromISR_40374d44,
                 PTR_s______pvItemToQueue______void___0_40374d30);
  }
  if (param_4 == 2) {
    if (*(int *)(param_1 + 0x3c) != 1) {
      FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x49e,
                   PTR_s_xQueueGenericSendFromISR_40374d44,
                   PTR_s______xCopyPosition________BaseTy_40374d34);
      goto LAB_4037b9d0;
    }
    FUN_4037bf44(param_1 + 0x4c,0xffffffff);
    memw();
    memw();
    iVar2 = *(int *)(param_1 + 0x38);
    FUN_4037b3b8(param_1,param_2,2);
    if (*(int *)(param_1 + 0x48) == 0) goto LAB_4037ba20;
    uVar1 = 1;
    if (iVar2 != 0) goto LAB_4037ba55;
LAB_4037ba14:
    iVar2 = FUN_4037b440(param_1);
joined_r0x4037ba30:
    if ((param_3 != (undefined4 *)0x0) && (iVar2 != 0)) {
      *param_3 = 1;
    }
  }
  else {
LAB_4037b9d0:
    FUN_4037bf44(param_1 + 0x4c,0xffffffff);
    memw();
    uVar1 = 0;
    if (*(uint *)(param_1 + 0x3c) <= *(uint *)(param_1 + 0x38)) goto LAB_4037ba55;
    memw();
    FUN_4037b3b8(param_1,param_2,param_4);
    if (*(int *)(param_1 + 0x48) != 0) goto LAB_4037ba14;
LAB_4037ba20:
    memw();
    if (*(int *)(param_1 + 0x24) != 0) {
      iVar2 = FUN_4037dde4(param_1 + 0x24);
      goto joined_r0x4037ba30;
    }
  }
  uVar1 = 1;
LAB_4037ba55:
  FUN_4037c094(param_1 + 0x4c);
  return uVar1;
}


