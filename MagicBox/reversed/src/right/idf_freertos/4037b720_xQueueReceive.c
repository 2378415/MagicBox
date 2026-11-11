// strings: ( pxQueue ) | !( ( ( pvBuffer ) == ((void *)0) ) && ( ( pxQueu | queue.c | xQueueReceive | !( ( xTaskGetSchedulerState() == ( ( BaseType_t 

undefined4 FUN_4037b720(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 in_PRID;
  undefined1 auStack_40 [16];
  int local_30 [12];
  
  local_30[0] = param_3;
  if (param_1 == 0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x5fb,PTR_s_xQueueReceive_40374cb0,
                 PTR_s___pxQueue___40374cac);
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x5ff,PTR_s_xQueueReceive_40374cb0,
                 PTR_s________pvBuffer________void___0__40374cb4);
  }
  iVar2 = FUN_4037db0c();
  if (iVar2 == 0) {
    bVar1 = false;
    if (local_30[0] == 0) goto LAB_4037b778;
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x604,PTR_s_xQueueReceive_40374cb0,
                 PTR_s______xTaskGetSchedulerState______40374c84);
  }
  bVar1 = false;
LAB_4037b778:
  while( true ) {
    iVar3 = param_1 + 0x4c;
    FUN_4037bbe8(iVar3,0xffffffff);
    memw();
    iVar2 = *(int *)(param_1 + 0x38);
    if (iVar2 != 0) {
      FUN_4037b030(param_1,param_2);
      memw();
      *(int *)(param_1 + 0x38) = iVar2 + -1;
      memw();
      if ((*(int *)(param_1 + 0x10) != 0) && (iVar2 = FUN_4037d664(param_1 + 0x10), iVar2 != 0)) {
        uVar4 = rsr(in_PRID);
        FUN_403787f4(uVar4 >> 0xd & 1);
      }
      FUN_4037bd38(iVar3);
      return 1;
    }
    if (local_30[0] == 0) break;
    if (!bVar1) {
      FUN_4037d860(auStack_40);
      bVar1 = true;
    }
    iVar2 = FUN_4037d87c(auStack_40,local_30);
    if (iVar2 != 0) {
      FUN_4037bd38(iVar3);
      return 0;
    }
    FUN_4037d564(param_1 + 0x24,local_30[0]);
    uVar4 = rsr(in_PRID);
    FUN_403787f4(uVar4 >> 0xd & 1);
    FUN_4037bd38(iVar3);
  }
  FUN_4037bd38(iVar3);
  return 0;
}