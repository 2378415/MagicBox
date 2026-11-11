// 4037b768  xQueueGenericSend  FUN_4037b768  size=293
// strings: pxQueue | !( ( pvItemToQueue == ((void *)0) ) && ( pxQueue | queue.c | xQueueGenericSend | !( ( xCopyPosition == ( ( BaseType_t ) 2 ) ) &&  | !( ( xTaskGetSchedulerState() == ( ( BaseType_t 

undefined4 FUN_4037b768(int param_1,int param_2,int param_3,uint param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 in_PRID;
  undefined1 auStack_40 [16];
  int local_30;
  uint uStack_2c;
  int iStack_28;
  
  local_30 = param_3;
  uStack_2c = param_4;
  iStack_28 = param_2;
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x3a8,PTR_s_xQueueGenericSend_40374d2c,
                 PTR_s_pxQueue_40374cf0);
  }
  if ((iStack_28 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x3a9,PTR_s_xQueueGenericSend_40374d2c,
                 PTR_s______pvItemToQueue______void___0_40374d30);
  }
  if ((uStack_2c == 2) && (*(int *)(param_1 + 0x3c) != 1)) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x3aa,PTR_s_xQueueGenericSend_40374d2c,
                 PTR_s______xCopyPosition________BaseTy_40374d34);
  }
  iVar1 = FUN_4037e0e0();
  if ((iVar1 == 0) && (local_30 != 0)) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x3ad,PTR_s_xQueueGenericSend_40374d2c,
                 PTR_s______xTaskGetSchedulerState______40374d38);
  }
  else {
    param_2 = 1;
    param_4 = (uint)(uStack_2c == 2);
    param_6 = param_1 + 0x4c;
    param_3 = param_1 + 0x10;
    param_5 = 0;
  }
  while( true ) {
    FUN_4037bf44(param_6,0xffffffff);
    memw();
    if ((*(uint *)(param_1 + 0x38) < *(uint *)(param_1 + 0x3c)) || (param_4 != 0)) break;
    if (local_30 == 0) {
LAB_4037b885:
      FUN_4037c094(param_6);
      return 0;
    }
    if (param_5 == 0) {
      FUN_4037dfb8(auStack_40);
    }
    iVar1 = FUN_4037dfd4(auStack_40,&local_30);
    if (iVar1 != 0) goto LAB_4037b885;
    FUN_4037dce8(param_3,local_30);
    uVar3 = rsr(in_PRID);
    FUN_40378e40(uVar3 >> 0xd & 1);
    FUN_4037c094(param_6);
    param_5 = param_2;
  }
  memw();
  iVar2 = *(int *)(param_1 + 0x38);
  iVar1 = FUN_4037b3b8(param_1,iStack_28,uStack_2c);
  if (*(int *)(param_1 + 0x48) == 0) {
    memw();
    if (*(int *)(param_1 + 0x24) != 0) {
      iVar1 = FUN_4037dde4(param_1 + 0x24);
    }
  }
  else {
    if ((iVar2 != 0) && (param_4 != 0)) goto LAB_4037b846;
    iVar1 = FUN_4037b440(param_1);
  }
  if (iVar1 != 0) {
    uVar3 = rsr(in_PRID);
    FUN_40378e40(uVar3 >> 0xd & 1);
  }
LAB_4037b846:
  FUN_4037c094(param_6);
  return 1;
}


