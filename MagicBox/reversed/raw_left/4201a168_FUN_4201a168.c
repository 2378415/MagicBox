// 4201a168  FUN_4201a168  FUN_4201a168  size=255
// strings: Task watchdog got triggered. The following tasks | task_wdt |  (CPU 0/1)

undefined4 FUN_4201a168(code *param_1,undefined4 param_2,uint *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  
  piVar1 = DAT_42001868;
  puVar5 = *(undefined4 **)(*DAT_42001868 + 4);
  if (puVar5 == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    if (param_1 == (code *)0x0) {
      if (*(int *)PTR_DAT_42000028 == 0) goto LAB_4201a1b0;
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*DAT_42000060)(PTR_DAT_420018ec,uVar2,PTR_s_task_wdt_42001870,
                      PTR_s_Task_watchdog_got_triggered__The_420018e8);
      puVar5 = *(undefined4 **)(*piVar1 + 4);
    }
    else {
      (*param_1)(param_2,PTR_s_Task_watchdog_got_triggered__The_420018e8);
      puVar5 = *(undefined4 **)(*piVar1 + 4);
    }
    for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
LAB_4201a1b0:
      if (*(char *)(puVar5 + 3) == '\0') {
        if (puVar5[1] == 0) {
          uVar2 = puVar5[2];
LAB_4201a20f:
          if (param_3 != (uint *)0x0) {
            *param_3 = *param_3 | 3;
          }
LAB_4201a211:
          puVar6 = PTR_s__CPU_0_1__420018e4;
        }
        else {
          uVar2 = (*(code *)PTR_FUN_420018f8)();
          if (puVar5[1] == 0) goto LAB_4201a20f;
          uVar3 = (*(code *)PTR_FUN_420006c0)(puVar5[1]);
          if (1 < uVar3) {
            if (param_3 != (uint *)0x0) {
              *param_3 = *param_3 | 3;
            }
            goto LAB_4201a211;
          }
          if (param_3 == (uint *)0x0) {
            if (uVar3 != 0) goto LAB_4201a1f4;
LAB_4201a1ec:
            puVar6 = PTR_s__CPU_0__420018e0;
          }
          else {
            *param_3 = *param_3 | 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
            if (uVar3 == 0) goto LAB_4201a1ec;
LAB_4201a1f4:
            puVar6 = PTR_s__CPU_1__420018dc;
          }
        }
        if (param_1 == (code *)0x0) {
          if (*(int *)PTR_DAT_42000028 != 0) {
            uVar4 = (*(code *)PTR_FUN_4200005c)();
            (*DAT_42000060)(PTR_DAT_420018f0,uVar4,PTR_s_task_wdt_42001870,uVar2,puVar6);
          }
        }
        else {
          (*param_1)(param_2,PTR_DAT_420018f4);
          (*param_1)(param_2,uVar2);
          (*param_1)(param_2,puVar6);
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


