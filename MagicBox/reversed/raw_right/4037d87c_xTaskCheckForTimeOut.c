// 4037d87c  xTaskCheckForTimeOut  FUN_4037d87c  size=182
// strings: pxTimeOut | pxTicksToWait | tasks.c | xTaskCheckForTimeOut

undefined4 FUN_4037d87c(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 in_PRID;
  
  if (param_1 == (int *)0x0) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374ee8,
                 PTR_s_xTaskCheckForTimeOut_40374ee4,PTR_s_pxTimeOut_40374ee0);
  }
  if (param_2 == (uint *)0x0) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374ef0,
                 PTR_s_xTaskCheckForTimeOut_40374ee4,PTR_s_pxTicksToWait_40374eec);
  }
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  memw();
  uVar4 = *DAT_40374e68;
  uVar3 = param_1[1];
  uVar2 = rsr(in_PRID);
  uVar2 = uVar2 >> 0xd & 1;
  memw();
  if (*(char *)(*(int *)(uVar2 * 4 + DAT_40374d64) + 0x152) == '\0') {
    uVar2 = *param_2;
    if (uVar2 == 0xffffffff) {
      uVar1 = 0;
    }
    else {
      memw();
      if ((*param_1 == *DAT_40374ea8) || (uVar4 < uVar3)) {
        if (uVar4 - uVar3 < uVar2) {
          *param_2 = (uVar3 - uVar4) + uVar2;
          FUN_4037d860(param_1);
          uVar1 = 0;
        }
        else {
          *param_2 = 0;
          uVar1 = 1;
        }
      }
      else {
        *param_2 = 0;
        uVar1 = 1;
      }
    }
  }
  else {
    memw();
    *(undefined1 *)(*(int *)(uVar2 * 4 + DAT_40374d64) + 0x152) = 0;
    uVar1 = 1;
  }
  FUN_4037bd38(PTR_DAT_40374e54);
  return uVar1;
}


