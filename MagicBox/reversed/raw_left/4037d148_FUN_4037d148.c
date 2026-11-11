// 4037d148  FUN_4037d148  FUN_4037d148  size=143
// strings: uxPriority < ( 25 ) | tasks.c | prvInitialiseNewTask

void FUN_4037d148(undefined4 param_1,undefined1 *param_2,int param_3,undefined4 param_4,uint param_5
                 ,undefined4 *param_6,undefined4 *param_7,undefined4 param_8)

{
  undefined4 uVar1;
  uint uVar2;
  
  (*DAT_403744c4)(param_7[0xc],0xa5,param_3);
  uVar2 = param_7[0xc] + param_3 + -1 & 0xfffffff0;
  param_7[0x12] = uVar2;
  if (param_2 != (undefined1 *)0x0) {
    *(undefined1 *)(param_7 + 0xd) = *param_2;
    *(undefined1 *)((int)param_7 + 0x43) = 0;
  }
  if (0x18 < param_5) {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,0x440,PTR_s_prvInitialiseNewTask_40374f3c,
                 PTR_s_uxPriority_<_(_25_)_40374f38);
  }
  param_7[0xb] = param_5;
  param_7[0x11] = param_8;
  param_7[0x13] = param_5;
  FUN_4037cbe0(param_7 + 1);
  FUN_4037cbe0(param_7 + 6);
  param_7[4] = param_7;
  memw();
  param_7[6] = -(param_5 - 0x19);
  param_7[9] = param_7;
  FUN_40376f00(param_7 + 0x17);
  uVar1 = FUN_4037be94(uVar2,param_1,param_4);
  *param_7 = uVar1;
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = param_7;
  }
  return;
}


