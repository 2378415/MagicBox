// 42012fb8  FUN_42012fb8  FUN_42012fb8  size=133
// strings: Task watchdog got triggered. The following tasks |  (CPU 1)

undefined4 FUN_42012fb8(code *param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  
  if (*(int *)(*DAT_42000f78 + 4) == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    if (param_1 != (code *)0x0) {
      (*param_1)(param_2,PTR_s_Task_watchdog_got_triggered__The_42000fc8);
    }
    for (puVar4 = *(undefined4 **)(*DAT_42000f78 + 4); puVar4 != (undefined4 *)0x0;
        puVar4 = (undefined4 *)*puVar4) {
      if (*(char *)(puVar4 + 3) == '\0') {
        if (puVar4[1] == 0) {
          uVar2 = puVar4[2];
        }
        else {
          uVar2 = (*(code *)PTR_FUN_42000fd0)();
        }
        uVar1 = FUN_42012d50(puVar4[1]);
        if (param_3 != (uint *)0x0) {
          *param_3 = uVar1 | *param_3;
        }
        if (uVar1 == 1) {
          puVar3 = PTR_s__CPU_0__42000fbc;
        }
        else if (uVar1 == 2) {
          puVar3 = PTR_s__CPU_1__42000fc0;
        }
        else {
          puVar3 = PTR_s__CPU_0_1__42000fc4;
        }
        if (param_1 != (code *)0x0) {
          (*param_1)(param_2,PTR_DAT_42000fcc);
          (*param_1)(param_2,uVar2);
          (*param_1)(param_2,puVar3);
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


