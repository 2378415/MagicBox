// 4037dc38  vTaskDelay  FUN_4037dc38  size=59
// strings: ( ( xTaskGetSchedulerState() == ( ( BaseType_t )

void FUN_4037dc38(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  if (param_1 != 0) {
    iVar1 = FUN_4037db0c();
    if (iVar1 == 0) {
      FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,0x61b,PTR_s_vTaskDelay_40374f10,
                   PTR_s_____xTaskGetSchedulerState________40374f08);
    }
    FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
    FUN_4037cdbc(param_1,0);
    FUN_4037bd38(PTR_DAT_40374e54);
  }
  uVar2 = rsr(in_PRID);
  FUN_403787f4(uVar2 >> 0xd & 1);
  return;
}


