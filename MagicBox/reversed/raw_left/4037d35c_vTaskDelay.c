// 4037d35c  vTaskDelay  FUN_4037d35c  size=101
// strings: ( ( xTaskGetSchedulerState() == ( ( BaseType_t ) | vTaskDelay

void FUN_4037d35c(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  if (param_1 != 0) {
    uVar1 = rsil(3);
    memw();
    if (*DAT_40374f10 != 0) {
      uVar2 = rsr(in_PRID);
      memw();
      if (*(int *)((uVar2 >> 0xd & 1) * 4 + DAT_40374ed8) != 0) {
        (*DAT_40374db8)(uVar1);
        FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,0x61b,PTR_s_vTaskDelay_40374f48,
                     PTR_s_____xTaskGetSchedulerState________40374f40);
      }
    }
    (*DAT_40374db8)();
    FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
    FUN_4037cdc0(param_1,0);
    FUN_4037c094(PTR_DAT_40374ef4);
  }
  uVar2 = rsr(in_PRID);
  FUN_40378e40(uVar2 >> 0xd & 1);
  return;
}


