// strings: uxTaskPriority < ( 25 ) | prvIsYieldRequiredSMP

undefined4 FUN_4037cce8(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  if (0x18 < param_2) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,799,PTR_s_prvIsYieldRequiredSMP_40374ed0,
                 PTR_s_uxTaskPriority_<_(_25_)_40374ecc);
  }
  uVar1 = rsr(in_PRID);
  uVar2 = uVar1 >> 0xd & 1;
  uVar1 = *(uint *)(param_1 + 0x44);
  if (param_3 == 1) {
    param_2 = param_2 + 1;
  }
  if (uVar1 == uVar2) {
    memw();
    if ((*(uint *)(*(int *)(uVar1 * 4 + DAT_40374e18) + 0x2c) < param_2) &&
       (memw(), *(int *)(DAT_40374ed8 + uVar1 * 4) == 0)) {
      return 1;
    }
    if (uVar1 != DAT_40374eac) {
      return 0;
    }
  }
  else {
    if (uVar1 != DAT_40374eac) {
      uVar2 = (uint)(uVar2 == 0);
      if (uVar1 != uVar2) {
        return 0;
      }
      goto LAB_4037cd7a;
    }
    memw();
    if (*(uint *)(*(int *)(uVar2 * 4 + DAT_40374e18) + 0x2c) < param_2) {
      memw();
      if (*(int *)(DAT_40374ed8 + uVar2 * 4) == 0) {
        return 1;
      }
      uVar2 = (uint)(uVar2 == 0);
      goto LAB_4037cd7a;
    }
  }
  uVar2 = (uint)(uVar2 == 0);
LAB_4037cd7a:
  memw();
  if ((*(uint *)(*(int *)(uVar2 * 4 + DAT_40374e18) + 0x2c) < param_2) &&
     (memw(), *(int *)(DAT_40374ed8 + uVar2 * 4) == 0)) {
    FUN_4037c130();
  }
  return 0;
}