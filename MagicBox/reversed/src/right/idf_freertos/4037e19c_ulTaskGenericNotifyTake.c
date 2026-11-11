// strings: uxIndexToWait < 1 | ulTaskGenericNotifyTake

void FUN_4037e19c(int param_1,int param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined1 in_PRID;
  
  if (param_1 != 0) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374f4c,
                 PTR_s_ulTaskGenericNotifyTake_40374f48,PTR_s_uxIndexToWait_<_1_40374f44);
  }
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  uVar3 = rsr(in_PRID);
  uVar3 = uVar3 >> 0xd & 1;
  memw();
  memw();
  if (*(int *)((param_1 + 0x50) * 4 + *(int *)(uVar3 * 4 + DAT_40374d64) + 0xc) == 0) {
    memw();
    memw();
    *(undefined1 *)(*(int *)(uVar3 * 4 + DAT_40374d64) + param_1 + 0x150) = 1;
    if (param_3 != 0) {
      FUN_4037cdbc(param_3,1);
      uVar3 = rsr(in_PRID);
      FUN_403787f4(uVar3 >> 0xd & 1);
    }
  }
  puVar1 = PTR_DAT_40374e54;
  FUN_4037bd38(PTR_DAT_40374e54);
  FUN_4037bbe8(puVar1,0xffffffff);
  uVar3 = rsr(in_PRID);
  uVar3 = uVar3 >> 0xd & 1;
  memw();
  memw();
  iVar2 = *(int *)((param_1 + 0x50) * 4 + *(int *)(uVar3 * 4 + DAT_40374d64) + 0xc);
  if (iVar2 != 0) {
    if (param_2 == 0) {
      memw();
      memw();
      *(int *)((param_1 + 0x50) * 4 + *(int *)(uVar3 * 4 + DAT_40374d64) + 0xc) = iVar2 + -1;
    }
    else {
      memw();
      memw();
      *(undefined4 *)((param_1 + 0x50) * 4 + *(int *)(uVar3 * 4 + DAT_40374d64) + 0xc) = 0;
    }
  }
  memw();
  memw();
  *(undefined1 *)(*(int *)(uVar3 * 4 + DAT_40374d64) + param_1 + 0x150) = 0;
  FUN_4037bd38(PTR_DAT_40374e54);
  return;
}