// strings: ( ( xTaskGetSchedulerState() == ( ( BaseType_t )

void FUN_4037d1d8(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 in_PRID;
  
  puVar3 = PTR_DAT_40374ef4;
  FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
  iVar1 = DAT_40374e18;
  uVar5 = rsr(in_PRID);
  uVar5 = uVar5 >> 0xd & 1;
  if (param_1 == 0) {
    uVar8 = rsil(3);
    uVar6 = rsr(in_PRID);
    memw();
    param_1 = *(int *)((uVar6 >> 0xd & 1) * 4 + DAT_40374e18);
    (*DAT_40374db8)(uVar8);
  }
  iVar4 = param_1 + 4;
  FUN_4037cc94(iVar4);
  memw();
  if (*(int *)(param_1 + 0x28) != 0) {
    FUN_4037cc94(param_1 + 0x18);
  }
  memw();
  iVar7 = *(int *)(uVar5 * 4 + iVar1);
  *DAT_40374f14 = *DAT_40374f14 + 1;
  piVar2 = DAT_40374eec;
  if (iVar7 == param_1) {
    FUN_4037cbec(DAT_40374ee0,iVar4);
    memw();
    memw();
    *DAT_40374f2c = *DAT_40374f2c + 1;
    FUN_4037c094(puVar3);
    FUN_4037bf44(puVar3,0xffffffff);
    memw();
    if (*DAT_40374f10 != 0) {
      uVar8 = rsil(3);
      memw();
      if (*DAT_40374f10 != 0) {
        uVar5 = rsr(in_PRID);
        memw();
        if (*(int *)((uVar5 >> 0xd & 1) * 4 + DAT_40374ed8) != 0) {
          (*DAT_40374db8)(uVar8);
          FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,0x5ab,PTR_s_vTaskDelete_40374f44,
                       PTR_s_____xTaskGetSchedulerState________40374f40);
        }
      }
      (*DAT_40374db8)();
      uVar5 = rsr(in_PRID);
      FUN_40378e40(uVar5 >> 0xd & 1);
    }
  }
  else {
    uVar5 = (uint)(uVar5 == 0);
    memw();
    if (*(int *)(uVar5 * 4 + iVar1) == param_1) {
      FUN_4037cbec(DAT_40374ee0,iVar4);
      memw();
      memw();
      *DAT_40374f2c = *DAT_40374f2c + 1;
      FUN_4037c130(uVar5);
      FUN_4037c094(puVar3);
    }
    else {
      memw();
      memw();
      *DAT_40374ef8 = *DAT_40374ef8 + -1;
      memw();
      memw();
      if (*(int *)*piVar2 == 0) {
        memw();
        *DAT_40374ef0 = 0xffffffff;
        FUN_4037c094(puVar3);
      }
      else {
        memw();
        memw();
        memw();
        memw();
        *DAT_40374ef0 = **(undefined4 **)(*piVar2 + 0xc);
        FUN_4037c094(puVar3);
      }
      FUN_4037d068(param_1);
    }
    FUN_4037bf44(puVar3,0xffffffff);
    memw();
  }
  FUN_4037c094(puVar3);
  return;
}