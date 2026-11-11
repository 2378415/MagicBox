// 4037db44  vTaskDelete  FUN_4037db44  size=242
// strings: ( ( xTaskGetSchedulerState() == ( ( BaseType_t ) | vTaskDelete

void FUN_4037db44(int param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined1 in_PRID;
  
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  uVar4 = rsr(in_PRID);
  uVar4 = uVar4 >> 0xd & 1;
  if (param_1 == 0) {
    param_1 = FUN_4037d934();
  }
  FUN_4037c980(param_1 + 4);
  memw();
  if (*(int *)(param_1 + 0x28) != 0) {
    FUN_4037c980(param_1 + 0x18);
  }
  *DAT_40374e90 = *DAT_40374e90 + 1;
  memw();
  if (*(int *)(uVar4 * 4 + DAT_40374d64) == param_1) {
    bVar1 = true;
  }
  else {
    memw();
    if (*(int *)((uint)(uVar4 == 0) * 4 + DAT_40374d64) != param_1) {
      memw();
      memw();
      *DAT_40374e5c = *DAT_40374e5c + -1;
      FUN_4037ca1c();
      bVar2 = false;
      bVar1 = false;
      goto LAB_4037dbf0;
    }
    bVar1 = false;
  }
  FUN_4037c8e8(DAT_40374e58,param_1 + 4);
  memw();
  memw();
  *DAT_40374e60 = *DAT_40374e60 + 1;
  if (bVar1) {
    bVar2 = true;
  }
  else {
    FUN_4037bdd4(uVar4 == 0);
    bVar2 = true;
  }
LAB_4037dbf0:
  FUN_4037bd38(PTR_DAT_40374e54);
  if (!bVar2) {
    FUN_4037ccdc(param_1);
  }
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  memw();
  if ((*DAT_40374e8c != 0) && (bVar1)) {
    iVar3 = FUN_4037db0c();
    if (iVar3 == 0) {
      FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,0x5ab,PTR_s_vTaskDelete_40374f0c,
                   PTR_s_____xTaskGetSchedulerState________40374f08);
    }
    uVar4 = rsr(in_PRID);
    FUN_403787f4(uVar4 >> 0xd & 1);
  }
  FUN_4037bd38(PTR_DAT_40374e54);
  return;
}


