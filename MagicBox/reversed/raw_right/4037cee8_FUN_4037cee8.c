// 4037cee8  FUN_4037cee8  FUN_4037cee8  size=158
// strings: uxPriority < ( 25 ) | tasks.c | prvInitialiseNewTask

void FUN_4037cee8(undefined4 param_1,int param_2,int param_3,undefined4 param_4,uint param_5,
                 undefined4 *param_6,undefined4 *param_7,undefined4 param_8,undefined4 param_9)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  (*DAT_4037448c)(param_7[0xc],0xa5,param_3);
  uVar3 = param_7[0xc] + param_3 + -1 & 0xfffffff0;
  param_7[0x12] = uVar3;
  if (param_2 != 0) {
    for (uVar4 = 0;
        (uVar4 < 0x10 &&
        (cVar1 = *(char *)(param_2 + uVar4), *(char *)((int)param_7 + uVar4 + 0x34) = cVar1,
        cVar1 != '\0')); uVar4 = uVar4 + 1) {
    }
    *(undefined1 *)((int)param_7 + 0x43) = 0;
  }
  if (0x18 < param_5) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,0x440,PTR_s_prvInitialiseNewTask_40374e7c,
                 PTR_s_uxPriority_<_(_25_)_40374e78);
  }
  param_7[0xb] = param_5;
  param_7[0x11] = param_9;
  param_7[0x13] = param_5;
  FUN_4037c8dc(param_7 + 1);
  FUN_4037c8dc(param_7 + 6);
  param_7[4] = param_7;
  memw();
  param_7[6] = -(param_5 - 0x19);
  param_7[9] = param_7;
  FUN_40376c5c(param_7 + 0x17);
  uVar2 = FUN_4037bb28(uVar3,param_1,param_4);
  *param_7 = uVar2;
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = param_7;
  }
  return;
}


