// strings: ( pxQueue ) | !( ( ( pvBuffer ) == ((void *)0) ) && ( ( pxQueu | queue.c | xQueueReceive | !( ( xTaskGetSchedulerState() == ( ( BaseType_t 

undefined4 FUN_4037bafc(undefined4 *param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined1 in_PRID;
  undefined1 auStack_40 [16];
  int local_30;
  int iStack_2c;
  
  local_30 = param_3;
  if (param_1 == (undefined4 *)0x0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x5fb,PTR_s_xQueueReceive_40374d58,
                 PTR_s___pxQueue___40374d54);
  }
  if ((param_2 == 0) && (param_1[0x10] != 0)) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x5ff,PTR_s_xQueueReceive_40374d58,
                 PTR_s________pvBuffer________void___0__40374d5c);
  }
  iVar2 = FUN_4037e0e0();
  if ((iVar2 == 0) && (local_30 != 0)) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x604,PTR_s_xQueueReceive_40374d58,
                 PTR_s______xTaskGetSchedulerState______40374d38);
  }
  puVar3 = param_1 + 0x13;
  bVar1 = false;
  while( true ) {
    FUN_4037bf44(puVar3,0xffffffff);
    memw();
    iVar2 = param_1[0xe];
    if (iVar2 != 0) {
      if (param_1[0x10] != 0) {
        uVar4 = param_1[3] + param_1[0x10];
        param_1[3] = uVar4;
        if ((uint)param_1[2] <= uVar4) {
          param_1[3] = *param_1;
        }
        iStack_2c = iVar2;
        (*DAT_4037450c)(param_2);
        iVar2 = iStack_2c;
      }
      memw();
      param_1[0xe] = iVar2 + -1;
      memw();
      if ((param_1[4] != 0) && (iVar2 = FUN_4037dde4(param_1 + 4), iVar2 != 0)) {
        uVar4 = rsr(in_PRID);
        FUN_40378e40(uVar4 >> 0xd & 1);
      }
      FUN_4037c094(puVar3);
      return 1;
    }
    if (local_30 == 0) break;
    if (!bVar1) {
      FUN_4037dfb8(auStack_40);
    }
    iVar2 = FUN_4037dfd4(auStack_40,&local_30);
    if (iVar2 != 0) break;
    FUN_4037dce8(param_1 + 9,local_30);
    uVar4 = rsr(in_PRID);
    FUN_40378e40(uVar4 >> 0xd & 1);
    FUN_4037c094(puVar3);
    bVar1 = true;
  }
  FUN_4037c094(puVar3);
  return 0;
}