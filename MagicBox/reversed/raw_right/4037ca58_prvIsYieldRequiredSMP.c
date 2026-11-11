// 4037ca58  prvIsYieldRequiredSMP  FUN_4037ca58  size=152
// strings: uxTaskPriority < ( 25 ) | prvIsYieldRequiredSMP

undefined4 FUN_4037ca58(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 in_PRID;
  
  if (0x18 < param_2) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,799,PTR_s_prvIsYieldRequiredSMP_40374e28,
                 PTR_s_uxTaskPriority_<_(_25_)_40374e24);
  }
  uVar3 = rsr(in_PRID);
  uVar3 = uVar3 >> 0xd & 1;
  if (param_3 == 1) {
    param_2 = param_2 + 1;
  }
  uVar2 = *(uint *)(param_1 + 0x44);
  if ((((uVar2 == uVar3) || (uVar2 == DAT_403747f4)) &&
      (memw(), *(uint *)(*(int *)(uVar3 * 4 + DAT_40374d64) + 0x2c) < param_2)) &&
     (memw(), *(int *)(uVar3 * 4 + DAT_40374e18) == 0)) {
    uVar1 = 1;
  }
  else {
    uVar3 = (uint)(uVar3 == 0);
    if ((uVar2 == uVar3) || (uVar2 == DAT_403747f4)) {
      memw();
      if (*(uint *)(*(int *)(uVar3 * 4 + DAT_40374d64) + 0x2c) < param_2) {
        memw();
        if (*(int *)(uVar3 * 4 + DAT_40374e18) == 0) {
          FUN_4037bdd4();
          uVar1 = 0;
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


